#include <iostream>
#include <string>

// Kelas untuk mengelola bahan bakar pesawat luar angkasa
class FuelTank {
private:
    // DATA MEMBER PRIBADI:
    // Tingkat bahan bakar disembunyikan dan dilindungi dari akses langsung. 
    long long fuel_level;

public:
    // Constructor untuk menginisialisasi tangki dengan bahan bakar awal. 
    FuelTank(long long initial_fuel) {
        fuel_level = initial_fuel;
    }

    // METHOD PUBLIK:
    // Antarmuka yang aman untuk berinteraksi dengan data pribadi.

    // Menambah bahan bakar ke tangki. 
    void refuel(long long x) {
        fuel_level += x;
    }

    // Menggunakan bahan bakar untuk perjalanan. 
    void travel(long long x) {
        // Logika perjalanan: hanya berhasil jika bahan bakar cukup. 
        // Ini memastikan aturan (invariant) bahwa bahan bakar tidak pernah negatif terpenuhi. 
        if (fuel_level >= x) {
            fuel_level -= x;
        }
        // Jika tidak cukup, perintah diabaikan sesuai permintaan. 
    }

    // Mengembalikan tingkat bahan bakar saat ini. 
    long long report() const {
        return fuel_level;
    }
};

// Fungsi utama program
int main() {
    // Optimasi input/output
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long initial_fuel;
    int Q;
    // Membaca input awal 
    std::cin >> initial_fuel >> Q;

    // Membuat satu objek FuelTank. 
    FuelTank tank(initial_fuel);

    // Loop untuk memproses semua perintah 
    for (int i = 0; i < Q; ++i) {
        std::string command;
        long long x;
        std::cin >> command >> x; // Membaca perintah dan nilainya [cite: 1]

        // Memanggil method publik berdasarkan perintah.
        // TIDAK ADA AKSES LANGSUNG ke variabel fuel_level dari main. 
        if (command == "REFUEL") {
            tank.refuel(x);
        } else if (command == "TRAVEL") {
            tank.travel(x);
        } else if (command == "REPORT") {
            // Untuk setiap perintah REPORT, cetak hasilnya. 
            std::cout << tank.report() << std::endl;
        }
    }

    return 0;
}