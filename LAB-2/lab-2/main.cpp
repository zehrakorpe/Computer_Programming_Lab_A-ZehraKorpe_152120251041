#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;
};


void addWord(Node* &head, string word) {

    Node* newNode = new Node();
    newNode->data = word;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else {

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void undo(Node* &head) {

    if (head == nullptr) {
        return;
    }


    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;

  while (temp->next->next != nullptr) {
        temp = temp->next;
    }

 delete temp->next;
  temp->next = nullptr;

}
 void display(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << "[" << temp->data << "] -> ";
        temp = temp->next;
    }


    cout << "NULL" << endl;
}



int main() {

    Node* head = nullptr;
    string input;

    cout << " TEXT EDITOR " << endl;
    cout << " Please type a word to add, 'UNDO' to delete last, 'EXIT' to quit." << endl;


    while (true) {
        cout << "\nEnter word: ";
        cin >> input;


        if (input == "EXIT") {
            cout << "Closing..." << endl;
            break;
        }
        else if (input == "UNDO") {
            undo(head);
        }
        else {
            addWord(head, input);
        }


        cout << "Current List: ";
        display(head);
    }

    return 0;
}




