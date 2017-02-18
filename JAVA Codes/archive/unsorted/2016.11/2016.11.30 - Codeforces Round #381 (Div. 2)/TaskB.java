package juniorAndrade.main;

import juniorAndrade.lib.io.IOUtils;
import juniorAndrade.lib.utils.io.InputReader;
import juniorAndrade.lib.utils.io.OutputWriter;

public class TaskB {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.readInt();
        int m = in.readInt();
        int [] arr = IOUtils.readIntArray(in, n);
        long ans = 0;
        while(m-- > 0) {
            int l = in.readInt(), r = in.readInt();
            long foo = 0;
            for(int i = l - 1; i <= r - 1; ++i) foo += arr[i];
            if(foo > 0) ans += foo;
        }
        out.printLine(ans);
    }
}
