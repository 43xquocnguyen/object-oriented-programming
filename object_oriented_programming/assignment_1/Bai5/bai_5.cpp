#include "student.h"

int main() {
    Student *student = new Student;
    student->Nhap();
    student->Xuat();
    delete student;
    student = nullptr;
    return 0;
}
