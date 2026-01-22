// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 10005 , oo = INT_MIN;

ll rtt = 0;

void solve() {
//    memset(dp , -1 , sizeof(dp));
    ll n; cin >> n;
    vector <ll> arr(n - 1); input(arr);


    int i = 0 , j , l = 0 , r = 0;
    ll mx = 0;

    while (i < n - 1) {
        if (arr[i] < 0) {
            i++; continue;
        }

        ll cur = 0; j = i;

        while (j < n - 1 && arr[j] + cur >= 0) {
            cur += arr[j];

            if (cur > mx) {
                mx = cur , l = i + 1 , r = j + 1;
            }

            else if (cur == mx && (j - i > r - l)) {
                l = i + 1 , r = j + 1;
            }

            ++j;
        }

        i = j;
    }

    if (!mx) {
        cout << "Route " << rtt << " has no nice parts" << '\n';
        return;
    }

    cout << "The nicest part of route " << rtt << " is between stops " << l << " and " << r + 1 << '\n';
}

int main() {
    ABo_ZeiD; // i'm backkkkkkk

    //freopen("smallest.in" , "r", stdin);


    int t = 1;
    cin >> t;
    for (int i = 1 ; i <= t ; i++) {
        rtt = i;
        solve();
    }


    return 0;
}
