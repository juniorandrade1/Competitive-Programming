package juniorAndrade.main;

import juniorAndrade.lib.geometry.Point;
import juniorAndrade.lib.utils.io.InputReader;
import juniorAndrade.lib.utils.io.OutputWriter;

public class TaskA {
    Point getPoint(long a){
        if (a == 1) return new Point (0, 0);
        int id;
        for (int i = 1; ; i += 2) {
            if (a <= i * i) {
                id = i;
                break;
            }
        }
        int num = id * id - (id - 2) * (id - 2);
        int t = id / 2;
        int now = (id - 2) * (id - 2);
        num /= 4;
        if (a <= now + num) return new Point (a - now - t, -t);
        if (a <= now + 2 * num) return new Point (t, a - now - num - t);
        if (a <= now + 3 * num) return new Point (-(a - now - 2 * num - t), t);
        return new Point (-t, -(a - now - 3 * num - t));
    }
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int a = in.readInt();
        int b = in.readInt();
        Point p1 = getPoint(a);
        Point p2 = getPoint(b);
        out.printLine((int)Math.abs(p1.x - p2.x) + (int)Math.abs(p1.y - p2.y));
    }
}
