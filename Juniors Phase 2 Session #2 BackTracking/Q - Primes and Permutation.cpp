// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N =  1e4 + 1;

int n;
vector <int> tmp; vector <bool> vis;
set <vector<int>> ans;
set <int> prm;


void rec() {
    if (tmp.size() >= n) {
        if (prm.count(tmp.front() + tmp.back())) ans.insert(tmp);
        return;
    }

    for (int idx = 2 ; idx <= n ; idx++) {
        if (!vis[idx] && prm.count(idx + tmp.back())) {
            tmp.push_back(idx); vis[idx] = 1;
            rec();
            tmp.pop_back(); vis[idx] = 0;
        }
    }

}


void solve() {
    cin >> n; vis.resize(n + 1);

    tmp.push_back(1); vis[1] = 1;
    rec();

    for (auto i : ans) {
        for (auto x : i) {
            cout << x << " ";
        }
        cout << '\n';
    }

}

int main() {
    ABo_ZeiD; // i'm backkkkkkk

    for (int i = 2 ; i <= 200 ; i++) {
        bool cc = 1;
        for(ll j = 2 ; j*j <= i ; j++){
            if((i != j) && (i % j == 0)) {
                cc = 0; break;
            }
        }
        if (cc) prm.insert(i);
    }



    //freopen("smallest.in" , "r", stdin);


    int t = 1;

//    cin >> t;
    while (t--)
        solve();


    return 0;
}
