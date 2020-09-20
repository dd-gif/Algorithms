#include <iostream>
using namespace std;

__int64 A[300000], M[300000], l = 0;
int Merge( __int64 r, __int64 q, __int64 p ){
    __int64 i = r, j = q + 1, w = 0;
    for ( __int64 k = r; k <= p; k ++ ){
        if ( ( i <= q ) && ( ( j > p ) || ( A[i] <= A[j] ) ) ){
            M[k] = A[i];
            i++;
            w++;
            //cout << M[k] << "( " << q << "," << r << " ) ";
        }
        else{
            M[k] = A[j];
            j++;
            l += q + 1 - r - w;
            //cout << M[k] << "( " << q << "," << r << " ) ";
            
        }
        
    }//cout << l << endl;
    for ( __int64 i = r; i <= p; i++ ){
        A[i] = M[i];
    }
}
int MergeSort( __int64 r, __int64 p ){
    __int64 q;
    if ( r < p ){
        q = ( r + p ) / 2;
        MergeSort ( r, q );
        MergeSort ( q+1, p );
        Merge ( r, q, p );
    }
}
 
int main() {
    freopen ( "inversions.in", "r", stdin );
    freopen ( "inversions.out", "w", stdout);
    __int64 n;
    cin >> n;
    for ( __int64 i = 1; i <= n; i++ )
        cin >> A[i];
    MergeSort( 1, n );
    cout << l;
    return 0;
}


