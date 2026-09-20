#ifndef RESERVATION_MANAGER_H
#define RESERVATION_MANAGER_H

#include "ResourceManager.h"
#include "Link.h"
#include "Queue.h"
#include "Stack.h"
#include <string>

using namespace std;

class ReservationManager {
private:
    ResourceManager& resourceManager;
    ReservationList& activeReservations;
    Queue& waitingList;
    Stack& cancellationHistory;

public:
    // Creates a reservation manager using the existing systems.
    ReservationManager(ResourceManager& resources,
                        ReservationList& reservations,
                        Queue& waiting,
                        Stack& cancellations);

    // Creates a reservation if the requested resources are avaliable
    // If unavaliable, the student is added to a waiting list.                   
    void createReservation(int reservationID,
                            int studentID,
                            string studentName,
                            int resourceID,
                            string reservationDate);

    // Cancels an active reservation and records it in the cancellation stack.                       
    void cancelReservation(int reservationID);

    // Searches for an active reservation by reservation ID.
    void searchReservation(int reservationID);

    // Displays all currently active reservations.
    void displayReservations();

};
#endif