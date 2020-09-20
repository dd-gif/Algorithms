#include <iostream>
#define lli long long int
#define fin for ( lli i = 0; i < n; i++ )
using namespace std;
lli a[100000];
int binSearchLeft( lli n, lli key ){
    lli left = -1, right = n, middle;
    while ( left < right - 1 ){
        middle = ( left + right ) / 2;
        if ( a[middle] < key )
            left = middle;
        else
            right = middle;
    }
    return right;
}
int binSearchRight( lli n, lli key ){
    lli left = -1, right = n, middle;
    while ( left < right - 1 ){
        middle = ( left + right ) / 2;
        if ( a[middle] <= key )
            left = middle;
        else
            right = middle;
    }
    return right;
}
int main(){
	freopen ( "binsearch.in", "r", stdin );
	freopen ( "binsearch.out", "w", stdout);
    lli n;
    cin >> n;
    fin
        cin >> a[i];
    lli m, b;
    cin >> m;
    for ( lli i = 0; i < m; i++ ){
    	cin >> b;
    	if ( a[binSearchLeft ( n, b )] != b && a[binSearchRight ( n, b )] != b )
    		cout << -1 << " " << -1 << endl;
    	else
    		cout << binSearchLeft ( n, b ) + 1 << " " << binSearchRight ( n, b ) << endl;
    }
}