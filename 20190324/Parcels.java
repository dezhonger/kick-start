

import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

/**
 * Created by dezhonger on 2019/3/25
 */
public class Parcels {

    static int[] dx = new int[]{-1, 1, 0, 0};
    static int[] dy = new int[]{0, 0, -1, 1};
    static int n, m;

    static boolean check(int x, int y) {
        return x > 0 && x <= n && y > 0 && y <= m;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();

        for (int cT = 1; cT <= T; cT++) {

            n = scanner.nextInt();
            m = scanner.nextInt();
            int[][] a = new int[n + 1][m + 1];
            int[][] d = new int[n + 1][m + 1];
            boolean[][] v = new boolean[n + 1][m + 1];
            Queue<Q> queue = new ArrayDeque<>();
            for (int j = 1; j <= n; j++) {
                String s = scanner.next();
                for (int k = 1; k <= s.length(); k++) {
                    a[j][k] = s.charAt(k - 1) - '0';
                    if (a[j][k] ==1) {
                        d[j][k] = 0;
                        v[j][k] = true;
                        queue.add(new Q(j, k));
                    }
                }
            }

//            int maxDis = Integer.MAX_VALUE;
            while (!queue.isEmpty()) {

                Q q = queue.poll();
                for (int i = 0; i < 4; i++) {
                    int ddx = q.x + dx[i];
                    int ddy = q.y+dy[i];
                    if (check(ddx, ddy) && !v[ddx][ddy]) {
                        d[ddx][ddy] = d[q.x][q.y] +1;
                        queue.add(new Q(ddx, ddy));
                        v[ddx][ddy] = true;
//                        maxDis = Math.max(maxDis, d[ddx][ddy]);
                    }
                }
            }

            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if(!v[i][j]) {
                        d[i][j] = Integer.MAX_VALUE;
                    }
                }
            }

            int l = 0;
            int r = n + m;
            can(1, d);
            while(l < r) {
                int mid = (l + r)>>1;
                if (can(mid, d)) {
                    r=  mid;
                } else {
                    l = mid + 1;
                }
            }
            System.out.printf("Case #%s: ", cT);
            System.out.println(l);
        }
    }

    private static boolean can(int value, int[][] d) {
        int xplusymax = Integer.MAX_VALUE;
        int xplusymin = Integer.MIN_VALUE;
        int xminusymax = Integer.MAX_VALUE;
        int xminusymin = Integer.MIN_VALUE;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m ;j++) {
                if (d[i][j] > value) {
                    cnt++;
                    xplusymax = Math.min(xplusymax, i + j + value);
                    xplusymin = Math.max(xplusymin, i + j - value);
                    xminusymax = Math.min(xminusymax, i - j + value);
                    xminusymin = Math.max(xminusymin, i - j - value);

                }
            }
        }
        if (cnt == 0) {
            return true;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int plus = i + j;
                int minus = i - j;
                if (plus >= xplusymin && plus <= xplusymax && minus <= xminusymax && minus >= xminusymin) {
                    //this position is a solution
                    return true;
                }
            }
        }
        return false;
    }


}

class Q {
    public Q(int x, int y) {
        this.x = x;
        this.y = y;
    }

    int x, y;
}
