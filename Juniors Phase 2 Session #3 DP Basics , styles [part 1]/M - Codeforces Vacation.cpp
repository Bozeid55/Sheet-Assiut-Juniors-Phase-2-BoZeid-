// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 1e2 + 5 , oo = -1e18;

int n;
vector <int> arr;
int dp[N][4];

int rec (int idx , int lst) {
    if (idx >= n) return 0;


    int &ret = dp[idx][lst];
    if (~ret) return ret;

    int ans = rec(idx + 1 , 3);

    if (arr[idx] == 1) {
        if (lst != 1) ans = max(ans , 1 + rec(idx + 1 , 1));
    }

    if (arr[idx] == 2) {
        if (lst != 2) ans = max(ans , 1 + rec(idx + 1 , 2));
    }

     if (arr[idx] == 3) {
        if (lst != 1) ans = max(ans , 1 + rec(idx + 1 , 1));
        if (lst != 2) ans = max(ans , 1 + rec(idx + 1 , 2));
    }


    return ret = ans;
}

void solve() {
    cin >> n; arr.resize(n); input(arr);

    cout << n - rec(0 , 3) << '\n';
}

int main() {
    ABo_ZeiD; // i'm backkkkkkk

    memset(dp , -1 , sizeof(dp));
    //freopen("smallest.in" , "r", stdin);


    int t = 1;
//    cin >> t;

    while (t--)
        solve();


    return 0;
}
