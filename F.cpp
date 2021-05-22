#include<bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

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

ll const l = 1e5 + 10, INF = 1e18;
vector< pair<ll, ll> > g[l];
vector<ll> dist(l, INF);
set< pair<ll, ll> > s;

void solve() {
    ll n, m, st, fn, u, v, w;
    cin >> n >> m >> st >> fn;
    st--; fn--;
    for (int i = 0 ; i < m ; i++) {
        cin >> u >> v >> w;
        u--; v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dist[st] = 0;
    s.insert({0, st});
    while (!s.empty()) {
        pair <ll, ll> v = *s.begin();
        s.erase(s.begin());
        for (int i = 0 ; i < g[v.second].size() ; i++) {
            if (dist[g[v.second][i].first] > dist[v.second] + g[v.second][i].second) {
                s.erase({dist[g[v.second][i].first], g[v.second][i].first});
                dist[g[v.second][i].first] = dist[v.second] + g[v.second][i].second;
                s.insert({dist[g[v.second][i].first], g[v.second][i].first});
            }
        }
    }
    if (dist[fn] == INF){
        cout << "-1" << endl;
        return;
    }
    cout << dist[fn] << endl;
}

