#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#define lli long long int
#define fiton for ( lli i = 0; i < n; i++ )
#define fjn for ( lli j = 0; j < n; j++ )
using namespace std;
struct List{
    int value;
    List *next = NULL, *prev = NULL;
} *chtoto = NULL, *t, *head;
void push( int x ){
    chtoto->value = x;
    chtoto->next = new List;
    t = chtoto;
    chtoto = chtoto->next;
    chtoto->next = NULL;
    chtoto->prev = t;
} 
void del(){
    t = head->next;
    head->next = head->next->next;
    head->next->prev = NULL;
    delete t;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    freopen ( "quack.in", "r", stdin );
    freopen ( "quack.out", "w", stdout );
    chtoto = new List;
    head = new List;
    head->next = chtoto;
    int x, y;
    int reg[26] = { 0 };
    string com;
    vector<string> coms;
    vector<pair<int, string>> labels;
    while( cin >> com ){
    	coms.push_back( com );
    	if( com[0] == ':' )
    		labels.emplace_back( coms.size() - 1, com.substr( 1 ) );
    }
 	for( int i = 0; i < coms.size(); i++ ){
 		if( coms[i] == "+" ){
 			x = head->next->value;
 			y = head->next->next->value;
 			del();
 			del();
 			push( ( uint16_t )( x + y ) );
 		}
 		else if( coms[i] == "-" ){
 			x = head->next->value;
 			y = head->next->next->value;
 			del();
 			del();
 			push( ( uint16_t )( x - y ) );
 		}
 		else if( coms[i] == "*" ){
 			x = head->next->value;
 			y = head->next->next->value;
 			del();
 			del();
 			push( ( uint16_t )( x * y ) );
 		}
 		else if( coms[i] == "/" ){
 			x = head->next->value;
 			y = head->next->next->value;
 			del();
 			del();
 			if( y == 0 )
 				push( 0 );
 			else
 				push( ( uint16_t )( x / y ) );
 		}
 		else if( coms[i] == "%"){
 			x = head->next->value;
 			y = head->next->next->value;
 			del();
 			del();
 			if( y == 0 )
 				push( 0 );
 			else
 				push( ( uint16_t )( x % y ) );
 		}
 		else if( coms[i][0] == '>' ){
 			x = head->next->value;
 			del();
 			reg[int( coms[i][1] ) - 97] = x;
 		} 
 		else if( coms[i][0] == '<' ){
 			push( reg[int( coms[i][1] ) - 97] );
 		}
 		else if( coms[i][0] == 'P' ){
 			if( coms[i].size() == 1 ){
 				x = head->next->value;
 				del();
 				cout << x << "\n";
 			}
 			else
 				cout << reg[int( coms[i][1] ) - 97] << "\n";
 		}
 		else if( coms[i][0] == 'C' ){
 			if( coms[i].size() == 1 ){
 				x = head->next->value;
 				del();
 				cout << ( char )( x % 256 );
 			}
 			else{
 				com = coms[i].substr( 1 );
 				cout << ( char )( reg[int( coms[i][1] ) - 97] );
 			}
 		}
 		else if( coms[i][0] == 'J' ){
 			com = coms[i].substr( 1 );
 			for( int j = 0; j < labels.size(); j++ ){
 				if( labels[j].second == com ){
 					i = labels[j].first;
 					break;
 				}
 			}
 		}
 		else if( coms[i][0] == 'Z' ){
 			com = coms[i].substr( 2 );
 			if( reg[int( coms[i][1] ) - 97] == 0 ){
 				for( int j = 0; j < labels.size(); j++ ){
 					if( labels[j].second == com ){
 						i = labels[j].first;
 						break;
 					}
 				}
 			}
 		}
 		else if( coms[i][0] == 'E' ){
 			com = coms[i].substr( 3 );
 			if( reg[int( coms[i][1] ) - 97] == reg[int( coms[i][2] ) - 97] ){
 				for( int j = 0; j < labels.size(); j++ ){
 					if( labels[j].second == com ){
 						i = labels[j].first;
 						break;
 					}
 				}
 			}
 		}
 		else if( coms[i][0] == 'G' ){
 			com = coms[i].substr( 3 );
 			if( reg[int( coms[i][1] ) - 97] > reg[int( coms[i][2] ) - 97] ){
 				for( int j = 0; j < labels.size(); j++ ){
 					if( labels[j].second == com ){
 						i = labels[j].first;
 						break;
 					}
 				}
 			}
 		}
 		else if( coms[i] == "Q" ){
 			return 0;
 		}
 		else if( coms[i][0] != ':' ){
            push( ( atoi( coms[i].c_str() ) % 65536 ) );
 		}
 	}
}