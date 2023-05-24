#pragma once

#include <iostream>
#include <string>

class Student {
public:
    // Конструктор за замовчуванням
    Student();

    // Конструктор з параметрами
    Student(int groupNumber, const std::string& studentName);

    // Деструктор
    ~Student();

    // Методи встановлення і виведення значень полів даних
    int getGroupNumber() const;
    void setGroupNumber(int _groupNumber);

    const std::string& getStudentName() const;
    void setStudentName(const std::string& _studentName);

    // Перевантажена операція () для встановлення значень полів даних
    void operator()(int group, const std::string& name);

    // Перевантажена операція присвоєння =
    Student& operator=(const Student& other);

    // Перевантажені потокові операції >> та <<
    friend std::istream& operator>>(std::istream& input, Student& student);
    friend std::ostream& operator<<(std::ostream& output, const Student& student);

private:
    int groupNumber;

    std::string studentName;

};
