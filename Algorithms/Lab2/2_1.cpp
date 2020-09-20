#include <iostream>
using namespace std;

int A[300000], M[300000];
int Merge( int r, int q, int p ){
    int i = r, j = q + 1;
    for ( int k = r; k <= p; k ++ ){
        if ( ( i <= q ) && ( ( j > p ) || ( A[i] < A[j] ) ) ){
            M[k] = A[i];
            i++;
        }
        else{
            M[k] = A[j];
            j++;
        }
    }
    for ( int i = r; i <= p; i++ ){
        A[i] = M[i];
    }
}
int MergeSort( int r, int p ){
    int q;
    if ( r < p ){
        q = ( r + p ) / 2;
        MergeSort ( r, q );
        MergeSort ( q+1, p );
        Merge ( r, q, p );
    }
}
 
int main() {
    freopen ( "sort.in", "r", stdin );
    freopen ( "sort.out", "w", stdout);
    int n;
    cin >> n;
    for ( int i = 1; i <= n; i++ )
        cin >> A[i];
    MergeSort( 1, n );
    for ( int i = 1; i <= n; i++ )
        cout << A[i] << " ";
    return 0;
}