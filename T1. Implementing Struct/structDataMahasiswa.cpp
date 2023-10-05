//Nama: Muhammad Afif
//NRP: 5027221032

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

struct data {
    string nama;
    string nrp;
    int umur;
    bool kelamin;
};
const int max_amount = 20;
struct data mahasiswa[max_amount];

//menggeser data jika ada data yang kosong
int geser(int A) {
    for (A; A<max_amount; A++) {
        if (A >= 0 && mahasiswa[A].nama.empty() && !mahasiswa[A+1].nama.empty()) {

            mahasiswa[A].nama = mahasiswa[A+1].nama;
            mahasiswa[A].nrp = mahasiswa[A+1].nrp;
            mahasiswa[A].umur = mahasiswa[A+1].umur;
            mahasiswa[A].kelamin = mahasiswa[A+1].kelamin;

            mahasiswa[A+1].nama.erase();
            mahasiswa[A+1].nrp.erase();
            mahasiswa[A+1].umur = 0;
            mahasiswa[A+1].kelamin = 0;
        } else if (A <= 0) {
            break;
        }
    }
    return 0;
}

//fungsi manipulasi data struct
void aplikasi () {
    int input_menu;
    char choice;

    cout << "\n================\n" << endl;
    cout << "Pilih Menu: \n" << endl;
    cout << "1. Menambah data" << endl;
    cout << "2. Menghapus data" << endl;
    cout << "3. Mengubah data" << endl;
    cout << "4. Menampilkan semua data" << endl;
    cout << "0. Keluar" << endl << endl;
    cout << "Masukkan input: ";

    cin >> input_menu;

    switch (input_menu) {
    case 0 :
        break;

    case 1 :
        for (int i = 0; i< max_amount; i++) {
            if (mahasiswa[i].nama.empty()) {
                cout << "\nMasukkan nama mahasiswa: ";
                cin >> mahasiswa[i].nama;
                cout << "Masukkan NRP mahasiswa: ";
                cin >> mahasiswa[i].nrp;
                cout << "Masukkan umur mahasiswa: ";
                cin >> mahasiswa[i].umur;
                cout << "Masukkan kelamin mahasiswa: ";
                cin >> mahasiswa[i].kelamin;
                cout << endl << "Data berhasil ditambahkan!\n" << endl;
                break;
            } else if (i == max_amount-1) {
                cout << endl << "Data sudah penuh!\n" << endl;
                break;
            }
        }

        cout << "\nKembali ke Menu?[y/n]: ";
        cin >> choice;
        switch (choice) {
        case 'y' :
            aplikasi();
            break;
        case 'n' :
            break;
        }
        break;

    case 2 :
        int del_choice;
        cout << "\nPilih data mahasiswa yang akan dihapus: ";
        for (int i = 0; i<max_amount; i++) {
            if (!mahasiswa[i].nama.empty()) {
                cout << endl << i+1 << ". " << mahasiswa[i].nama;
            }
        }
        cout << "\nMasukkan Input (tekan 0 untuk kembali ke menu awal): ";
        cin >> del_choice;

        if (del_choice == 0) {
            aplikasi ();
            break;
        }

        del_choice--;


        if (!mahasiswa[del_choice].nama.empty()) {

            cout << "\nData mahasiswa " << mahasiswa[del_choice].nama << " telah berhasil dihapus!\n";

            mahasiswa[del_choice].nama.erase();
            mahasiswa[del_choice].nrp.erase();
            mahasiswa[del_choice].umur = 0;
            mahasiswa[del_choice].kelamin = 0;

            geser(del_choice);


            cout << "\nKembali ke Menu?[y/n]: ";
            cin >> choice;
            switch (choice) {
            case 'y' :
                aplikasi();
                break;
            case 'n' :
                break;
            }
        } else {
            cout << "\nData mahasiswa tidak ditemukan\n";

            cout << "\nKembali ke Menu?[y/n]: ";
            cin >> choice;
            switch (choice) {
            case 'y' :
                aplikasi();
                break;
            case 'n' :
                break;
            }
        }
        break;

    case 3 :
        int change_choice;
        cout << "\nPilih data mahasiswa yang akan diubah: ";
        for (int i = 0; i<max_amount; i++) {
            if (!mahasiswa[i].nama.empty()) {
                cout << endl << i+1 << ". " << mahasiswa[i].nama;
            }
        }
        cout << "\nMasukkan Input (tekan 0 untuk kembali ke menu awal): ";
        cin >> change_choice;
        if (change_choice == 0) {
            aplikasi();
            break;
        }

        change_choice--;

        if (!mahasiswa[change_choice].nama.empty()) {
            cout << "\nMasukkan nama baru mahasiswa: ";
            cin >> mahasiswa[change_choice].nama;
            cout << "Masukkan NRP baru mahasiswa: ";
            cin >> mahasiswa[change_choice].nrp;
            cout << "Masukkan umur baru mahasiswa: ";
            cin >> mahasiswa[change_choice].umur;
            cout << "Masukkan kelamin baru mahasiswa: ";
            cin >> mahasiswa[change_choice].kelamin;
            cout << endl << "\nData berhasil diubah!\n" << endl;
        } else {
            cout << "\nData mahasiswa tidak tersedia\n";
        }

        cout << "\nKembali ke Menu?[y/n]: ";
        cin >> choice;
        switch (choice) {
            case 'y' :
                aplikasi();
                break;
            case 'n' :
                break;
        }

        break;

    case 4 :
        cout << "\n========================";
        cout << "\n||Data Semua Mahasiswa||\n";
        cout << "========================\n" << endl;
        for (int i = 0; i<max_amount; i++) {
            if(!mahasiswa[i].nama.empty()) {
                cout << "Mahasiswa " << i+1 << ": \n" << endl;
                cout << "Nama: " << mahasiswa[i].nama << endl;
                cout << "NRP: " << mahasiswa[i].nrp << endl;
                cout << "Umur: " << mahasiswa[i].umur << endl;
                cout << "Kelamin: " << (mahasiswa[i].kelamin ? "Laki-laki" : "Perempuan") << endl;
                cout << "\n========================\n" << endl;
            }
        }

        cout << "\nKembali ke Menu?[y/n]: ";
        cin >> choice;
        switch (choice) {
            case 'y' :
                aplikasi();
                break;
            case 'n' :
                break;
        }

        break;



    }
}

