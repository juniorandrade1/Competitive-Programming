package juniorAndrade.main;

import juniorAndrade.lib.utils.io.InputReader;
import juniorAndrade.lib.utils.io.OutputWriter;

public class TaskC {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int sol = 12345789;
        int n = in.readInt();
        int m = in.readInt();
        for(int i = 0; i < m; ++i) {
            int l = in.readInt(), r = in.readInt();
            sol = Math.min(sol, r - l + 1);
        }
        out.printLine(sol);
        for(int i = 0; i < n; ++i) out.print((i % sol) + " ");
        out.printLine();
    }
}
