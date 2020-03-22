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

const int maxn = 100010;
int T, N, K, all;
int a[maxn];

int check(int mid) {
    int last = a[0];
    for (int i = 1; i < N; i++) {
        if (a[i] - last <= mid) continue;
        int d = a[i] - last - 1;

        int y = (d + 1 + mid) / (mid + 1);
        int z = y - 1;
        if (z > all) return 0;
        all -= z;
        last = a[i];
    }
    return 1;
}

int main() {
    cin >> T;
    for (int i = 1; i <= T; i++ ) {
        cin >> N >> K;
        int maxDiff = 0;
        for (int i = 0; i < N; i++) cin >> a[i];
        for (int i = 1; i < N; i++) {
            maxDiff = max(maxDiff, a[i] - a[i-1]);
        }
        int l = 0, r = maxDiff + 10;
        while (l < r) {
            int mid = (l + r) / 2;
            all = K;
            if (check(mid)) {
                r = mid;

            } else {
                l = mid + 1;
            }
        }
        cout << "Case #" << i << ": " << l + 1 << endl;

    }
    return 0;
}
