// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 30 , W = 1e5 + 5 , oo = 1e9 - 1;

vector <vector <char>> arr(4 , vector <char>(4)) , 
                       tmp(4 , vector <char>(4));

bool can (vector <vector <char>> a, char cur) {

    return (
            (a[0][0] == cur && a[0][1] == cur && a[0][2] == cur) ||
            (a[1][0] == cur && a[1][1] == cur && a[1][2] == cur) ||
            (a[2][0] == cur && a[2][1] == cur && a[2][2] == cur) ||

            (a[0][0] == cur && a[1][0] == cur && a[2][0] == cur) ||
            (a[0][1] == cur && a[1][1] == cur && a[2][1] == cur) ||
            (a[0][2] == cur && a[1][2] == cur && a[2][2] == cur) ||

            (a[0][0] == cur && a[1][1] == cur && a[2][2] == cur) ||
            (a[0][2] == cur && a[1][1] == cur && a[2][0] == cur)

           );
}

bool bfs () {
    queue <pair<vector <vector<char>> , bool>> q;
    q.push({tmp , true});
    
    bool flag = false;
    
    while (!q.empty()) {
        auto [a , b] = q.front(); q.pop();
        
        if (a == arr) {
            return true;
        }
        
        if (can(a , 'X') || can(a , 'O')) continue;
        
        for (int i = 0 ; i < 3 ; i++) {
            for (int j = 0 ; j < 3 ; j++) {
                if (a[i][j] == '.') {
                    a[i][j] = (b ? 'X' : 'O');
                    
                    if (a[i][j] == arr[i][j]) {
                        q.push({a , b ^ 1});
                    }
                    
                    a[i][j] = '.';
                }
            }
        }
    
    }
    
    
    return false;
}

void solve() {

    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            cin >> arr[i][j]; 
            tmp[i][j] = '.';
        }
    }
    
    cout << (bfs() ? "yes" : "no") << '\n';
    
}

int main() {
    ABo_ZeiD; // i'm backkkkkk;


//    memset(dp , -1 , sizeof(dp));
    //freopen("smallest.in" , "r", stdin);


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
