#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct User {
    string nama;
    string nim;
};

struct PembelianUC {
    int jumlah;
    double harga;
};

struct DataUser {
    User user;
    vector<PembelianUC> pembelian;
};

vector<DataUser> daftarUser;

void registrasiUser(vector<DataUser>* daftar) {
    DataUser newUser;
    cout << "\n--- Registrasi User ---\n";
    cout << "Masukkan Nama: "; cin.ignore(); getline(cin, newUser.user.nama);
    cout << "Masukkan NIM: "; cin >> newUser.user.nim;
    daftar->push_back(newUser);
    cout << "Registrasi berhasil! Silakan login.\n";
}

int loginUser(vector<DataUser>* daftar) {
    string nama, nim;
    int attempts = 3;
    while (attempts--) {
        cout << "\n--- Login ---\n";
        cout << "Masukkan Nama: "; cin.ignore(); getline(cin, nama);
        cout << "Masukkan NIM: "; cin >> nim;

        for (int i = 0; i < daftar->size(); i++) {
            if ((*daftar)[i].user.nama == nama && (*daftar)[i].user.nim == nim) {
                cout << "Login berhasil!\n";
                return i;
            }
        }
        cout << "Login gagal! Sisa percobaan: " << attempts << "\n";
    }
    return -1;
}

void tambahPembelian(DataUser* user) {
    PembelianUC pembelian;
    cout << "\nMasukkan jumlah UC yang ingin dibeli: ";
    cin >> pembelian.jumlah;
    pembelian.harga = pembelian.jumlah * 3000;
    user->pembelian.push_back(pembelian);
    cout << "Total harga: " << pembelian.harga << "\n";
}

void tampilkanData(const DataUser& user) {
    cout << "\n--- Data Pembelian ---\n";
    for (int i = 0; i < user.pembelian.size(); i++) {
        cout << i + 1 << ". Jumlah UC: " << user.pembelian[i].jumlah
             << ", Total Harga: " << user.pembelian[i].harga << "\n";
    }
}

void editPembelian(DataUser* user) {
    int index;
    cout << "\n--- Edit Pembelian ---\n";
    cout << "Masukkan nomor pembelian yang ingin diedit: ";
    cin >> index;
    if (index > 0 && index <= user->pembelian.size()) {
        cout << "Masukkan jumlah UC baru: ";
        cin >> (*user).pembelian[index - 1].jumlah;
        (*user).pembelian[index - 1].harga = (*user).pembelian[index - 1].jumlah * 3000;
        cout << "Data berhasil diperbarui!\n";
    } else {
        cout << "Nomor tidak valid!\n";
    }
}

void hapusPembelian(DataUser* user) {
    int index;
    cout << "\n--- Hapus Pembelian ---\n";
    cout << "Masukkan nomor pembelian yang ingin dihapus: ";
    cin >> index;
    if (index > 0 && index <= user->pembelian.size()) {
        user->pembelian.erase(user->pembelian.begin() + index - 1);
        cout << "Data berhasil dihapus!\n";
    } else {
        cout << "Nomor tidak valid!\n";
    }
}

int main() {
    int pilihan;
    while (true) {
        cout << "\n--- Sistem Multiuser ---\n";
        cout << "1. Registrasi\n2. Login\n3. Keluar\nPilih: ";
        cin >> pilihan;

        if (pilihan == 1) {
            registrasiUser(&daftarUser);
        } 
        else if (pilihan == 2) {
            int index = loginUser(&daftarUser);
            if (index == -1) {
                cout << "Anda telah gagal login 3 kali. Program berhenti.\n";
                break;
            }

            int menuPilihan;
            do {
                cout << "\n--- Menu ---\n";
                cout << "1. Tambah Pembelian UC\n2. Tampilkan Data\n3. Edit Pembelian\n4. Hapus Pembelian\n5. Logout\nPilih: ";
                cin >> menuPilihan;

                switch (menuPilihan) {
                    case 1: tambahPembelian(&daftarUser[index]); break;
                    case 2: tampilkanData(daftarUser[index]); break;
                    case 3: editPembelian(&daftarUser[index]); break;
                    case 4: hapusPembelian(&daftarUser[index]); break;
                    case 5: cout << "Logout...\n"; break;
                    default: cout << "Pilihan tidak valid!\n";
                }
            } while (menuPilihan != 5);
        } 
        else if (pilihan == 3) {
            cout << "Keluar...\n";
            break;
        } 
        else {
            cout << "Pilihan tidak valid!\n";
        }
    }

    return 0;
}

