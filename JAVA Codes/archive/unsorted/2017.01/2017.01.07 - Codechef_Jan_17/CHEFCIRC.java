package juniorAndrade.main;

import juniorAndrade.lib.geometry.GeometryUtils;
import juniorAndrade.lib.geometry.Line;
import juniorAndrade.lib.geometry.Point;
import juniorAndrade.lib.io.IOUtils;
import juniorAndrade.lib.utils.io.InputReader;
import juniorAndrade.lib.utils.io.OutputWriter;

import java.net.PortUnreachableException;

public class CHEFCIRC {
    int n, m;
    Point [] p;

    boolean test(double x, double y, double r) {
        int ans = 0;
        Point oth = new Point(x, y);
        for(int i = 0; i < n && ans < m; ++i) {
            if(r + GeometryUtils.epsilon >= oth.distance(p[i])) ans++;
        }
        return ans >= m;
    }
    boolean go(double r) {
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                double d = p[i].distance(p[j]);
                if(d * 0.5 > r) continue;
                double x3 = (p[i].x + p[j].x) * 0.5;
                double y3 = (p[i].y + p[j].y) * 0.5;
                double basex = Math.sqrt((r * r) - ((d * 0.5) * (d * 0.5)))*(p[i].y-p[j].y)/d;
                double basey = Math.sqrt((r * r) - ((d * 0.5) * (d * 0.5)))*(p[i].x-p[j].x)/d;
                double centerx1 = x3 + basex;
                double centery1 = y3 + basey;
                double centerx2 = x3 - basex;
                double centery2 = y3 - basey;
                if(test(centerx1, centery1, r) || test(centerx2, centery2, r)) return true;
            }
        }
        return false;
    }
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        n = in.readInt();
        m = in.readInt();
        p = new Point[n];
        for(int i = 0; i < n; ++i) p[i] = Point.readPoint(in);
        double lo = 0, hi = 100000;
        for(int i = 0; i < 100; ++i) {
            double mid = (lo + hi) * 0.5;
            if(go(mid)) hi = mid;
            else lo = mid;
        }
        out.printFormat("%.6f\n", lo);
    }
}
