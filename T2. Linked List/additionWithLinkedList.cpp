//Nama: Muhammad Afif
//NRP: 5027221032

#include <iostream>
#include <string>

using namespace std;

struct hslNode {
    int dgit;
    hslNode* lnjt;
};
struct hslList {
    int pnjgList;
    hslNode* kepala;
};

struct hslList iniList;

//linked list func
hslNode* newNode(int angka) {
    hslNode* Baru = new hslNode();
    Baru->dgit = angka;
    Baru->lnjt = NULL;
    return Baru;
}

void pushDpn(int angka) {
    hslNode* Baru = newNode(angka);
    if (iniList.kepala != NULL) {
        iniList.pnjgList++;
        Baru->lnjt = iniList.kepala;
    }
    iniList.kepala = Baru;
}

void printList() {
    if (iniList.pnjgList < 0) return;
    int digt;
    digt = iniList.kepala->dgit;
    cout << digt;

    iniList.kepala = iniList.kepala->lnjt;
    iniList.pnjgList--;
    printList();
}
//count func

//ini namanya main func
int main() {
    string angk1, angk2;
    char k;
    int panjang, hasil, temp, simpan, d1, d2, p1, p2;
    cout << "Masukkan angka besar 1: ";
    cin >> angk1;
    cout << "Masukkan angka besar 2: ";
    cin >> angk2;

    p1 = angk1.length();
    p2 = angk2.length();

    panjang = p1+1;
    if(angk1.length() < angk2.length()) {
        panjang = p2+1;
    }
    simpan = 0;
    for(int i=1; i<=panjang;i++) {
        if (p1 - i >= 0) {
            k = angk1[p1-i];
            d1 = stoi(&k);
        } else d1 = 0;

        if (p2 - i >= 0) {
            k = angk2[p2-i];
            d2 = stoi(&k);
        } else d2 = 0;

        temp = d1 + d2 + simpan;
        hasil = temp%10;
        simpan = temp/10;

        if (i == panjang && hasil == 0) {
            break;
        }
        pushDpn(hasil);
    }
    cout << endl << "Hasil Penjumlahan = ";
    printList();
    cout << endl;
    return 0;
}
