package juniorAndrade.main;

import juniorAndrade.lib.collections.intervaltree.LongIntervalTree;
import juniorAndrade.lib.io.IOUtils;
import juniorAndrade.lib.utils.io.InputReader;
import juniorAndrade.lib.utils.io.OutputWriter;

public class URI2185 {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.readInt();
        int m = in.readInt();
        int [] arr = IOUtils.readIntArray(in, n);
        LongIntervalTree tree = new LongIntervalTree(n) {
            @Override
            protected long joinValue(long left, long right) {
                return (left ^ right);
            }

            @Override
            protected long joinDelta(long was, long delta) {
                return delta;
            }

            @Override
            protected long accumulate(long value, long delta, int length) {
                return (length % 2 == 1) ? delta : 0;
            }

            @Override
            protected long neutralValue() {
                return 0;
            }

            @Override
            protected long neutralDelta() {
                return 0;
            }
        };
        for(int i = 0; i < n; ++i) tree.update(i, i, arr[i]);
        for(int i = 0; i < m; ++i) {
            int l, r, v;
            l = in.readInt();
            r = in.readInt();
            v = in.readInt();
            tree.update(l - 1, r - 1, v);
            out.printLine(tree.query(0, n - 1) != 0 ? "Possivel" : "Impossivel");
        }
    }
}
