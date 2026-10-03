#include"class.h"
#include<iostream>

Student::Student() : name(""),grade(0){}
Student::Student(std::string name,int grade) : name(name),grade(grade) {}
std::string Student::getName() const {
    return this->name;
}
int Student::getGrade() const {
    return this->grade;
}
bool Student::isValidGrade(int grade) {
    return (grade>=0 && grade <= 100);
}
void Student::setGrade(int grade) {
    if (Student::isValidGrade(grade)) {
        this->grade = grade;
    }else {
        std::cout << "Invalid grade! Grade set failed.\n";
    }
}