#include <iostream>

#include "Exam.h"
#include "GradeBook.h"

int main()
{
    setlocale(LC_ALL, "ukr");

    GradeBook gradeBook;

    Exam exam1(456, "Георгій Стефаник", "Фізика", 40, "2023-06-10", 85, "Олекса Біланюк", "Асистент професора");
    Exam exam2(123, "Валерій Скороход", "Математика", 60, "2023-05-24", 90, "Олександр Борисенко", "Професор");

    gradeBook.addExam(exam1);
    gradeBook.addExam(exam2);

    std::cout << "Результат:" << std::endl;
    gradeBook.displayResults();

    system("pause");
    return 0;
}
