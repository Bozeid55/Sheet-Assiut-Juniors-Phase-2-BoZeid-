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

vector <vector <char>> cur;
set <vector <vector <char>>> ans;

vector <bool> visC , visDr , visDl;

void rec (int idx) {
    if (idx >= n) {
        ans.insert(cur);
        return;
    }

    for (int i = 0 ; i < n ; i++) {

        if (!visC[i] && !visDr[i + idx] && !visDl[n + i - idx]) {
            cur[i][idx] = 'Q';

            visC[i] = visDr[i + idx] = visDl[n + i - idx] = 1;
            rec(idx + 1);
            visC[i] = visDr[i + idx] = visDl[n + i - idx] = 0;
            cur[i][idx] = '.';
        }
    }

}

void solve() {
    cin >> n;

    visC.resize(n); visDr.resize(2 * n + 1); visDl.resize(2 * n + 1);

    cur.resize(n);
    for (int i = 0 ; i < n ; i++) {
        cur[i].resize(n);

        for (int j = 0 ; j < n ; j++) {
            cur[i][j] = '.';
        }
    }

    rec(0);

    int sz = ans.size() , cnt = 0;
    for (auto i : ans) {

        for (auto x : i) {
            for (auto y : x) {
                cout << y;
            }
            cout << '\n';
        }
        cnt++;
        if (cnt < sz) cout << '\n';
    }


}

int main() {
    ABo_ZeiD; // i'm backkkkkkk

    //freopen("smallest.in" , "r", stdin);


    int t = 1;

//    cin >> t;
    while (t--)
        solve();


    return 0;
}
