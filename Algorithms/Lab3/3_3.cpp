#include <iostream>
#define lli long long int
#define fin for ( lli i = 1; i <= n; i++ )
using namespace std;
int main(){
	freopen ( "isheap.in", "r", stdin );
	freopen ( "isheap.out", "w", stdout);
    lli n, a[100000], k = 0, l = 0;
    cin >> n;
    fin
    	cin >> a[i];
    fin{
    	if ( 2 * i <= n ){
    		if ( a[i] <= a[2 * i] )
    			k = 1;
    		else{
    			cout << "NO";
    			return 0;
    		}
    	}
    	if ( 2 * i + 1 <= n ){
    		if ( a[i] <= a[2 * i + 1] )
    			l = 1;
    		else{
    			cout << "NO";
    			return 0;
    		}
    	}
    }
    if ( k == 1 && l == 1 )
    	cout << "YES";
}