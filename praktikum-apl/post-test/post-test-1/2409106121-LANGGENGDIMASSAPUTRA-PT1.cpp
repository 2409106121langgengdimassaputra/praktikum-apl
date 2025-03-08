#include <iostream>
using namespace std;

bool cekBilanganPrima(int angka) {
    if (angka < 2) return false;
    for (int i = 2; i * i <= angka; i++) {
        if (angka % i == 0) return false;
    }
    return true;
}

bool validasiKode(int angka) {
    return (angka > 100 && angka <= 99999);
}

bool cekPembagian(int angka) {
    return (angka % 6 == 0 && angka % 5 != 0);
}

int main() {
    string username, password;
    cout << "=== LOGIN ===\n";
    cout << "Username: ";
    getline(cin, username);
    cout << "Password: ";
    getline(cin, password);

    if (username != "Langgeng Dimas Saputra" || password != "2409106121") {
        cout << "Login gagal!\n";
        return 0;
    }

    int kode;
    do {
        cout << "\nMasukkan angka(bilangan bulat positif): ";
        cin >> kode;

        if (!validasiKode(kode)) {
            cout << "angka yang dimasukkan harus lebih dari 100 dan tidak lebih dari 99999!\n";
        }
    } while (!validasiKode(kode));

    int pilihan;
    do {
        cout << "\n=== MENU VERIFIKASI ===\n";
        cout << "1. Cek apakah angka bilangan prima\n";
        cout << "2. Cek apakah angka habis dibagi 2 dan 3 tetapi tidak 5\n";
        cout << "3. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                if (cekBilanganPrima(kode))
                    cout << "angka tersebut adalah bilangan prima.\n";
                else
                    cout << "angka tersebut bukan bilangan prima.\n";
                break;
            case 2:
                if (cekPembagian(kode))
                    cout << "angka tersebut bisa dibagi  .\n";
                else
                    cout << "angka tidak bisa di bagi 2 dan 3.\n";
                break;
            case 3:
                cout << "Keluar .\n";
                break;
            default:
                cout << "Opsi tidak valid, silakan pilih lagi!\n";
        }
    } while (pilihan != 3);

    return 0;
}


