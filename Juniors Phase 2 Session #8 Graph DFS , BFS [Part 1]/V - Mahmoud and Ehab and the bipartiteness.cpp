// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 1e5 + 5 , w = 1e6 + 5 , oo = 1e9;

int dx[] = {0 , 0  , 1 , -1} ,
    dy[] = {1 , -1 , 0 , 0};


vector <int> adj[N]; bool vis[N];
ll a = 0 , b = 0;

void dfs (int node , bool cur) {
    vis[node] = 1;
    a += (cur == 1);
    b += (cur == 0);

    for (auto i : adj[node]) {
        if (!vis[i]) dfs(i , (cur ^ 1));
    }
}

void solve () {
    int n , x , y; cin >> n;
    for (int i = 1 ; i < n ; i++) {
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x); 
    }

    dfs(1 , 1);

//    cout << a << " " << b << '\n';

    cout << (a * b * 1ll) - (n - 1) << '\n';
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
