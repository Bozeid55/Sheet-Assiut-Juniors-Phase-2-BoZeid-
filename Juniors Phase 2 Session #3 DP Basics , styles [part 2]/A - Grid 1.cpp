// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 1005 , W = 1e5 + 5 , oo = 1e9 + 7;

ll add (ll a ,ll b) {
    return ((a % oo)+(b % oo)) % oo;
}

int n , m;
vector <vector <char>> arr;

ll dp[N][N];
ll rec (int l , int r) {
    if (l >= n - 1 && r >= m - 1) return 1;


    ll &ret = dp[l][r];
    if (~ret) return ret;

    ret = 0;

    if (l + 1 < n && arr[l + 1][r] != '#') ret = add(ret , rec(l + 1 , r));
    if (r + 1 < m && arr[l][r + 1] != '#') ret = add(ret , rec(l , r + 1));


    return ret;
}


void solve() {
    cin >> n >> m;

    arr.resize(n);
    for (int i = 0 ; i < n ; i++) {
        arr[i].resize(m);
        for (int j = 0 ; j < m ; j++) {
            cin >> arr[i][j];
        }
    }

    cout << rec(0 , 0) << '\n';
}

int main() {
    ABo_ZeiD; // i'm backkkkkkk
    memset(dp , -1 , sizeof(dp));

    //freopen("smallest.in" , "r", stdin);


    int t = 1;
    //cin >> t;
    while (t--)
        solve();


    return 0;
}
