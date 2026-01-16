// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N =  1e2 + 5;

ll add(ll a,ll b,ll m) {
    return ((a%m)+(b%m))%m;
}

ll sub(ll a,ll b,ll m) {
    return ((a%m)-(b%m)+m)%m;
}

string a , b;

int dp[N][N];

int rec (int i , int j) {
    if (i >= a.length() || j >= b.length()) return 0;


    int &ret = dp[i][j];
    if (~ret) return ret;


    if (a[i] == b[j]) {
        return 1 + rec(i + 1 , j + 1);
    }


    return ret = max(rec(i + 1 , j) , rec(i , j + 1));
}

void solve() {
    int cnt = 1;

    while (true) {
        memset(dp , -1 , sizeof(dp));

        getline(cin, a); if (a == "#") return;
        getline(cin, b);


        cout << "Case #" << cnt++ << ": you can visit at most " << rec(0 , 0) << " cities." << '\n';
    }
}

int main() {
    ABo_ZeiD; // i'm backkkkkkk

    //freopen("smallest.in" , "r", stdin);


    int t = 1;

    //cin >> t;
    while (t--)
        solve();


    return 0;
}
