#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void acceleration(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve();

int main() {
    acceleration();
    solve();
}

bool find_circle(vector<vector<ll>>& g, vector<ll>& used, ll v, vector<ll>& ans) {
    if (used[v] == 1) {
        ans.push_back(v);
        return 1;
    }
    if (used[v])
        return 0;
    used[v] = 1;
    ans.push_back(v);
    bool f = 0;
    for (ll u = 0; u < g[v].size(); ++u) {
        if(find_circle(g, used, g[v][u], ans)) {
            f = 1;
            break;
        }
    }
    if (!f)
        ans.pop_back();
    used[v] = 2;
    return f;
}

void solve() {
    ll n, m, u, v;
    cin >> n >> m;
    vector<vector<ll>> g(n + 1);// А всё это можно было спрятать в структурку с названием вершина, что было бы приятнее на глаз
    vector<ll> used(n + 1, 0);
    vector<ll> ans;
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
    }
    bool flag = 0;
    for (ll i = 1; i <= n; ++i) {
        ans.clear();
        if (!used[i])
            if(find_circle(g, used, i, ans)) {
                flag = 1;
                break;
            }
    }
    if (flag) {
        cout << "YES" << endl;
        vector<ll> r;
        ll res = ans[ans.size() - 1];
        for (ll i = ans.size() - 1; i >= 0; --i) {
             if (i != ans.size() - 1 && res == ans[i])
                break;
             r.push_back(ans[i]);

        }
        for (ll i = r.size() - 1; i >= 0; --i)
            cout << r[i] << " ";
        return;
    }
    cout << "NO" << endl;
}
