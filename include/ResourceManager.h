#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include "Resource.h"
#include <string>
#include <vector>

using namespace std;

class ResourceManager {
  public:
    ResourceManager (); //default constructor to create an empty resource manager

    bool loadResources (); //getting the information from the text file

    void displayResources() const; // displays the resources currently saved in the text file

    void displayAvailability() const; // displays if the resources are available or not

    Resource* findResource(int resourceID); // finds a resource by ID

  private:
    vector<Resource> resources; //contains all resources loaded from the resource data file

};

#endif
