#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    freopen("spantree.in", "r", stdin);
    freopen("spantree.out", "w", stdout);
    int n, c = 0, pos;
    cin >> n;
    double length[n], weigth = 0;
    bool checked[n];
    pair<int, int>g[n];
    for(int i = 0; i < n; i++){
        cin >> g[i].first >> g[i].second;
        checked[i] = false;
        length[i] = sqrt(pow((g[i].first - g[0].first), 2) + pow((g[i].second - g[0].second), 2));
    }
    checked[0] = true;
    c++;
    while(c != n){
        double min = 999999999;
        for(int i = 0; i < n; i++){
            if(min > length[i] && !checked[i]){
                min = length[i];
                pos = i;
            }
        }
        weigth += min;
        checked[pos] = true;
        c++;
        for(int i = 0; i < n; i++){
            if(!checked[i] && pos != i){
                min = sqrt(pow((g[i].first - g[pos].first), 2) + pow((g[i].second - g[pos].second), 2));
                if(min < length[i])
                    length[i] = min;
            }
        }
    }
    cout.precision(20);
    cout << weigth;
}
