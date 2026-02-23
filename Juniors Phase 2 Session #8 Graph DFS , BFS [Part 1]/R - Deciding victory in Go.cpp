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


vector <vector <char>> arr;
bool vis[10][10];

bool can (int i , int j) {
    return i >= 0 && i < 9 && j >= 0 && j < 9 && !vis[i][j];
}

bool a = 0 , b = 0; int cnt = 0;
void dfs (int l , int r) {
    if (arr[l][r] == 'X') {
        a = 1; return;
    }
    
    if (arr[l][r] == 'O') {
        b = 1; return;
    }

    vis[l][r] = 1; cnt++;
    
    for (int i = 0 ; i < 4 ; i++) {
        int cX = (l + dx[i]) , cY = (r + dy[i]);

        if (can(cX , cY)) {
            dfs(cX , cY);
        }
    }
}


void solve () {
        arr.resize(9);

        for (int i = 0 ; i < 9 ; i++) {
            arr[i].resize(9);
            for (int j = 0 ; j < 9 ; j++) {
                cin >> arr[i][j];
            }
        }

        int wt = 0 , bl = 0;

        for (int i = 0 ; i < 9 ; i++) {
            for (int j = 0 ; j < 9 ; j++) {
                if (arr[i][j] == 'X') wt++;
                if (arr[i][j] == 'O') bl++;
                
                if (arr[i][j] == '.' && !vis[i][j]) {
                    dfs(i , j); 
                    
                    if (a && !b) wt += cnt;
                    if (!a && b) bl += cnt;
                    
                    a = 0 , b = 0; cnt = 0;
                }
            }
        }
        

        cout << "Black " << wt << " White " << bl << '\n';


        arr.clear(); a = 0 , b = 0; cnt = 0;
        memset(vis , 0 , sizeof(vis));
}

int main() {
    ABo_ZeiD; // i'm backkkkkk;

//    memset(dp , -1 , sizeof(dp));
    //freopen("smallest.in" , "r", stdin);
//    pre();

    int t = 1;
    cin >> t;
    for (int i = 1 ; i <= t ; i++) {
//        cout << "Case " << i << ": ";
        solve();
//        if (i != t) {
//            cout << '\n';
//        }
    }


    return 0;
}
