#include <iostream>
#include <string>

using namespace std;

struct Song {
    string title;
    string artist;
    int ratings[3];

    Song *next;
    Song *prev;
};


Song* head = nullptr;
Song* current = nullptr;

void addSong(string t, string a, int r[]) {
    Song* newSong = new Song;
    newSong->title = t;
    newSong->artist = a;
    for (int i = 0; i < 3; i++) {
        newSong->ratings[i] = r[i];
    }
    newSong->next = nullptr;
    newSong->prev = nullptr;

    if (head == nullptr) {
        head = newSong;
        current = head;
    } else {
        Song* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newSong;
        newSong->prev = temp;
    }
}

void nextSong() {
    if (current && current->next) current = current->next;
}

void prevSong() {
    if (current && current->prev) current = current->prev;
}

void removeCurrent() {
    if (!current) return;

    Song* toDelete = current;

    /
    if (toDelete->prev) toDelete->prev->next = toDelete->next;
    if (toDelete->next) toDelete->next->prev = toDelete->prev;


    if (toDelete == head) head = toDelete->next;


    if (toDelete->next) current = toDelete->next;
    else current = toDelete->prev;

    delete toDelete;
}

void display() {
    Song* temp = head;
    while (temp != nullptr) {

        if (temp == current) cout << "-> ";
        else cout << "   ";

        cout << temp->title << " - " << temp->artist << " | Ratings: ";

        for (int i = 0; i < 3; i++) {
            cout << temp->ratings[i] << " ";
        }
        cout << endl;
        temp = temp->next;
    }
}

int main() {
    int r1[3] = {5, 4, 3};
    int r2[3] = {4, 4, 4};

    addSong("Song A", "Artist A", r1);
    addSong("Song B", "Artist B", r2);

    display();
    return 0;
}
