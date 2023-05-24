#include "Teacher.h"

Teacher::Teacher()
{
    teacherName = "";
    teacherPosition = "";
}

Teacher::Teacher(const std::string& teacherName, const std::string& teacherPosition)
    : teacherName(teacherName), teacherPosition(teacherPosition) {}

Teacher::~Teacher()
{

}

const std::string& Teacher::getTeacherName() const
{
    return teacherName;
}

void Teacher::setTeacherName(const std::string& _teacherName)
{
    teacherName = _teacherName;
}

const std::string &Teacher::getTeacherPosition() const
{
    return teacherPosition;
}

void Teacher::setTeacherPosition(const std::string& _teacherPosition)
{
    teacherPosition = _teacherPosition;
}

void Teacher::operator()(const std::string& name, const std::string& position)
{
    teacherName = name;
    teacherPosition = position;
}

Teacher& Teacher::operator=(const Teacher& other)
{
    if (this != &other)
    {
        teacherName = other.teacherName;
        teacherPosition = other.teacherPosition;
    }

    return *this;
}

std::istream& operator>>(std::istream& input, Teacher& teacher)
{
    std::cout << "Введіть призвище викладача: ";
    input.ignore();
    getline(input, teacher.teacherName);

    std::cout << "Введіть посаду викладача: ";
    getline(input, teacher.teacherPosition);

    return input;
}

std::ostream& operator<<(std::ostream& output, const Teacher& teacher)
{
    output << "Прізвище викладача: " << teacher.teacherName << std::endl;
    output << "Посада викладача: " << teacher.teacherPosition << std::endl;

    return output;
}

void Teacher::printName() const
{
    std::cout << "Прізвище викладача: " << teacherName << std::endl;
}
