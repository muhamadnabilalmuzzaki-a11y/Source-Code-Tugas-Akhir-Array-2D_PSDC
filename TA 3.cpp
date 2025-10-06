#include <iostream>
#include <string>
using namespace std;

int main() {
    string film[] = {"Avatar", "Venom", "Spiderman", "Joker", "Moana 2", "Frozen", "Inside Out 2"};
    const int n = sizeof(film) / sizeof(film[0]);

    string target;
    cout << "Masukkan judul film yang ingin dicari: ";
    getline(cin, target);

    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (film[i] == target) {
            pos = i;
            break;
        }
    }

    if (pos != -1)
        cout << "Film ditemukan di posisi ke-" << pos + 1 << endl;
    else
        cout << "Film tidak ada dalam daftar." << endl;

    return 0;
}