// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 1e5 + 5, W = 1e4 + 5, oo = 1e18;

int n , m , V , T;
vector <pair <ll , ll>> arr;
map <pair <int , ll> , ll> dp;

ll rec (int idx , ll sum) {
    if (idx >= n) {
        return (sum >= V ? 0 : oo);
    }

    if (dp[{idx , sum}]) {
        return dp[{idx , sum}];
    }

    dp[{idx , sum}] = oo;
    dp[{idx , sum}] = min(dp[{idx , sum}] , rec(idx + 1 , sum));
    return dp[{idx , sum}] = min(dp[{idx , sum}]  , rec(idx + 1 , sum + (T * arr[idx].first)) + arr[idx].second);
}

void solve() {
    cin >> n; arr.resize(n);

    for (int i = 0 ; i < n ; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    cin >> m;

    int cur = 1;
    while (m--) {
        cin >> V >> T;

        ll ans = rec(0 , 0);

        cout << "Case " << cur << ": ";
        if (ans >= oo) cout << "IMPOSSIBLE" << '\n';
        else cout << ans << '\n';


        dp.clear(); cur++;
    }

}

int main() {
    ABo_ZeiD; // i'm backkkkkkk
//    memset(dp , -1 , sizeof(dp));

    //freopen("input.txt" , "r", stdin);
    //freopen("output.txt" , "w", stdout);


    int t = 1;
//    cin >> t;
    while (t--)
        solve();


    return 0;
}
