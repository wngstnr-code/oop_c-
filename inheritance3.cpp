#include <iostream>
#include <string>

using namespace std;

class Mahasiswa {
protected:
    string nama;
    string jurusan;

public:
    Mahasiswa(string nama, string jurusan) : nama(nama), jurusan(jurusan) {}
    virtual void tampilkanInfo(){
        cout << "Nama: " << nama << endl;
        cout << "Jurusan: " << jurusan << endl;
    }
};

class Pekerja {
protected:
    string perusahaan;
    string posisi;

public:
    Pekerja(string perusahaan, string posisi) : perusahaan(perusahaan), posisi(posisi){}
    virtual void tampilkanInfo(){
        cout << "Perusahaan: " << perusahaan << endl;
        cout << "Posisi: " << posisi << endl;
    }
};

class MahasiswaPekerja : public Mahasiswa, public Pekerja {
private:
    string idMahasiswaPekerja;

public:
    MahasiswaPekerja(string nama, string jurusan, string perusahaan, string posisi, string id) : Mahasiswa(nama, jurusan), Pekerja(perusahaan, posisi), idMahasiswaPekerja(id){}

    void tampilkanInfo() override {
        Mahasiswa :: tampilkanInfo();
        Pekerja :: tampilkanInfo();
        cout << "ID Mahasiswa Pekerja: " << this->idMahasiswaPekerja << endl;
    }
};

int main(){
    MahasiswaPekerja orang1("Dewi", "Sistem Informasi", "TechCorp", "Junior Developer", "MHP-007");
    
    cout << "\n=== Info Mahasiswa Pekerja ===\n" << endl;
    orang1.tampilkanInfo();
    cout << "\n==============================\n" << endl;
}