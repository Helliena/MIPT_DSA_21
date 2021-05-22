#include<bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

void acceleration() {
     ios_base::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
}

void solve();
int main(){
    acceleration();
    solve();
}

ll const N = 2e4 + 10;
vector<ll> g[N];
set<ll> ans;
ll t, tin[N], fup[N];

void DFS(vector<bool>& used, ll v, ll p) {
	used[v] = 1;
	t++;
	tin[v] = t;
	fup[v] = t;
	ll cnt = 0;
	for (ll i = 0; i < g[v].size(); ++i) {
		if (g[v][i] != p) {
            if (used[g[v][i]])
                fup[v] = min(fup[v], tin[g[v][i]]);
            else {
                DFS(used, g[v][i], v);
                ++cnt;
                fup[v] = min(fup[v], fup[g[v][i]]);
                if (fup[g[v][i]] >= tin[v] && p != -1)
                    ans.insert(v + 1);
            }
		}
	}
	if (p == -1 && cnt > 1)
		ans.insert(v + 1);
}


void solve(){
    ll n, m, u, v;
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    t = 0;
    vector<bool> used(n + 1, 0);
	for (ll i = 0; i < n; ++i) {
        if (!used[i])
			DFS(used, i, -1);
	}
    cout << ans.size() << endl;
    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";
}

