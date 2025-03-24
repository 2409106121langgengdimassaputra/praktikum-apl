#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Struct untuk menyimpan data user
struct User {
    string nama;
    string nim;
};

// Struct untuk data pembelian UC
struct PembelianUC {
    int jumlah;
    double harga;
};

// Struct utama yang menggabungkan semua data
struct DataUser {
    User user;
    vector<PembelianUC> pembelian;
};

vector<DataUser> daftarUser;

int main() {
    int pilihan;
    while (true) {
        cout << "\n--- Sistem Multiuser ---\n";
        cout << "1. Registrasi\n2. Login\n3. Keluar\nPilih: ";
        cin >> pilihan;
        
        if (pilihan == 1) {
            DataUser newUser;
            cout << "\n--- Registrasi User ---\n";
            cout << "Masukkan Nama: "; cin.ignore(); getline(cin, newUser.user.nama);
            cout << "Masukkan NIM: "; cin >> newUser.user.nim;
            daftarUser.push_back(newUser);
            cout << "Registrasi berhasil! Silakan login.\n";
        } 
        else if (pilihan == 2) {
            string nama, nim;
            int attempts = 3, userIndex = -1;
            while (attempts--) {
                cout << "\n--- Login ---\n";
                cout << "Masukkan Nama: "; cin.ignore(); getline(cin, nama);
                cout << "Masukkan NIM: "; cin >> nim;
                
                for (int i = 0; i < daftarUser.size(); i++) {
                    if (daftarUser[i].user.nama == nama && daftarUser[i].user.nim == nim) {
                        userIndex = i;
                        cout << "Login berhasil!\n";
                        break;
                    }
                }
                if (userIndex != -1) break;
                cout << "Login gagal! Sisa percobaan: " << attempts << "\n";
            }
            if (userIndex == -1) {
                cout << "Anda telah gagal login 3 kali. Program berhenti.\n";
                return 0;
            }
            
            int menuPilihan;
            do {
                cout << "\n--- Menu ---\n";
                cout << "1. Tambah Pembelian UC\n2. Tampilkan Data\n3. Edit Pembelian\n4. Hapus Pembelian\n5. Logout\nPilih: ";
                cin >> menuPilihan;
                
                if (menuPilihan == 1) {
                    PembelianUC pembelian;
                    cout << "\nMasukkan jumlah UC yang ingin dibeli: ";
                    cin >> pembelian.jumlah;
                    pembelian.harga = pembelian.jumlah * 3000; // Harga 1 UC = 3000
                    cout << "Total harga: " << pembelian.harga << "\n";
                    daftarUser[userIndex].pembelian.push_back(pembelian);
                } 
                else if (menuPilihan == 2) {
                    cout << "\n--- Data Pembelian ---\n";
                    for (int i = 0; i < daftarUser[userIndex].pembelian.size(); i++) {
                        cout << i + 1 << ". Jumlah UC: " << daftarUser[userIndex].pembelian[i].jumlah
                             << ", Total Harga: " << daftarUser[userIndex].pembelian[i].harga << "\n";
                    }
                } 
                else if (menuPilihan == 3) {
                    int index;
                    cout << "\n--- Edit Pembelian ---\n";
                    cout << "Masukkan nomor pembelian yang ingin diedit: "; cin >> index;
                    if (index > 0 && index <= daftarUser[userIndex].pembelian.size()) {
                        cout << "Masukkan jumlah UC baru: "; cin >> daftarUser[userIndex].pembelian[index - 1].jumlah;
                        daftarUser[userIndex].pembelian[index - 1].harga = daftarUser[userIndex].pembelian[index - 1].jumlah * 3000;
                        cout << "Data berhasil diperbarui!\n";
                    } else {
                        cout << "Nomor tidak valid!\n";
                    }
                }
                else if (menuPilihan == 4) {
                    int index;
                    cout << "\n--- Hapus Pembelian ---\n";
                    cout << "Masukkan nomor pembelian yang ingin dihapus: "; cin >> index;
                    if (index > 0 && index <= daftarUser[userIndex].pembelian.size()) {
                        daftarUser[userIndex].pembelian.erase(daftarUser[userIndex].pembelian.begin() + index - 1);
                        cout << "Data berhasil dihapus!\n";
                    } else {
                        cout << "Nomor tidak valid!\n";
                    }
                }
                else if (menuPilihan == 5) {
                    cout << "Logout...\n";
                    break;
                }
                else {
                    cout << "Pilihan tidak valid!\n";
                }
            } while (true);
        } 
        else if (pilihan == 3) {
            cout << "Keluar...\n";
            return 0;
        } 
        else {
            cout << "Pilihan tidak valid!\n";
        }
    }
}

