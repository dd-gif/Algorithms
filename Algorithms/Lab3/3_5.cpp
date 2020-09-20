#include <iostream>
#define lli long long int
#define fin for ( lli i = 0; i < n; i++ )
#define fjn for ( lli j = 0; j < n; j++ )
using namespace std;
string s[1000], b[1000];
int radixSort( lli n, lli m, lli k ){
    for ( int i = m - 1; i >= m - k; i -- ){
        char compare = 'a';
        int l = 26, number = 0;
        while ( l > 0 ){
            fjn{
                if ( s[j][i] == compare ){
                    b[number] = s[j];
                    number++;
                }
            }
            compare++;
            l--;
        }
        fin
            s[i] = b[i]; 
    }
}
int main(){
    freopen("radixsort.in", "r", stdin);
    freopen("radixsort.out", "w", stdout);
    lli n, m, k;
    cin >> n >> m >> k;
    fin
        cin >> s[i];
    radixSort ( n, m, k );
    fin
        cout << s[i] << endl;
}