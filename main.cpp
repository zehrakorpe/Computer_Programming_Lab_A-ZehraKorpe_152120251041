#include <iostream>
#include <string>

using namespace std;

struct Package {
    string packageID;
    string destinationCity;
    int dimensions[3]; 
    Package* next;     
};
struct Courier {
    string courierName;
    string vehicleType;
};

Package* top = nullptr; 

Courier courierArray[5]; 
int front = 0;          
int rear = -1;          
int currentSize = 0;    
int capacity = 5;        


void pushPackage(string id, string city, int d0, int d1, int d2) {
    Package* newPack = new Package;
    newPack->packageID = id;
    newPack->destinationCity = city;
    newPack->dimensions[0] = d0;
    newPack->dimensions[1] = d1;
    newPack->dimensions[2] = d2;

    newPack->next = top; 
    top = newPack;      
}


void enqueueCourier(string name, string vehicle) {
    if (currentSize == capacity) {
        cout << "Queue is full!" << endl;
        return;
    }
  
    rear = (rear + 1) % capacity; 
    courierArray[rear].courierName = name;
    courierArray[rear].vehicleType = vehicle;
    currentSize++;
}

void dispatch() {

    if (top == nullptr) {
        cout << "No packages in stack!" << endl;
        return;
    }
    if (currentSize == 0) {
        cout << "No couriers in queue!" << endl;
        return;
    }


    Package* temp = top;
    cout << "Dispatching package " << temp->packageID << " to " << temp->destinationCity;
    top = top->next;
    delete temp;


    cout << " with courier " << courierArray[front].courierName << endl;
    front = (front + 1) % capacity;
    currentSize--;
}
void display() {

    cout << "\n--- CURRENT PACKAGES (Stack) ---" << endl;
    if (top == nullptr) {
        cout << "Stack is empty." << endl;
    } else {
        Package* temp = top;
        while (temp != nullptr) {
            cout << "ID: " << temp->packageID << " | City: " << temp->destinationCity << endl;
            temp = temp->next;
        }
    }


    cout << "--- WAITING COURIERS (Queue) ---" << endl;
    if (currentSize == 0) {
        cout << "Queue is empty." << endl;
    } else {
        for (int i = 0; i < currentSize; i++) {

            int index = (front + i) % capacity;
            cout << i + 1 << ". " << courierArray[index].courierName << " (" << courierArray[index].vehicleType << ")" << endl;
        }
    }
    cout << endl;
}
