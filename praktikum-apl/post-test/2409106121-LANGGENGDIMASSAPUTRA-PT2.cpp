#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Pesanan {
    int id;
    string nama_pembeli;
    int jumlah_uc;
    int total_harga;
};

// Array satu dimensi untuk menyimpan pesanan
vector<Pesanan> daftar_pesanan;
int id_pesanan = 1;

int main() {
    int role;
    do {
        cout << "\n===== Sistem Login =====" << endl;
        cout << "1. Login sebagai Admin" << endl;
        cout << "2. Masuk sebagai User" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih peran: ";
        cin >> role;

        if (role == 1) { // Admin harus login dulu
            string input_id, input_pw;
            int attempts = 0;
            
            // Sistem login admin (maksimal 3 percobaan)
            while (attempts < 3) {
                cout << "Masukkan Username Admin: ";
                cin >> input_id;
                cout << "Masukkan Password Admin: ";
                cin >> input_pw;

                if (input_id == "dimas" && input_pw == "121") { 
                    cout << "Login Admin berhasil!\n";
                    break;  // Berhasil login
                } else {
                    cout << "Username atau Password salah! Coba lagi.\n";
                    attempts++;
                }
            }
            
            if (attempts == 3) {
                cout << "Gagal login setelah 3 kali percobaan.\n";
                return 0; // Keluar dari program
            }

            // Menu Admin
            int pilihan;
            do {
                cout << "\n===== Menu Admin =====" << endl;
                cout << "1. Lihat Daftar Harga UC" << endl;
                cout << "2. Lihat Pesanan Pembeli" << endl;
                cout << "3. Logout" << endl;
                cout << "Pilih menu: ";
                cin >> pilihan;

                if (pilihan == 1) {
                    cout << "\nHarga UC PUBG:\n";
                    cout << "20 UC = Rp10.000\n";
                } else if (pilihan == 2) {
                    cout << "\nDaftar Pesanan Pembeli:\n";
                    if (daftar_pesanan.empty()) {
                        cout << "Belum ada pesanan.\n";
                    } else {
                        for (const auto &pesanan : daftar_pesanan) {
                            cout << "ID: " << pesanan.id 
                                 << " | Nama: " << pesanan.nama_pembeli
                                 << " | UC: " << pesanan.jumlah_uc
                                 << " | Total Harga: Rp" << pesanan.total_harga << endl;
                        }
                    }
                } else if (pilihan == 3) {
                    cout << "Logout berhasil!\n";
                } else {
                    cout << "Pilihan tidak valid!\n";
                }
            } while (pilihan != 3);
            
        } else if (role == 2) { // User langsung masuk tanpa login
            int pilihan;
            do {
                cout << "\n===== Menu User =====" << endl;
                cout << "1. Lihat Daftar Harga UC" << endl;
                cout << "2. Beli UC" << endl;
                cout << "3. Logout" << endl;
                cout << "Pilih menu: ";
                cin >> pilihan;

                if (pilihan == 1) {
                    cout << "\nHarga UC PUBG:\n";
                    cout << "20 UC = Rp10.000\n";
                } else if (pilihan == 2) {
                    int jumlah;
                    cout << "Masukkan jumlah UC yang ingin dibeli (kelipatan 20): ";
                    cin >> jumlah;
                    if (jumlah % 20 == 0) {
                        int total = (jumlah / 20) * 10000;
                        daftar_pesanan.push_back({id_pesanan++, "Pembeli", jumlah, total});
                        cout << "Pesanan berhasil! Total pembayaran: Rp" << total << endl;
                        cout << "Terima kasih telah membeli UC PUBG!\n";
                        break; // Keluar setelah transaksi selesai
                    } else {
                        cout << "Jumlah UC harus kelipatan 20!\n";
                    }
                } else if (pilihan == 3) {
                    cout << "Logout berhasil!\n";
                } else {
                    cout << "Pilihan tidak valid!\n";
                }
            } while (pilihan != 3);
        } else if (role == 3) {
            cout << "Terima kasih telah menggunakan sistem penjualan UC PUBG!\n";
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    } while (role != 3);

    return 0;
}
