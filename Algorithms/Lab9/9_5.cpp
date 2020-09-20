#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, c = 0;
vector<int> g[100000];
vector<int> flag; bool check = true;
stack<int> way;
void dfs( int i ){
    flag[i] = 1;
    for( int j = 0; j < g[i].size(); j++ ){
        if( flag[g[i][j]] == 0 )
            dfs( g[i][j] );
    }
    flag[i] = 2;
    way.push( i ); 
    
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    freopen( "hamiltonian.in", "r", stdin );
    freopen( "hamiltonian.out", "w", stdout );
    cin >> n >> m;
    if( n == 1 ){
        cout << "YES";
        return 0;
    }
    for( int i = 0; i < m; i++ ){
        cin >> a >> b;
        g[a - 1].push_back( b - 1 );
    }
    for( int i = 0; i < n; i++ ){
        flag.push_back( 0 );
    }
    for( int i = 0; i < n; i++ ){
        if( flag[i] == 0 )
            dfs( i );
    }
    if( !way.empty() ){
        a = way.top();
        way.pop();
    }
    while( true ){
        check = false;
        b = way.top();
        way.pop();
        for( int i = 0; i < g[a].size(); i++ ){
            if( g[a][i] == b )
                check = true;
        }
        a = b;
        if( check == false || way.empty() )
            break;
    }
    if( check )
        cout << "YES";
    else
        cout << "NO";
}
