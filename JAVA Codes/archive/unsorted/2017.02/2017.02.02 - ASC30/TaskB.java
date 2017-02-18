package juniorAndrade.main;

import juniorAndrade.lib.utils.io.InputReader;
import juniorAndrade.lib.utils.io.OutputWriter;

import java.math.BigInteger;

public class TaskB {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.readInt();
        BigInteger[] pd = new BigInteger[n + 2];

        BigInteger[][] C = new BigInteger[n + 2][n + 2];
        BigInteger[] fat = new BigInteger[n + 2];
        BigInteger[] pw = new BigInteger[n + 2];

        pd[0] = fat[0] = pw[0] = BigInteger.ONE;
        for(int i = 1; i <= n; ++i) {
            fat[i] = fat[i - 1].multiply(BigInteger.valueOf(i));
            pw[i] = pw[i - 1].multiply(BigInteger.valueOf(2));
            for(int j = 1; j <= i; ++j) {
                if(i == j || j == 1) C[i][j] = BigInteger.ONE;
                else C[i][j] = C[i - 1][j].add(C[i - 1][j - 1]);
            }
        }

        for(int i = 1; i <= n; ++i) {
            pd[i] = pw[i].multiply(fat[i]);
            for(int j = 1; j <= i; ++j) {
                BigInteger c = fat[i].divide(fat[j].multiply(fat[i - j]));
                pd[i] = pd[i].subtract(c.multiply(pd[i - j]));
            }
        }
        out.printLine(pd[n]);
    }
}
