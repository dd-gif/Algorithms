#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
bool tw = true;
vector<int> g[100000], color;
void dfs( int i ){
    for( int j = 0; j < g[i].size(); j++ ){
        if( color[g[i][j]] == 0 ){
            color[g[i][j]] = 3 - color[i];
            dfs( g[i][j] );
        }
        else if( color[g[i][j]] == color[i] )
            tw = false;
    }
}
int main(){
    freopen( "bipartite.in", "r", stdin );
    freopen( "bipartite.out", "w", stdout );
    cin >> n >> m;
    for( int i = 0; i < m; i++ ){
        cin >> a >> b;
        g[a - 1].push_back( b - 1 );
        g[b - 1].push_back( a - 1 );
    }
    for( int i = 0; i < n; i++ )
        color.push_back( 0 );
    for( int i = 0; i < n; i++ ){
        if( color[i] == 0 ){
            color[i] = 1;
            dfs( i );
        }
    }
    if( tw == true )
        cout << "YES";
    else
        cout << "NO";
}
