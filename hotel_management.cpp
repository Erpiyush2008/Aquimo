#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Guest {
public:
    string name;
    int age;
    string gender;
    int roomNumber;

    Guest(string n, int a, string g, int r) : name(n), age(a), gender(g), roomNumber(r) {}
};

class Hotel {
private:
    vector<Guest> guests;
    vector<bool> rooms;

public:
    Hotel(int totalRooms) {
        rooms.resize(totalRooms, false); 
    }

    void addGuest(string name, int age, string gender) {
        for (int i = 0; i < rooms.size(); ++i) {
            if (!rooms[i]) { 
                rooms[i] = true; 
                guests.emplace_back(name, age, gender, i + 1); 
                cout << "Guest " << name << " added to room " << (i + 1) << endl;
                return;
            }
        }
        cout << "No rooms available!" << endl;
    }

    void displayGuests() {
        cout << "\nGuest List:\n";
        for (const auto& guest : guests) {
            cout << "Name: " << guest.name
                 << ", Age: " << guest.age
                 << ", Gender: " << guest.gender
                 << ", Room Number: " << guest.roomNumber << endl;
        }
    }

    void removeGuest(int roomNumber) {
        if (roomNumber < 1 || roomNumber > rooms.size() || !rooms[roomNumber - 1]) {
            cout << "Invalid room number or room is already available!" << endl;
            return;
        }
        rooms[roomNumber - 1] = false;
        for (auto it = guests.begin(); it != guests.end(); ++it) {
            if (it->roomNumber == roomNumber) {
                guests.erase(it);
                cout << "Guest removed from room " << roomNumber << endl;
                return;
            }
        }
    }
};

int main() {
    Hotel hotel(5); 
    int choice;

    do {
        cout << "\nHotel Management System\n";
        cout << "1. Add Guest\n";
        cout << "2. Display Guests\n";
        cout << "3. Remove Guest\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, gender;
                int age;
                cout << "Enter guest name: ";
                cin >> name;
                cout << "Enter guest age: ";
                cin >> age;
                cout << "Enter guest gender: ";
                cin >> gender;
                hotel.addGuest(name, age, gender);
                break;
            }
            case 2:
                hotel.displayGuests();
                break;
            case 3: {
                int roomNumber;
                cout << "Enter room number to remove guest: ";
                cin >> roomNumber;
                hotel.removeGuest(roomNumber);
                break;
            }
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
