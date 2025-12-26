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

string s , p;
vector <string> mp(27);
bool can = false;

bool rec(int i , int j) {
    if (i >= s.length() && j >= p.length()) return 1;
    if (i >= s.length() || j >= p.length()) return 0;

    if (mp[p[j] - 'A'] != "") {
        if (s.substr(i , mp[p[j] - 'A'].length()) != mp[p[j] - 'A']) return 0;

        return rec(i + mp[p[j] - 'A'].length() , j + 1);
    }

    for (int idx = i ; idx < s.length() ; idx++) {
        mp[p[j] - 'A'] = s.substr(i, idx - i + 1);

        can = (rec(idx + 1, j + 1) == 1 ? 1 : can);

        mp[p[j] - 'A'] = "";
    }

    return can;
}


void solve() {
    cin >> s >> p;
    for (auto &i : mp) i = "";

    cout << (rec(0 , 0) ? "YES" : "NO") << '\n';

    can = 0;
}

int main() {
    ABo_ZeiD; // i'm backkkkkkk
    //freopen("smallest.in" , "r", stdin);


    int t = 1;

    cin >> t;
    while (t--)
        solve();


    return 0;
}
