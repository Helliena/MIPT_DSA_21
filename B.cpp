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
    ll n;// И всё же ввод красивее отдельно)
    cin >> n;
    vector<ll> a(n);
    vector<ll> dp(n + 1, INF);
    vector<ll> pos(n + 1);
    vector<ll> prev(n + 1);
    for (ll i = 0; i < n; ++i) {
        cin >> a[n - i - 1];
    }
    dp[0] = -INF;
    pos[0] = -1;
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        auto bin_s = upper_bound(dp.begin(), dp.end(), a[i]);// А можно было за логарифм... но ладно
        ll ind = static_cast<ll>(bin_s - dp.begin());
        if (dp[ind - 1] <= a[i] && a[i] < dp[ind]) {
            dp[ind] = a[i];
            pos[ind] = i;
            prev[i] = pos[ind - 1];
            ans = max(ans, ind);
        }
    }
    vector<ll> result;
    ll p = pos[ans];
    while (p != -1) {
       result.push_back(p);
       p = prev[p];
    }
    cout << ans << endl;
    for (ll i = 0 ; i < result.size(); ++i) {
       cout << n - result[i] << " ";
    }
}
