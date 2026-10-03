#include "class.h"
#include <iostream>
/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */
void sandbox() {
  // STUDENT TODO: Construct an instance of your class!
    Student a("Tony",85);
    std::cout << "Student : " << a.getName() << ", old grade : " << a.getGrade() << '\n' ;
    a.setGrade(90);
    std::cout << "Student : " << a.getName() << ", new grade : " << a.getGrade() << '\n' ;
}