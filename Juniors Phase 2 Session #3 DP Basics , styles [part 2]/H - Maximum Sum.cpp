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
const ll N = 1000005, W = 1e4 + 5, oo = -1e18;


void solve() {
    int n; cin >> n;
    vector <vector <int>> arr(n + 1 , vector <int>(n + 1));

    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            cin >> arr[i][j];
        }
    }

    /*-------------------------------------*/
    for (int i = 1; i <= n ; i++) {
          for (int j = 1; j <= n ; j++){
            arr[i][j] += arr[i][j-1];
          }
    }

    for (int j = 1; j <= n ; j++){
          for (int i = 1; i <= n ; i++){
              arr[i][j] += arr[i-1][j];
          }
    }
    /*-------------------------------------*/
    auto get = [&](int a , int b , int x , int y) -> int {
        return arr[x][y] - arr[x][b - 1] - arr[a - 1][y] + arr[a - 1][b - 1];
    };
    /*-------------------------------------*/

    int mx = oo;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            for (int a = i ; a <= n ; a++) {
                for (int b = j ; b <= n ; b++) {
                    mx = max(mx , get(i , j , a , b));
                }
            }
        }
    }

    cout << mx << '\n';
}

int32_t main() {
    ABo_ZeiD; // i'm backkkkkkk
//    memset(dp , -1 , sizeof(dp));


    //freopen("input.txt" , "r", stdin);
    //freopen("output.txt" , "w", stdout);


    int t = 1;
//    cin >> t;
    while (t--)
        solve();


    return 0;
}
