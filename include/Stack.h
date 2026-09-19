#ifndef STACK_H
#define STACK_H

struct CanceledReservations {
  Reservation reservation;
  CanceledReservations* next;

  CanceledReservation(const Reservation&res) : reservation(res), next(nullptr){}
};


class Stack {
  Public:
    Stack(); //default constructor to create an empty cancellation stack
   
    //stores into the cancellation stack
    void push(const Reservation& reservation);
    //removes the most recently canceled reservation 
    Reservation pop();

    //The display of the cancellation history
    void display() const;

    bool isEmpty() const;
  Private:
    //will show the the most recent canceled reservation which will be the top of the stack
    CanceledReservations* top;
}

#endif
