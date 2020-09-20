#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, compNumber = 0;
vector<int> g[20000], gt[20000], order, comp;
vector<bool> checked, checkedt;
void dfs( int i ){
    checked[i] = true;
    for( int j = 0; j < g[i].size(); j++ ){
        if( checked[g[i][j]] == false )
            dfs( g[i][j] );
    }
    order.push_back( i );
}
void dfst( int i ){
    checkedt[i] = true;
    comp[i] = compNumber;
    for( int j = 0; j < gt[i].size(); j++ ){
        if( checkedt[gt[i][j]] == false )
            dfst( gt[i][j] );
    }
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    freopen("cond.in", "r", stdin);
    freopen("cond.out", "w", stdout);
    cin >> n >> m;
    for( int i = 0; i < m; i++ ){
        cin >> a >> b;
        g[a - 1].push_back( b - 1 );
        gt[b - 1].push_back( a - 1 ); 
    }
    for( int i = 0; i < n; i++ ){
        checked.push_back( false );
        checkedt.push_back( false );
        comp.push_back( 0 );
    }
    for( int i = 0; i < n; i++ ){
        if( checked[i] == false )
            dfs( i );
    }
    for( int i = n - 1; i >= 0; i-- ){
        if( checkedt[order[i]] == false ){
            compNumber++;
            dfst( order[i] );
        }
    }
    cout << compNumber << "\n";
    for( int i = 0; i < n; i++ )
        cout << comp[i] << " ";
}
