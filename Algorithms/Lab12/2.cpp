#include <bits/stdc++.h>
using namespace std;
int n, m, k, a, b, ans = 0, num;
int g[501][501];
vector<int> p;
vector<bool> checked;
void initialization(){
    cin >> n >> m >> k;
    num = n + m + 2;
    for (int i = 0; i < num; i++) //n + m -> S; n + m + 1 -> T
        for (int j = 0; j < num; j++)
            g[i][j] = 0;
    p.resize(num, -1);
    checked.resize(num, false);
    for (int i = 1; i <= k; i++){
        cin >> a >> b;
        g[a][b + n] = 1;
    }
    for (int i = 1; i <= n; i++)
        g[0][i] = 1;
    for (int i = n + 1; i <= n + m; i++)
        g[i][n + m + 1] = 1;
}
bool bfs(int i){
    for (int j = 0; j < num; j++)
        checked[j] = false;
    queue<int> q;
    q.push(i);
    checked[i] = true;
    p[i] = -1;
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (int j = 0; j < num; j++){
            if (!checked[j] && g[v][j] > 0){
                q.push(j);
                p[j] = v;
                checked[j] = true;
            }
        }
    }
    return checked[n + m + 1];
}
int Ford(int i){
    while (bfs(i)){
        int flow = 1e9;
        for (int v = num - 1; v != i; v = p[v])
            flow = min(flow, g[p[v]][v]);
        for (int v = num - 1; v != i; v = p[v]){
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
    freopen("matching.in", "r", stdin);
    freopen("matching.out", "w", stdout);
    initialization();
    cout << Ford(0);
}
