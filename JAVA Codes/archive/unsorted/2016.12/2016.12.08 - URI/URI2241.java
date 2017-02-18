package juniorAndrade.main;

import juniorAndrade.lib.utils.io.InputReader;
import juniorAndrade.lib.utils.io.OutputWriter;

public class URI2241 {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.readInt();
        int p = in.readInt();
        int [][] a = new int[n + 1][n + 1];
        int [][] b = new int[n + 1][n + 1];
        for(int i = 0; i < p; ++i) {
            int x = in.readInt();
            int y = in.readInt();
            a[x][y]++;
        }
        for(int i = 0; i < p; ++i) {
            int x = in.readInt();
            int y = in.readInt();
            b[x][y]++;
        }
        for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) {
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
        }
        int solA = 0;
        int solB = 0;
        for(int z = 1; z <= n; ++z) {
            for(int i = z; i <= n; ++i) {
                for(int j = z; j <= n; ++j) {
                    int ca = a[i][j] - a[i - z][j] - a[i][j - z] + a[i - z][j - z];
                    int cb = b[i][j] - b[i - z][j] - b[i][j - z] + b[i - z][j - z];
                    if(ca == 0 && cb != 0) solB++;
                    if(cb == 0 && ca != 0) solA++;
                }
            }
        }
        out.printLine(solA + " " + solB);
    }
}
