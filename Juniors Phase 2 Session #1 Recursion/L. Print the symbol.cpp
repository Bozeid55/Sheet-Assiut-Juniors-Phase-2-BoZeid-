// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 1000000007;
int dx[]= {-1 , 1 , 0 , 0 , 1 , -1 , 1, -1} ,
    dy[]= {0 , 0 , 1 , -1 , 1 , -1 , -1 ,1};


ll n , k;
int rec (ll a , ll idx) {
    if (a == 1) return 0;

    if (idx <= ((1ll << (a - 1)) / 2)) return rec(a - 1 , idx);

    return rec(a - 1 , idx - (1ll << (a - 1)) / 2) ^ 1;
}

void solve() {
    cin >> n >> k;

    cout << rec(n , k) << '\n';
}

int main() {
    ABo_ZeiD;

    //freopen("smallest.in" , "r", stdin);


    int t = 1;

    cin >> t;
    while (t--)
        solve();


    return 0;
}
