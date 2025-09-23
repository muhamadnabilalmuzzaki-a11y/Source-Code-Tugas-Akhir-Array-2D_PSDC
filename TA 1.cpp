#include <iostream>
using namespace std;

int main() {
    // Nama mahasiswa
    string nama[3] = {"Nabil", "Almu", "Zzaki"};

    // Data presensi: 3 mahasiswa, 4 pertemuan
    int presensi[3][4] = {
        {1, 1, 1, 1},  // Nabil
        {1, 0, 1, 1},  // Almu 
        {0, 1, 1, 0}   // Zzaki
    };

    cout << "Data Presensi Mahasiswa (1 = Hadir, 0 = Tidak Hadir)\n\n";
    
    for (int i = 0; i < 3; i++) {
        int totalHadir = 0;
        cout << nama[i] << ": ";
        for (int j = 0; j < 4; j++) {
            cout << presensi[i][j] << " ";
            totalHadir += presensi[i][j];
        }
        cout << "| Total Hadir = " << totalHadir << endl;
    }

    return 0;
}
