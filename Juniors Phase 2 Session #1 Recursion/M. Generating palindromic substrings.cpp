// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 1000000007;
int dx[]= {-1 , 1 , 0 , 0 , 1 , -1 , 1, -1} ,
    dy[]= {0 , 0 , 1 , -1 , 1 , -1 , -1 ,1};


string s;
multiset <string> st;

bool can (string ss) {
    string tmp = ss; reverse(all(tmp));

    return ss == tmp;
}

void rec (int l , int r ,int sz) {
    if (l >= sz) return;

    if (r < sz) {
        if (can(s.substr(l , r - l + 1))) {
            st.insert(s.substr(l , r - l + 1));
        }

        rec(l  , r + 1 , sz);
    }

    else rec(l + 1 , l + 1 , sz);
}

void solve() {
    cin >> s;

    rec(0 , 0 , s.size());

    for (auto i : st) {
        cout << i << '\n';
    }
}

int main() {
    ABo_ZeiD;

    //freopen("smallest.in" , "r", stdin);


    int t = 1;

//    cin >> t;
    while (t--)
        solve();


    return 0;
}
