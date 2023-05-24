#pragma once

#include <vector>

#include "Exam.h"

class GradeBook {
public:
    // Конструктор за замовчуванням
    GradeBook() = default;

    // Деструктор
    ~GradeBook() = default;

    void addExam(const Exam& exam);

    void displayResults() const;

    class Iterator {
    public:
        Iterator(const std::vector<Exam>& exams, size_t index);

        bool operator!=(const Iterator& other) const;
        Iterator& operator++();
        const Exam& operator*() const;

    private:
        size_t index;

        const std::vector<Exam>& exams;
    };

    Iterator begin() const;
    Iterator end() const;

private:
    std::vector<Exam> exams;
};