#include <iostream>
#include <string>

using namespace std;

class Produk {
private:
    string sku;
    string namaProduk;
    double harga;
    int stok;

public:
    Produk(string sku, string namaProduk, double hargaAwal, int stokAwal) {
        this->sku = sku;
        this->namaProduk = namaProduk;
        this->harga = (hargaAwal >= 0) ? hargaAwal : 0.0;
        this->stok = (stokAwal >= 0) ? stokAwal : 0;
        cout << "-> Produk " << this->namaProduk << " berhasil dibuat dan dimasukkan ke dalam sistem\n" << endl;
    }

    string getSku() {
        return this->sku;
    }

    string getNamaProduk() {
        return this->namaProduk;
    }

    double getHarga() {
        return this->harga;
    }

    int getStok() {
        return this->stok;
    }

    void setHarga(double hargaBaru) {
        if (hargaBaru < 0) {
            cout << "[GAGAL] Harga tidak boleh negatif" << endl;
        } else {
            this->harga = hargaBaru;
            cout << "[SUKSES] Harga Produk " << this->namaProduk << " berhasil diubah menjadi " << this->harga << endl; 
        }
    }

    void tambahStok(int jumlah) {
        if (jumlah <= 0) {
            cout << "[GAGAL] jumlah penambahan stok harus lebih dari 0" << endl;
        } else {
            this->stok += jumlah;
            cout << "[SUKSES] Stok Produk " << this->namaProduk << " berhasil ditambah. Stok sekarang: " << this->stok << endl;
        }
    }

    void kurangiStok(int jumlah) {
        if (jumlah <=0) {
            cout << "[GAGAL] jumlah pengurangan stok harus lebih dari 0" << endl;
        } else if (jumlah > this->stok) {
            cout << "[GAGAL] Stok tidak mencukupi untuk pengurangan" << endl;
        } else {
            this->stok -= jumlah;
            cout << "[SUKSES] Penjualan " << jumlah << " buah " << this->namaProduk << " berhasil. Sisa stok: " << this->stok << ".\n";
        }
    }

    void tampilkanInfo() {
        cout << "========== Info Produk ==========" << endl;
        cout << "SKU: " << this->sku << endl;
        cout << "Nama Produk: " << this->namaProduk << endl;
        cout << "Harga: " << this->harga << endl;
        cout << "Stok: " << this->stok << endl;
        cout << "================================\n" << endl;
    }
};

int main() {
    Produk buku("MN-01", "Buku Memasak", 12000.0, 5);
    buku.tampilkanInfo();

    cout << "\n>> Percobaan mengubah harga (gagal)...\n";
    buku.setHarga(-20000);

    cout << "\n>> Mengubah harga (berhasil)...\n";
    buku.setHarga(17500);

    cout << "\n>> Menambah stok baru...\n";
    buku.tambahStok(25);

    cout << "\n>> Memproses penjualan...\n";
    buku.kurangiStok(10);
    buku.kurangiStok(70);

    buku.tampilkanInfo();
}