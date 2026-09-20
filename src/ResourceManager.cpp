#include "ResourceManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//default constructoer for an empty resource manager
ResourceManager::ResourceManager() {
}

//gets the information from the resource data file by opening the data file and checking if it opened successfully
bool ResourceManager::loadResources() {
  ifstream inputFile("resources.txt");

  if (!inputFile.is_open()) {
    cout << "Cannot open resource file." << endl;
    return false;
  }
  resources.clear();

  //This reads the resources one line at a time and seperate them into seperate values based on ID, name, type and availability
  string line;
  while (getline(inputFile, line)) {
    stringstream ss(line);
    string idString;
    string name;
    string type;
    string availabilityString;

  //reads the value when seperated by the commas from the list 
    getline(ss, idString, ',');
    getline(ss, name, ',');
    getline(ss, type, ',');
    getline(ss, availabilityString, ',');
    
  //chnages the strings to an integer and change the bool to be 1 = true, 0 for false and store them into the vector
    int id = stoi(idString);
    int availability = stoi(availabilityString);
    bool available = (availability == 1);
    Resource resource(id, name, type, available);
    resources.push_back(resource);
  }

  inputFile.close();
  cout << "Resources loaded" << endl;
  return true;
}

//a display for the contents in the resource manager and to see if it is empty or not
void ResourceManager::displayResources() const {
  if (resources.empty()) {
    cout << "There are no resources to display." << endl;
    return;
  }

  cout << "Here are all the resources." << endl;

  //it goes through every resource that is in the vector and display the current resource
  for (const Resource& resource : resources) {
    resource.display();
    cout << endl;
  }
}

//a display for the availability for the resources and to see if it is empty or not
void ResourceManager::displayAvailability() const {
  if (resources.empty()) {
    cout << "There are no resources to display." << endl;
    return;
  }

  cout << "Here are the availability of the resources." << endl;

//it goes through every resource that is in the vector and and check to see if it is available or not
  for (const Resource& resource : resources) {
    cout << "Resource ID: " << resource.getResourceID() << endl;
    cout << "Resource Name: " << resource.getResourceName() << endl;
    cout << "Resource Type: " << resource.getResourceType() << endl;
    cout << "Availability: ";

    if (resource.getAvailability()) {
      cout << "Available" << endl;
    }
    else {
      cout << "Unavailable" << endl;
    }
    cout << endl;
  }
}
