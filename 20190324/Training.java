

//排序，枚举维护前缀o(N)


import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by zhangweilong on 2019/03/24
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/03/24
 */
public class Training {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        int c = 0;
        while(T > 0) {
            T--;
            c++;
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            int[] a =new int[n + 1];
            long[] sum =new long[n + 1];

            for (int i =  1; i <= n; i++) {
                int tmp = scanner.nextInt();
                a[i] = tmp;
            }
            Arrays.sort(a);
            for (int i =  1; i <= n; i++) {
                sum[i] = sum[i-1] + a[i];
            }
            long r = Long.MAX_VALUE;
            for (int i = m; i <= n; i++) {
                long tmp = 1L * a[i] * m - (sum[i] - sum[i - m]);
                r = Math.min(r, tmp);
            }
            System.out.printf("Case #%s: %s", c, r);
            System.out.println();
        }
    }

}
