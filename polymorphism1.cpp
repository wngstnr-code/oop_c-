#include <iostream>
#include <vector>

using namespace std;

class Bentuk {
public:
    virtual double hitungLuas() = 0;
    virtual~Bentuk() {}
};

class Lingkaran : public Bentuk {
private:
    double radius;

public:
    Lingkaran(double r) : radius(r) {}

    double hitungLuas() override {
        return 3.14159 * radius * radius;
    }
};

class Persegi : public Bentuk {
private:
    double sisi;

public:
    Persegi(double s) : sisi(s) {}

    double hitungLuas() override {
        return sisi*sisi;
    }
};

void cetakInfoBentuk(Bentuk* bentuk){
    cout << "Luas dari bentuk ini adalah " << bentuk->hitungLuas() << endl;
}

int main() {
    Lingkaran lingkaran1(14.0);
    Persegi persegi1(8.0);

    cout << "--- Memanggil fungsi polimorfik secara langsung ---" << endl;
    cout << "Luas Lingkaran: " << lingkaran1.hitungLuas() << endl;
    cout << "Luas Persegi: " << persegi1.hitungLuas() << endl;

    cout << "\n--- Menggunakan Vector Polimorfik ---" << endl;
    vector<Bentuk*> semuaBentuk;
    semuaBentuk.push_back(new Lingkaran(7.0));
    semuaBentuk.push_back(new Persegi(5.0));
    semuaBentuk.push_back(new Lingkaran (21.0));

    for (Bentuk* b : semuaBentuk) {
        b->hitungLuas();
        cetakInfoBentuk(b);
    }

    for (Bentuk* b : semuaBentuk) {
        delete b;
    }

    return 0;
}
//1. Pointer Ajaib (Bentuk*): Kunci dari polimorfisme ada pada pointer ke kelas induk (Bentuk*). Variabel pointer ini bisa "memegang" alamat dari objek anak mana pun (Lingkaran, Persegi).
//2. Fungsi cetakInfoBentuk(Bentuk* bentuk): Fungsi ini adalah contoh sempurna dari polimorfisme.
//      - Ia tidak tahu dan tidak peduli apakah bentuk yang masuk adalah Lingkaran atau Persegi.
//      -Ketika baris bentuk->hitungLuas() dieksekusi, C++ secara cerdas akan memeriksa "Oh, objek asli yang dipegang pointer ini adalah Lingkaran, jadi saya akan jalankan hitungLuas() versi Lingkaran." Saat berikutnya objeknya Persegi, ia akan otomatis menjalankan versi Persegi.
//      -Ini disebut Run-Time Polymorphism atau late binding, karena keputusan fungsi mana yang akan dipanggil baru dibuat saat program berjalan.
//3. Vector Polimorfik: Bagian vector<Bentuk*> menunjukkan kekuatan terbesar polimorfisme. Kita bisa mengumpulkan berbagai jenis objek yang berbeda ke dalam satu wadah dan memproses semuanya dalam satu for loop yang sama. Bayangkan jika kamu harus membuat if-else untuk setiap jenis bentuk, kodemu akan sangat berantakan!
//4. Dengan polimorfisme, kamu bisa menambahkan kelas Segitiga besok, dan fungsi cetakInfoBentuk serta for loop di main() tidak perlu diubah sama sekali! Inilah yang dimaksud dengan "terbuka untuk ekstensi, tapi tertutup untuk modifikasi" (Open-Closed Principle).


