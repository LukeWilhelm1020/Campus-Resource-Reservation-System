#ifndef QUEUE_H
#define QUEUE_H

#include <string>
using namespace std;

// Represents a single student waiting for an unavaliable resource.
struct WaitingStudent {
    int studentID;
    string studentName;
    int resourceID;
    WaitingStudent* next;

    // Creates waiting list entry for a student and a resource.
    WaitingStudent(int id, string name, int resource)
        :studentID(id), studentName(name), resourceID(resource), next(nullptr) {}

};

// Queue stores students waiting for a resource using First in First out ordering.
class Queue {
    private:
        // Points to student who has been waiting the longest.
        WaitingStudent* front;
        // Points to the most recent student.
        WaitingStudent* rear;

    public:
        // Creates an empty waiting queue.
        Queue();
        // Adds one student to the end of the waiting queue.
        void enqueue(int studentID, string studentName, int resourceID);
        // Removes the student at the front of the waiting queue.
        void dequeue();
        // Displays all students currently in the waiting queue.
        void display() const;
        // Returns true if the waiting queue is empty.
        bool isEmpty() const;

};

#endif