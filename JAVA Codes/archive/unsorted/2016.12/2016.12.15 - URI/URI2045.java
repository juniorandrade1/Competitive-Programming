package juniorAndrade.main;

import juniorAndrade.lib.geometry.Point;
import juniorAndrade.lib.geometry.Polygon;
import juniorAndrade.lib.utils.io.InputReader;
import juniorAndrade.lib.utils.io.OutputWriter;

public class URI2045 {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        while(true) {
            int n = in.readInt();
            if (n == 0) break;
            Point[] p = new Point[n];
            for (int i = 0; i < n; ++i) p[i] = Point.readPoint(in);
            Polygon poly = new Polygon(p);
            if (testNumber != 1) out.printLine();
            out.printLine("Instancia " + testNumber);
            Point texas = Point.readPoint(in);
            int p1 = poly.contains(texas) ? 1 : 0;
            int m = in.readInt();
            for (int i = 1; i <= m; ++i) {
                Point foo = Point.readPoint(in);
                int p2 = poly.contains(foo) ? 1 : 0;
                int sol = p1 ^ p2;
                out.printLine(sol == 0 ? "soldado " + i + " defender" : "soldado " + i + " espanhol");
            }
            testNumber++;
        }
    }
}