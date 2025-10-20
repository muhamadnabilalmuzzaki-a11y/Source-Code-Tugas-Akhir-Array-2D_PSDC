#include <iostream>
using namespace std;

struct Mahasiswa {
    int nim;
    string nama;
    Mahasiswa* left;
    Mahasiswa* right;
    Mahasiswa(int n, string nm) : nim(n), nama(nm), left(nullptr), right(nullptr) {}
};

Mahasiswa* insertData(Mahasiswa* root, int nim, string nama) {
    if (!root) return new Mahasiswa(nim, nama);
    if (nim < root->nim) root->left = insertData(root->left, nim, nama);
    else if (nim > root->nim) root->right = insertData(root->right, nim, nama);
    return root;
}

bool searchData(Mahasiswa* root, int nim) {
    if (!root) return false;
    if (root->nim == nim) return true;
    return nim < root->nim ? searchData(root->left, nim) : searchData(root->right, nim);
}

Mahasiswa* findMin(Mahasiswa* root) {
    while (root->left) root = root->left;
    return root;
}

Mahasiswa* deleteData(Mahasiswa* root, int nim) {
    if (!root) return nullptr;
    if (nim < root->nim) root->left = deleteData(root->left, nim);
    else if (nim > root->nim) root->right = deleteData(root->right, nim);
    else {
        if (!root->left) return root->right;
        else if (!root->right) return root->left;
        Mahasiswa* temp = findMin(root->right);
        root->nim = temp->nim;
        root->nama = temp->nama;
        root->right = deleteData(root->right, temp->nim);
    }
    return root;
}

void tampilkan(Mahasiswa* root) {
    if (!root) return;
    tampilkan(root->left);
    cout << "NIM: " << root->nim << " | Nama: " << root->nama << endl;
    tampilkan(root->right);
}

int main() {
    Mahasiswa* root = nullptr;
    int pilih, nim;
    string nama;

    do {
        cout << "\n=== SISTEM DATA MAHASISWA (BST) ===\n";
        cout << "1. Tambah Mahasiswa\n2. Cari Mahasiswa\n3. Hapus Mahasiswa\n4. Tampilkan Semua\n5. Keluar\n";
        cout << "Pilih: "; cin >> pilih;

        if (pilih == 1) {
            cout << "Masukkan NIM: "; cin >> nim;
            cout << "Masukkan Nama: "; cin.ignore(); getline(cin, nama);
            root = insertData(root, nim, nama);
        } 
        else if (pilih == 2) {
            cout << "Masukkan NIM yang dicari: "; cin >> nim;
            cout << (searchData(root, nim) ? "Mahasiswa ditemukan.\n" : "Mahasiswa tidak ditemukan.\n");
        } 
        else if (pilih == 3) {
            cout << "Masukkan NIM yang ingin dihapus: "; cin >> nim;
            root = deleteData(root, nim);
            cout << "Data berhasil dihapus (jika ada).\n";
        } 
        else if (pilih == 4) {
            cout << "\n=== Data Mahasiswa (Urut NIM) ===\n";
            tampilkan(root);
        }
    } while (pilih != 5);

    return 0;
}