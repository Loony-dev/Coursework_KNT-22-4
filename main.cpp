#include <iostream>

#include "Exam.h"
#include "GradeBook.h"

int main()
{
    setlocale(LC_ALL, "ukr");

    GradeBook gradeBook;

    Exam exam1(456, "������ ��������", "Գ����", 40, "2023-06-10", 85, "������ �������", "�������� ���������");
    Exam exam2(123, "������ ��������", "����������", 60, "2023-05-24", 90, "��������� ���������", "��������");

    gradeBook.addExam(exam1);
    gradeBook.addExam(exam2);

    std::cout << "���������:" << std::endl;
    gradeBook.displayResults();

    system("pause");
    return 0;
}
