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

    Resource* findResource(string resourceID); // finds a resource by ID

    void searchResource(string resourceID) const;

    void sortResources();

    void generateReport() const;

    const vector<Resource>& getResources() const; //accessing resources without making changes

  private:
    vector<Resource> resources; //contains all resources loaded from the resource data file

    //Merge Sort helpers, implementing without the use of a sort library.
    void mergeSort(int left, int right);
    void merge(int left, int middle, int right);
    
};

#endif
