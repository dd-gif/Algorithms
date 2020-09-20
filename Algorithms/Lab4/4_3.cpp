#include <iostream>
#define lli long long int
#define fiton for ( lli i = 0; i < n; i++ )
#define fjn for ( lli j = 0; j < n; j++ )
using namespace std;
struct Stack{
    char value;
    Stack *next;
    Stack *prev;
};
Stack *head;
Stack *tail;
Stack *t;
void push ( Stack *temp ){
    tail->value = temp->value;
    tail->next = (Stack *)malloc(sizeof(Stack));
    t = tail;
    tail = tail->next;
    tail->prev = t;
    tail->next = NULL;
}
void lilpops (){
    tail = tail->prev;
    tail->value = NULL;
    tail->next = NULL;
}
void createStack(){
    head = (Stack *)malloc(sizeof(Stack));
    head->next = NULL;
    head->prev = NULL;
    tail = head;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen ("brackets.in", "r", stdin); 
    freopen ("brackets.out", "w", stdout); 
    Stack steik;
    string s;
    while ( getline(cin, s) ){
        createStack();
        for ( int i = 0; i < s.length(); i++ ){
            if ( s[i] == '(' || s[i] == '['){
                steik.value = s[i];
                push ( &steik );
            }
            else{
                if ( s[i] == ')' && head != tail && tail->prev->value == '(' )
                    lilpops();
                else if ( s[i] == ']' && head != tail && tail->prev->value == '[' )
                    lilpops();
                else if ( ( s[i] == ')' || s[i] == ']' ) && head == tail ){
                    steik.value = s[i];
                    push( &steik );
                    break;
                }
                else if ( s[i] == ')' && tail->prev->value =='[' || s[i] == ']' && tail->prev->value == '(' ){
                    steik.value = s[i];
                    push( &steik );
                    break;
                }
            }
        }
        if ( head == tail )
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
            
    }
}

