#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

struct Node {
    string nim;
    string nama;
    Node* next;
};

int hashFunction(const string& nim) {
    int sum = 0;
    for (char c : nim)
        sum += c;
    return sum % SIZE;
}

void initTable(Node* table[]) {
    for (int i = 0; i < SIZE; i++)
        table[i] = nullptr;
}

void insert(Node* table[], const string& nim, const string& nama) {
    int index = hashFunction(nim);
    Node* newNode = new Node{nim, nama, table[index]};
    table[index] = newNode;
    cout << "Data mahasiswa berhasil ditambahkan.\n";
}

void search(Node* table[], const string& nim) {
    int index = hashFunction(nim);
    Node* cur = table[index];
    while (cur != nullptr) {
        if (cur->nim == nim) {
            cout << "Data ditemukan!\n";
            cout << "NIM  : " << cur->nim << endl;
            cout << "Nama : " << cur->nama << endl;
            return;
        }
        cur = cur->next;
    }
    cout << "Data dengan NIM " << nim << " tidak ditemukan.\n";
}

void removeData(Node* table[], const string& nim) {
    int index = hashFunction(nim);
    Node *cur = table[index], *prev = nullptr;
    while (cur != nullptr) {
        if (cur->nim == nim) {
            if (prev == nullptr)
                table[index] = cur->next;
            else
                prev->next = cur->next;
            delete cur;
            cout << "Data mahasiswa dengan NIM " << nim << " berhasil dihapus.\n";
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    cout << "Data dengan NIM " << nim << " tidak ditemukan.\n";
}

void display(Node* table[]) {
    cout << "\n=== Daftar Data Mahasiswa ===\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << ": ";
        Node* temp = table[i];
        while (temp != nullptr) {
            cout << "[" << temp->nim << " - " << temp->nama << "] -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
}

int main() {
    Node* table[SIZE];
    initTable(table);

    int pilihan;
    string nim, nama;

    do {
        cout << "\n=== MENU DATA MAHASISWA ===\n";
        cout << "1. Tambah data mahasiswa\n";
        cout << "2. Cari data mahasiswa\n";
        cout << "3. Hapus data mahasiswa\n";
        cout << "4. Tampilkan semua data\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "Masukkan NIM  : ";
                getline(cin, nim);
                cout << "Masukkan Nama : ";
                getline(cin, nama);
                insert(table, nim, nama);
                break;

            case 2:
                cout << "Masukkan NIM yang ingin dicari: ";
                getline(cin, nim);
                search(table, nim);
                break;

            case 3:
                cout << "Masukkan NIM yang ingin dihapus: ";
                getline(cin, nim);
                removeData(table, nim);
                break;

            case 4:
                display(table);
                break;

            case 5:
                cout << "Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 5);

    return 0;
    }

