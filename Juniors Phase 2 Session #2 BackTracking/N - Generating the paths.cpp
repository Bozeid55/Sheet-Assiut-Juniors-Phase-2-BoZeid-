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

int n , m;
vector <vector <int>> arr;
vector <int> tmp;
set <vector <int>> ans;


void rec (int i , int j) {
    if (i == n - 1 && j == m - 1) {
        tmp.push_back(arr[i][j]);
        ans.insert(tmp);
        tmp.pop_back();

        return;
    }


    if (j + 1 < m) {
        tmp.push_back(arr[i][j]);
        rec(i , j + 1);
        tmp.pop_back();
    }

    if (i + 1 < n) {
        tmp.push_back(arr[i][j]);
        rec(i + 1 , j);
        tmp.pop_back();
    }


}

void solve() {
    cin >> n >> m;

    arr.resize(n);
    for (int i = 0 ; i < n ; i++) {
        arr[i].resize(m);

        for (int j = 0 ; j < m ; j++) {
            cin >> arr[i][j];
        }
    }


    rec(0 , 0);

    for (auto i : ans) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << '\n';
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
