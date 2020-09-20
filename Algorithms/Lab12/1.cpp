#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, c, ans = 0;
int g[101][101];
vector<int> p;
vector<bool> checked;
void initialization(){
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = 0;
    p.resize(n, -1);
    checked.resize(n, false);
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        g[a - 1][b - 1] = c;
    }
}
bool bfs(int i){
    for (int j = 0; j < n; j++)
        checked[j] = false;
    queue<int> q;
    q.push(i);
    checked[i] = true;
    p[i] = -1;
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (int j = 0; j < n; j++){
            if (!checked[j] && g[v][j] > 0){
                q.push(j);
                p[j] = v;
                checked[j] = true;
            }
        }
    }
    return checked[n - 1];
}
int Ford(int i){
    while (bfs(i)){
        int flow = 1e9;
        for (int v = n - 1; v != i; v = p[v])
            flow = min(flow, g[p[v]][v]);
        for (int v = n - 1; v != i; v = p[v]){
            g[p[v]][v] -= flow;
            g[v][p[v]] += flow;
        }
        ans += flow;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    freopen("maxflow.in", "r", stdin);
    freopen("maxflow.out", "w", stdout);
    initialization();
    cout << Ford(0);
}
