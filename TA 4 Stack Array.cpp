#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;
string st[MAX];
int topIdx = -1;

bool isEmpty() { 
    return topIdx == -1; 
}
bool isFull()  { 
    return topIdx == MAX - 1; 
}

void push(string x) {
    if (isFull()) { 
        cout << "Tumpukan film penuh!\n"; 
        return; 
    }
    st[++topIdx] = x;
    cout << "Film \"" << x << "\" berhasil ditambahkan!\n";
}

void pop() {
    if (isEmpty()) { 
        cout << "Tidak ada film untuk dihapus.\n"; 
        return; 
    }
    cout << "Film \"" << st[topIdx--] << "\" telah dihapus dari daftar.\n";
}

void peek() {
    if (isEmpty()) { 
        cout << "Belum ada film dalam daftar.\n"; 
        return; 
    }
    cout << "Film terakhir yang kamu tonton: " << st[topIdx] << '\n';
}

void display() {
    if (isEmpty()) { 
        cout << "Daftar film kosong.\n"; 
        return; 
    }
    cout << "Daftar film yang sudah kamu tonton (dari terakhir):\n";
    for (int i = topIdx; i >= 0; --i) {
        cout << i + 1 << ". " << st[i] << '\n';
    }
}

int main() {
    int pilih;
    string val;
    do {
        cout << "\n=== STACK FILM ===\n";
        cout << "1. Tambah film (Push)\n";
        cout << "2. Hapus film terakhir (Pop)\n";
        cout << "3. Lihat film terakhir (Peek)\n";
        cout << "4. Tampilkan semua film (Display)\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore(); 
        if (pilih == 1) {
            cout << "Masukkan judul film: ";
            getline(cin, val);
            push(val);
        }
        else if (pilih == 2) pop();
        else if (pilih == 3) peek();
        else if (pilih == 4) display();
    } while (pilih != 5);
    return 0;
}