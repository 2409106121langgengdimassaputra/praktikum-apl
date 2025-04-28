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

// --- Fungsi Registrasi dan Login ---
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

// --- Fungsi CRUD ---
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

// --- Sorting Methods ---
// 1. Selection Sort (Sorting Nama Ascending)
void selectionSortNama(vector<DataUser>& daftar) {
    for (int i = 0; i < daftar.size() - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < daftar.size(); j++) {
            if (daftar[j].user.nama < daftar[minIndex].user.nama) {
                minIndex = j;
            }
        }
        swap(daftar[i], daftar[minIndex]);
    }
}

// 2. Merge Sort (Sorting Jumlah UC Descending)
void merge(vector<PembelianUC>& arr, int left, int mid, int right) {
    vector<PembelianUC> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    vector<PembelianUC> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i].jumlah > rightArr[j].jumlah) { // Descending
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }
    while (i < leftArr.size()) arr[k++] = leftArr[i++];
    while (j < rightArr.size()) arr[k++] = rightArr[j++];
}

void mergeSort(vector<PembelianUC>& arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// 3. Quick Sort (Sorting Harga Ascending)
int partition(vector<PembelianUC>& arr, int low, int high) {
    double pivot = arr[high].harga;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].harga < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<PembelianUC>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
                cout << "1. Tambah Pembelian UC\n2. Tampilkan Data\n3. Edit Pembelian\n4. Hapus Pembelian\n";
                cout << "5. Sorting Nama (Asc)\n6. Sorting Jumlah UC (Desc)\n7. Sorting Harga (Asc)\n8. Logout\nPilih: ";
                cin >> menuPilihan;

                switch (menuPilihan) {
                    case 1: tambahPembelian(&daftarUser[index]); break;
                    case 2: tampilkanData(daftarUser[index]); break;
                    case 3: editPembelian(&daftarUser[index]); break;
                    case 4: hapusPembelian(&daftarUser[index]); break;
                    case 5: selectionSortNama(daftarUser); cout << "Data user telah diurutkan berdasarkan Nama (Ascending).\n"; break;
                    case 6: mergeSort(daftarUser[index].pembelian, 0, daftarUser[index].pembelian.size() - 1); cout << "Data pembelian diurutkan berdasarkan Jumlah UC (Descending).\n"; break;
                    case 7: quickSort(daftarUser[index].pembelian, 0, daftarUser[index].pembelian.size() - 1); cout << "Data pembelian diurutkan berdasarkan Harga (Ascending).\n"; break;
                    case 8: cout << "Logout...\n"; break;
                    default: cout << "Pilihan tidak valid!\n";
                }
            } while (menuPilihan != 8);
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

