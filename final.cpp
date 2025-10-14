#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MetodePembayaran {
public:
    virtual void prosesPembayaran(double jumlah) = 0;
    virtual ~MetodePembayaran() {}

    virtual string getNamaMetode() = 0;
};

class KartuKredit : public MetodePembayaran {
private:
    string nomorKartu;
    string namaPemilik;

public:
    KartuKredit(string nomor, string nama) : nomorKartu(nomor), namaPemilik(nama) {}

    void prosesPembayaran(double jumlah) override {
        cout << "Pembayaran Rp " << jumlah << " dengan Kartu Kredit " << nomorKartu << " atas nama " << namaPemilik << " berhasil." << endl;
    }

    string getNamaMetode() override {
        return "Kartu Kredit";
    }
};

class TransferBank : public MetodePembayaran {
private:
    string kodeBank;
    string nomorVA;

public:
    TransferBank(string kode, string va) : kodeBank(kode), nomorVA(va) {}

    void prosesPembayaran(double jumlah) override {
        cout << "Silakan transfer Rp " << jumlah << " ke Virtual Account " << nomorVA << " pada Bank " << kodeBank << "." << endl;
    }

    string getNamaMetode() override {
        return "Transfer Bank";
    }
};

class DompetDigital : public MetodePembayaran {
private:
    string nomorTelepon;

public: 
    DompetDigital(string nomor) : nomorTelepon(nomor) {}

    void prosesPembayaran(double jumlah) override {
        cout << "Pembayaran Rp " << jumlah << " dari akun Dompet Digital " << nomorTelepon << " sedang diproses." << endl;
    }

    string getNamaMetode()override {
        return "Dompet Digital";
    }
};

int main () {
    double jumlah = 250000.0;

    vector<MetodePembayaran*> listMetodePembayaran;
    listMetodePembayaran.push_back(new KartuKredit("1234-9876-5050", "Wangsit Nursyahada"));
    listMetodePembayaran.push_back(new TransferBank("BNI", "09080706050403"));
    listMetodePembayaran.push_back(new DompetDigital("081234567890"));

    for (MetodePembayaran* metode : listMetodePembayaran) {
        metode->prosesPembayaran(jumlah);
    }

    for (MetodePembayaran* metode : listMetodePembayaran) {
        delete metode;
    }

    return 0;
}