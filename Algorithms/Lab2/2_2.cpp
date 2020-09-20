#include <iostream>
#include <string>
using namespace std;

string s[100001][3], m[100001][3], check;
int Merge( int r, int q, int p ){
    int i = r, j = q + 1;
    for ( int k = r; k <= p; k ++ ){
        if ( ( i <= q ) && ( ( j > p ) || ( s[i][1] <= s[j][1] ) ) ){
            m[k][1] = s[i][1];
            m[k][2] = s[i][2];
            i++;
        }
        else{
            m[k][1] = s[j][1];
            m[k][2] = s[j][2];
            j++;
        }
    }
    for ( int i = r; i <= p; i++ ){
        s[i][1] = m[i][1];
        s[i][2] = m[i][2];
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
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    int n;
    cin >> n;
    for ( int i = 1; i <= n; i++ ) {
        string str1, str2;
        cin >> str1 >> str2;
        s[i][1] = str1;
        s[i][2] = str2;
    }
    //cout << s[1][2] << " ";
    MergeSort ( 1, n );
    check = s[1][1];
    cout << "=== " << s[1][1] << " ===" << endl;
    for ( int i = 1; i <= n; i++ ){
        if ( check != s[i][1] )
            cout << "=== " << s[i][1] << " ===" << endl;
        cout << s[i][2] << endl;
        check = s[i][1];
        
    }
}