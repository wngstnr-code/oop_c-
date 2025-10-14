#include <iostream>
#include <string>
#include <vector>
#include <memory> // Diperlukan untuk std::unique_ptr dan std::make_unique

using namespace std;

// Kelas Dasar (Parent Class)
// Bertindak sebagai blueprint untuk semua jenis karyawan.
class Employee {
protected:
    string name;

public:
    // Constructor untuk inisialisasi nama
    Employee(string name) : name(move(name)) {}
    // Virtual destructor (praktik yang baik untuk kelas dasar)
    virtual ~Employee() = default;

    // Pure virtual function, memaksa kelas turunan untuk mengimplementasikannya.
    // Ini adalah "kontrak" bahwa setiap Karyawan harus tahu cara menghitung gajinya.
    virtual int salary() const = 0; 

    // Getter untuk nama, diwarisi oleh semua kelas turunan.
    string getName() const { return name; }
};

// Kelas Turunan 1: Karyawan Penuh Waktu
class FullTime : public Employee {
private:
    int baseSalary;
    int bonus;

public:
    // Constructor yang memanggil constructor kelas dasar (Employee)
    FullTime(string name, int baseSalary, int bonus)
        : Employee(move(name)), baseSalary(baseSalary), bonus(bonus) {}

    // Implementasi spesifik perhitungan gaji untuk karyawan FullTime.
    int salary() const override {
        return baseSalary + bonus;
    }
};

// Kelas Turunan 2: Karyawan Paruh Waktu
class PartTime : public Employee {
private:
    int hourlyRate;
    int hours;

public:
    // Constructor yang memanggil constructor kelas dasar (Employee)
    PartTime(string name, int hourlyRate, int hours)
        : Employee(move(name)), hourlyRate(hourlyRate), hours(hours) {}

    // Implementasi spesifik perhitungan gaji untuk karyawan PartTime.
    int salary() const override {
        return hourlyRate * hours;
    }
};

// Fungsi utama
int main() {
    // Optimasi input/output C++
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    // Menggunakan vector dari unique_ptr untuk mengelola berbagai jenis karyawan secara polimorfik.
    // Ini adalah cara modern dan aman untuk menangani objek yang dibuat secara dinamis.
    vector<unique_ptr<Employee>> employees;

    while (Q--) {
        string type;
        cin >> type;
        if (type == "FULLTIME") {
            string n;
            int base, bonus;
            cin >> n >> base >> bonus;
            // Membuat objek FullTime dan menyimpannya sebagai pointer Employee
            employees.push_back(make_unique<FullTime>(n, base, bonus));
        } else { // PARTTIME
            string n;
            int rate, hours;
            cin >> n >> rate >> hours;
            // Membuat objek PartTime dan menyimpannya sebagai pointer Employee
            employees.push_back(make_unique<PartTime>(n, rate, hours));
        }
    }

    // Mencetak hasil secara polimorfik.
    // Loop ini tidak perlu tahu apakah 'e' adalah FullTime atau PartTime.
    // Panggilan e->salary() akan secara otomatis menjalankan versi yang benar.
    for (const auto& e : employees) {
        cout << e->getName() << ": " << e->salary() << "\n";
    }

    return 0;
}