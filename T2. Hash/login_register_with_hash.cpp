#include <iostream>
#include <string>
#include <string.h>
#include <map>

using namespace std;

map<string, map<string, string>> akunData;

//Mohon maaf, saya terlanjur melakukan koding sendiri sehingga mungkin banyak yang berbeda dari yang Ibu tunjukkan di kelas
int hashFunction(string pssword) {
    long long int c = 1;
    int passLen = pssword.length();
   for (int i = 0; i<passLen; i++) {
    char a = pssword.at(i);
    int b = a;
    b = b*(i+1);
    c += b;
   }
   return c;
}

void rGister() {
    string uName, passw, meil;
    int N;

    cout << endl << "Hello User! to register, please create a username and password" << endl << "\nUsername: ";
    cin >> uName;
    cout << "Email: ";
    cin >> meil;
    cout << "Password: ";
    cin >> passw;

    string hashKey = to_string(hashFunction(passw));

    map<string, string> akunDetail;
    akunDetail["username"] = uName;
    akunDetail["email"] = meil;

    akunData[hashKey] = akunDetail;
    cout << endl <<"Register Berhasil!";
}

void loging() {
    string uname, passw, hashKey, real_name;
    cout << endl << "Masukkan Username: ";
    cin >> uname;
    cout << "Masukkan Password: ";
    cin >> passw;

    hashKey = to_string(hashFunction(passw));
    real_name = akunData[hashKey]["username"];

    if (akunData.find(hashKey) != akunData.end() && uname.compare(real_name) == 0) {
        cout << endl << endl << "Login Berhasil!\n" << endl << "Selamat Datang, " << akunData[hashKey]["username"];
        cout << endl << "Username: " << akunData[hashKey]["username"];
        cout << endl << "Email: " << akunData[hashKey]["email"] << endl;
    } else {
        cout << endl << endl << "Login Gagal!\nInvalid username/password." << endl;
    }
}

int main() {
    char menu_cho;
    while (true) {
        int chooze;
    cout << endl;
    cout << "+---------------+" << endl;
    cout << "Menu: " << endl << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "0. Exit" << endl;
    cout << "+---------------+" << endl << endl;
    cout << "Select Menu: ";
    cin >> chooze;

    switch(chooze) {
    case 1 :
        rGister();
        break;
    case 2 :
        loging();
        break;
    case 0 :
        return 0;
        break;
    }
        cout << "\n\nKembali ke Menu? (y/n) ";
        cin >> menu_cho;
        switch (menu_cho) {
        case 'y' :
            continue;
            break;
        case 'Y' :
            continue;
            break;
        default :
            return 0;
        }
    }
    return 0;
}
