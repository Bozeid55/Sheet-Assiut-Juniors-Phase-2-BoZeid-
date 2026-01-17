// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 5005 , oo = LLONG_MIN;

string s;
ll dp[N][N];

ll rec(int l , int r) {
    if (l >= r) return (l == r ? 1 : 0);

    ll &ret = dp[l][r];
    if (~ret) return ret;

    ret = 0;
    if (s[l] == s[r]) ret = rec(l + 1 , r - 1) + 1;

    return ret += (rec(l + 1 , r) + rec(l , r - 1) - rec(l + 1 , r - 1));
}

void solve() {
    memset(dp , -1 , sizeof(dp));
    cin >> s;

    int n = s.length();

    cout << rec(0 , n - 1) << '\n';
}

int main() {
    ABo_ZeiD; // i'm backkkkkkk

    //freopen("smallest.in" , "r", stdin);


    int t = 1;

    cin >> t;
    while (t--)
        solve();


    return 0;
}
