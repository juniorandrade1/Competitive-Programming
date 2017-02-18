package juniorAndrade.main;

import juniorAndrade.lib.utils.io.InputReader;
import juniorAndrade.lib.utils.io.OutputWriter;

import java.util.ArrayList;

public class TaskA {
    int [] have;
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.readInt();
        have = new int[n + 10];
        int p = n;
        for(int i = 1; i <= n; ++i) {
            int x = in.readInt();
            have[x] = 1;
            ArrayList<Integer>arr = new ArrayList<Integer>();
            while(have[p] == 1) {
                arr.add(p);
                p--;
            }
            for(int j = 0; j < arr.size(); ++j) {
                if(j > 0) out.print(" ");
                out.print(arr.get(j));
            }
            out.printLine();
        }
    }
}
