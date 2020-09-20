#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    freopen("pathmgep.in", "r", stdin);
    freopen("pathmgep.out", "w", stdout);
    long long n, s, f;
    cin >> n >> s >> f;
    if (n == 1){
        cout << -1;
        return 0;
    }
    long long g[n][n], d[n];
    bool checked[n];
    for (long long i = 0; i < n; i++){
        for (long long j = 0; j < n; j++){
            cin >> g[i][j];
        }
    }
    for (long long i = 0; i < n; i++){
        checked[i] = false;
        d[i] = 1000000000000000000;
    }
    d[s - 1] = 0;
    for (long long j = 0; j < n; j++){
        long long min = 1000000000000000000, pos = 1000000000000000000;
        for (long long i = 0; i < n; i++){
            if (!checked[i] && d[i] < min){
                min = d[i];
                pos = i;
            }
        }
        if (pos == 1000000000000000000)
            continue;
        for (long long i = 0; i < n; i++){
            if (g[pos][i] >= 0 && i != pos){
                long long temp = min + g[pos][i];
                if (temp < d[i])
                    d[i] = temp;
            }
        }
        checked[pos] = true;
    }
    if (!checked[f - 1])
        cout << -1;
    else
        cout << d[f - 1];
}
