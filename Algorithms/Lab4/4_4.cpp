#include <iostream>
#define lli long long int
#define fiton for ( lli i = 0; i < n; i++ )
#define fjn for ( lli j = 0; j < n; j++ )
using namespace std;
struct Stack{
    int value;
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
int lilpops (){
    if (tail == head )
        return -1;
    tail = tail->prev;
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
    freopen ("postfix.in", "r", stdin);
    freopen ("postfix.out", "w", stdout);
    createStack();
    Stack steik;
    string s;
    int charToint, k, l;
    getline ( cin, s );
    for ( int i = 0; i < s.length(); i++ ){
        if ( s[i] == 32 )
            continue;
        if ( s[i] >= 48 && s[i] <= 57 ){
            charToint = static_cast<int>(s[i]) - 48;
            steik.value = charToint;
            push ( &steik );
        }
        if ( s[i] == '+' ){
            tail->prev->prev->value = tail->prev->value + tail->prev->prev->value;
            tail = tail->prev;
        }
        if ( s[i] == '-' ){
            tail->prev->prev->value = tail->prev->prev->value - tail->prev->value;
            tail = tail->prev;
        }
        if ( s[i] == '*' ){
            tail->prev->prev->value = tail->prev->value * tail->prev->prev->value;
            tail = tail->prev;
        }
    }
    cout << head->value;
}