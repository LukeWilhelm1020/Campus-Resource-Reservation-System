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
  ifstream inputFile("data/resources.txt");

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
    getline(ss, idString, '|');
    getline(ss, name, '|');
    getline(ss, type, '|');
    getline(ss, availabilityString, '|');
    
  //chnages the strings to an integer and change the bool to be 1 = true, 0 for false and store them into the vector
    string id = idString;
    bool available = (availabilityString == "Available");
      
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
// returns pointer to search by ID
Resource* ResourceManager::findResource(string resourceID) {
  for (Resource& resource : resources) {
    if (resource.getResourceID() == resourceID) {
      return &resource;
    }
  }

  return nullptr;
}
// Searches and displays resource ID
void ResourceManager::searchResource(string resourceID) const {
  for (const Resource& resource : resources) {
    if (resource.getResourceID() == resourceID) {
      cout << "Resource found!" << endl;
      resource.display();
      return;
    }
  }

  cout << "Resource " << resourceID << " not found." << endl;
}

//Sorts resources by name with a merge-sort
void ResourceManager::sortResources() {
    if (resources.size() > 1) {
        mergeSort(0, static_cast<int>(resources.size()) - 1);
    }
    
    cout << "Resources sorted by Resource Name." << endl;
}

//Recursively divide the resource vector into sections
void ResourceManager::mergeSort(int left, int right) {
    if (left >= right) {
        return;
    }
    
    int middle = left + (right - left) / 2;
    
    mergeSort(left, middle);
    mergeSort(middle + 1, right);
    merge(left, middle, right);
}

//Combine two sorted sections into a single section
void ResourceManager::merge(int left, int middle, int right) {

    vector<Resource> temporary;

    temporary.reserve(right - left + 1);

    int i = left;

    int j = middle + 1;

    while (i <= middle && j <= right) {

        // Sort by resource name

        if (resources[i].getResourceName() <= resources[j].getResourceName()) {

            temporary.push_back(resources[i]);

            ++i;

        }

        else {

            temporary.push_back(resources[j]);

            ++j;

        }

    }

    // Copy remaining resources from the left half

    while (i <= middle) {

        temporary.push_back(resources[i]);

        ++i;

    }

    // Copy remaining resources from the right half

    while (j <= right) {

        temporary.push_back(resources[j]);

        ++j;

    }

    // Copy the sorted section back into resources

    for (int k = 0; k < static_cast<int>(temporary.size()); ++k) {

        resources[left + k] = temporary[k];

    }

}

void ResourceManager::generateReport() const {
    int availableCount = 0;
    int unavailableCount = 0;
    
    for (const Resource& resource : resources) {
        if (resource.getAvailability()) {
            availableCount++;
        }
        else {
            unavailableCount++;
        }
    }
    
    cout << "\n==== Resource Report ====" << endl;
    cout << "Total Resources: " << resources.size() << endl;
    cout << "Available Resources: " << availableCount << endl;
    cout << "Unavailable Resources: " << unavailableCount << endl;
}

const vector<Resource>& ResourceManager::getResources() const {
    return resources;
}
            
        
        
    


