// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 10005 , W = 1e5 + 5 , oo = LLONG_MIN;


void solve() {
    int n;

    while (cin >> n) {
        vector <int> arr(n) , brr , tmp1 , tmp2 , a(n , 1) , b(n , 1); input(arr);
        brr = arr; reverse(all(brr));

        for (int i = 0 ; i < n ; i++) {
            auto it = lower_bound(all(tmp1) , arr[i]);
            if (it != tmp1.end()) *it = arr[i];
            else tmp1.push_back(arr[i]);


            auto it2 = lower_bound(all(tmp2) , brr[i]);
            if (it2 != tmp2.end()) *it2 = brr[i];
            else tmp2.push_back(brr[i]);


            a[i] = tmp1.size(); b[i] = tmp2.size();
        }
        reverse(all(b));

        ll mx = 0;
        for (int i = 0 ; i < n ; i++) mx = max(mx , (ll)(2 * min(a[i] , b[i]) - 1 ));

        cout << mx << '\n';
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
