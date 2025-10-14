#include <iostream>
#include <string>

using namespace std;

class Kendaraan {
protected:
    string merk;
    string model;
    int tahun;

public:
    Kendaraan (string merk, string model, int tahun) : merk(merk), model(model), tahun(tahun){}

    virtual void tampilkanDetail(){
        cout << "Merk: " << merk << endl;
        cout << "Model: " << model << endl;
        cout << "Tahun: " << tahun << endl;
    }
};

class Mobil : public Kendaraan{
private:
    int jumlahPintu;

public:
    Mobil(string merk, string model, int tahun, int pintu) : Kendaraan(merk, model, tahun), jumlahPintu(pintu) {
        this->jumlahPintu = pintu;
    }

    void tampilkanDetail() override {
        Kendaraan::tampilkanDetail();
        cout << "Jumlah Pintu: " << this->jumlahPintu << endl;
    }
};

class Motor : public Kendaraan{
private:
    string jenisTransmisi;

public: 
    Motor(string merk, string model, int tahun, string transmisi) : Kendaraan(merk,model,tahun), jenisTransmisi(transmisi) {
        this->jenisTransmisi = transmisi;
    }

    void tampilkanDetail() override {
        Kendaraan::tampilkanDetail();
        cout << "Jenis Transmisi: " << this->jenisTransmisi << endl;
    }
};

int main () {
    Mobil mobil1("Toyota", "Avanza", 2023, 4);

    Motor motor1("Honda", "Vario 160",2024, "Matic");

    cout << "=== Detail Mobil ===" << endl;
    mobil1.tampilkanDetail();
    cout << "===================\n" << endl;

    cout << "=== Detail Motor ===" << endl;
    motor1.tampilkanDetail();
    cout << "===================\n" << endl;
}