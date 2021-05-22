#include <bits/stdc++.h>
#include <stdio.h>

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

void file() {
    freopen("map.in", "r", stdin);
    freopen("map.out", "w", stdout);
}

int main() {
    file();
    acceleration();
    solve();
}

ll const N = 1e7 + 3;
list<pair<string, string>> a[N];
ll power[N];

ll hash_function (string s, ll p) {
  power[0] = 1;
  ll h = s[0] - 'A' + 1;
  for (ll i = 1 ; i < s.size() ; i++) {
    power[i] = (power[i - 1] % N * p) % N;
    h = (h + (s[i] - 'A' + 1) * power[i]) % N;
  }
  return h;
}

void solve() {
    string s;
    while (cin >> s) {
        string x, y;
        if (s == "put") {
            cin >> x >> y;
            ll h = hash_function(x, 71) % N;
            bool f = 0;
            for (auto i = a[h].begin() ; i != a[h].end() ; ++i) {
                pair<string, string> t = *i;
                if (t.f == x) {
                    i->second = y;
                    f = 1;
                    break;
                }
            }
            if (!f) {
                a[h].push_back({x, y});
            }
        } else if (s == "delete") {
            cin >> x;
            ll h = hash_function(x, 71) % N;
            for (auto i = a[h].begin() ; i != a[h].end() ; ++i) {
                pair<string, string> t = *i;
                if (t.f == x) {
                    i->second = "none";
                    break;
                }
            }
        } else {
            cin >> x;
            ll h = hash_function(x, 71) % N;
            bool f = 0;
            for (auto i = a[h].begin() ; i != a[h].end() ; ++i) {
                pair<string, string> t = *i;
                if (t.f == x) {
                    cout << i->second << endl;
                    f = 1;
                    break;
                }
            }
            if (!f) {
                cout << "none" << endl;
            }
        }
    }
}
