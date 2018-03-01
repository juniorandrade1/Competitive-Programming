import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.CharBuffer;
import java.util.*;

public class kina_petr {
    private static final int MAX_INPUT_SIZE = 4000;
    private static final int HASH_BASE = 3137;

    public static void main(String[] args) throws IOException {
        FileReader reader = new FileReader("kina.in");
        CharBuffer inputBuffer = CharBuffer.allocate(MAX_INPUT_SIZE + 10);
        int len = reader.read(inputBuffer);
        if (len > MAX_INPUT_SIZE)
            throw new RuntimeException();
        inputBuffer.rewind();
        String input = inputBuffer.toString().substring(0, len) + " ";

        StringBuffer currentWord = new StringBuffer();
        List<String> wordList = new ArrayList<String>();
        for (int i = 0; i < input.length(); ++i) {
            char ch = input.charAt(i);
            if ((ch < 32 || ch > 126) && ch != 10 && ch != 13)
                throw new RuntimeException();
            if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
                currentWord.append(Character.toUpperCase(ch));
            else if (currentWord.length() > 0) {
                wordList.add(currentWord.toString());
                currentWord = new StringBuffer();
            }
        }

        int n = wordList.size();
        String[] words = wordList.toArray(new String[wordList.size()]);
        int[] wordId = new int[n];
        Map<String, Integer> idMap = new HashMap<String, Integer>();
        Set<Long> wordHashes = new HashSet<Long>();
        {
            int lastId = 0;
            for (int i = 0; i < n; ++i) {
                if (!idMap.containsKey(words[i])) {
                    idMap.put(words[i], lastId++);
                }
                wordId[i] = idMap.get(words[i]);
            }
            for (String word : words) {
                long hash = 0;
                for (int i = 0; i < word.length(); ++i)
                    hash = hash * HASH_BASE + word.charAt(i);
                wordHashes.add(hash);
            }
        }

        short[][] sameLen = new short[n + 1][n + 1];
        short[][] sameAbbrev = new short[n + 1][n + 1];
        for (int i = n - 1; i >= 0; --i)
            for (int j = n - 1; j >= 0; --j) {
                if (wordId[i] == wordId[j]) {
                    sameLen[i][j] = (short) (1 + sameLen[i + 1][j + 1]);
                }
                if (words[i].charAt(0) == words[j].charAt(0)) {
                    sameAbbrev[i][j] = (short) (1 + sameAbbrev[i + 1][j + 1]);
                }
                if (sameAbbrev[i][j] < sameLen[i][j])
                    throw new RuntimeException();
            }

        short[][] numNonOverlapping = new short[n + 1][n + 1];
        for (int i = n - 1; i >= 0; --i) {
            int leftmost = n;
            int[] whereWill = new int[n - i + 1];
            for (int j = 0; j <= n - i; ++j)
                whereWill[j] = n;
            for (int j = n - i; j >= 1; --j) {
                leftmost = Math.min(leftmost, whereWill[j]);
                int newlyAdded = sameLen[i][i + j];
                if (newlyAdded < j) {
                    whereWill[newlyAdded] = i + j;
                } else {
                    leftmost = i + j;
                }
                numNonOverlapping[i][j] = (short) (1 + numNonOverlapping[leftmost][j]);
            }
        }

        StringBuffer res = null;
        int resLen = 0;
        int resScore = 0;
        for (int i = 0; i < n; ++i) {
            int[] lenCnt = new int[n + 1];
            int[] abbrevCnt = new int[n + 1];
            for (int j = 0; j < n; ++j) {
                ++lenCnt[sameLen[i][j]];
                ++abbrevCnt[sameAbbrev[i][j]];
            }
            int totalLen = n;
            int totalAbbrev = n;
            int lenSum = 0;
            long curHash = 0;
            StringBuffer abbrev = new StringBuffer();
            for (int j = 1; i + j <= n; ++j) {
                totalLen -= lenCnt[j - 1];
                totalAbbrev -= abbrevCnt[j - 1];
                lenSum += words[i + j - 1].length();
                char ch = words[i + j - 1].charAt(0);
                abbrev.append(ch);
                curHash = curHash * HASH_BASE + ch;
                if (totalLen == totalAbbrev) {
                    boolean met = wordHashes.contains(curHash);
                    if (met)
                        met = idMap.containsKey(abbrev.toString());
                    if (!met) {
                        int score = (lenSum - j) * (numNonOverlapping[i][j] - 1) - j;
                        if (score > resScore) {
                            resScore = score;
                            res = abbrev;
                            resLen = abbrev.length();
                        }
                    }
                }
            }
        }

        PrintWriter writer = new PrintWriter("kina.out");
        writer.println(resScore);
        if (res != null) {
            writer.println(res.toString().substring(0, resLen));
        }
        writer.close();
    }
}
