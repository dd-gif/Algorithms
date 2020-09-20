#include <iostream>
#define lli long long int
#define fin for ( lli i = 0; i < n; i++ )
using namespace std;
lli a[100000];
int heapBuild ( lli n, lli i ){
    lli key = i, l = 2 * i + 1, r = 2 * i + 2;
    if ( l < n && a[l] > a[key] )
        key = l;
    if ( r < n && a[r] > a[key] )
        key = r;
    if ( key != i ){
        swap ( a[i], a[key] );
        heapBuild ( n, key );
    }
}
int heapSort ( lli n ){
    for ( int i = n / 2 - 1; i >= 0; i-- )
        heapBuild ( n, i );
    for ( int i = n - 1; i >= 0; i-- ){
        swap ( a[0], a[i] );
        heapBuild ( i, 0 );
    }
}
int main (){
    freopen ( "sort.in", "r", stdin );
    freopen ( "sort.out", "w", stdout );
    lli n;
    cin >> n;
    fin
        cin >> a[i];
    heapSort ( n );
    fin 
        cout << a[i] << " ";
}