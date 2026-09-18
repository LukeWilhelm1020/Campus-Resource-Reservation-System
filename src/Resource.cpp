#include "Resource.h"
#include <iostream>

using namespace std;

Resource::Resource() { //for the defualt constrictor they all initialize for Null or 0 and blank
    resourceID = 0;
    resourceName = "";
    resourceType = "";
    available = true;
}

Resource::Resource(int id, string name, string type, bool status) {
    resourceID = id;
    resourceName = name;
    resourceType = type;
    available = status;
}

int Resource::getResourceID() const {
    return resourceID;
}
void Resource::setResourceID(int id) {
    resourceID = id;
}

string Resource::getResourceName() const {
    return resourceName;
}
void Resource::setResourceName(string name) {
    resourceName = name;
}

string Resource::getResourceType() const {
    return resourceType;
}
void Resource::setResourceType(string type) {
    resourceType = type;
}

bool Resource::getAvailability() const{
    return available;
}
void Resource::setAvailability(bool status) {
    available = status;
}

void Resource::display() const {
    cout << "Resource ID: " << resourceID << endl;
    cout << "Resource Name: " << resourceName << endl;
    cout << "Resource Type: " << resourceType << endl;
    cout << "Availability: ";
    if (available) 
        cout << "Available" << endl;
    else 
        cout << "Unavailable" << endl;
}
