#include <iostream>
#include <string>
#include <iomanip> // Diperlukan untuk mengatur presisi angka desimal (IPK)

using namespace std;

class Mahasiswa {
private:
    string nim;

protected:
    string nama;

public:
    double ipk;

public:
    Mahasiswa() : nim("000000"), nama("Default Name"), ipk(0.0){
        cout << "\n-> Object Mahasiswa Default <-\n" << endl;
    }

    Mahasiswa(string inputNIM, string inputNama,double inputIPK) : nim(inputNIM), nama(inputNama), ipk(inputIPK){
        cout << "-> Object Mahasiswa Parameter <-" << endl;
    }

    void tampilkanProfil(){
        cout << "========== Profil Mahasiswa ==========" << endl;
        cout << "Nama: " << nama << endl;
        cout << "NIM: " << nim << endl;
        cout << fixed <<setprecision(2);
        cout << "IPK: " << ipk << endl;
        cout << "======================================" << endl;
    }
};

int main() {
    Mahasiswa mhs1 ("24/545092/TK/60594", "Wangsit Nursyahada", 3.92);
    mhs1.tampilkanProfil();

    cout << "\nIPK Wangsit telah diperbarui!!!\n" << endl;
    mhs1.ipk = 3.88;
    mhs1.tampilkanProfil();

    Mahasiswa mhs2;
    mhs2.tampilkanProfil();
}