int main () {

    //memasukkan data tambahan
    int L = 0;
    mahasiswa[L].nama = "Hadi";
    mahasiswa[L].nrp = "5027221069";
    mahasiswa[L].umur = 17;
    mahasiswa[L].kelamin = 1;
    L++;

    mahasiswa[L].nama = "Shanti";
    mahasiswa[L].nrp = "5027221087";
    mahasiswa[L].umur = 18;
    mahasiswa[L].kelamin = 0;
    L++;

    mahasiswa[L].nama = "Budi";
    mahasiswa[L].nrp = "5027221032";
    mahasiswa[L].umur = 19;
    mahasiswa[L].kelamin = 1;
    L++;

    mahasiswa[L].nama = "Aji";
    mahasiswa[L].nrp = "5027221050";
    mahasiswa[L].umur = 20;
    mahasiswa[L].kelamin = 1;
    L++;

    mahasiswa[L].nama = "Mira";
    mahasiswa[L].nrp = "5027221029";
    mahasiswa[L].umur = 18;
    mahasiswa[L].kelamin = 0;
    L++;

    mahasiswa[L].nama = "Ao";
    mahasiswa[L].nrp = "5027221028";
    mahasiswa[L].umur = 18;
    mahasiswa[L].kelamin = 0;
    L++;

    mahasiswa[L].nama = "Hantu";
    mahasiswa[L].nrp = "5027221099";
    mahasiswa[L].umur = 100;
    mahasiswa[L].kelamin = 1;
    L++;

    mahasiswa[L].nama = "Budyi";
    mahasiswa[L].nrp = "5027221051";
    mahasiswa[L].umur = 19;
    mahasiswa[L].kelamin = 1;
    L++;

    mahasiswa[L].nama = "Kucing";
    mahasiswa[L].nrp = "5027221072";
    mahasiswa[L].umur = 90;
    mahasiswa[L].kelamin = 0;
    L++;

    mahasiswa[L].nama = "sateKelinci";
    mahasiswa[L].nrp = "5027221100";
    mahasiswa[L].umur = 29;
    mahasiswa[L].kelamin = 1;
    L++;

    aplikasi();

    return 0;
}
