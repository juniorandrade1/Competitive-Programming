package juniorAndrade.main;

import juniorAndrade.lib.collections.Pair;
import juniorAndrade.lib.collections.sequence.Array;
import juniorAndrade.lib.utils.io.InputReader;
import juniorAndrade.lib.utils.io.OutputWriter;

import java.util.Arrays;
import java.util.PriorityQueue;

public class cowqueue {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.readInt();
        Pair<Integer, Integer> [] arr = new Pair[n];
        for(int i = 0; i < n; ++i) {
            int a = in.readInt();
            int b = in.readInt();
            arr[i] = Pair.makePair(a, b);
        }
        Arrays.sort(arr);
        PriorityQueue<Integer> q = new PriorityQueue<>();
        int p = 0;
        int t = 0;
        while(p < n || q.size() > 0) {
            if(p < n && q.size() == 0 && t < arr[p].first) t = arr[p].first;
            while(p < n && arr[p].first <= t) q.add(arr[p++].second);
            int x = q.peek(); q.poll();
            //out.printLine("AQUI = " + t + " " + x + " === " + (t + x));
            t += x;
        }
        out.printLine(t);

    }
}
