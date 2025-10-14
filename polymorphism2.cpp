#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Hewan{
protected:
    string nama;

public:
    Hewan (string nama) : nama(nama) {}

    virtual void bersuara () = 0;    
    virtual ~Hewan() {}

    string getNama() {
        return nama;
    }
};

class Kucing : public Hewan {
public:
    Kucing(string nama) : Hewan(nama) {}

    void bersuara() override {
        cout << nama << " MEONG!" << endl;
    }
};

class Anjing : public Hewan {
public:
    Anjing(string nama) : Hewan(nama) {}

    void bersuara() override {
        cout << nama << " GUK GUK!" << endl;
    }
};

int main () {
    vector<Hewan*> semuaHewan;
    semuaHewan.push_back(new Kucing("Oyen"));
    semuaHewan.push_back(new Anjing ("Doggo"));
    semuaHewan.push_back(new Kucing("Mochi"));

    for (Hewan* h : semuaHewan) {
        h->bersuara();
    }

    for (Hewan* h : semuaHewan) {
        delete h;
    }

    return 0;
}