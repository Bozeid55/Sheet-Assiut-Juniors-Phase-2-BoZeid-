// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 5005 , w = 1e6 + 5 , oo = 1e9;

int dx[] = {1 , 1 , 1 , -1 , -1 , -1 , 0 , 0} ,
    dy[] = {-1 , 0 , 1 , -1 , 0 , 1 , -1 , 1};

vector <int> adj[N]; bool vis[N];
vector <int> idk;

int mx = 0 , nd = 0;

void bfs (int node) {
    queue <int> q; q.push(node);
    idk[node] = 0;

    mx = 1;

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (auto i : adj[cur]) {
            if (idk[i] == -1) {
                idk[i] = idk[cur] + 1;
                mx = max(mx , idk[i]);
                q.push(i);
            }
        }

    }
}

void solve () {
    int n , x , y;
    while (cin >> n) {
        vector <int> dep(n + 1 , 0);

        for (int i = 1 ; i <= n ; i++) {
            cin >> x;

            while (x--) {
                cin >> y;
                adj[i].push_back(y);
                dep[y]++;
            }
        }

        queue <int> q;

        for (int i = 1 ; i <= n ;i++) {
            if (dep[i] == 1) {
                q.push(i);
            }
        }

        int nod = n;

        while (nod > 2) {
            int sz = q.size();
            nod -= sz;

            while (sz--) {
                int cur = q.front(); q.pop();

                for (auto i : adj[cur]) {
                    dep[i]--;

                    if (dep[i] == 1) {
                        q.push(i);
                    }
                }

                dep[cur] = 0;
            }
        }

        vector <int> ans;

        while (!q.empty()) {
            ans.push_back(q.front()); q.pop();
        }
        sort(all(ans)); 
        
        set <int> jsst;

        cout << "Best Roots  : ";
        for (int i = 0 ; i < ans.size() ; i++) {
            cout << ans[i]; jsst.insert(ans[i]);

            if (i != ans.size() - 1) cout << ' ';
        }
        cout << '\n';

        cout << "Worst Roots : ";

        vector <int> tmm(n + 1 , -1);

        set <int> st;
        for (auto i : ans) {
            idk = tmm;
            bfs(i);

            for (int k = 1 ; k <= n ; k++) {
                if (idk[k] == mx) {
                    st.insert(k);
                }
            }
            mx = 0;
        }

        int cnt = 0 , sz = st.size();
        for (auto i : st) {
            if (jsst.count(i)) continue;
            cout << i; cnt++;
            if (cnt < sz) {
                cout << ' ';
            }
        }

        cout << '\n';

        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }
        mx = 0 , nd = 0; tmm.clear();
    }
}

int main() {
    ABo_ZeiD; // i'm backkkkkk;

//    memset(dp , -1 , sizeof(dp));
    //freopen("smallest.in" , "r", stdin);
//    pre();

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
