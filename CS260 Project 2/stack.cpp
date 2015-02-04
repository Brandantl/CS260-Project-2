/* 
 * File:   stack.cpp
 * Author: Brandan Tyler Lasley
 * Project: CS260 Project 2
 *
 * Created on October 15, 2014, 11:45 AM
 */
#include "stack.hpp"

stack::stack() {
    compaticy = MAX_SIZE;
    top = -1;
    revistList = new House[compaticy];
}

stack::stack(char * filename) {
    compaticy = MAX_SIZE;
    top = -1;
    ifstream codes(filename);
    while (codes) {
        string s;
        if (!getline(codes, s)) break;
        istringstream ss(s);
        while (ss) {
            House obj;
            string s;
            if (!getline(ss, s, ',')) break;
            obj.setAddress(s.c_str());
            if (!getline(ss, s, ',')) break;
            obj.setDescription(s.c_str());
            if (!getline(ss, s, ',')) break;
            obj.setBath((float) atof(s.c_str()));
            if (!getline(ss, s, ',')) break;
            obj.setSquareFoot((float) atof(s.c_str()));
            if (!getline(ss, s, ',')) break;
            obj.setBed(atoi(s.c_str()));
            this->push(obj);
        }
    }
    if (!codes.eof()) {
        cout << "Error reading/processing file!";
    }
}

stack::stack(const stack& obj) {
    compaticy = obj.compaticy;
    revistList = new House[compaticy];
    top = obj.top;
    for (int i = 0; i <= obj.top; i++) {
        revistList[i] = obj.revistList[i];
    }
}

stack::~stack() {
    if (this->revistList) {
        delete [] this->revistList;
    }
}

bool stack::push(const House& obj) {
    if (top + 1 == compaticy) {
        expandArray();
    }

    top++;
    revistList[top] = obj;
    return true;
}

bool stack::pop(House& obj) {
    if (isEmpty()) {
        return false;
    }
    obj = revistList[top];
    top--;
    return true;
}

bool stack::peek(House& obj) const {
    if (isEmpty()) {
        return false;
    }
    obj = revistList[top];
    return true;
}

bool stack::isEmpty() const {
    return top < 0;
}

bool stack::SaveToDisk(char * filename) {
    ofstream launchCodesFile;
    launchCodesFile.open(filename, ios::trunc); // Truncate those codes, do not want spies stealing them.
    if (!isEmpty()) {
        for (int i = 0; i < top; i++) {
            int POS = (top + i) % MAX_SIZE;
            launchCodesFile << revistList[POS].getAddress();
            launchCodesFile << ",";
            launchCodesFile << revistList[POS].getDescription();
            launchCodesFile << ",";
            launchCodesFile << revistList[POS].getBath();
            launchCodesFile << ",";
            launchCodesFile << revistList[POS].getSquareFoot();
            launchCodesFile << ",";
            launchCodesFile << revistList[POS].getBed();
            launchCodesFile << "\n";
        }
    }
    launchCodesFile.close();
    return true;
}

void stack::expandArray() {
	House  * tmp;
	tmp = new House[compaticy + 10];
    for (int i = 0; i <= top; i++) {
        tmp[i] = revistList[i];
    }
    delete [] revistList;
    revistList = tmp;
}

const stack& stack::operator=(const stack& obj) {
    if (this == &obj) {
        return *this;
    }
    delete [] revistList;
    compaticy = obj.compaticy;
    top = obj.top;
    revistList = new House[compaticy];
    for (int i = 0; i <= obj.top; i++) {
        revistList[i] = obj.revistList[i];
    }
    return *this;
}
