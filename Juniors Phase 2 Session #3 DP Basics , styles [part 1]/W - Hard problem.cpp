// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 100005 , W = 1e5 + 5 , oo = 1e18;

int n;
vector <ll> arr;
vector <string> a , b;

ll dp[N][2];

ll rec (int idx , bool cur) {
    if (idx >= n) return 0;

    ll &ret = dp[idx][cur];
    if (~ret) return ret;

    ret = oo; //damn

    if (cur) {
        if (a[idx] >= b[idx - 1]) {
            ret = min(ret ,rec(idx + 1 , 0));
        }

        if (b[idx] >= b[idx - 1]) {
            ret = min(ret , rec(idx + 1 , 1) + arr[idx]);
        }
    }

    else {
        if (a[idx] >= a[idx - 1]) {
            ret = min(ret ,rec(idx + 1 , 0));
        }

        if (b[idx] >= a[idx - 1]) {
            ret = min(ret , rec(idx + 1 , 1) + arr[idx]);
        }
    }

    return ret;
}


void solve() {
    cin >> n; arr.resize(n);
    a.resize(n); b.resize(n);
    input(arr); input(a);

    for (int i = 0 ; i < n ; i++) {
        b[i] = a[i];
        reverse(all(b[i]));
    }


    ll mn = min(rec(1 , 0) , rec(1 , 1) + arr[0]);

    cout << (mn < oo ? mn : -1) << '\n'; //ايييه الغباء اللي بعمله ده
}

int main() {
    ABo_ZeiD; // i'm backkkkkkk
    memset(dp , -1 , sizeof(dp));

    //freopen("smallest.in" , "r", stdin);


    int t = 1;
    //cin >> t;
    while (t--)
        solve();


    return 0;
}
