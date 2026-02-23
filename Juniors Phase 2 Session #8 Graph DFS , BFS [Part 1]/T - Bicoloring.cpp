// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 205 , w = 1e6 + 5 , oo = 1e9;

int dx[] = {0 , 0  , 1 , -1} ,
    dy[] = {1 , -1 , 0 , 0};


int n , m , x , y;
vector <int> adj[N];
vector <int> col;
bool vis[N] , flag = 1;

void dfs (int node) {
    vis[node] = 1;
    
    for (auto i : adj[node]) {
        if (!vis[i]) {
            col[i] = 3 - col[node];
            dfs(i);
        }
        
        else if (col[i] == col[node]) {
            flag = false; return;
        }
    }
    
}


void solve () {

    while (cin >> n) { 
        if (n == 0) return;
        
        col.resize(n);
        cin >> m;
        int a , b;
        
        while (m--) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }


        dfs(0);
        
        cout << (flag ? "BICOLORABLE." : "NOT BICOLORABLE.") << '\n';
        
        for (int i = 0 ; i < n ; i++) {
            adj[i].clear(); vis[i] = 0; col[i] = 0;
        }
        
        flag = 1;
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
