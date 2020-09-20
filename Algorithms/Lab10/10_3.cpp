#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
double weight, w;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    freopen("spantree3.in", "r", stdin);
    freopen("spantree3.out", "w", stdout);
    cin >> n >> m;
    vector<bool> used( n ); 
    vector<pair<double, int>>g[n];
    for( int i = 0; i < m; i++ ){
        cin >> a >> b >> w;
        g[a - 1].push_back( make_pair( w, b - 1 ) );
        g[b - 1].push_back( make_pair( w, a - 1 ) );
    }
    double mst_weight = 0;
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
    q.push( {0, 0} );
    while( !q.empty() ){
        pair< double, int> c = q.top();
        q.pop();
        double dst = c.first;
        int v = c.second;
        if( used[v] )
            continue;
        used[v] = true;
        mst_weight += dst;
        for( pair<double, int> e: g[v] ){
            int u = e.second;
            double lev_vu = e.first;
            if( !used[u] ){
                q.push( {lev_vu, u} );
            }
        }
    }
    cout.precision(10);
    cout << mst_weight;
     
}
