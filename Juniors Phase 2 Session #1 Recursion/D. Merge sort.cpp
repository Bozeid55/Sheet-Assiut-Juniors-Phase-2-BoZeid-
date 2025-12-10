// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 1000000007;


vector <ll> arr;

void Merge (int l , int mid , int r) {
    vector <ll> a , b;

    for (int i = l ; i <= mid ; i++) a.push_back(arr[i]);
    for (int i = mid + 1 ; i <= r; i++) b.push_back(arr[i]);


    vector <ll> tmp;

    int i = 0 , j = 0;
    while ((i < a.size()) && (j < b.size())) {
        if (a[i] <= b[j]) {
            tmp.push_back(a[i]); i++;
        }
        else if (b[j] <= a[i]) {
            tmp.push_back(b[j]); j++;
        }
    }

    for (int aa = i ; aa < a.size() ; aa++) tmp.push_back(a[aa]);
    for (int bb = j ; bb < b.size() ; bb++) tmp.push_back(b[bb]);



    for (int x = 0 ; x < tmp.size() ; x++) {
        arr[x + l] = tmp[x];
    }

}

void rec (int l , int r) {
    if (l >= r) return;

    int mid = l + (r - l) / 2;

    rec(l , mid);
    rec(mid + 1 , r);

    Merge(l , mid , r);
}

void solve() {
    int n; cin >> n; arr.resize(n); input(arr);
    rec(0 , n - 1);

    for (auto i : arr) {
        cout << i << " ";
    }
}

int main() {
    ABo_ZeiD;

    //freopen("smallest.in" , "r", stdin);


    int t = 1;

//    cin >> t;
    while (t--)
        solve();


    return 0;
}
