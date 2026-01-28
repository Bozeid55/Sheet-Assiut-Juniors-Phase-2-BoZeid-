// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define inputz(vec , x) for (int i = 0 ; i < x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 1000005, W = 1e4 + 5, oo = 1e18;


int n , a , b , c;
ll dp[155][155][155];

ll rec (int idx , int a , int b , int c) {
    if (idx >= n) {
        return 0;
    }

    ll &ret = dp[idx][b][c];
    if (~ret) return ret;

    ret = oo;

    if (a >= 8) ret = min(ret , rec(idx + 1 , a - 8 , b , c) + 8);
    if (b >= 2) ret = min(ret , rec(idx + 1 , a + 2 , b - 2 , c) + 2);
    if (c) ret = min(ret , rec(idx + 1 , a + 2 , b , c - 1) + 1);

    if (b && a >= 3) ret = min(ret , rec(idx + 1 , a - 3 , b - 1 , c) + 4);
    if (c && b >= 2) ret = min(ret , rec(idx + 2 , a + 4 , b - 2 , c - 1) + 3);

    if (c && a >= 3) ret = min(ret , rec(idx + 1 , a - 3 , b + 1 , c - 1) + 4);
    if (c && b && a >= 3) ret = min(ret , rec(idx + 1 , a - 3 , b - 1 , c - 1) + 5);


    return ret;
}

void solve() {
    memset(dp , -1 , sizeof(dp));
    cin >> n >> a >> b >> c;

    cout << rec(0 , a , b , c) << '\n';
}

int32_t main() {
    ABo_ZeiD; // i'm backkkkkkk


    //freopen("input.txt" , "r", stdin);
    //freopen("output.txt" , "w", stdout);


    int t = 1;
    cin >> t;
    while (t--)
        solve();


    return 0;
}
