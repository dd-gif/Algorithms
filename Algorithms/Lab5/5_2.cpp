#include <iostream>
#include <vector>
#include <cmath>
#define lli long long int
#define fiton for ( lli i = 0; i < n; i++ )
#define fjn for ( lli j = 0; j < n; j++ )
using namespace std;
vector<pair<string, string>>tab[100007]; 
int getHash( string key ){
    int hashFunc = 0, p = 1;
    for ( int i = 0; i < key.length() + 1; i++ ){
        hashFunc = hashFunc + p * ( int( key[i] ) - 101 ) % 100007;
        //hashFunc = hashFunc + 31 * int(key[i]);
        p = p * 7 % 100007;
    }
    return abs( hashFunc % 100007 );
}
string get( string key ){
    int index = getHash( key );
    for( int i = 0; i < tab[index].size(); i++ ){
        if( tab[index][i].first == key ){
            return tab[index][i].second;
        }
    }
    return "none";
}
void put( string value, string key ){
    string check = get( key );
    int index = getHash( key );
    if( check != "none" ){
        for( int i = 0; i < tab[index].size(); i++ ){
            if( tab[index][i].first == key ){
                tab[index][i].second = value;
                return;
            }
        }
    }
    else{
        tab[index].emplace_back( key, value );
    }
}
void deleteEl( string key ){
    int index = getHash( key );
    string check = get( key );
    if( check != "none" ){
        for( int i = 0; i < tab[index].size(); i++ ){
            if( !tab[index].empty() &&  tab[index][i].first == key ){
                swap( tab[index][i], tab[index][tab[index].size() - 1] );
                tab[index].pop_back();
                return;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    freopen ( "map.in", "r", stdin );
    freopen ( "map.out", "w", stdout );
    string s, key, value;
    while(cin >> s){
        cin >> key;
        if ( s == "put" ){
            cin >> value;
            put( value, key );
        }
        else if ( s == "delete" ){
            deleteEl( key );
        }
        else if ( s == "get" ){
            cout << get( key ) << endl;
        }
    }
    /*tab[1].emplace_back( "abs", "ooo" );
    int k = getHash( "abs" );
    cout << k << endl;
    cout << tab[1][0].first << " " << tab[1][0].second;*/
}