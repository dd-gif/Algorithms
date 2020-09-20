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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen ("stack.in", "r", stdin); 
    freopen ("stack.out", "w", stdout); 
    head = (Stack *)malloc(sizeof(Stack));
    head->next = NULL;
    head->prev = NULL;
    tail = head;
    Stack steik;
    lli n, p;
    char c;
    cin >> n;
    fiton{
        cin >> c;
        if ( c == 43 ){
            cin >> p;
            steik.value = p;
            push ( &steik );
        }
        if ( c == 45 ){
            cout << tail->prev->value << endl;
            tail = tail->prev;
        }
    }
}