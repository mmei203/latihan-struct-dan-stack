#include <iostream>
#include <string>
#include <limits> //untuk cin.ignore()
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

// fungsi pop
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

    cout << "tekan enter untuk kembali ke menu utama";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.get();
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
        cout << "\t 3. Tampilkan stack\n" ;
        cout << "\t 4. Keluar\n" ;
        cout << "pilih menu : " ;

        cin >> pilihan;

        switch (pilihan) {
        case 1:{
        string input;
        while (true) {
            cout << "Masukkan Nilai (Q untuk keluar dari push) : ";
            cin >> input;
            if (input == "Q" || input == "q" ) break;
            try {
                nilai = stoi(input);
                push(&S, nilai);
            }
            catch(...){
                cout << "input tidak valid. gunakan Q atau q untuk keluar.";
            }
            
            }
        }
        break;

        case 2:
            pop(&S, &nilai);
            break;

        case 3:
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            printStack(&S);
            break;

        case 4:
            cout << "keluar dari program";
            break;

        default:
            cout << "Pilihan tidak ada.";
            break;
        }

    }
    while (pilihan !=4);
    

    return 0;
}