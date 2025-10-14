#include <iostream>
#include <string>
#include <vector>
#include <memory> // Diperlukan untuk std::unique_ptr

using namespace std;

// Kelas Dasar Abstrak
class Animal {
public:
    // Virtual destructor default
    virtual ~Animal() = default;

    // 1. Pure Virtual Function (Kontrak untuk Overriding)
    // Memaksa setiap kelas turunan untuk menyediakan implementasi suara dasarnya.
    virtual string speak() const = 0;

    // 2. Overloaded Function (Polimorfisme Compile-Time)
    // Menyediakan fungsionalitas tambahan untuk mengulang suara.
    // Method ini tidak virtual, karena logikanya sama untuk semua hewan.
    string speak(int times) const {
        string out = "";
        // Memanggil method speak() virtual. Panggilan ini bersifat polimorfik.
        string sound = speak(); 
        for (int i = 0; i < times; ++i) {
            out += sound;
            // Tambahkan spasi jika bukan pengulangan terakhir
            if (i < times - 1) {
                out += ' ';
            }
        }
        return out;
    }
};

// Kelas Turunan 1
class Dog : public Animal {
public:
    // Override: Menyediakan implementasi spesifik untuk anjing
    string speak() const override {
        return "Woof";
    }
};

// Kelas Turunan 2
class Cat : public Animal {
public:
    // Override: Menyediakan implementasi spesifik untuk kucing
    string speak() const override {
        return "Meow";
    }
};

// Kelas Turunan 3
class Cow : public Animal {
public:
    // Override: Menyediakan implementasi spesifik untuk sapi
    string speak() const override {
        return "Moo";
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
        string t;
        cin >> t;

        // Cek apakah ada angka K setelah tipe hewan
        int k = 1; // Nilai default jika tidak ada K
        // cin.peek() melihat karakter berikutnya tanpa mengeluarkannya dari stream
        if (cin.peek() != '\n' && cin.peek() != EOF) {
            cin >> k;
        }

        // Mengelola objek secara polimorfik menggunakan unique_ptr
        unique_ptr<Animal> a;
        if (t == "DOG") {
            a = make_unique<Dog>();
        } else if (t == "CAT") {
            a = make_unique<Cat>();
        } else { // COW
            a = make_unique<Cow>();
        }

        // Panggilan fungsi berdasarkan ada atau tidaknya K
        // Jika k=1, panggil a->speak() (overridden virtual function)
        // Jika k>1, panggil a->speak(k) (overloaded non-virtual function)
        cout << (k == 1 ? a->speak() : a->speak(k)) << "\n";
    }
    
    return 0;
}