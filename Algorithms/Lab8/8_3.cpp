#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );
    int n, m;
    cin >> n >> m;
    int a[m], b[m];
    for( int i = 0; i < m; i++ )
        cin >> a[i] >> b[i];
    int p = 0;
    while( true ){
        for( int j = p + 1; j < m; j++ ){
            if( a[p] == a[j] && b[p] == b[j] ){
                cout << "YES";
                return 0;
            }
        }
        p++;
        if( p == m )
            break;
    }
    cout << "NO";
}