#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );
    int n;
    cin >> n;
    int a[100][100];
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ){
            cin >> a[i][j];
        }
    }
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ){
            if( a[i][j] != a[j][i] || i == j && a[i][j] ){
                cout << "NO";
                exit(0);
            }
        }
    }
    cout << "YES";
}