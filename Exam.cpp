#include "Exam.h"

Exam::Exam()
{
    subjectName = "";
    examDate = "";

    studyHours = 0;
    grade = 0;
}

Exam::Exam(int group, const std::string& name, const std::string& subject, int hours, const std::string& date,
           int examGrade, const std::string& teacherName, const std::string& teacherPosition)
    : Student(group, name), Teacher(teacherName, teacherPosition), subjectName(subject),
    studyHours(hours), examDate(date), grade(examGrade) {}

Exam::~Exam()
{

}

const std::string& Exam::getSubjectName() const
{
    return subjectName;
}

void Exam::setSubjectName(const std::string& _subjectName)
{
    subjectName = _subjectName;
}

const std::string& Exam::getExamDate() const
{
    return examDate;
}

void Exam::setExamDate(const std::string& _examDate)
{
    examDate = _examDate;
}

int Exam::getStudyHours() const
{
    return studyHours;
}

void Exam::setStudyHours(int _studyHours)
{
    studyHours = _studyHours;
}

int Exam::getGrade() const
{
    return grade;
}

void Exam::setGrade(int _grade)
{
    grade = _grade;
}

void Exam::operator()(int group, const std::string& name, const std::string& _subjectName, int _studyHours,
        const std::string& _examDate, int _grade, const std::string& teacherName, const std::string& teacherPosition)
{
    setGroupNumber(group);
    setStudentName(name);

    setTeacherName(teacherName);
    setTeacherPosition(teacherPosition);

    subjectName = _subjectName;
    studyHours = _studyHours;
    examDate = _examDate;
    grade = _grade;
}

Exam& Exam::operator=(const Exam& other)
{
    if (this != &other)
    {
        Student::operator=(other);
        Teacher::operator=(other);

        subjectName = other.subjectName;
        studyHours = other.studyHours;
        examDate = other.examDate;
        grade = other.grade;
    }

    return *this;
}

std::istream& operator>>(std::istream& input, Exam& exam)
{
    input >> static_cast<Student&>(exam);
    input >> static_cast<Teacher&>(exam);

    std::cout << "Введіть назву предмету: ";
    input.ignore();
    getline(input, exam.subjectName);

    std::cout << "Введіть кількість годин для вивчення предмета: ";
    input >> exam.studyHours;

    std::cout << "Введіть дату проведення екзамену: ";
    input.ignore();
    getline(input, exam.examDate);

    std::cout << "Введіть оцінку: ";
    input >> exam.grade;

    return input;
}

std::ostream& operator<<(std::ostream& output, const Exam& exam)
{
    output << static_cast<const Student&>(exam);
    output << static_cast<const Teacher&>(exam);

    output << "Назва предмету: " << exam.subjectName << std::endl;
    output << "Кількість годин для вивчення предмета: " << exam.studyHours << std::endl;
    output << "Дату проведення екзамену: " << exam.examDate << std::endl;
    output << "Оцінка: " << exam.grade << std::endl;

    return output;
}
