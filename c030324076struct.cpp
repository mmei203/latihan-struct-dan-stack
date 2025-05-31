#include <iostream>
#include <string>
using namespace std;

struct mahasiswa
{
    string nim;
    string nama;
    string alamat;
    float ipk;
};

int main () {
    mahasiswa meisya;

    meisya.nim = "C030324076";
    meisya.nama = "Meisya Andaryani";
    meisya.alamat = "Jl.Padat karya No.22";
    meisya.ipk = 4;

    cout << meisya.nim<<"\n";
    cout << meisya.nama<<"\n";
    cout << meisya.alamat<<"\n";
    cout << meisya.ipk<<"\n";

    return 0;
}