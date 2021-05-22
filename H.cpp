#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define f first
#define s second

void acceleration() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve();

int main() {
    acceleration();
    solve();
}

ll const INF = 1e18, N = 3e3 + 10, MOD = 1e9 + 7;
ll dp[N][N];

void get_and_Solve () {
    int n, m;
    cin >> n >> m;
    vector<ll> f(n + 1);
    for (ll i = 1; i <= n; ++i)
        cin >> f[i];
    vector<ll> s(m + 1);
    for (ll i = 1; i <= m; ++i)
        cin >> s[i];

    ll res = 0, ans;
    for (ll i = 1; i <= n; ++i) {
        ans = 0;
        for (ll j = 1; j <= m; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (f[i] == s[j])
                dp[i][j] = ans + 1;
            else if (f[i] > s[j] && dp[i - 1][j] > ans)
                ans = dp[i - 1][j];
            res = max(dp[i][j], res);
        }
    }
    cout << res << endl;
}
