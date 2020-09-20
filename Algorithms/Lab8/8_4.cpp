#include<bits/stdc++.h>
using namespace std;
int n, m, a, b, number = 0;
vector<int> g[100000], component;
vector<bool> checked;
void dfs( int i ){
    checked[i] = 1;
    component[i] = number;
    if( !g[i].empty() ){
        for( int j = 0; j < g[i].size(); j++ ){
            if( !checked[g[i][j]] )
                dfs( g[i][j] );
        }
    }
}
int main(){
    freopen( "components.in", "r", stdin );
    freopen( "components.out", "w", stdout);
    cin >> n >> m;
    for( int i = 0; i < m; i++ ){
        cin >> a >> b;
        g[a - 1].push_back( b - 1 );
        g[b - 1].push_back( a - 1 );
    }
    for( int i = 0; i < n; i++ ){
        checked.push_back( false );
        component.push_back( 0 );
    }
    for( int i = 0; i < n; i++ ){
        if( !checked[i] ){
            number++;
            dfs( i );
        }
    }
    cout << number << endl;
    for( int i = 0; i < n; i++ )
        cout << component[i] << " ";
}