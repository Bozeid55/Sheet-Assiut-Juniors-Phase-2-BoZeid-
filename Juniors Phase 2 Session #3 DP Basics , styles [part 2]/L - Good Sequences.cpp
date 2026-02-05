// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 1e5 + 3 , W = 1e5 + 5 , oo = 1e9 + 5;

vector <vector <int>> divs;

void pre() {
    for (int i = 2 ; i < N ; i++) {
        if (!divs[i].empty()) continue;
        for (int j = i ; j < N ; j += i) divs[j].push_back(i);
    }
}

void solve() {
    int n , x , mx; cin >> n;

    vector <int> dp(N , 1);
    while (n--) {
        cin >> x; mx = 1;

        for (int i : divs[x]) mx = max(mx , dp[i] + 1);
        for (int i : divs[x]) dp[i] = mx;
    }

    mx = *max_element(all(dp)) - 1;

    cout << (mx >= 1 ? mx : 1) << '\n';
}

int main() {
    ABo_ZeiD; // i'm backkkkkk;
    divs.resize(N);
    pre();

//    memset(dp , -1 , sizeof(dp));
    //freopen("smallest.in" , "r", stdin);


    int t = 1;
//    cin >> t;
    for (int i = 1 ; i <= t ; i++) {
//        cout << "Case " << i << ": ";
        solve();
    }


    return 0;
}
