#ifndef LINK_H
#define LINK_H

#include <iostream>
#include <string>
using namespace std;


// Represents one reservation in the active linked list.
struct Reservation {
    int reservationID;
    int studentID;
    string studentName;
    int resourceID;
    string reservationDate;
    Reservation* next;

    // Setting arguments
    Reservation()
        : reservationID(0),
        studentID(0),
        studentName(""),
        resourceID(0),
        reservationDate(""),
        next(nullptr) {}

    // Creates a reservation node.
    Reservation(int id, int studentId, string student, 
        int resourceId, string date) {
            reservationID = id;
            studentID = studentId;
            studentName = student;
            resourceID = resourceId;
            reservationDate = date;
            next = nullptr;
    }
    // adding display function 
void display() const {
    cout << "Reservation ID: " << reservationID << endl;
    cout << "Student ID: " << studentID << endl;
    cout << "Student Name: " << studentName << endl;
    cout << "Resource ID: " << resourceID << endl;
    cout << "Reservation Date: " << reservationDate << endl; 
}

};


#endif