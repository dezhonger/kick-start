#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <string.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define reps(i, a, b) for(int i = (a); i < (b); i++)
#define pb push_back
#define ps push
#define mp make_pair
#define CLR(x,t) memset(x,t,sizeof x)
#define LEN(X) strlen(X)
#define F first
#define S second
#define Debug(x) cout<<#x<<"="<<x<<endl;


const double euler_r = 0.57721566490153286060651209;
const double pi = 3.141592653589793238462643383279;
const double E = 2.7182818284590452353602874713526;
const int inf = ~0U >> 1;
const int MOD = int (1e9) + 7;
const double EPS = 1e-6;

typedef long long LL;

int gcd (int a, int b) {
    return b == 0 ? a : gcd (b, a % b);
}

const int maxn = 2020;
int a[maxn][maxn];
int T, k, p, n;
int dp[maxn][maxn];
int main() {
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> n >> k >> p;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                cin >> a[i][j];
            }
        }
        CLR (dp, 0xc0);
        dp[0][0] = 0;


        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= p; j++) {
                for (int o = 0; o <= min(k, j); o++) {
                    int s = 0;
                    for (int m = 1; m <= o; m++)
                        s += a[i][m];
                    dp[i][j] = max (dp[i][j], dp[i - 1][j - o] + s);
                }
            }
        }
        cout << "Case #" << k << ": " << dp[n][p] << endl;

    }
    return 0;



}
