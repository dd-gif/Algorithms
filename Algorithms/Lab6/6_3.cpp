#include <iostream>
#include <cmath>
#include <algorithm>
#define lli long long int
#define fiton for ( lli i = 0; i < n; i++ )
#define fjn for ( lli j = 0; j < n; j++ )
using namespace std;
struct Tree{
    int value;
    Tree *left;
    Tree *right;
};
Tree *mytree = NULL;
struct Tree *insert( Tree *mytree, int x ){
    if( mytree == NULL ){
        mytree = new Tree;
        mytree->value = x;
        mytree->left = NULL;
        mytree->right = NULL;
    }
    if( mytree->value == x )
        return ( mytree );
    else if( x < mytree->value )
        mytree->left = insert( mytree->left, x );
    else
        mytree->right = insert( mytree->right, x );
    return( mytree );
}
string exists( struct Tree *node, int x ){
    if( node == NULL )
        return "false";
    if( node->value == x )
        return "true";
    if( x < node->value )
        return exists( node->left, x );
    else
        return exists( node->right, x );
}
struct Tree *minimum( struct Tree *node ){
    if( node->left == NULL )
        return node;
    return minimum( node->left );
}
struct Tree *maximum( struct Tree *node ){
    if( node->right == NULL )
        return node;
    return maximum( node->right );
}
struct Tree *del( struct Tree *node, int x ){
    if( node == NULL )
        return node;
    if( x < node->value )
        node->left = del( node->left, x );
    else if( x > node->value )
        node->right = del( node->right, x );
    else if( node->right != NULL && node->left != NULL ){
        node->value = minimum( node->right )->value;
        node->right = del( node->right, node->value );
    }
    else{
        if( node->left != NULL )
            node = node->left;
        else if( node->right != NULL )
            node = node->right;
        else
            node = NULL;
    }
    return node;
}
int prev( struct Tree *node, int x ){
    if( node == NULL )
        return -1000000001;
    struct Tree *temp = node;
    if( temp->value == x ){
        if( temp->left == NULL )
            return -1000000001;
        temp = temp->left;
        while( temp->right != NULL )
            temp = temp->right;
        return temp->value;
    }
    //---//
    else if( temp->value > x ){
        while( temp->value > x ){
            if( temp->left == NULL )
                return -1000000001;
            temp = temp->left;
        }
        if( temp->value == x ){
            if( temp->left == NULL )
                return -1000000001;
            temp = temp->left;
            while( temp->right != NULL )
                temp = temp->right;
            return temp->value;
        }
        else if( temp->value < x ){
            while( temp->right != NULL ){
                if( temp->right->value >= x )
                    break;
                temp = temp->right;
            }
            if( temp->right != NULL ){
                struct Tree *ptr = temp->right;
                return max( temp->value, prev( ptr, x ) );
            }
            return temp->value;
        }
    }
    //---//
    else if( temp->value < x ){
        while( temp->right != NULL ){
            if( temp->right->value >= x  )
                break;
            temp = temp->right;
        }
        if( temp->right != NULL ){
            struct Tree *ptr = temp->right;
            return max( temp->value, prev( ptr, x ) );
        }
        return temp->value;
    }
}
int next( struct Tree *node, int x ){
    if( node == NULL )
        return 1000000001;
    struct Tree *temp = node;
    if( temp->value == x ){
        if( temp->right == NULL )
            return 1000000001;
        temp = temp->right;
        return minimum( temp )->value;
    }
    //---//
    if( temp->value > x ){
        while( temp->left != NULL ){
            if( temp->left->value <= x )
                break;
            temp = temp->left;
        }
        if( temp->left != NULL ){
            struct Tree *ptr = temp->left;
            return min( temp->value, next( ptr, x ) );
        }
        return temp->value;
    }
    //---//
    else if( temp->value < x ){
        while( temp->value < x ){
            if( temp->right == NULL )
                return 1000000001;
            temp = temp->right;
        }
        if( temp->value == x ){
            if( temp->right == NULL )
                return 1000000001;
            temp = temp->right;
            return minimum( temp )->value;
        }
        if( temp->value > x ){
            while( temp->left != NULL ){
                if( temp->left->value <= x )
                    break;
                temp = temp->left;
            }
            if( temp->left != NULL ){
                struct Tree *ptr = temp->left;
                return min( temp->value, next( ptr, x ) );
            }
            return temp->value;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    freopen ( "bstsimple.in", "r", stdin );
    freopen ( "bstsimple.out", "w", stdout );
    string com;
    int x;
    while( cin >> com ){
        cin >> x;
        if( com == "insert" )
            mytree = insert( mytree, x );
        if( com == "exists" )
            cout << exists( mytree, x ) << "\n";
        if( com == "delete" )
            mytree = del( mytree, x );
        if( com == "prev" ){
            int k = prev( mytree, x );
            if( k == -1000000001 )
                cout << "none" << "\n";
            else
                cout << k << "\n";
        }
        if( com == "next" ){
            int k = next( mytree, x );
            if( k == 1000000001 )
                cout << "none" << "\n";
            else
                cout << k << "\n";
        }
    }
}