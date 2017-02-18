package juniorAndrade.main;

import juniorAndrade.lib.utils.io.InputReader;
import juniorAndrade.lib.utils.io.OutputWriter;

public class TaskK {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        String s = in.readLine();
        String wa = "KANGAROO";
        int [] a = new int[26];
        for(int i = 0; i < wa.length(); ++i) a[wa.charAt(i) - 'A']++;
        String wb = "KIWIBIRD";
        int [] b = new int[26];
        for(int i = 0; i < wb.length(); ++i) b[wb.charAt(i) - 'A']++;
        int sa = 0, sb = 0;
        s = s.toLowerCase();
        for(int i = 0; i < s.length(); ++i) {
            sa += a[s.charAt(i) - 'a'];
            sb += b[s.charAt(i) - 'a'];
        }
        if(sa == sb) out.printLine("Feud continues");
        else if(sa > sb) out.printLine("Kangaroos");
        else out.printLine("Kiwis");
    }
}
