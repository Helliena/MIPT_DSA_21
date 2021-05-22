#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;


ll const MOD = 999999937;

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

vector<vector<ll>> mult(vector<vector<ll>> &a, vector<vector<ll>> &b) {
     vector<vector<ll>> c;
     for (ll i = 0 ; i < a.size() ; i++) {
        vector<ll> s;
        for (ll j = 0 ; j < b[0].size() ; j++) {
            s.push_back(0);
            for (ll q = 0 ; q < b.size() ; q++) {
                s[j] += (a[i][q] % MOD * b[q][j] % MOD) % MOD;
                s[j] %= MOD;
            }
        }
        c.push_back(s);
     }
     return c;
}


vector<vector<ll>> bin_pow (vector<vector<ll> > &x, ll n) {
    vector<vector<ll> > ans, t;
    if (n == 1) return x;
    if (n % 2) {
        t = bin_pow(x, n - 1);
        ans = mult(t, x);
        return ans;
    }
    t = bin_pow(x, n / 2);
    ans = mult(t, t);
    return ans;
}

void solve(){
    ll x;
    vector < vector <ll> > a;
    a.push_back({1, 1, 1, 1, 1});
    a.push_back({1, 1, 1, 1, 1});
    a.push_back({1, 1, 1, 1, 1});
    a.push_back({1, 1, 0, 1, 0});
    a.push_back({1, 1, 0, 0, 1});
    vector < vector <ll> > b;
    b.push_back({1});
    b.push_back({1});
    b.push_back({1});
    b.push_back({1});
    b.push_back({1});
    while (cin >> x){
        if (!x) return;
        if (x == 1) {
            cout << 5 << endl;
        } else {
            vector < vector <ll> > t = bin_pow(a, x - 1);
            vector < vector <ll> > ans = mult(t, b);
            ll res = 0;
            for (ll i = 0 ; i < ans.size() ; i++) {
                for (ll j = 0 ; j < ans[i].size() ; j++) {
                    res += ans[i][j];
                    res %= MOD;
                }
            }
            cout << res % MOD << endl;
        }
    }
}

