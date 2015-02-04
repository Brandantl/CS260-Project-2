/* 
 * File:   main.cpp
 * Author: Brandan Tyler Lasley
 * Project: CS260 Project 2
 *
 * Created on October 15, 2014, 11:43 AM
 */

#include <cstdlib>
#include "queue.hpp"
#include "stack.hpp"

using namespace std;
void Header();

int main(int argc, char** argv) {
    char fileName[] = "data.dat";
    queue housesOnList(fileName);
    House house;
    stack houseInterested;
    char response;

    cout << "\nthe houses we will visit today:" << endl << endl;
	Header();
    housesOnList.DisplayAll();
    if (housesOnList.getSize() != 0) {
        while (housesOnList.dequeue(house)) {
            cout << "\nnext house to be visited:" << endl << endl;
			Header();
			cout << house;
            cout << "\nWould you like to revisit this house on our way back? (y, n): ";
            cin >> response;
            cin.ignore(100, '\n');

            if (response == 'y' || response == 'Y') {
                cout << "\nthe house is saved for revisiting" << endl;
                houseInterested.push(house);
            }
        }

        cout << "\nWe have finished the first round of screening" << endl << endl;
        cout << "\nOn the way back to the office: " << endl << endl;

        while (houseInterested.pop(house)) {
			cout << "\nnext house to be revisited: " << endl;
			Header();
			cout << house << endl;
        }
    }

    cout << "\nWe've finished the second round. ready to make an offer? (y, n):";
    cin >> response;
    cin.ignore(100, '\n');
    cout << "\nlet's talk about that in my office. " << endl << endl;

    return 0;
}

void Header() {
	cout << left << setw(25) << "Address" << left << setw(30) << "Description" << left << setw(9) << "Sqr Foot " << left << setw(5) << "Bed" << left << setw(5) << "Bath" << endl;
}

