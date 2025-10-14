#include <iostream>
#include <string>

using namespace std;

class Petarung {
protected:
    string nama;

private:
    int healthPoint;
    int attackPower;

public:
    Petarung(string nama, int hp, int ap) : nama(nama), healthPoint(hp), attackPower(ap) {
        cout << "-> " << this -> nama << "Telah memasuki arena pertarungan <-" << endl;
    }

    void serang(Petarung &target) {
        cout << "\n** " << this->nama << " menyerang " << target.getNama() << "! **" << endl;
        target.terimaSerangan(this->attackPower);
    }

    void tampilkanStatus(){
        cout << "--------------------------------------------\n";
        cout << "nama: " << this->nama << endl;
        cout << "Health Point: " << this->healthPoint << " HP" << endl;
        cout << "Attack Power: " << this->attackPower << endl;
        cout << "--------------------------------------------\n";
    }

    string getNama(){
        return this->nama;
    }

private:
    void terimaSerangan(int damage) {
        this->healthPoint -= damage;
        if (this->healthPoint < 0) {
            this->healthPoint = 0;
        }
        cout << this->nama << " menerima serangan sebesar " << damage << " kerusakan!" << endl;
    }
};

int main() {
    Petarung ksatria("Kesatria Baja Hitam", 80, 25);
    Petarung penyihir("Nenek Lampir", 85, 40);

    cout << "\n===== STATUS AWAL =====\n" << endl;
    ksatria.tampilkanStatus();
    penyihir.tampilkanStatus();

    ksatria.serang(penyihir);

    penyihir.serang(ksatria);

    ksatria.serang(penyihir);

    penyihir.serang(ksatria);

    cout << "\n===== STATUS AKHIR =====\n" << endl;
    ksatria.tampilkanStatus();
    penyihir.tampilkanStatus();

    return 0;
}