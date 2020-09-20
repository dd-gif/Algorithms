#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, st[100];
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    for( int i = 0; i < n; i++ )
        st[i] = 0;
    cin >> n >> m;
    for( int i = 0; i < m; i++ ){
        cin >> a >> b;
        st[a - 1]++;
        st[b - 1]++;
    }
    for ( int i = 0 ; i < n; i++ )
        cout << st[i] << " ";
}
