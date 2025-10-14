#include <iostream>
#include <string>
#include <vector>
#include <memory> // Diperlukan untuk std::unique_ptr

using namespace std;

// Kelas Dasar Abstrak (Blueprint)
class Transport {
public:
    // Virtual destructor default
    virtual ~Transport() = default;

    // Pure virtual function, memaksa kelas turunan untuk mengimplementasikannya.
    // Ini adalah "kontrak" bahwa setiap jenis Transportasi harus tahu cara menghitung biayanya.
    virtual int fare(int d) const = 0;
};

// Kelas Turunan 1
class Car : public Transport {
public:
    // Override: Menyediakan implementasi spesifik untuk Mobil
    int fare(int d) const override {
        return 100 + 10 * d;
    }
};

// Kelas Turunan 2
class Bus : public Transport {
public:
    // Override: Menyediakan implementasi spesifik untuk Bus
    int fare(int d) const override {
        return 50 + 8 * d;
    }
};

// Kelas Turunan 3
class Train : public Transport {
public:
    // Override: Menyediakan implementasi spesifik untuk Kereta
    int fare(int d) const override {
        if (d <= 50) {
            // Rumus untuk jarak 50 km pertama
            return 200 + 3 * d;
        } else {
            // Rumus untuk jarak di atas 50 km
            // Biaya untuk 50 km pertama + biaya untuk sisa jaraknya
            return 200 + (3 * 50) + (2 * (d - 50));
        }
    }
};

// Fungsi utama
int main() {
    // Optimasi input/output C++
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;
    while (Q--) {
        string type;
        int d;
        cin >> type >> d;

        // Mengelola objek secara polimorfik menggunakan unique_ptr
        unique_ptr<Transport> t;
        if (type == "CAR") {
            t = make_unique<Car>();
        } else if (type == "BUS") {
            t = make_unique<Bus>();
        } else { // TRAIN
            t = make_unique<Train>();
        }

        // Panggilan polimorfik:
        // C++ akan secara otomatis memanggil versi 'fare' yang benar
        // (Car, Bus, atau Train) tergantung pada objek aslinya.
        cout << t->fare(d) << "\n";
    }
    return 0;
}