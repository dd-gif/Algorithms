#include <iostream>
#include <cmath>
#define lli long long int
#define fiton for ( lli i = 0; i < n; i++ )
#define fjn for ( lli j = 0; j < n; j++ )
using namespace std;
struct List{
    int value;
    List *next;
    List *prev;
};
List *a[1000007], *t;
void goToTheEnd( int index ){
    while ( a[index]->next != NULL )
        a[index] = a[index]->next;
}
void createHash(){
    for ( int i = 0; i < 1000007; i++ ){
        a[i] = (List*)malloc(sizeof(List));
        a[i]->next = NULL;
        a[i]->prev = NULL;
    }
}
int exists( int value, int index ){
    if ( a[index]->prev == NULL ){
        goToTheEnd( index );
        return 0;
    }
    while ( a[index]->prev != NULL ){
        if ( a[index]->prev->value == value ){
            goToTheEnd( index );
            return 1;
        }
        else 
            a[index] = a[index]->prev;
    }
    goToTheEnd( index );
    return 0;
}
void insert( List *temp, int index ){
    bool isHere = exists( temp->value, index );
    if ( isHere == 0 ){
        a[index]->next = (List*)malloc(sizeof(List));
        a[index]->value = temp->value;
        t = a[index];
        a[index] = a[index]->next;
        a[index]->prev = t;
        a[index]->next = NULL;        
    }
}
void deleteEl( int value, int index ){
    bool isHere = exists( value, index );
    if ( isHere == 1 ){
        while ( a[index]->prev != NULL ){
            if ( a[index]->prev->value == value ){
                if ( a[index]->prev->prev == NULL ){
                    a[index]->prev = NULL;
                    goToTheEnd( index );
                    break;
                }
                else{
                    a[index]->prev->prev->next = a[index];
                    a[index]->prev = a[index]->prev->prev;
                    goToTheEnd( index );
                    break;
                }
            }
            else{
                a[index] = a[index]->prev;
            }
        }
    }
}
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
    freopen ( "set.in", "r", stdin );
    freopen ( "set.out", "w", stdout );
    createHash();
    string s;
    List hash;
    int value, index;
    while ( cin >> s ){
        cin >> value;
        index = abs( value % 100019 );
        if ( s == "insert" ){
            hash.value = value;
            insert( &hash, index );
        }
        if ( s == "delete" ){
            deleteEl ( value, index );
        }
        if ( s == "exists" ){
            bool check = exists( value, index );
            if ( check == 0 )
                cout << "false" << endl;
            else
                cout << "true" << endl;
        }
    }
}