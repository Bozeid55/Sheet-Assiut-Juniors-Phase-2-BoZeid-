#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5 + 5;
int n;
vector<int> arr; ll dp[N];

ll solve(int i) {
    if (i == n - 1) return 0;
    if (dp[i] != -1) return dp[i];

    dp[i] = INT_MAX;
    dp[i] = min(dp[i], solve(i + 1) + abs(arr[i + 1] - arr[i]));

    if (i + 2 <= n - 1) {
        dp[i] = min(dp[i], solve(i + 2) + abs(arr[i + 2] - arr[i]));
    }
    return dp[i];
}

int main() {
    cin >> n;
    arr.resize(n);
    memset(dp , -1 ,  sizeof(dp));

    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << solve(0) << endl;
    return 0;
}
