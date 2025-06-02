#include <iostream>
using namespace std;

// deklarasi
#define MAXSTACK 100

typedef int itemType;

typedef struct
{
    itemType Item[MAXSTACK];
    int count;
} stack;


// stack dimulai dari 0
void Initialize (stack *S) {
    S -> count = 0;
}


int full (stack *S){
    return (S -> count == MAXSTACK);
}

int empty (stack *S){
    return (S -> count == 0);
}

void pop (stack *S, itemType *x){
    if (S -> count == 0)
    {
        cout << "stack kosong";
    }
    else
    {
        --(S -> count);
        *x = S->Item[S->count];
    }
}

void push(stack *S, itemType x) {
    if (full(S)) {
        cout << "Stack penuh\n";
    } else {
        S->Item[S->count] = x;
        S->count++;
    }
}


// menambahkan PrintStack
void printStack(stack *S) {
    if (empty(S)) {
        cout << "Stack kosong\n";
        return;
    }

    cout << "Isi stack (dari atas ke bawah):\n";
    for (int i = S->count - 1; i >= 0; i--) {
        cout << S->Item[i] << endl;
    }
}

int main() {
    stack S;
    Initialize(&S);

    push(&S, 10);
    push(&S, 20);
    push(&S, 30);

    printStack(&S);

    return 0;
}
