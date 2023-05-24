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
    // Òóò ìîæíà ğåàë³çóâàòè íåîáõ³äíó ëîã³êó ïğè çíèùåíí³ îá'ºêòà
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

Student& Student::operator=(const Student& other)
{
    if (this != &other)
    {
        groupNumber = other.groupNumber;
        studentName = other.studentName;
    }

    return *this;
}

std::istream& operator>>(std::istream& input, Student& student) {
    std::cout << "Ââåä³òü íîìåğ ãğóïè: ";
    input >> student.groupNumber;
    std::cout << "Ââåä³òü ïğ³çâèùå ñòóäåíòà: ";

    input.ignore();
    getline(input, student.studentName);

    return input;
}

std::ostream& operator<<(std::ostream& output, const Student& student) {
    output << "Íîìåğ ãğóïè: " << student.groupNumber << std::endl;
    output << "Ïğ³çâèùå ñòóäåíòà: " << student.studentName << std::endl;

    return output;
}

void Student::printName() const
{
    std::cout << "Ïğ³çâèùå ñòóäåíòà: " << studentName << std::endl;
}
