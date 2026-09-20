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

// Linked list for active reservations
class ReservationList {
private:
    Reservation* head;

public:

    // Constructor
    ReservationList() {
        head = nullptr;
    }

    // Insert a new reservation
    void insertReservation(int id, int studentId, string student,
                            int resourceId, string date) {

        Reservation* newReservation =
            new Reservation(id, studentId, student, resourceId, date);

        // If the list is empty
        if (head == nullptr) {
            head = newReservation;
        }
        else {
            // Traverse to the end of the list
            Reservation* current = head;

            while (current->next != nullptr) {
                current = current->next;
            }

            // Add the new reservation
            current->next = newReservation;
        }
    }


    // Remove a reservation using its reservation ID
    void removeReservation(int id) {

        // Nothing to remove
        if (head == nullptr) {
            cout << "No active reservations." << endl;
            return;
        }

        // If the reservation to remove is the first node
        if (head->reservationID == id) {
            Reservation* temp = head;
            head = head->next;
            delete temp;

            cout << "Reservation " << id << " removed." << endl;
            return;
        }

        // Search through the list
        Reservation* current = head;

        while (current->next != nullptr &&
               current->next->reservationID != id) {
            current = current->next;
        }

        // Reservation was found
        if (current->next != nullptr) {
            Reservation* temp = current->next;
            current->next = temp->next;
            delete temp;

            cout << "Reservation " << id << " removed." << endl;
        }
        else {
            cout << "Reservation " << id << " not found." << endl;
        }
    }


    // Search for a reservation using its reservation ID
    Reservation* searchReservation(int reservationID) {

        Reservation* current = head;

        while (current != nullptr) {

            if (current->reservationID == reservationID) {
                cout << "Reservation found!" << endl;
                cout << "Reservation ID: "
                     << current->reservationID << endl;

                cout << "Student ID: "
                     << current->studentID << endl;

                cout << "Student Name: "
                     << current->studentName << endl;

                cout << "Resource ID: "
                     << current->resourceID << endl;

                cout << "Reservation Date: "
                     << current->reservationDate << endl;

                return current;
            }

            current = current->next;
        }

        cout << "Reservation " << reservationID
             << " not found." << endl;

        return nullptr;
    }


    // Traverse and display all active reservations
    void displayReservations() {

        Reservation* current = head;

        // Check if list is empty
        if (current == nullptr) {
            cout << "No active reservations." << endl;
            return;
        }

        cout << "===== Active Reservations =====" << endl;

        // Traverse the linked list
        while (current != nullptr) {

            cout << "Reservation ID: "
                 << current->reservationID << endl;

            cout << "Student ID: "
                 << current->studentID << endl;

            cout << "Student Name: "
                 << current->studentName << endl;

            cout << "Resource ID: "
                 << current->resourceID << endl;

            cout << "Reservation Date: "
                 << current->reservationDate << endl;

            cout << "-----------------------------" << endl;

            current = current->next;
        }
    }
};



#endif