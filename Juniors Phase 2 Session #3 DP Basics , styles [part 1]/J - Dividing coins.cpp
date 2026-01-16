// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N =  50005;

int n;
vector <int>arr;
ll dp[105][N];
ll cnt = 0;

ll rec (int idx , ll a) {
    if (idx >= n) return abs(a - (cnt - a));

    ll &ret = dp[idx][a];
    if (~ret) return ret;



    return ret = min(rec(idx + 1 , a) , rec(idx + 1 , a + arr[idx]));
}

void solve() {
    memset(dp , -1 , sizeof(dp));

    cin >> n; arr.resize(n);

    for (auto &i : arr) {
        cin >> i; cnt += i;
    }


    cout << rec(0 , 0) << '\n';
    arr.clear(); cnt = 0;
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
