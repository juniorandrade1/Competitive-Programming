package juniorAndrade.main;

import juniorAndrade.lib.collections.Pair;
import juniorAndrade.lib.collections.set.MultiSet;
import juniorAndrade.lib.utils.io.InputReader;
import juniorAndrade.lib.utils.io.OutputWriter;

import java.util.Arrays;
import java.util.Iterator;

public class helpcross {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.readInt();
        int m = in.readInt();
        MultiSet<Integer> s = new MultiSet<Integer>();
        for(int i = 0; i < n; ++i) {
            int x = in.readInt();
            s.add(x);
        }
        Pair<Integer, Integer>[] arr = new Pair[m];
        for(int i = 0; i < m; ++i) {
            int x = in.readInt();
            int y = in.readInt();
            arr[i] = Pair.makePair(y, x);
        }
        Arrays.sort(arr);
        int ans = 0;
        for(int i = 0; i < m; ++i) {
            int l = arr[i].second;
            int r = arr[i].first;
            Iterator<Integer> it = s.low
        }
        out.printLine(ans);
    }
}
