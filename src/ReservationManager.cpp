#include "ReservationManager.h"
#include <iostream>

using namespace std;

ReservationManager::ReservationManager(ResourceManager& resources,
                                        ReservationList& reservations,
                                        Queue& waiting,
                                        Stack& cancellations)
    : resourceManager(resources),
      activeReservations(reservations),
      waitingList(waiting),
      cancellationHistory(cancellations) {
 }

 void ReservationManager::createReservation(int reservationID,
                                            int studentID,
                                            string studentName,
                                            int resourceID,
                                            string reservationDate) {
    Resource* resource = resourceManager.findResource(resourceID);                                            
        
    if (resource == nullptr) {
        cout << "Resource not found." << endl;
        return;
    }

    if (resource->getAvailability()) {
        Reservation reservation(reservationID,
                                studentID,
                                studentName,
                                resourceID,
                                reservationDate);
        activeReservations.insertReservation(
            reservationID,
            studentID,
            studentName,
            resourceID,
            reservationDate
        );

        resource->setAvailability(false);

        cout << "Reservation created successfully." << endl;
    }
    else {
        waitingList.enqueue(studentID, studentName, resourceID);

        cout << "Resource is unavialable. Adding student to waiting list." << endl;
    }
}

void ReservationManager::cancelReservation(int reservationID) {
    Reservation* reservation = 
        activeReservations.searchReservation(reservationID);

    if (reservation == nullptr) {
        cout << "Reservation not found." << endl;
        return;
    }

    Reservation canceled = *reservation;

    Resource* resource = 
        resourceManager.findResource(canceled.resourceID);
    
    activeReservations.removeReservation(reservationID);
    cancellationHistory.push(canceled);

    if (resource != nullptr) {
        resource->setAvailability(true);

        WaitingStudent* nextStudent = waitingList.frontStudent();

        if (nextStudent != nullptr &&
            nextStudent->resourceID == canceled.resourceID) {

            int nextReservationID = canceled.reservationID + 1;
            
            activeReservations.insertReservation(
                nextReservationID,
                nextStudent->studentID,
                nextStudent->studentName,
                nextStudent->resourceID,
                canceled.reservationDate
            );

            resource->setAvailability(false);

            waitingList.dequeue();
            cout << "Resource automatically assigned to " 
                << nextStudent->studentName << "." << endl;
            }
    }

    cout << "Reservation canceled successfully. " << endl;
}

void ReservationManager::searchReservation(int reservationID) {
    Reservation* reservation =
        activeReservations.searchReservation(reservationID);

    if (reservation == nullptr) {
        cout << "Reservation not found." << endl;
        return;
    }

    reservation->display();
}

void ReservationManager::displayReservations() {
    activeReservations.displayReservations();
}

            
                                        