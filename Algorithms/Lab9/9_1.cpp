#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, color[100000], flag = 0;
vector<int> g[100000], answer;
void dfs( int i ){
    color[i] = 1;
    for( int j = 0; j < g[i].size(); j++ ){
        if( color[g[i][j]] == 0 ){
            dfs( g[i][j] );
        }
        if( color[g[i][j]] == 1 ){
            flag = -1;
            break;
        }
    }
    color[i] = 2;
    answer.push_back( i + 1 );
}
void topSort(){
    for( int i = 0; i < n; i++ ){
        if( flag == - 1 ) 
            break;
        if( color[i] == 0 )
            dfs( i );
    }
    if( flag != -1 )
        reverse( answer.begin(), answer.end() );
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    freopen( "topsort.in", "r", stdin );
    freopen( "topsort.out", "w", stdout );
    cin >> n >> m;
    for( int i = 0; i < m; i++ ){
        cin >> a >> b;
        g[a - 1].push_back( b - 1 );
        if( i < n )
            color[i] = 0;
    }
    topSort();
    if( flag != -1 )
        for( int i = 0; i < n; i++ )
            cout << answer[i] << " ";
    else
        cout << -1;
}
