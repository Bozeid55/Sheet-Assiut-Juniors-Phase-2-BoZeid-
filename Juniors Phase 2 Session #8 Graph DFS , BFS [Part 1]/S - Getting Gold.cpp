// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 5005 , w = 1e6 + 5 , oo = 1e9;

int dx[] = {0 , 0  , 1 , -1} ,
    dy[] = {1 , -1 , 0 , 0};


int n , m , x , y;
vector <vector <char>> arr;
bool vis[55][55];
int cnt = 0 , mx = 0; char lnd;

bool in (int i , int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

bool can (int i , int j) {
    return in(i , j) && arr[i][j] != '#' && arr[i][j] != 'T' && !vis[i][j];
}

void dfs (int l , int r) {
    vis[l][r] = 1; if (arr[l][r] == 'G') cnt++;

    for (int i = 0 ; i < 4 ; i++) {
        int cX = (l + dx[i]) , cY = (r + dy[i]);
        if (in(cX , cY) && arr[cX][cY] == 'T') {
            return;
        }
    }


    for (int i = 0 ; i < 4 ; i++) {
        int cX = (l + dx[i]) , cY = (r + dy[i]);

        if (can(cX , cY)) {
            dfs(cX , cY);
        }
    }
}


void solve () {

    while (cin >> m >> n) { // daaamnnnn
        arr.resize(n);

        int st = 0 ,  ed = 0;
        for (int i = 0 ; i < n ; i++) {
            arr[i].resize(m);
            for (int j = 0 ; j < m ; j++) {
                cin >> arr[i][j];

                if (arr[i][j] == 'P') {
                    st = i , ed = j;
                }
            }
        }


        dfs(st , ed);

        cout << cnt << '\n'; //ems7 el3ar XDD

        arr.clear(); cnt = 0;
        memset(vis , 0 , sizeof(vis));
    }

}

int main() {
    ABo_ZeiD; // i'm backkkkkk;

//    memset(dp , -1 , sizeof(dp));
    //freopen("smallest.in" , "r", stdin);
//    pre();

    int t = 1;
//    cin >> t;
    for (int i = 1 ; i <= t ; i++) {
//        cout << "Case " << i << ": ";
        solve();
//        if (i != t) {
//            cout << '\n';
//        }
    }


    return 0;
}
