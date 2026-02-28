// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 1e5 + 5 , w = 1e6 + 5 , oo = 1e9;

int dx[] = {0 , 0  , 1 , -1} ,
    dy[] = {1 , -1 , 0 , 0};


queue <string> q;
string ans = ""; bool flag = 1;

void bfs () {
    if (q.empty()) {
        flag = 0; return;
    }

    string cur = q.front(); q.pop();
    if (cur == "pair") {
        ans += (cur);
        ans += ('<');

        bfs();
        ans += (',');
        bfs();

        ans += ('>');
    }

    else {
        ans += (cur);
    }

}

void solve () {
    int n; cin >> n;

    string s;
    while (cin >> s) q.push(s);

    bfs();

    //cout << flag << '\n';

    cout << ((q.empty() && flag) ? ans : "Error occurred") << '\n';
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
