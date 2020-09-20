#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, color[100000], beginCycleValue;
vector<int> g[100000], dist;
bool dfs( int i ){
    color[i] = 1;
    for( int j = 0; j < g[i].size(); j++ ){
        if( color[g[i][j]] == 0 ){
            if( dfs( g[i][j] ) ) { 
                if ( dist.front() != dist.back() ){
                    dist.push_back( i );
                }
                return true;
            }
        }
        else if( color[g[i][j]] == 1 ) {
            dist.push_back( g[i][j] );
            dist.push_back( i );
            return true;
        }
    }
    color[i] = 2;
    return false;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    freopen( "cycle.in", "r", stdin );
    freopen( "cycle.out", "w", stdout );
    cin >> n >> m;
    for( int i = 0; i < m; i++ ){
        cin >> a >> b;
        g[a - 1].push_back( b - 1 );
        if( i < n )
            color[i] = 0;
    }
    for( int i = 0; i < n; i++ ){
        if( color[i] == 0 && dfs( i ) ){
            cout << "YES\n";
            dist.erase( dist.begin() );
            reverse( dist.begin(), dist.end() );
            for( int j = 0; j < dist.size(); j++ )
                cout << dist[j] + 1 << " ";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
