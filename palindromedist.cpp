#include <bits/stdc++.h>
using namespace std;

int minEditsToPalindrome(const string &s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;
            if (s[l] == s[r]) {
                dp[l][r] = dp[l+1][r-1];
            } else {
                dp[l][r] = min({
                    1 + dp[l+1][r-1], // substitute
                    1 + dp[l+1][r],   // delete/insert left
                    1 + dp[l][r-1]    // delete/insert right
                });
            }
        }
    }
    return dp[0][n-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << minEditsToPalindrome(s) << "\n";
    }
    return 0;
}
