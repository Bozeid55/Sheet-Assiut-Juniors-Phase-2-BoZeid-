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
vector <int> arr , brr , tmp;
vector <vector <int>> ans;

void rec(int i , int j) {
    if (!(i < n && (tmp.empty() || arr[i] > tmp.back()))  &&
        !(j < m && (tmp.empty() || brr[j] > tmp.back()))) {

        if (!tmp.empty()) ans.push_back(tmp);

        return;
    }


    if (i < n && (tmp.empty() || arr[i] > tmp.back())) {
        tmp.push_back(arr[i]);
        rec(i + 1 , j);
        tmp.pop_back();
    }


    if (j < m && (tmp.empty() || brr[j] > tmp.back())) {
        tmp.push_back(brr[j]);
        rec(i , j + 1);
        tmp.pop_back();
    }

}


void solve() {
    cin >> n; arr.resize(n); input(arr);
    cin >> m; brr.resize(m); input(brr);

    rec(0 , 0);

    sort(all(ans));
    for (auto i : ans) {
        for (auto x : i) {
            cout << x << " ";
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
