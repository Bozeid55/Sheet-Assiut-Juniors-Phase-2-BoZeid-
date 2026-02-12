// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 1e5 + 5 , W = 1e5 + 5 , oo = 1e9 - 1;

vector <int> adj[N];
vector <int> ans , cnt(N); bool vis[N];

void dfs (int node) {
    vis[node] = 1;

    for (auto i : adj[node]) {
        if (!vis[i]) dfs(i);
    }

    ans.push_back(node);
}

void solve() {
    int n , k , a , b; cin >> n >> k;

    for (int i = 1 ; i <= k ; i++) {
        cin >> a;

        while (a--) {
            cin >> b; adj[i].push_back(b);
        }
    }

    for (int i = 1 ; i <= n ; i++) if (!vis[i]) dfs(i);

    reverse(all(ans));

    for (int i = 0 ; i < n ; i++) {
        cnt[ans[i]] = (!i ? 0 : ans[i - 1]);
    }

    for (int i = 1 ; i <= n ; i++) {
        cout << cnt[i] << '\n';
    }
}

int main() {
    ABo_ZeiD; // i'm backkkkkk;


//    memset(dp , -1 , sizeof(dp));
    //freopen("smallest.in" , "r", stdin);


    int t = 1;
//    cin >> t;
    for (int i = 1 ; i <= t ; i++) {
//        cout << "Case " << i << ": ";
        solve();
//        if (i != t) {
//            cout << '\n';
//        }
    }


    return 0;
}
