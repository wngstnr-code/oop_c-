#include <iostream>
#include <string>

using namespace std;

class RekeningBank {
private:
    string nomorRekening;
    double saldo;

protected:
    string namaPemilik;


public:
    RekeningBank() : nomorRekening("XXXX-XXXX"), namaPemilik("Belum terdaftar"), saldo(0.0){
        cout << "\n-> Rekening Bank Default Dibuat <-\n" << endl;
    }

    RekeningBank(string inputNomor, string inputNama, double inputSaldo) : nomorRekening(inputNomor), namaPemilik(inputNama), saldo(inputSaldo){
        cout << "\nRekening untuk " << namaPemilik << " Berhasil dibuat!\n" << endl;
    }

    void setor(double jumlah) {
        cout << "\n>> Transaksi Setor: " << jumlah << endl;
        if (jumlah <= 0) {
            cout << "[GAGAL] Jumlah setor harus lebih dari 0." << endl;
            return;
        }
        saldo += jumlah;
        cout << "[SUKSES] Setoran berhasil. Saldo baru: " << saldo << endl;
    }

    void tarik(double jumlah) {
        cout << "Tarik tunai sebesar: " << jumlah << endl;
        if (jumlah <=0) {
            cout << "[GAGAL] Jumlah penarikan harus lebhih dari 0\n" << endl;
            return;
        }
        if (jumlah > saldo) {
            cout << "[GAGAL] saldo anda tidak mencukupi\n" << endl;
            return;
        }
        saldo-=jumlah;
        cout << "[SUKSES] Penarikan berhasil. Saldo baru:\n" << saldo << endl;
    }

    void tampilkanInfo() {
        cout << "========== Info Rekening Bank ==========" << endl;
        cout << "Nama Pemiliki: " << namaPemilik << endl;
        cout << "Nomor Rekening: " << nomorRekening << endl;
        cout << "Saldo: " << saldo << endl;
        cout << "========================================\n" << endl;
    }
};

int main () {
    RekeningBank rekeningWangsit("545-092", "Wangsit Nursyahada", 150000.0);
    rekeningWangsit.tampilkanInfo();

    rekeningWangsit.setor(250000.0);
    rekeningWangsit.tampilkanInfo();

    rekeningWangsit.tarik(45000.0);
    rekeningWangsit.tampilkanInfo();

    rekeningWangsit.tarik(800000.0);
    rekeningWangsit.tampilkanInfo();
}