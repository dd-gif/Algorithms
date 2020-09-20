#include <bits/stdc++.h>
#define elif else if
#define lli long long int
#define fiton for ( int i = 0; i < n; i++ )
using namespace std;
struct vertex {
    int val = 0;
    int left = 0;
    int right = 0;
    int depth = 0;
} mytree[1000000];
lli n;
vector<vertex> newtree;
void makenewtree( int now = 0, int newnow = 0 ) {
    if( mytree[now].left > 0 ) {
        newtree.push_back( mytree[mytree[now].left] );
        newtree[newnow].left = newtree.size() - 1;
        makenewtree( mytree[now].left, newtree.size() - 1 );
    }
    else
        newtree[newnow].left = -1;
    if( mytree[now].right > 0 ) {
        newtree.push_back( mytree[mytree[now].right] );
        newtree[newnow].right = newtree.size() - 1;
        makenewtree( mytree[now].right, newtree.size() - 1 );
    }
    else
        newtree[newnow].right = -1;
}
 
int main() {
    freopen("rotation.in", "r", stdin);
    freopen("rotation.out", "w", stdout);
    cin >> n;
    fiton {
        cin >> mytree[i].val >> mytree[i].left >> mytree[i].right;
        mytree[i].left--;
        mytree[i].right--;
    }
    fiton
        mytree[n - 1 - i].depth = max(mytree[mytree[n - 1 - i].left].depth, mytree[mytree[n - 1 - i].right].depth) + 1;
    if( mytree[mytree[mytree[0].right].left].depth - mytree[mytree[mytree[0].right].right].depth > 0 ) {
        int a, b, c, d, e;
        a = mytree[0].left;
        b = mytree[0].right;
        c = mytree[mytree[mytree[0].right].left].left;
        d = mytree[mytree[mytree[0].right].left].right;
        e = mytree[mytree[0].right].left;
        swap( mytree[0], mytree[mytree[mytree[0].right].left] );
       
        mytree[e].left = a;
        mytree[0].right = b;
        mytree[b].left = d;
        mytree[e].right = c;
        mytree[0].left = e;
    }
    else {
        swap( mytree[0].val, mytree[mytree[0].right].val );
        swap( mytree[0].left, mytree[0].right );
        swap( mytree[mytree[0].left].left, mytree[mytree[0].left].right );
        swap( mytree[mytree[0].left].left, mytree[0].right );
    }
    newtree.push_back( mytree[0] );
    makenewtree();
    fiton {
        if( i == 0 )
            cout << n << endl;
        cout << newtree[i].val << ' ' << newtree[i].left + 1 << ' ' << newtree[i].right + 1 << endl;
    }
    return 0;
}