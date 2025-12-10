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


ll mul(ll a , ll b) {
    return ((a%N)*(b%N))%N;
}

ll rec (ll a  , ll b) {
    if (b == 0) return 1;

    if (b % 2 == 0) {
        return rec(mul(a , a) , b / 2);
    }

    else return(mul(a , rec(a , b - 1)));
}

void solve() {
    ll a , b; cin >> a >> b;

    cout << rec(a , b) << '\n';
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
