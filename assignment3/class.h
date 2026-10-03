#include<string>
class Student {
private:
    std::string name;
    int grade;
    bool isValidGrade(int grade);
public:
    Student(std::string name, int grade);
    Student();
    std::string getName() const;
    int getGrade() const;
    void setGrade(int newGrade);
};