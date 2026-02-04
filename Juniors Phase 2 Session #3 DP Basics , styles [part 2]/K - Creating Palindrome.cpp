// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 1e3 + 1 , W = 1e5 + 5 , oo = 1e9 + 5;

int n , k;
vector <int> arr;

ll rec(int l , int r , int cnt) {
    if (cnt > k) return oo;
    if (l > r) return 0;


    if (arr[l] == arr[r]) return rec(l + 1 , r - 1 , cnt);

    else return min(rec(l + 1 , r , cnt + 1) , rec(l , r - 1 , cnt + 1)) + 1;
}

void solve() {
    cin >> n >> k; arr.resize(n);
    for (auto &i : arr) cin >> i;

    int ans = rec(0 , n - 1 , 0);

    if (ans >= oo) {
        cout << "Too difficult" << '\n';
        return;
    }

    if (ans <= 0) {
        cout << "Too easy" << '\n';
        return;
    }

    cout << ans << '\n';
}

int main() {
    ABo_ZeiD; // i'm backkkkkkk

//    memset(dp , -1 , sizeof(dp));
    //freopen("smallest.in" , "r", stdin);


    int t = 1; cin >> t;
    for (int i = 1 ; i <= t ; i++) {
        cout << "Case " << i << ": ";
        solve();
    }


    return 0;
}
