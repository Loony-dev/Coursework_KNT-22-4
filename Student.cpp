#include "Student.h"

Student::Student()
{
    groupNumber = 0;
    studentName = "";
}

Student::Student(int groupNumber, const std::string& studentName)
    : groupNumber(groupNumber), studentName(studentName) {}

Student::~Student()
{
    // Тут можна реалізувати необхідну логіку при знищенні об'єкта
}

int Student::getGroupNumber() const
{
    return groupNumber;
}

void Student::setGroupNumber(int _groupNumber)
{
    groupNumber = _groupNumber;
}

const std::string &Student::getStudentName() const
{
    return studentName;
}

void Student::setStudentName(const std::string& _studentName)
{
    studentName = _studentName;
}

void Student::operator()(int group, const std::string& name)
{
    groupNumber = group;
    studentName = name;
}

Student& Student::operator=(const Student& other) {
    if (this != &other)
    {
        groupNumber = other.groupNumber;
        studentName = other.studentName;
    }

    return *this;
}

std::istream& operator>>(std::istream& input, Student& student) {
    std::cout << "Введіть номер групи: ";
    input >> student.groupNumber;
    std::cout << "Введіть прізвище студента: ";

    input.ignore();
    getline(input, student.studentName);

    return input;
}

std::ostream& operator<<(std::ostream& output, const Student& student) {
    output << "Номер групи: " << student.groupNumber << std::endl;
    output << "Прізвище студента: " << student.studentName << std::endl;

    return output;
}
