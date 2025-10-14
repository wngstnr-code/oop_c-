#include <iostream>
#include <string>

using namespace std;

class Siswa {
protected:
    string nama;
    int umur;

public:
    Siswa(string nama, int umur) : nama(nama), umur(umur) {}

    virtual void tampilkanInfo(){
        cout << "Nama: " << nama << endl;
        cout << "Umur: " << umur << " tahun" << endl;
    }
};

class Mahasiswa : public Siswa {
private:
    string programStudi;

public:
    Mahasiswa (string nama, int umur, string prodi) : Siswa(nama,umur), programStudi(prodi) {
        this->programStudi = prodi;
    }

    void tampilkanInfo() override {
        Siswa::tampilkanInfo();
        cout << "Program Studi: " << this->programStudi << endl;
    }
};

int main () {
    Siswa siswa1("Sada", 12);
    cout << "\n=== Info Siswa ===\n" << endl;
    siswa1.tampilkanInfo();
    cout << "\n==================\n" << endl;

    Mahasiswa mhs1("Wangsit", 20, "Teknologi Informasi");
    cout << "\n=== Info Mahasiswa ===\n" << endl;
    mhs1.tampilkanInfo();
    cout << "\n======================\n" << endl;

}