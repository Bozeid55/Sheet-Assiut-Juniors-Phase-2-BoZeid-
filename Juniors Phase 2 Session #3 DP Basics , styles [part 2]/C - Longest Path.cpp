// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 1e5 + 5, W = 1e4 + 5, oo = LLONG_MIN;

int n , m;
vector <int> adj[N];
int dp[N];

int rec (int idx) {

    int &ret = dp[idx];
    if (~ret) return ret;

    ret = 1;

    for (auto it : adj[idx]) {
        ret = max(ret , rec(it) + 1);
    }

    return ret;
}

void solve() {
    cin >> n >> m;

    int a , b;
    while (m--) {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    int mx = 1;

    for (int i = 1 ; i <= n ; i++) {
        mx = max(mx , rec(i));
    }

    cout << mx - 1 << '\n';
}

int main() {
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
