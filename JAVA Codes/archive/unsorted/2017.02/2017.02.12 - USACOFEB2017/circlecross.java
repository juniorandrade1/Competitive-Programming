package juniorAndrade.main;

import juniorAndrade.lib.utils.io.InputReader;
import juniorAndrade.lib.utils.io.OutputWriter;

public class circlecross {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        String s = in.readLine();
        int [] a = new int[26];
        int [] b = new int[26];
        for(int i = 0; i < 26; ++i) a[i] = b[i] = -1;
        for(int i = 0; i < s.length(); ++i) {
            int op = (int)(s.charAt(i) - 'A');
            if(a[op] == -1) a[op] = i;
            else b[op] = i;
        }

        int cnt = 0;
        for(int i = 0; i < 26; ++i) {
            for(int j = i + 1; j < 26; ++j) {
                if(a[i] <= a[j] && b[i] >= a[j] && a[i] <= b[j] && b[i] >= b[j]) continue;
                if(a[j] <= a[i] && b[j] >= a[i] && a[j] <= b[i] && b[j] >= b[i]) continue;
                if(a[i] <= a[j] && b[i] >= a[j] && b[i] < b[j]) cnt++;
                else if(a[j] <= a[i] && b[j] >= a[i] && b[j] < b[i]) cnt++;
            }
        }
        out.printLine(cnt);

    }
}
