#pragma once

#include <string>
#include <iostream>

class Teacher {
public:
    // Конструктор за замовчуванням
    Teacher();

    // Конструктор з параметрами
    Teacher(const std::string &teacherName, const std::string &teacherPosition);

    // Деструктор
    ~Teacher();

    // Методи встановлення і виведення значень полів даних
    const std::string& getTeacherName() const;
    void setTeacherName(const std::string& _teacherName);

    const std::string& getTeacherPosition() const;
    void setTeacherPosition(const std::string& _teacherPosition);

    // Перевантажена операція () для встановлення значень полів даних
    void operator()(const std::string& name, const std::string& position);

    // Перевантажена операція присвоєння =
    Teacher& operator=(const Teacher& other);

    // Перевантажені потокові операції >> та <<
    friend std::istream& operator>>(std::istream& input, Teacher& teacher);
    friend std::ostream& operator<<(std::ostream& output, const Teacher& teacher);

    virtual void printName() const;

private:
    std::string teacherName;
    std::string teacherPosition;
};