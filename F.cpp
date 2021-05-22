#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;


void acceleration () {
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

void solve(){
     ll n;
     cin >> n;
     vector<vector<ll>> dp ((1 << n) + 10, vector<ll> (n, INF));
     vector<vector<ll>> p((1 << n) + 10, vector<ll> (n, INF));
     vector<vector<ll>> m (n, vector<ll> (n, 0));
     for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            cin >> m[i][j];
        }
     }
     for (ll mask = 0; mask < (1 << n); ++mask) {
        for (ll i = 0 ; i < n; ++i) {
              if ((1 << i) & mask){
                  ll new_mask = mask - (1 << i);
                  if (new_mask == 0) {
                      dp[mask][i] = 0;
                      p[mask][i] = -1;
                 } else {
                    for (ll j = 0; j < n; ++j) {
                        if (new_mask & (1 << j)) {
                            if (dp[mask][i] > dp[new_mask][j] + m[j][i]) {
                                dp[mask][i] = dp[new_mask][j] + m[j][i];
                                p[mask][i] = j;
                            }
                        }
                    }
                }
            }
          }
       }
     ll prev, ans = INF, mask = (1 << n) - 1;
     for (ll i = 0 ; i < n; ++i) {
        if (dp[(1 << n) - 1][i] < ans) {
            ans = dp[(1 << n) - 1][i];
            prev = i;
        }
     }
     vector<ll> temp;
     cout << ans << endl;
     while (prev != -1) {
         temp.push_back(prev);
         ll pt = prev;
         prev = p[mask][prev];
         mask -= (1 << pt);
     }
     for (ll i = 0 ; i < temp.size(); ++i)
        cout << temp[i] + 1 << " ";
}

