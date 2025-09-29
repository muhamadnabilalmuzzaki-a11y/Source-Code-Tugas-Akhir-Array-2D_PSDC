#include <iostream>
using namespace std;

int main() {
    int n;
    int tinggi[200];

    cout << "Masukkan jumlah atlet: ";
    cin >> n;

    cout << "Masukkan tinggi badan atlet:\n";
    for (int i = 0; i < n; i++) {
        cout << "Tinggi atlet ke-" << i + 1 << " (cm): ";
        cin >> tinggi[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tinggi[j] < tinggi[j + 1]) {                                            // Descending: tukar jika kiri < kanan
                int temp = tinggi[j];
                tinggi[j] = tinggi[j + 1];
                tinggi[j + 1] = temp;
            }
        }
    }

    cout << "\nTinggi badan atlet setelah diurutkan:\n";
    for (int i = 0; i < n; i++) {
        cout << "Posisi " << i + 1 << ": " << tinggi[i] << " cm" << endl;
    }

    return 0;
}