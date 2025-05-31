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
    mahasiswa* namaku = &meisya;

    namaku->nim = "C030324076";
    namaku->nama = "Meisya Andaryani";
    namaku->alamat = "Jl.Padat karya No.22";
    namaku->ipk = 4;

    cout << namaku->nim << endl;
    cout << namaku->nama << endl;
    cout << namaku->alamat << endl;
    cout << namaku->ipk << endl;

    return 0;
}