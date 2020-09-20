#include <iostream>
#define lli long long int
#define fiton for ( lli i = 0; i < n; i++ )
#define fjn for ( lli j = 0; j < n; j++ )
using namespace std;
struct Queue{
    int value;
    Queue *next;
};
Queue *head;
Queue *tail;
void push ( Queue *temp ){
    tail->value = temp->value;
    tail->next = (Queue *)malloc(sizeof(Queue));
    tail = tail->next;
    tail->next = NULL;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen ("queue.in", "r", stdin); 
    freopen ("queue.out", "w", stdout); 
    head = (Queue *)malloc(sizeof(Queue));
    head->next = NULL;
    tail = head;
    Queue quas;
    int n, p;
    cin >> n;
    char c;
    fiton{
        cin >> c;
        if ( c == 43 ){
            cin >> p;
            quas.value = p;
            push ( &quas );
        }
        if ( c == 45 ){
            cout << head->value << endl;
            head = head->next;
        }
    }
}