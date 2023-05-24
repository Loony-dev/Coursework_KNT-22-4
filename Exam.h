#pragma once

#include <string>
#include <iostream>

#include "Student.h"
#include "Teacher.h"

class Exam : public Student, public Teacher {
public:
    // Конструктор за замовчуванням
    Exam();

    // Конструктор з параметрами
    Exam(int group, const std::string& name, const std::string& subject, int hours, const std::string& date,
         int examGrade, const std::string& teacherName, const std::string& teacherPosition);

    // Деструктор
    ~Exam();

    // Методи встановлення і виведення значень полів даних
    const std::string& getSubjectName() const;
    void setSubjectName(const std::string& subjectName);

    const std::string& getExamDate() const;
    void setExamDate(const std::string& examDate);

    int getStudyHours() const;
    void setStudyHours(int studyHours);

    int getGrade() const;
    void setGrade(int grade);

    // Перевантажена операція () для встановлення значень полів даних
    void operator()(int group, const std::string& name, const std::string& _subjectName, int _studyHours,
            const std::string& _examDate, int _grade, const std::string& teacherName, const std::string& teacherPosition);

    // Перевантажена операція присвоєння =
    Exam& operator=(const Exam& other);

    // Перевантажені потокові операції >> та <<
    friend std::istream& operator>>(std::istream& input, Exam& exam);
    friend std::ostream& operator<<(std::ostream& output, const Exam& exam);

    void printName() const override;

private:
    std::string subjectName;
    std::string examDate;

    int studyHours;
    int grade;
};