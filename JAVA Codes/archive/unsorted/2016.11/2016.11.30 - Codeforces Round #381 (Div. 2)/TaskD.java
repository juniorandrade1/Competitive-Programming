package juniorAndrade.main;

import juniorAndrade.lib.collections.Pair;
import juniorAndrade.lib.io.IOUtils;
import juniorAndrade.lib.utils.io.InputReader;
import juniorAndrade.lib.utils.io.OutputWriter;

import java.util.ArrayList;

public class TaskD {
    ArrayList<Pair<Long, Long>>[]g;
    int n;
    long [] arr;
    int [][] lca;
    int [] h;
    long [] sumH;
    int logn = 20;
    int [] sub;

    void dfs(int x, int ult) {
        lca[x][0] = ult;
        for(int i = 1; i < logn; ++i) lca[x][i] = lca[lca[x][i - 1]][i - 1];
        for(Pair<Long, Long> it : g[x]) {
            long y = it.first;
            long w = it.second;
            if(y == ult) continue;
            h[(int)y] = h[x] + 1;
            sumH[(int)y] = sumH[x] + w;
            dfs((int) y, x);
        }
    }

    void go(int x) {
        for(Pair<Long, Long> it : g[x]) {
            long y = it.first;
            go((int)y);
            sub[x] += sub[(int)y];
        }
    }

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        n = in.readInt();
        g = new ArrayList[n + 1];
        h = new int[n + 1];
        sumH = new long[n + 1];
        lca = new int[n + 1][logn + 1];
        arr = new long[n + 1];
        sub = new int[n + 1];
        for(int i = 0; i <= n; ++i) g[i] = new ArrayList<Pair<Long, Long>>();
        for(int i = 1; i <= n; ++i) arr[i] = in.readLong();
        for(int i = 2; i <= n; ++i) {
            int p, w;
            p = in.readInt();
            w = in.readInt();
            g[p].add(Pair.makePair((long)i, (long)w));
        }
        dfs(1, 0);
        for(int i = 2; i <= n; ++i) {
            sub[lca[i][0]]++;
            int anc = i;
            for(int j = logn - 1; j >= 0; --j){
                if(h[anc] >= (1 << j) && sumH[i] - sumH[lca[anc][j]] <= arr[i]) {
                    anc = lca[anc][j];
                }
            }
            sub[lca[anc][0]]--;
        }
        go(1);
        for(int i = 1; i <= n; ++i) out.print(sub[i] + " ");
        out.printLine();

    }
}
