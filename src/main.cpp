#include <iostream>

#include "ResourceManager.h"
#include "ReservationManager.h"
#include "Link.h"
#include "Queue.h"
#include "Stack.h"

using namespace std;

int main() {
    ResourceManager resourceManager;
    ReservationList reservations;
    Queue waitingList;
    Stack cancellationHistory;

    ReservationManager reservationManager(
        resourceManager,
        reservations,
        waitingList,
        cancellationHistory
    );

    resourceManager.loadResources();

    int choice;

    do {
        cout << "\n===== Campus Resource Reservation System =====" << endl;
        cout << "1. View Resources" << endl;
        cout << "2. View Availability" << endl;
        cout << "3. Create Reservation" << endl;
        cout << "4. Cancel Reservation" << endl;
        cout << "5. View Waiting Lists" << endl;
        cout << "6. Undo Cancellation" << endl;
        cout << "7. Search Reservations" << endl;
        cout << "8. Search Resources" << endl;
        cout << "9. Sort Resources" << endl;
        cout << "10. Generate Report" << endl;
        cout << "11. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            // switch case checking the options entered by the user
            case 1:
                resourceManager.displayResources();
                break;
                
            case 2:
                resourceManager.displayAvailability();
                break;

            case 3: {
                int reservationID;
                int studentID;
                string studentName;
                string resourceID;
                string reservationDate;

                // Displaying interface options
                cout << "Enter reservationID: ";
                cin >> reservationID;

                cout << "Enter student ID: ";
                cin >> studentID;

                cout << "Enter student name: ";
                cin.ignore();
                getline(cin, studentName);

                cout << "Enter resource ID: ";
                cin >> resourceID;

                cout << "Enter reservation date: ";
                cin.ignore();
                cin >> reservationDate;

                reservationManager.createReservation(
                    reservationID,
                    studentID,
                    studentName,
                    resourceID,
                    reservationDate
                );

                break;
            }   
            
            case 4: {
                int reservationID;

                cout << "Enter reservation ID to cancel: ";
                cin >> reservationID;

                reservationManager.cancelReservation(reservationID);

                break;
            }

            case 5:
                waitingList.display();
                break;

            case 6:
                reservationManager.undoCancellation();
                break;

            case 7: {
                int reservationID;
                cout << "Enter reservation ID: ";
                cin >> reservationID;
                reservationManager.searchReservation(reservationID);
                break;
            }

            case 8: {
                string resourceID;

                cout << "Enter resource ID: ";
                cin >> resourceID;

                resourceManager.searchResource(resourceID);

                break;
            }

            case 9:
                resourceManager.sortResources();
                break;

            case 10:
                resourceManager.generateReport();
                reservationManager.generateReport();
                break;

            case 11:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "That option is not implemented yet." << endl;
        }
    } while (choice != 11);
    return 0;

}
