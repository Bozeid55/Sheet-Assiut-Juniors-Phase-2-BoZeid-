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


bool knowBit(ll n , int i) {
    return (n>>i)&1;
}
vector <ll> arr;

ll rec (int l , int r , int trg) {
    int mid = l + (r - l) / 2;

    if (arr[mid] == trg) return mid + 1;

    if (l > r) return -1;


    if (arr[mid] > trg) return rec(l , mid - 1 , trg);
    else return rec(mid + 1 , r , trg);
}

void solve() {
    int n ,q; cin >> n;
    arr.resize(n); input(arr);
    cin >> q;

    ll x;
    while (q--) {
        cin >> x;

        cout << rec(0 , n - 1 , x) << '\n';
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
