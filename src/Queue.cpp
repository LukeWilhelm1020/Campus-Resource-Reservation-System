#include "Queue.h"
#include <iostream>
using namespace std;

// Creates an empty queue by setting both ends to nullptr.
Queue::Queue() {
    front = nullptr;
    rear = nullptr;
}

// Adds a student to the rear of the queue.
// Students are processed in the same order they were added.
void Queue::enqueue(int studentID, string studentName, int resourceID) {
    WaitingStudent* newStudent =
        new WaitingStudent(studentID, studentName, resourceID);

    // If the queue is empty, the new student is both the front and the rear.
    if (rear == nullptr) {
        front = newStudent;
        rear = newStudent;
    }
    else {
        // Add the new student after the current rear.
        // Puts the new student at the back.
        rear->next = newStudent;
        rear = newStudent;
    }
}

// Removes the student at the front of the queue.
void Queue::dequeue() {
    // There is nothing to remove if the queue is empty.
    if (front == nullptr) {
        return;
    }


    // Save the current front so it's memory can be released.
    WaitingStudent* temp = front;

    // Move the front pointer to the next student.
    // Moves the front foward.
    front = front->next;

    // If the queue is now empty, rear must also be nullptr.
    if (front == nullptr) {
        rear = nullptr;
    }

    delete temp;
}

// Displays all students currently waiting in the queue.
void Queue::display() const {
    // Check whether there are any students waiting.
    if (front == nullptr) {
        cout << "No students are currently waiting." << endl;
        return;
    }
    cout << "====== Waiting List ======" << endl;

    WaitingStudent* current = front;

    // Traverse the queue from the front to rear.
    while (current != nullptr) {
        cout << "Student ID: " << current->studentID << endl;
        cout << "Student Name: " << current-> studentName << endl;
        cout << "Resource ID: " << current->resourceID << endl;
        cout << "-----------------------------" << endl;

        current = current->next;
    }

}

// Returns true if the queue is empty.
bool Queue::isEmpty() const {
    return front == nullptr;
}

WaitingStudent* Queue::frontStudent() const {
    return front;
}