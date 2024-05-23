#include <iostream>
#include <vector>
#include <string>
#include "roster.h"
#include "student.h"
#include <sstream>

using namespace std;

void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
                 int age, int numDays1, int numDays2, int numDays3, DegreeProgram degreeProgram) {
    Student newStudent(studentID, firstName, lastName, emailAddress,
                       age, numDays1, numDays2, numDays3, degreeProgram);
    classRosterArray.push_back(newStudent);
}

void Roster::remove(string studentID) {
    for (auto it = classRosterArray.begin(); it != classRosterArray.end(); ++it) {
        if (it->getStudentID() == studentID) {
            classRosterArray.erase(it);
            cout << "Removed Successfully";
            return;
        }
    }
    cout << "Student Not Found";
}

void Roster::printAll() const {
    for (const auto& student : classRosterArray) {
        student.print(student.getStudentID());
    }
}

void Roster::printAverageDaysInCourse(string studentID) const {
    for (const auto& student : classRosterArray) {
        if (student.getStudentID() == studentID) {
            cout << "Average Days in Course: " << (student.getNumDays1() + student.getNumDays2() + student.getNumDays3()) / 3 << endl;
            return;
        }
    }
    cout << "Student not Found." << endl;
}

// Print invalid email addresses
void Roster::printInvalidEmails() const {
    cout << "Invalid Email Addresses:" << endl;
    for (const auto& student : classRosterArray) {
        if (!isValidEmail(student.getEmailAddress())) {
            cout << student.getEmailAddress() << endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const {
    for (const auto& student : classRosterArray) {
        if (student.getDegreeProgram() == degreeProgram) {
            student.print(student.getStudentID());
        }
    }
}


bool Roster::isValidEmail(const string& email) const {
    size_t atIndex = email.find('@');
    size_t dotIndex = email.find('.', atIndex);


    return (atIndex != string::npos && dotIndex != string::npos &&
            email.find(' ') == string::npos);
}

void Roster::ParseData() {
    // Parse and add students to the roster
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99@yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Matthew,Ryther,matthew.ryther@wgu.edu,23,19,10,7,SOFTWARE"
    };

    for (const auto& data : studentData) {
        istringstream iss(data);
        string studentID, firstName, lastName, emailAddress, degreeProgramStr;
        int age, numDays1, numDays2, numDays3;
        char comma;

        if (!(getline(iss, studentID, ',') &&
              getline(iss, firstName, ',') &&
              getline(iss, lastName, ',') &&
              getline(iss, emailAddress, ',') &&
              (iss >> age >> comma >> numDays1 >> comma >> numDays2 >> comma >> numDays3 >> comma >> degreeProgramStr))) {
            cerr << "Error: Malformed input data." << endl;
            continue; // Skip to next iteration
        }

        DegreeProgram degreeProgram;
        if (degreeProgramStr == "SECURITY") {
            degreeProgram = SECURITY;
        } else if (degreeProgramStr == "NETWORK") {
            degreeProgram = NETWORK;
        } else if (degreeProgramStr == "SOFTWARE") {
            degreeProgram = SOFTWARE;
        } else {
            cerr << "Error: Unknown degree program." << endl;
            continue; // Skip to next iteration
        }

        add(studentID, firstName, lastName, emailAddress, age, numDays1, numDays2, numDays3, degreeProgram);
    }
}





