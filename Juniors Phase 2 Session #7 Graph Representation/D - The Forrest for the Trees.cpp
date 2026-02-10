// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 1e5 + 5, W = 1e5 + 5 , oo = 1e9 + 5;

vector <int> adj[N]; bool vis[N];

void dfs (int node) {
    vis[node] = 1;

    for (auto i : adj[node]) {
        if (!vis[i]) {
            dfs(i);
        }
    }
}

void solve() {
    string s;

    bool f[29] = {0};

    while (cin >> s) {
        if (s[0] == '*') break;

        adj[(s[1] - 'A') + 1].push_back((s[3] - 'A') + 1);
        adj[(s[3] - 'A') + 1].push_back((s[1] - 'A') + 1);
    }

    cin >> s;

    int tr = 0 , ar = 0;

    for (auto i : s) {
        if (i >= 'A' && i <= 'Z') {
            if (adj[(i - 'A') + 1].empty()) {
                ar++; continue;
            }

            else if (!vis[(i - 'A') + 1]) {
                dfs((i - 'A') + 1); tr++;
            }
        }
    }



    cout << "There are " << tr << " tree(s) and " << ar << " acorn(s)." << '\n';

    for (int i = 1 ; i <= 26 ; i++) {
        adj[i].clear();
    }

    for (int i = 1 ; i <= 26 ; i++) {
        vis[i] = 0;
    }
}

int main() {
    ABo_ZeiD; // i'm backkkkkk;


//    memset(dp , -1 , sizeof(dp));
    //freopen("smallest.in" , "r", stdin);


    int t = 1;
    cin >> t;
    for (int i = 1 ; i <= t ; i++) {
//        cout << "Case " << i << ": ";
        solve();
//        if (i != t) {
//            cout << '\n';
//        }
    }


    return 0;
}
