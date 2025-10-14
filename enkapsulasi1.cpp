#include <iostream>
#include <string>

using namespace std;

class ProfilPengguna {
private:
    string username;
    string email;
    int level;

public:
    ProfilPengguna(string username, string email) {
        this->username = username;
        this->setEmail(email);
        this->level = 1;
        cout << "-> Profil Pengguna untuk " << this->username << " telah dibuat\n" << endl;
    }

    void setEmail(string newEmail) {
        if (newEmail.find('@') != string::npos) {
            this->email = newEmail;
            cout << "[INFO] Email berhasil diubah menjadi: " << this->email << "\n" << endl;
        } else {
            cout << "[GAGAL] Format email " << newEmail << " tidak valid. Harus mengandung '@'.\n" << endl;
        }
    }

    string getUsername(){
        return this->username;
    }

    string getEmail(){
        return this->email;
    }

    int getLevel(){
        return this->level;
    }

    void levelUp() {
        this->level++;
        cout << "[NAIK LEVEL!] " << this->username << " sekarang mencapai level " << this->level << "!\n" << endl;
    }

    void tampilkanInfo() {
        cout << "========== Info Profil Pengguna ==========" << endl;
        cout << "Username: " << this->username << endl;
        cout << "Email: " << this->email << endl;
        cout << "Level: " << this->level << endl;
        cout << "========================================\n" << endl;
    }
};

int main() {
    ProfilPengguna user1("anjaygaming", "anjaygaming@gmail.com");
    user1.tampilkanInfo();
    cout << "Mengubah email...\n" << endl;
    user1.setEmail("anjaygaming[at]gmail.com");

    cout << "Mengubah email...\n" << endl;
    user1.setEmail("anjayani@gmail.com");
    
    user1.levelUp();
    user1.tampilkanInfo();

    return 0;
}