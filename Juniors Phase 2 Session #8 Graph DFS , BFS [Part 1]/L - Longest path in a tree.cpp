// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 10005 , w = 1e6 + 5 , oo = 1e9;

int dx[] = {1 , 1 , 1 , -1 , -1 , -1 , 0 , 0} ,
    dy[] = {-1 , 0 , 1 , -1 , 0 , 1 , -1 , 1};

vector <int> adj[N]; bool vis[N] , vis2[N];

ll mx = 0 , cnt = 0 , nd = 0;

void dfs (ll node , bool flag) {
    if (flag) vis[node] = 1;
    else vis2[node] = 1;

    if (cnt > mx) {
        mx = cnt , nd = node;
    }

    for (auto i : adj[node]) {
        if (flag) {
            if (!vis[i]) {
                cnt++; dfs(i , flag); cnt--;
            }
        }
        else {
            if (!vis2[i]) {
                cnt++; dfs(i , flag); cnt--;
            }
        }
    }
}

void solve () {
    ll n , a , b; cin >> n;

    for (int i = 0 ; i < n - 1; i++) {
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1 , 1);

    mx = 0 , cnt = 0;
    dfs(nd , 0);

    cout << mx << '\n';
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
