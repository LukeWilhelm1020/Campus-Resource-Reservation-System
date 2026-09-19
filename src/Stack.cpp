#include "Stack.h"
#include <iostream>

using namespace std;

//default stack constructor
Stack::Stack() {
  top = nullptr;
}
//stores into the cancellation stack
//This makes it be the LIFO fuctionality where the most recent will be on top
void Stack::push(const Reservation& reservation) {
  CanceledReservation* newReservation = new CanceledReservation(reservation);

  newReservation -> next = top;
  top = newReservation;
}
//removes the most recently canceled reservation
Reservation Stack::pop() {
  if (top == nullptr) {
    return Reservation();
  }
  CanceledReservation* temp = top;
  Reservation reservation = temp -> reservation;
  top = top -> next;
  delete temp;
  return reservation;
}
//The display of the cancellation history
void Stack::display() const {
  if (top == nullptr) {
    cout << "There are no cancelled reservations." << endl;
    return;
  }
  cout << " ---Cancelation History--- " << endl;
  CanceledReservation* current = top;

  while (current != nullptr) {
    current -> reservation.display();
    cout << endl;
    current = current -> next;
  }
}
//when the cancellation list is empty and true itll show as empty
bool Stack::isEmpty() const {
  return top == nullptr;
}
