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

int n;
vector <vector <char>> arr;
vector <vector <char>> tmp;
vector <vector <vector <char>>> ans;
bool flag = false;

bool valid () {
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            if ((arr[i][j]!= '.') && (tmp[i][j] != arr[i][j])) {
                return false;
            }
        }
    }

    for (int i = 1 ; i <= n ; i++) {
        int a = 0 , cur = 0 , b = 0;

        for (int j = 1 ; j <= n ; j++) {
            if ((tmp[i][j] - '0') > cur) {
                cur = (tmp[i][j] - '0'); a++;
            }
        }
        if ((arr[i][0] != '.') && (a != arr[i][0] - '0')) return false;

        a = 0 , cur = 0;
        for (int j = n ; j >= 1 ; j--) {
            if ((tmp[i][j] - '0') > cur) {
                cur = (tmp[i][j] - '0'); a++;
            }
        }

        if ((arr[i][n + 1] != '.') && (a != arr[i][n + 1] - '0')) return false;
        /*=====================================================*/
        /*=====================================================*/
        cur = 0;

        for (int j = 1 ; j <= n ; j++) {
            if ((tmp[j][i] - '0') > cur) {
                cur = (tmp[j][i] - '0'); b++;
            }
        }
        if ((arr[0][i] != '.') && (b != arr[0][i] - '0')) return false;

        b = 0 , cur = 0;
        for (int j = n ; j >= 1 ; j--) {
            if ((tmp[j][i] - '0') > cur) {
                cur = (tmp[j][i] - '0'); b++;
            }
        }

        if ((arr[n + 1][i] != '.') && (b != arr[n + 1][i] - '0')) return false;
    }


    return true;
}

bool can (int i , int j , int cur) {
    for (int idx = 1 ; idx <= n ; idx++) {
        if (((tmp[i][idx] - '0') == cur) || ((tmp[idx][j] - '0') == cur)) return false;
    }
    
    return true;
}

void rec (int i , int j) {
    if (flag) return;

    if (i > n) {
        if (valid()) {
            flag = true; ans.push_back(tmp);
        }
        return;
    }

    if (j > n) {
        rec(i + 1 , 1); return;
    }


    for (int idx = 1 ; idx <= n ; idx++) {
        if (can(i , j , idx)) {
            tmp[i][j] = char(idx + '0');
            rec(i , j + 1);
            tmp[i][j] = '.';
        }
    }
}


void solve() {
    cin >> n; arr.resize(n + 2);

    for (int i = 0 ; i < n + 2 ; i++) {
        arr[i].resize(n + 2);
        for (int j = 0 ; j < n + 2 ; j++) {
            cin >> arr[i][j];
        }
    }

    tmp.resize(n + 2);
    for (int i = 0 ; i < n + 2 ; i++) {
        tmp[i].resize(n + 2);
        for (int j = 0 ; j < n + 2 ; j++) {
            tmp[i][j] = '.';
        }
    }


    rec(1 , 1);

    if (!flag) {
        cout << "no" << '\n';
        cout << '\n';
        return;
    }

    for (int k = 0 ; k < 1 ; k++) {
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= n ; j++) {
                cout << ans[k][i][j];
            }
            cout << '\n';
        }
    }

    cout << '\n';

    flag = false; ans.clear();
}

int main() {
    ABo_ZeiD; // i'm backkkkkkk

    //freopen("smallest.in" , "r", stdin);


    int t = 1;

    cin >> t;
    while (t--)
        solve();


    return 0;
}
