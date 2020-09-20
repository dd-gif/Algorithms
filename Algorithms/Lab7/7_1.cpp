#include <iostream>
#include <cmath>
#define lli long long int
#define fiton for ( lli i = 0; i < n; i++ )
#define fjn for ( lli j = 0; j < n; j++ )
using namespace std;
struct Tree{
    int value;
    int left;
    int right;
    int balance;
};
struct Tree *mytree[200001];
void createTree(){
    for( int i = 0; i <= 2000001; i++ )
        mytree[i] = NULL;
}
void zapulTango( int K, int L, int R, int i ){
    mytree[i + 1] = new Tree;
    mytree[i + 1]->value = K;
    mytree[i + 1]->left = L;
    mytree[i + 1]->right = R;
}
int height( int number ){
    if( mytree[number] == NULL || number == 0 )
        return 0;
    int h1, h2;
    h1 = height( mytree[number]->left );
    h2 = height( mytree[number]->right );
    mytree[number]->balance = h2 - h1;
    return( max( h1, h2 ) + 1 );
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    freopen ( "balance.in", "r", stdin );
    freopen ( "balance.out", "w", stdout );
    int N, K, L, R;
    cin >> N;
    for( int i = 0; i < N; i++ ){
        cin >> K >> L >> R;
        zapulTango( K, L, R, i );
    }
    height( 1 );
    for( int i = 1; i <= N; i++ ){
        cout << mytree[i]->balance << "\n";
    }
}