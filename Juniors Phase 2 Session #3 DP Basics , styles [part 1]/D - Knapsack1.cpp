// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 105 , W = 1e5 + 5 , oo = LLONG_MIN;

ll n , mx , w[N] , p[W] , dp[N][W];

ll rec(int idx , ll cur) {
    if (idx == n) return 0;

    ll &ret = dp[idx][cur];
    if (~ret) return ret;

    return ret = max((cur - w[idx] >= 0 ? rec(idx + 1, cur - w[idx]) + p[idx] : oo) , rec(idx + 1 , cur));
}

void solve() {
    cin >> n >> mx;

    for (int i = 0 ; i < n ; i++) cin >> w[i] >> p[i];

    cout << rec(0 , mx) << '\n';
}

int main() {
    ABo_ZeiD; // i'm backkkkkkk

    memset(dp , -1 , sizeof(dp));
    //freopen("smallest.in" , "r", stdin);


    int t = 1;

//    cin >> t;
    while (t--)
        solve();


    return 0;
}
