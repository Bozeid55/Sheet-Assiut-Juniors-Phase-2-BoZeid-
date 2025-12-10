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


int n , cnt = 0;
vector <vector <ll>> arr;
vector <vector <bool>> vis;
vector <ll> ans;

vector <char> dic = {'R' , 'L' , 'D' , 'U'};

bool can (int i , int j) {
    return i >= 0 && i < n && j >=0 && j < n && !vis[i][j];
}


void rec (int a , int b , int cur) {
    if (a < 0 || a >= n || b < 0 || b >= n || vis[a][b]) return;

    vis[a][b] = 1;
    ans.push_back(arr[a][b]);


    if (dic[cnt % 4] == 'R') {
        if (can(a , b + 1) && !cur) {
            rec(a , b + 1 , cur + 1);
        }
        else {
            if (b == n - 1) {
                //L
                if (can(a + 1 , b - 1)) {
                    cnt++; rec(a + 1 , b - 1 , cur);
                }

                //D
                else if (can(a + 1 , b)) {
                    cnt += 2; rec(a + 1 , b , cur);
                }

                //U
                else if (can(a - 1 , b + 1)) {
                    cnt += 3; rec(a - 1 , b + 1 , cur);
                }
            }
            else {
                cnt++; rec(a + 1 , b - 1 , cur);
            }
        }
    }


    if (dic[cnt % 4] == 'L') {
        if (can(a + 1 , b - 1)) {
            rec(a + 1 , b - 1 , cur);
        }


        else {
            if (b == n - 1) {
                //D
                if (can(a + 1 , b)) {
                    cnt++; rec(a + 1 , b , cur);
                }

                //U
                else if (can(a - 1  , b + 1)) {
                    cnt += 2; rec(a - 1 , b + 1 , cur);
                }

                //R
                else if (can(a  , b + 1)) {
                    cnt += 3; rec(a , b + 1 , cur);
                }
            }

            else {
                cnt++; rec(a + 1 , b , cur);
            }
        }
    }

    if (dic[cnt % 4] == 'D') {
        if (can(a + 1 , b) && !cur) {
            rec(a + 1 , b , cur + 1);
        }


        else {
            if (b == n - 1) {
                //U
                if (can(a - 1 , b + 1)) {
                    cnt++; rec(a - 1 , b + 1 , cur);
                }

                //R
                else if (can(a  , b + 1)) {
                    cnt += 2; rec(a , b + 1 , cur);
                }

                //L
                else if (can(a + 1  , b - 1)) {
                    cnt += 3; rec(a + 1 , b - 1 , cur);
                }
            }

            else {
                cnt++; rec(a - 1 , b + 1 , cur);
            }
        }
    }

    if (dic[cnt % 4] == 'U') {
        if (can(a - 1 , b + 1)) {
            rec(a - 1 , b + 1 , cur);
        }


        else {
            if (b == n - 1) {
                //R
                if (can(a , b + 1)) {
                    cnt++; rec(a  , b + 1 , cur);
                }

                //L
                else if (can(a + 1, b - 1)) {
                    cnt += 2; rec(a + 1 , b - 1 , cur);
                }

                //D
                else if (can(a + 1  , b)) {
                    cnt += 3; rec(a + 1 , b , cur);
                }
            }

            cnt++; rec(a , b + 1 , cur);
        }
    }

}

void solve() {
    cin >> n;
    arr.resize(n);
    for (int i = 0 ; i < n ; i++) {
        arr[i].resize(n);
        for (int j = 0 ; j < n ; j++) {
            cin >> arr[i][j];
        }
    }

    vis.resize(n);
    for (int i = 0 ; i < n ; i++) {
        vis[i].resize(n);
        for (int j = 0 ; j < n ; j++) {
            vis[i][j] = 0;
        }
    }


    rec(0 , 0 , 0);

    int cnt = 0;

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cout << ans[cnt] << " "; cnt++;
        }
        cout << '\n';
    }

    ans.clear();

    //cout << '\n';
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
