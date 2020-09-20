#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    freopen("pathbgep.in", "r", stdin);
    freopen("pathbgep.out", "w", stdout);
    int n, m, a, b, c;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    vector<int> d(n, 1000000000);
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        g[a - 1].emplace_back (b - 1, c);
        g[b - 1].emplace_back (a - 1, c);
    }
    set<pair<int,int>> q;
    q.emplace (0, 0);
    d[0] = 0;
    while (!q.empty()){
        int v = q.begin()->second;
        q.erase (q.begin());
        for (int j = 0; j < g[v].size(); j++){
            int u = g[v][j].first, dist_u = g[v][j].second;
            if (d[v] + dist_u < d[u]){
                q.erase ({d[u], u});
                d[u] = d[v] + dist_u;
                q.insert ({d[u], u});
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << d[i] << " ";
}
