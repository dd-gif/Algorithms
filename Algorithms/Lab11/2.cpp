#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    freopen("pathsg.in", "r", stdin);
    freopen("pathsg.out", "w", stdout);
    int n, m, a, b, c;
    cin >> n >> m;
    int d[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = INT_MAX;
        }
    }        
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        d[a - 1][b - 1] = c;
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (d[i][k] < INT_MAX && d[k][j] < INT_MAX)
                    d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }
}
