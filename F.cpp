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

ll const INF = 1e18;

void solve () {
    ll n, m;
    cin >> n;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> m;
    vector<ll> b(m + 1);
    for (ll i = 1; i <= m; ++i)
        cin >> b[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
    for (ll i = 1 ; i <= n ; ++i) {
        for (ll j = 1 ; j <= m ; ++j) {
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[n][m] << endl;
}

 
