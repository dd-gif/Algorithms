#include <iostream>
using namespace std;
int main (){
    int n;
    cin >> n;
    int a[n];
    freopen ( "antiqs.in", "r", stdin );
    freopen ( "antiqs.out", "w", stdout );
    for ( int i = 0; i < n; i++ )
        a[i] = i + 1;
    for ( int i = 0; i < n; i++ )
        swap ( a[i], a[i/2] );
    for ( int i = 0; i < n; i++ )
        cout << a[i] << " ";
}