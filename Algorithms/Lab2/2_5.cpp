#include <iostream>
using namespace std;
 
int a[30000000], k;
 
int QSort ( int left, int right ){
    int i, j, key, buf;
    key = a[( left + right ) / 2];
    i = left;
    j = right;
    while ( j >= i ){
        while ( a[i] < key )
            i++;
        while ( key < a[j] )
            j--;
        if ( i <= j ){
            buf = a[i];
            a[i] = a[j];
            a[j] = buf;
            i++;
            j--;
        }
    }
    if ( left <= k && k <= j && left < j)
        QSort ( left, j );
    if ( i < right && i <= k && k <= right )
        QSort ( i, right );
}
 
int main(){
    freopen ( "kth.in", "r", stdin );
    freopen ( "kth.out", "w", stdout);
    int n, Q, W, E, r1, r2, flag = 0;
    cin >> n >> k >> Q >> W >> E >> r1 >> r2;
    a[1] = r1;
    a[2] = r2;
    for ( int i = 3; i <= n; i++ )
        a[i] = Q * a[i - 2] + W * a[i - 1] + E;
    QSort ( 1, n );
    cout << a[k];
}