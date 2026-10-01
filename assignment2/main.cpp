/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>

std::string kYourName = "Kobe Bryant"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::unordered_set<std::string> get_applicants(const std::string filename) {
  // STUDENT TODO: Implement this function.
    //set version
    std::ifstream in(filename);
    std::string name;
    std::unordered_set<std::string> applicants;
    while(std::getline(in,name)) {
        if (name.empty()) continue;
        applicants.insert(name);
    }
    return applicants;
}

std::pair<char,char> get_initials(const std::string& student) {
    std::pair<char,char> ini;
    for(int i = 0;i <int(student.size());i++) {
        if (student[i] != ' ') {
            continue;
        }
        i++;
        ini = std::make_pair(student[0],student[i]);
        break;
    }
    return ini;
}
/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::unordered_set<std::string>& students) {
  // STUDENT TODO: Implement this function.
    std::queue<const std::string*> q;
    std::pair<char,char> my_initials = get_initials(name);
    for(auto it = students.begin(); it != students.end();++it) {
        if (get_initials(*it) == my_initials) {
            q.push(&(*it));
        }
    }
    return q;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // STUDENT TODO: Implement this function.
    if (matches.empty()) {
        return "NO MATCHES FOUND\n";
    }else {
        return *matches.front();
    }
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
