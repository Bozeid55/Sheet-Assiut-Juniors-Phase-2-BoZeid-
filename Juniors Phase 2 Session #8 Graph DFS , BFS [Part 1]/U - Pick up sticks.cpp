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


int n , m;
vector <int> adj[N];

void solve () {

    while (cin >> n >> m) { 
        if (n == 0 && m == 0) return;
        
        vector <int> dep(n+1 , 0) , ans;
        
        int a , b;
        while (m--) {
            cin >> a >> b;
            adj[a].push_back(b);
            dep[b]++;
        }
        
        queue <int> q;
        for (int i = 1 ; i <= n ; i++) {
            if (dep[i] == 0) q.push(i);
        }
        
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            
            ans.push_back(cur);
            
            for (auto i : adj[cur]) {
                dep[i]--;
                
                if (dep[i] == 0) {
                    q.push(i);
                }
            }
        }
        
        if (ans.size() < n) cout << "IMPOSSIBLE" << '\n';
        
        for (auto i : ans) {
            cout << i << '\n';
        }
        
        for (int i = 1 ; i <= n ; i++) {
            if (adj[i].size()) adj[i].clear();
        }
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
