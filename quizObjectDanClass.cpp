#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <numeric> // Diperlukan untuk std::accumulate

using namespace std;

// Kelas untuk merepresentasikan data seorang mahasiswa
class Student {
private:
    int id;
    string name;
    vector<int> grades;

public:
    // Constructor untuk membuat objek Student
    Student(int student_id, const string& student_name) 
        : id(student_id), name(student_name) {}

    // Getter untuk ID
    int get_id() const {
        return id;
    }

    // Getter untuk nama
    string get_name() const {
        return name;
    }

    // Method untuk menambahkan nilai
    void add_grade(int grade) {
        grades.push_back(grade);
    }

    // Method untuk menghitung total nilai
    double calculate_sum() const {
        // Menggunakan std::accumulate untuk menjumlahkan semua elemen di vector
        // Ini adalah cara yang efisien dan modern.
        return accumulate(grades.begin(), grades.end(), 0);
    }

    // Method untuk mengecek apakah mahasiswa sudah punya nilai
    bool has_grades() const {
        return !grades.empty();
    }
};

// Kelas untuk mengelola semua data mahasiswa
class GradeManager {
private:
    // Menyimpan semua objek mahasiswa. Urutan penambahan penting untuk 'LIST'.
    vector<Student> students;
    // Peta untuk mencari mahasiswa dengan cepat berdasarkan ID.
    // Memetakan ID ke index-nya di dalam vector 'students'.
    map<int, int> id_to_index;

public:
    // Method untuk menambah mahasiswa baru
    void add_student(int id, const string& name) {
        // Cek dulu apakah ID sudah ada untuk menghindari duplikasi
        if (id_to_index.find(id) == id_to_index.end()) {
            students.emplace_back(id, name);
            id_to_index[id] = students.size() - 1;
        }
    }

    // Method untuk menambah nilai ke mahasiswa yang ada
    void add_grade(int id, int grade) {
        // Cek apakah mahasiswa dengan ID tersebut ada
        if (id_to_index.count(id)) {
            int index = id_to_index[id];
            students[index].add_grade(grade);
        }
    }

    // Method untuk menampilkan total nilai seorang mahasiswa
    void show_sum(int id) {
        // Cek apakah mahasiswa dengan ID tersebut ada
        if (id_to_index.count(id)) {
            int index = id_to_index[id];
            const auto& student = students[index];
            // Tampilkan hanya jika mahasiswa memiliki nilai
            if (student.has_grades()) {
                cout << student.calculate_sum() << endl;
            }
        }
    }

    // Method untuk menampilkan total nilai semua mahasiswa
    void list_all_students() {
        // Iterasi melalui vector 'students' untuk menjaga urutan penambahan
        for (const auto& student : students) {
            // Tampilkan hanya jika mahasiswa memiliki nilai
            if (student.has_grades()) {
                cout << student.get_name() << ": " << student.calculate_sum() << endl;
            }
        }
    }
};

// Fungsi utama
int main() {
    // Optimasi input/output C++
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    GradeManager manager;
    string operation;
    int id, grade;
    string name;

    for (int i = 0; i < Q; ++i) {
        cin >> operation;

        if (operation == "ADD") {
            cin >> id;
            // Menggunakan getline untuk membaca nama yang mungkin mengandung spasi
            // (Meskipun soal menyebutkan hanya huruf, ini praktik yang lebih aman)
            cin.ignore(); // Membersihkan buffer setelah membaca integer
            getline(cin, name);
            manager.add_student(id, name);
        } else if (operation == "GRADE") {
            cin >> id >> grade;
            manager.add_grade(id, grade);
        } else if (operation == "SUM") {
            cin >> id;
            manager.show_sum(id);
        } else if (operation == "LIST") {
            manager.list_all_students();
        }
    }

    return 0;
}