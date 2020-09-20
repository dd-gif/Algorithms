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
};
struct Tree *mytree[200001];
void createTree(){
    for( int i = 0; i <= 200001; i++ )
        mytree[i] = NULL;
}
void zapulTango( int K, int L, int R, int i ){
    mytree[i + 1] = new Tree;
    mytree[i + 1]->value = K;
    mytree[i + 1]->left = L;
    mytree[i + 1]->right = R;
}
bool isTango( int number, int max, int min ){
    if( mytree[number] == NULL )
        return true;
    if( mytree[number]->value <= min || mytree[number]->value >= max )
        return false;
    bool leftRoot, rightRoot;
    leftRoot = isTango( mytree[number]->left, mytree[number]->value, min );
    rightRoot = isTango( mytree[number]->right, max, mytree[number]->value );
    return leftRoot & rightRoot;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    freopen ( "check.in", "r", stdin );
    freopen ( "check.out", "w", stdout );
    int N, K, L, R;
    cin >> N;
    for( int i = 0; i < N; i++ ){
        cin >> K >> L >> R;
        zapulTango( K, L, R, i );
    }
    bool check = isTango( 1, 1000000000, -1000000000 );
    if( check == true )
        cout << "YES";
    else
        cout << "NO";
}