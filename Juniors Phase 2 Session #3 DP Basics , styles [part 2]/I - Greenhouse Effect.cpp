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
const ll N = 5005, W = 1e4 + 5, oo = -1e18;

int n , m;
vector <int> arr;
int dp[N][N];

ll rec (int idx , int lst) {
    if (idx >= n) return 0;

    ll &ret = dp[idx][lst];
    if (~ret) return ret;

    ret = oo;
    ret = max(ret , rec(idx + 1 , lst));

    if (lst == -1 || arr[idx] >= lst) {
        ret = max(ret , rec(idx + 1 , arr[idx]) + 1);
    }

    return ret;
}

void solve() {
    cin >> n >> m; arr.resize(n);

    double x;
    for (int i = 0 ; i < n ; i++) cin >> arr[i] >> x;
    

    cout << n - rec(0 , 0) << '\n';
}

int32_t main() {
    ABo_ZeiD; // i'm backkkkkkk
    memset(dp , -1 , sizeof(dp));


    //freopen("input.txt" , "r", stdin);
    //freopen("output.txt" , "w", stdout);


    int t = 1;
//    cin >> t;
    while (t--)
        solve();


    return 0;
}
