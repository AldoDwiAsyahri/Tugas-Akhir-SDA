#include <iostream>
using namespace std;

// Implementasi antrian (queue) sederhana menggunakan array melingkar
class Antrian {
private:
    int* data;
    int kapasitas;
    int indeksDepan;
    int indeksBelakang;
    int jumlah;

public:
    // Konstruktor
    Antrian(int ukuran = 10) {
        kapasitas = ukuran;
        data = new int[kapasitas];
        indeksDepan = 0;
        indeksBelakang = -1;
        jumlah = 0;
    }

    // Destruktor
    ~Antrian() {
        delete[] data;
    }

    // Menambahkan elemen ke belakang antrian
    void masuk(int nilai) {
        if (penuh()) {
            cout << "Antrian penuh! Tidak dapat menambahkan " << nilai << "\n";
            return;
        }
        indeksBelakang = (indeksBelakang + 1) % kapasitas;
        data[indeksBelakang] = nilai;
        jumlah++;
        cout << nilai << " berhasil ditambahkan ke antrian." << endl;
    }

    // Mengeluarkan dan mengembalikan elemen di depan antrian
    int keluar() {
        if (kosong()) {
            cout << "Antrian kosong! Tidak ada elemen untuk dikeluarkan." << endl;
            return -1;
        }
        int nilaiDepan = data[indeksDepan];
        indeksDepan = (indeksDepan + 1) % kapasitas;
        jumlah--;
        cout << nilaiDepan << " berhasil dikeluarkan dari antrian." << endl;
        return nilaiDepan;
    }

    // Melihat elemen di depan tanpa mengeluarkannya
    int lihatDepan() const {
        if (kosong()) {
            cout << "Antrian kosong! Tidak ada elemen di depan." << endl;
            return -1;
        }
        return data[indeksDepan];
    }

    // Cek apakah antrian kosong
    bool kosong() const {
        return (jumlah == 0);
    }

    // Cek apakah antrian penuh
    bool penuh() const {
        return (jumlah == kapasitas);
    }

    // Mendapatkan jumlah elemen dalam antrian
    int ukuran() const {
        return jumlah;
    }
};

void tampilMenu() {
    cout << "\n=== MENU ANTRIAN ===" << endl;
    cout << "1. Tambah elemen (masuk)" << endl;
    cout << "2. Keluarkan elemen (keluar)" << endl;
    cout << "3. Lihat elemen depan" << endl;
    cout << "4. Lihat ukuran antrian" << endl;
    cout << "5. Cek antrian kosong/penuh" << endl;
    cout << "6. Keluar program" << endl;
    cout << "Pilihan: ";
}

int main() {
    cout << "=== Program Antrian Interaktif ===" << endl;
    int kapasitas;
    cout << "Masukkan kapasitas antrian: ";
    cin >> kapasitas;

    Antrian a(kapasitas);
    int pilihan;
    int nilai;

    do {
        tampilMenu();
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai yang akan ditambahkan: ";
                cin >> nilai;
                a.masuk(nilai);
                break;
            case 2:
                a.keluar();
                break;
            case 3:
                cout << "Elemen di depan: " << a.lihatDepan() << endl;
                break;
            case 4:
                cout << "Ukuran antrian: " << a.ukuran() << endl;
                break;
            case 5:
                cout << "Antrian " << (a.kosong() ? "kosong" : (a.penuh() ? "penuh" : "tidak kosong dan tidak penuh")) << endl;
                break;
            case 6:
                cout << "Keluar program. Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 6);

    return 0;
}

