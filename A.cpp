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

ll const N = 1e7 + 3;
list<pair<string, ll>> a[N];
ll power[N];

ll hash_function (string s, ll p) {
  power[0] = 1;
  ll h = s[0] - 'a' + 1;
  for (ll i = 1 ; i < s.size() ; i++) {
    power[i] = (power[i - 1] * p) % N;
    h = (h + (s[i] - 'a' + 1) * power[i]) % N;
  }
  return h;
}

void solve() {
    string s;
    ll x;
    while (cin >> s) {
        cin >> x;
        ll h = hash_function(s, 31) % N;
        bool f = 0;
        for (auto i = a[h].begin() ; i != a[h].end() ; ++i) {
            pair<string, ll> t = *i;
            if (t.f == s) {
                i->second += x;
                cout << i->second << endl;
                f = 1;
            }
        }
        if (!f) {
            cout << x << endl;
            a[h].push_back({s, x});
        }
    }
}
