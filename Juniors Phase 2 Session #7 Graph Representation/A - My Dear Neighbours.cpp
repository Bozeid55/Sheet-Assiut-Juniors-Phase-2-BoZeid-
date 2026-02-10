// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 1e4 + 5, W = 1e5 + 5 , oo = 1e9 + 5;

int p; vector <int> adj[N];

void solve() {
    cin >> p; cin.ignore();

    for (int i = 1 ; i <= p ; i++) {
        string s; getline(cin , s);

        stringstream gt(s);
        int x;

        while (gt >> x) {
            adj[i].push_back(x);
        }
    }

    int mn = oo;
    for (int i = 1 ; i <= p ; i++) {
        int sz = adj[i].size();

        if (sz >= 1) mn = min(mn , sz);
    }

    vector <int> ans;

    for (int i = 1 ; i <= p ; i++) {
        if (adj[i].size() == mn) ans.push_back(i);
    }

    cout << ans[0];

    for (int i = 1 ; i < ans.size() ; i++) {
        cout << " " << ans[i];
    }


    cout << '\n';
    string x; getline(cin , x);

    for (auto &i : adj) {
        i.clear();
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
    }


    return 0;
}
