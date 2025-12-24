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
vector <int> arr;
vector <vector <int>> ans;

void rec(int idx) {
    if (idx >= n) {
        ans.push_back(arr);
        return;
    }

    for (int i = idx ; i < n ; i++) {
        swap(arr[i] , arr[idx]);
        rec(idx + 1);
        swap(arr[i] , arr[idx]);
    }

}

void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; i++) arr.push_back(i);


    rec(0);
    sort(all(ans));

    for (int i = 0 ; i < ans.size() ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cout << ans[i][j] << (j < n - 1 ? " " : "");
        }

        if (i < ans.size() - 1) cout << '\n';
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
