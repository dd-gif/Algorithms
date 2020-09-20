#include<bits/stdc++.h>
using namespace std;
int n, m;
char c;
vector<pair<int, int>> p;
vector<bool> checked;
vector<char> point, dist;
void bfs( int i ){
    p[i].first = i;
    p[i].second = 0;
    queue<int> q;
    q.push( i );
    while( !q.empty() ){
        int E = q.front();
        q.pop();
        if( point[E] == 'T' )
            break;
        if( !checked[E] ){
            checked[E] = true;
            if( point[E - 1] != '#' && E % m != 0 && !checked[E - 1] ){
                p[E - 1].first = E;
                p[E - 1].second = p[E].second + 1;
                dist[E - 1] = 'L';
                q.push( E - 1 );
            } 
            if( point[E + 1] != '#' && ( E + 1 ) % m != 0 && !checked[E + 1] ){
                p[E + 1].first = E;
                p[E + 1].second = p[E].second + 1;
                dist[E + 1] = 'R';
                q.push( E + 1 );
            } 
            if( point[E - m] != '#' && E + 1 > m && !checked[E - m] ){
                p[E - m].first = E;
                p[E - m].second = p[E].second + 1;
                dist[E - m] = 'U';
                q.push( E - m );
            } 
            if( point[E + m] != '#' && E + 1 <= m * ( n - 1 ) && !checked[E + m] ){
                p[E + m].first = E;
                p[E + m].second = p[E].second + 1;
                dist[E + m] = 'D';
                q.push( E + m );
            }
        }
    }    
}
void distance( int i ){
    if( p[i].first != i )
        distance( p[i].first );
    if( dist[i] != 'r' )
        cout << dist[i];
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout);
    cin >> n >> m;
    if( n == 1 && m == 1 ){
        cout << -1;
        return 0;
    } 
    int s, f;
    for( int i = 0; i < n * m; i++ ){
        cin >> c;
        if( c == 'S' )
            s = i;
        if( c == 'T' )
            f = i;
        point.push_back( c );
        checked.push_back( false );
        dist.push_back( 'r' );
        p.push_back( { 0, 0 } );
    }
    bfs( s );
    if( p[f].second == 0 ){
        cout << -1;
        return 0;
    }
    cout << p[f].second << endl;
    distance( f );
}