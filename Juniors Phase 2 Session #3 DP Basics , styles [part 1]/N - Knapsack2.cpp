// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 1e5 + 5 , oo = LLONG_MAX;


ll n , mx , w[105] , p[105] , dp[105][N] , sum = 0;

ll rec (int idx , ll cur) {
    if (idx >= n) return (!cur ? 0 : 1e9);


    ll &ret = dp[idx][cur];
    if (~ret) return ret;


    return ret = min((cur - p[idx] >= 0 ? rec(idx + 1, cur - p[idx]) + w[idx] : oo) , rec(idx + 1 , cur));
}


void solve() {
    cin >> n >> mx;
    for (int i = 0 ; i < n ; i++) {
        cin >> w[i] >> p[i]; sum += p[i];
    }

    for (int i = sum ; i >= 0 ; i--) {
        if (rec(0 , i) <= mx) {
            cout << i << '\n';
            return;
        }
    }

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
