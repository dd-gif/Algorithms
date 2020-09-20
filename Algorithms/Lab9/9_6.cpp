#include <bits/stdc++.h>
using namespace std;
int n, m, s, a, b;
vector<int> g[100000];
vector<bool> check, flag;
void dfs( int i ){
    check[i] = true;
    for( int j = 0; j < g[i].size(); j++ ){
        if( check[g[i][j]] == false )
            dfs( g[i][j] );
        if( !flag[g[i][j]] ){
            flag[i] = true;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
    cin >> n >> m >> s;
    for( int i = 0; i < m; i++ ){
        cin >> a >> b;
        g[a - 1].push_back( b - 1 );
    }
    for( int i = 0; i < n; i++ ){
        check.push_back( false );
        flag.push_back( false );
    }
    dfs( s - 1 );
    if( flag[s - 1] )
        cout << "First player wins";
    else
        cout << "Second player wins";
}
