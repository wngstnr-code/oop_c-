#include <iostream>
#include <string>

using namespace std;

class MesinJual {
private:
    string namaBarang1, namaBarang2, namaBarang3;
    double hargaBarang1, hargaBarang2, hargaBarang3;
    int stokBarang1, stokBarang2, stokBarang3;
    double uangMasuk;

public:
    MesinJual() : namaBarang1("Pocari Sweat"), hargaBarang1(7000), stokBarang1(5), namaBarang2("Teh Botol"), hargaBarang2(5000), stokBarang2(10), namaBarang3("Lays"), hargaBarang3(10000), stokBarang3(3) {
        uangMasuk = 0.0;
        cout << "\n===== Mesin Jual Otomatis Siap Digunakan =====\n" << endl;
    }

    void tampilkanBarang() {
        cout << "----- Daftar Barang Tersedia -----" << endl;
        cout << "1. " << namaBarang1 << " - Harga: " << hargaBarang1 << " Rp - Stok: " << stokBarang1 << endl;
        cout << "2. " << namaBarang2 << " - Harga: " << hargaBarang2 << " Rp - Stok: " << stokBarang2 << endl;
        cout << "3. " << namaBarang3 << " - Harga: " << hargaBarang3 << " Rp - Stok: " << stokBarang3 << endl;
        cout << "-----------------------------------\n" << endl;
    }

    void masukkanUang(double jumlah) {
        if (jumlah > 0) {
            uangMasuk += jumlah;
            cout << "[SUKSES] Uang sebesar " << jumlah << " Rp telah dimasukkan. Total uang masuk: " << uangMasuk << " Rp\n" << endl;
        } else {
            cout << "[GAGAL] Jumlah uang yang dimasukkan harus lebih dari 0\n" << endl;
        }
        
    }

    void pilihBarang(int pilihan) {
        switch (pilihan) {
            case 1:
                prosesPembelian(namaBarang1, hargaBarang1, stokBarang1);
                break;
            case 2:
                prosesPembelian(namaBarang2, hargaBarang2, stokBarang2);
                break;
            case 3:
                prosesPembelian(namaBarang3, hargaBarang3, stokBarang3);
                break;
            default:
                cout << "[GAGAL] Pilihan tidak valid. Silakan pilih 1, 2, atau 3.\n" << endl;
        }
    }

private:
    void prosesPembelian(string &namaBarang, double hargaBarang, int &stokBarang) {
        if (stokBarang <= 0) {
            cout << "[GAGAL] Stok " << namaBarang << " habis. Silakan pilih barang lain.\n" << endl;
            return;
        }
        if (uangMasuk < hargaBarang) {
            cout << "[GAGAL] Uang tidak cukup untuk membeli " << namaBarang << ". Silakan masukkan uang lebih.\n" << endl;
            return;
        }
        stokBarang--;
        double kembalian = uangMasuk - hargaBarang;
        cout << "[SUKSES] Silakan ambil " << namaBarang << " Anda." << endl;
        cout << "         Uang kembalian Anda: Rp " << kembalian << "\n" << endl;

        uangMasuk = 0.0;
    }   
};

int main() {
    MesinJual pelanggan;

    pelanggan.tampilkanBarang();
    pelanggan.masukkanUang(5000);
    pelanggan.pilihBarang(3);
    pelanggan.masukkanUang(7000);
    pelanggan.pilihBarang(3);
    pelanggan.tampilkanBarang();
}