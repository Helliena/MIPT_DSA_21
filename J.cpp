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
    ll s, n;
    cin >> s >> n;
    
    vector<ll> a(n);
    vector<bool> v(s + 1, 0);
    for (ll i = 0 ; i < n ; ++i) {
        cin >> a[i];
    }
    
    v[0] = 1;
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = s; j >= 0; --j) {
            if (v[j] && j + a[i] <= s) {
                v[j + a[i]] = 1;
                ans = max(ans, j + a[i]);
            }

        }
    }
    
    cout << ans << endl;
}

 
