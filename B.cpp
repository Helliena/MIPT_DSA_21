#include<bits/stdc++.h>
#include<iostream>
#include<vector>

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
int main(){
    acceleration();
    solve();
}

ll const N = 1e5 + 10, INF = 1e18;
pair<ll, pll> g[N];
ll num[N];
ll cnt[N];
ll ans = 0;


int getNum(ll x) {
    if (x == num[x])
        return x;
    num[x] = getNum(num[x]);
    return num[x];
}

void unite(ll u, ll v) {
    if (cnt[u] < cnt[v])
        num[u] = v;
    else {
        num[v] = u;
        if (cnt[u] == cnt[v])
            cnt[u]++;
    }
}


void Kruskal(ll m) {
    for (ll i = 0; i < m; ++i){
        ll n1 = getNum(g[i].s.f), n2 = getNum(g[i].s.s);
        if (getNum(g[i].s.f) != getNum(g[i].s.s)){
            unite(n1, n2);
            ans += g[i].f;
        }
    }

}




void solve() {
    ll n, m, u, v, w;
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        u--;
        v--;
        g[i]= {w, {u, v}};
    }
    sort(g, g + m);
    for (ll i = 0; i < n; ++i)
        num[i] = i;
    Kruskal(m);
    cout << ans << endl;
}

