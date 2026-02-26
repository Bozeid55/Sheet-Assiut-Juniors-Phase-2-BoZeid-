// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 1005 , w = 1e6 + 5 , oo = 1e9;

int dx[] = {0 , 0  , 1 , -1} ,
    dy[] = {1 , -1 , 0 , 0};


int ca , cb , n;
vector <string> inst = {"fill A" , "fill B" , "empty A" , "empty B" , "pour A B" , "pour B A"};
bool vis[N][N];
bool flag = false;

void bfs (int l , int r) {
    queue <pair <pair <int , int> , vector <int>>> q;

    q.push({{l , r} , {}}); vis[l][r] = 1;

    while (!q.empty()) {
        auto [hs , bs] = q.front(); q.pop();

        int a = hs.first , b = hs.second;
        vector <int> cur = bs;

        if (b == n) {
            for (auto i : cur) {
                cout << inst[i] << '\n';
            }
            cout << "success" << '\n';

            return;
        }
        /*-------------------*/
        if ((a < ca) && !vis[ca][b]) {
            vis[ca][b] = 1;

            vector <int> tm = bs;

            tm.push_back(0);
            q.push({{ca , b} , tm});
        }

        if ((b < cb) && (!vis[a][cb])) {
            vis[a][cb] = 1;
            
            vector <int> tm = bs;
            
            tm.push_back(1);
            q.push({{a , cb}, tm});
        }
        /*-------------------*/
        if ((a > 0) && !vis[0][b]) {
            vis[0][b] = 1;

            vector <int> tm = bs;

            tm.push_back(2);
            q.push({{0 , b} , tm});
        }

        if ((b > 0) && (!vis[a][0])) {
            vis[a][0] = 1;
            
            vector <int> tm = bs;
            
            tm.push_back(3);
            q.push({{a , 0}, tm});
        }
        /*-------------------*/
        int x = min(a , cb - b),
            y = min(b , ca - a);

        if (x > 0 && !vis[a - x][b + x]) {
            vis[a - x][b + x] = 1;
            
            vector <int> tm = bs;

            tm.push_back(4);
            q.push({{a - x , b + x} , tm});
        }

        if (y > 0 && !vis[a + y][b - y]) {
            vis[a + y][b - y] = 1;

            vector <int> tm = bs;

            tm.push_back(5);
            q.push({{a + y , b - y} , tm});
        }
        /*-------------------*/
    }

}

void solve () {

    while (cin >> ca >> cb >> n) {
        bfs(0 , 0);

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
