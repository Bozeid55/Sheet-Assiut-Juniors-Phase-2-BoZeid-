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
const ll N = 30005, W = 30000, oo = -3000005 ;

int n , k , mx = 0 , add;
vector <int> frq;
int dp[N][555];

int rec (int idx , int lst) {
    if (idx > mx) return 0;

    int &ret = dp[idx][lst + 250];
    if (~ret) return ret;


    int cur = k + lst;

    ret = max({ret , rec(idx + cur , lst) + frq[idx] , rec(idx + cur + 1 , lst + 1) + frq[idx]});
    if (cur > 1) ret = max(ret , rec(idx + cur - 1 , lst - 1)+ frq[idx]);


    return ret;
}


void solve() {
    cin >> n >> k;
    frq.resize(30005);

    int x;
    for (int i = 0 ; i < n ; i++) {
        cin >> x; frq[x]++; mx = max(mx , x);
    }

    cout << rec(k , 0);
}

int32_t main() {
    ABo_ZeiD; // i'm backkkkkkk
    memset(dp , -1 , sizeof(dp));
//    memset(frq , 0 , sizeof(frq));

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
