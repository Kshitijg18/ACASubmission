#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string student_name;
    string subject;
    int score;
    Student *left_child, *right_child;

    Student(int i, string n, string s, int sc) : id(i), student_name(n), subject(s), score(sc), left_child(nullptr), right_child(nullptr) {}
};

class StudentManagementSystem {
private:
    Student* root;

    Student* addStudent(Student* node, int id, string student_name, string subject, int score) {
        if (node == nullptr)
            return new Student(id, student_name, subject, score);

        if (id < node->id)
            node->left_child = addStudent(node->left_child, id, student_name, subject, score);
        else if (id > node->id)
            node->right_child = addStudent(node->right_child, id, student_name, subject, score);

        return node;
    }

    Student* findMinimum(Student* node) {
        while (node->left_child != nullptr)
            node = node->left_child;
        return node;
    }

    Student* deleteStudent(Student* node, int id) {
        if (node == nullptr) return node;

        if (id < node->id)
            node->left_child = deleteStudent(node->left_child, id);
        else if (id > node->id)
            node->right_child = deleteStudent(node->right_child, id);
        else {
            if (node->left_child == nullptr) {
                Student* temp = node->right_child;
                delete node;
                return temp;
            } else if (node->right_child == nullptr) {
                Student* temp = node->left_child;
                delete node;
                return temp;
            }
            Student* temp = findMinimum(node->right_child);
            node->id = temp->id;
            node->student_name = temp->student_name;
            node->subject = temp->subject;
            node->score = temp->score;
            node->right_child = deleteStudent(node->right_child, temp->id);
        }
        return node;
    }

    Student* findStudent(Student* node, int id) {
        while (node != nullptr && node->id != id) {
            if (id < node->id)
                node = node->left_child;
            else
                node = node->right_child;
        }
        return node;
    }

    void displayStudents(Student* node) {
        if (node != nullptr) {
            displayStudents(node->left_child);
            cout << "Name: " << node->student_name << ", ID: " << node->id << ", Subject: " << node->subject << ", Score: " << node->score << endl;
            displayStudents(node->right_child);
        }
    }

public:
    StudentManagementSystem() : root(nullptr) {}

    void addStudent(int id, string student_name, string subject, int score) {
        root = addStudent(root, id, student_name, subject, score);
    }

    void removeStudent(int id) {
        root = deleteStudent(root, id);
    }

    void listStudents() {
        if (root == nullptr) {
            cout << "No students to display." << endl;
            return;
        }
        displayStudents(root);
    }

    void findStudentById(int id) {
        Student* student = findStudent(root, id);
        if (student != nullptr)
            cout << "Student found - Name: " << student->student_name << ", ID: " << student->id << ", Subject: " << student->subject << ", Score: " << student->score << endl;
        else
            cout << "No student found with ID " << id << "." << endl;
    }
};

int main() {
    StudentManagementSystem system;
    system.addStudent(1, "John", "CS", 85);
    system.addStudent(2, "Tom", "Math", 90);
    system.listStudents();
    system.findStudentById(1);
    system.removeStudent(1);
    system.listStudents();

    return 0;
}
