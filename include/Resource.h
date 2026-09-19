#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
using namespace std;


class Resource {
    public:
        Resource(); 
        Resource(int id, string name, string type, bool available); 
        
        //the prooject asks for that each resource must contain an ID, Name, Type and status of availability
        
        void setResourceID(int id);    
        int getResourceID() const;
        
        void setResourceName(string name);
        string getResourceName() const;
        
        void setResourceType(string type);
        string getResourceType() const;
        
        void setAvailability(bool available);
        bool getAvailability() const;
            
        void display() const; // be able to display all the resources
    private:
        int resourceID;
        string resourceName;
        string resourceType;
        bool available;
};

#endif
