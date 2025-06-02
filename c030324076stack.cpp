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
        cout << "stack kosong\n";
    }
    else
    {
        --(S -> count);
        *x = S->Item[S->count];
        cout << "elemen" << *x << "berhasil dihapus dari stack";
    }
}

// fungsi push
void push(stack *S, itemType x) {
    if (full(S)) {
        cout << "Stack penuh\n";
    } else {
        S->Item[S->count] = x;
        S->count++;
        // penambahan cout
        cout << "Elemen " << x << " berhasil ditambahkan ke stack.\n";
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

    int pilihan;
    itemType nilai;

    do {
        cout << "\n Menu Stack \n";
        cout << "\t 1. Push (menambahkan nilai stack)\n" ;
        cout << "\t 2. Pop (menghapus nilai stack)\n" ;
        cout << "\t 3. Keluar\n" ;
        cout << "pilih menu : " ;

        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            cout << "Masukkan Nilai : ";
            cin >> nilai;
            push(&S, nilai);
            break;

        case 2:
            pop(&S, &nilai);
            break;

        case 3:
            cout << "keluar dari program";
            break;

        default:
            cout << "Pilihan tidak ada.";
            break;
        }

    }
    while (pilihan !=3);
    

    return 0;
}