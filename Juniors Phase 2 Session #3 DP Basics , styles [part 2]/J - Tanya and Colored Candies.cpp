// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define inputz(vec , x) for (int i = 0 ; i < x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 1e5 + 5, W = 1e4 + 5, oo = 1e9 + 7;


int n , cur , k;
string s;
vector <int> arr;
int dp[55][5005];

int rec (int idx , int cnt) {
    if (cnt >= k) return 0;
    if (idx >= n) {
        return (cnt >= k ? 0 : oo);
    }

    int &ret = dp[idx][cnt];
    if (~ret) return ret;


    ret = oo;
    for (int i = 0 ; i < n ; i++) {
        if (arr[i] > arr[idx] && s[i] != s[idx]) {
            ret = min(ret , rec(i , cnt + arr[i]) + abs(idx - i));
        }
    }

    return ret;
}

void solve() {
    cin >> n >> cur >> k;
    arr.resize(n); input(arr);
    cin >> s;


    int mn = oo;
    for (int i = 0 ; i < n ; i++) {
        mn = min(mn , rec(i , arr[i]) + abs(cur - i - 1));
    }


    cout << (mn >= oo ? -1 : mn) << '\n';
}

int32_t main() {
    ABo_ZeiD; // i'm backkkkkkk
    memset(dp , -1 , sizeof(dp));

    //freopen("input.txt" , "r", stdin);
    //freopen("output.txt" , "w", stdout);


    int t = 1;
//    cin >> t;
    for (int i = 1 ; i <= t ; i++) {
//        cout << "Case " << i << ": ";
        solve();
    }


    return 0;
}
