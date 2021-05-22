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

ll const INF = 1e18, N = 110, MOD = 1e9 + 7;
ll a[N];

void test(vector<vector<ll>> &m, ll i, ll j) {
    ll temp = a[i] ^ a[j];
    ll cnt = 0, t = 1;
    while(t <= temp) {
        if (temp & t)
            cnt++;
        t *= 2;
    }
    if (!(cnt % 3)){
        m[i][j] = 1;
        m[j][i] = 1;
    }
}



vector<vector<ll>> operator *(const vector<vector<ll>> &a, const vector<vector<ll>> &b) {
    vector<vector<ll>> res(a.size(), vector<ll>(b[0].size()));
    for (ll i = 0; i < a.size(); ++i)
        for (ll j = 0; j < b[0].size(); ++j)
            for (ll k = 0; k < a[0].size(); ++k)
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
    return res;
}

vector<vector<ll>> binpow(vector<vector<ll>>& a, ll n) {
    vector<vector<ll>> res(a.size(), vector<ll> (a[0].size()));
    for (ll i = 0; i < a.size(); ++i)
        res[i][i] = 1;
    while (n) {
        if (n & 1)
            res = a * res;
        a = a * a;
        n >>= 1;
    }
    return res;
}

void solve(){
    ll n, m;
    cin >> n >> m;
    if (n > m)
        swap(n, m);
    vector<vector<ll>> temp;
    vector<vector<ll>> mtr(1 << n, vector<ll>(1 << n));
    for (ll i = 0; i < 1 << n; ++i)
        temp.push_back({1});
    for (ll i = 0; i < 1 << n; ++i)
        for (ll j = 0; j < 1 << n; ++j) {
            ll any = true;
            for (ll k = 0; k < n - 1; ++k) {
                ll i1 = (i >> k) & 1, i2 = (i >> (k + 1)) & 1;
                ll j1 = (j >> k) & 1, j2 = (j >> (k + 1)) & 1;
                if (i1 == i2 && i2 == j1 && j1 == j2)
                    any = false;
            }
            mtr[i][j] = any;
    }
    temp = binpow(mtr, m - 1) * temp;
    ll sum = 0;
    for (int i = 0; i < 1 << n; ++i)
        sum += temp[i][0];
    cout << sum;
}

