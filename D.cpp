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


const int maxn = 2000010;
int T, n, k, m, c[maxn][26],cnt[maxn];
LL ans;

void dfs (int u, int d) {
    for (int i = 0; i < 26; i++) {
        if (c[u][i]) {
            dfs (c[u][i], d + 1);
            cnt[u] += cnt[c[u][i]];
        }
    }

    int x = cnt[u] / k;

    cnt[u] = cnt[u] - x * k;
    ans += x * d;
}

void insertTrie(string s) {
    int u = 0;
    for (char d : s) {
        if (!c[u][d - 'A'])
            c[u][d - 'A'] = m++;
        u = c[u][d - 'A'];
    }
    cnt[u]++;
}

void solve() {
    cin >> n >> k;
    m = 1;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        insertTrie (s);
    }
    dfs (0, 0);
    CLR (c, 0);
    CLR (cnt, 0);
}

int main() {
    ios::sync_with_stdio (0);
    cin.tie (0);
    cin >> T;
    for (int i = 1; i <= T; i++) {
        ans = 0;
        solve();
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}

