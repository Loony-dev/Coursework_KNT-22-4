#include "GradeBook.h"

void GradeBook::addExam(const Exam& exam)
{
    exams.push_back(exam);
}

void GradeBook::displayResults() const
{
    for (const Exam& exam : *this)
        std::cout << exam << std::endl;
}

// Ітератор
GradeBook::Iterator::Iterator(const std::vector<Exam>& exams, size_t index)
        : exams(exams), index(index) {
}

bool GradeBook::Iterator::operator!=(const GradeBook::Iterator& other) const
{
    return index != other.index;
}

GradeBook::Iterator& GradeBook::Iterator::operator++()
{
    ++index;
    return *this;
}

const Exam& GradeBook::Iterator::operator*() const
{
    return exams[index];
}

GradeBook::Iterator GradeBook::begin() const
{
    return Iterator(exams, 0);
}

GradeBook::Iterator GradeBook::end() const
{
    return Iterator(exams, exams.size());
}
