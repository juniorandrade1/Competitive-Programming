package juniorAndrade.main;

import juniorAndrade.lib.graph.Graph;
import juniorAndrade.lib.graph.MaxFlow;
import juniorAndrade.lib.utils.io.InputReader;
import juniorAndrade.lib.utils.io.OutputWriter;

public class URI2354 {
    int n;
    int []a;
    int []b;
    int discover(int id) {
        int countVotes = 0;
        Graph g = new Graph((n * 3) + 2);
        int source = 0, target = 1;
        for(int i = 1; i <= n; ++i) {
            if(i == id) continue;
            if(a[i] == id) {
                countVotes++;
                continue;
            }
            else if(b[i] == id) {
                countVotes++;
                continue;
            }
            g.addFlowEdge(i * 2, a[i] * 2 + 1, Integer.MAX_VALUE);
            g.addFlowEdge(i * 2, b[i] * 2 + 1, Integer.MAX_VALUE);
        }
        int all = 0;
        for(int i = 1; i <= n; ++i) {
            if(i == id || a[i] == id || b[i] == id) continue;
            all++;
            int lolzin = 0;
            if(a[id] == i || b[id] == i) lolzin = 1;
            g.addFlowEdge(source, i * 2, 1);
            if(countVotes - 1 - lolzin < 0) return 0;
            g.addFlowEdge(i * 2 + 1, target, Math.max(countVotes - 1 - lolzin, 0));
        }
        MaxFlow f = new MaxFlow(g, source, target);
        long sol = f.dinic();
        return sol == all ? 1 : 0;
    }
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        n = in.readInt();
        a = new int[n + 1];
        b = new int[n + 1];
        for(int i = 1; i <= n; ++i) {
            a[i] = in.readInt();
            b[i] = in.readInt();
        }
        int ans = n;
        for(int i = 1; i <= n; ++i) ans -= discover(i);
        out.printLine(ans);
    }
}
