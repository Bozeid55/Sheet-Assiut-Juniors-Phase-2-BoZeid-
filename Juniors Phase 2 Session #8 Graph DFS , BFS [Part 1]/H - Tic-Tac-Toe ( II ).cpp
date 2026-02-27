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
    string s; 
    
    while (cin >> s) {
        if (s == "end") return;
        
        int k =0 , j = 0 , cnt = 0;
        
        for (int i = 0 ; i < 9 ; i++ , j++) {    
            cnt += (s[i] == '.');
            
            if (i && (i % 3 == 0)) {
                ++k; j = 0;
                arr[k][j] = s[i];
                tmp[k][j] = '.';
                
                continue;
            }
            
            arr[k][j] = s[i];
            tmp[k][j] = '.';
        }
        
        bool check = (can(arr , 'X') || can(arr , 'O') || !cnt);
        
        if (!check) {
            cout << "invalid" << '\n';
            continue;
        }
        
        cout << (bfs() ? "valid" : "invalid") << '\n';
    }

}

int main() {
    ABo_ZeiD; // i'm backkkkkk;


//    memset(dp , -1 , sizeof(dp));
    //freopen("smallest.in" , "r", stdin);


    int t = 1;
    //cin >> t;
    for (int i = 1 ; i <= t ; i++) {
//        cout << "Case " << i << ": ";
        solve();
//        if (i != t) {
//            cout << '\n';
//        }
    }


    return 0;
}
