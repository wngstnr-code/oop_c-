#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Dokumen{
protected:
    string namaFile;

public:
    Dokumen(string nama) : namaFile(nama) {}

    virtual void buka() = 0;
    virtual ~Dokumen() {};

    string getNamaFile() {
        return namaFile;
    }
};

class DokumenTeks : public Dokumen {
private:
    int jumlahKata;

public:
    DokumenTeks(string nama, int kata) : Dokumen(nama), jumlahKata(kata) {}

    void buka() override {
        cout << "Membuka dokumen teks " << namaFile << " yang memiliki " << jumlahKata << " kata." << endl; 
    }
};

class Spreadsheet : public Dokumen {
private:
    int jumlahBaris;
    int jumlahKolom;

public:
    Spreadsheet(string nama, int baris, int kolom) : Dokumen(nama), jumlahBaris(baris), jumlahKolom(kolom) {}
    
    void buka() override {
        cout << "Membuka spreadsheet " << namaFile << " dengan ukuran " << jumlahBaris << " x " << jumlahKolom<< endl;
    }
};

class Presentasi : public Dokumen {
private:
    int jumlahSlide;

public:
    Presentasi (string nama, int slide) : Dokumen(nama), jumlahSlide(slide) {}

    void buka() override {
        cout << "Memulai Presentasi " << namaFile << " yang terdiri dari " << jumlahSlide << " slide." << endl; 
    }
};

int main () {
    vector<Dokumen*> dokumenList;
    dokumenList.push_back(new DokumenTeks("Lpaporan.txt", 500));
    dokumenList.push_back(new Spreadsheet("Data.csv", 100, 15));
    dokumenList.push_back(new Presentasi("meeting.ppt", 20));

    for (Dokumen* doc : dokumenList) {
        doc->buka();
    }

    for (Dokumen* doc :dokumenList) {
        delete doc;
    }
}
