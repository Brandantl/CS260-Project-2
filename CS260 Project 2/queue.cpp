/* 
 * File:   queue.cpp
 * Author: Brandan Tyler Lasley
 * Project: CS260 Project 2
 *
 * Created on October 15, 2014, 11:45 AM
 */
#include "queue.hpp" 

queue::queue() {
    size = 0;
    front = 0;
    rear = 0;
}

queue::queue(char * filename) {
    size = 0;
    front = 0;
    rear = 0;
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
            this->enqueue(obj);
        }
    }
    if (!codes.eof()) {
        cout << "Error reading/processing file!";
    }
}

bool queue::peek(House& obj) const {
    if (!isEmpty()) {
        obj = waitList[front];
        return true;
    }
    return false;
}

bool queue::enqueue(const House& obj) {
    if (size == MAX_SIZE) {
        return false;
    }
    waitList[rear] = obj;
    rear = (rear + 1) % MAX_SIZE;
    size++;
    return true;
}

bool queue::dequeue(House& obj) {
    if (isEmpty()) {
        return false;
    }
    obj = waitList[front];
    front = (front + 1) % MAX_SIZE;
    size--;
    return true;
}

bool queue::isEmpty(void) const {
    if (size == 0) {
        return true;
    }
    return false;
}

bool queue::SaveToDisk(char * filename) {
    ofstream launchCodesFile;
    launchCodesFile.open(filename, ios::trunc); // Truncate those codes, do not want spies stealing them.
    if (!isEmpty()) {
        for (int i = 0; i < size; i++) {
            int POS = (front + i) % MAX_SIZE;
            launchCodesFile << waitList[POS].getAddress();
            launchCodesFile << ",";
            launchCodesFile << waitList[POS].getDescription();
            launchCodesFile << ",";
            launchCodesFile << waitList[POS].getBath();
            launchCodesFile << ",";
            launchCodesFile << waitList[POS].getSquareFoot();
            launchCodesFile << ",";
            launchCodesFile << waitList[POS].getBed();
            launchCodesFile << "\n";
        }
    }
    launchCodesFile.close();
    return true;
}

int queue::getSize(void) {
    return this->size;
}

void queue::DisplayAll() {
    if (!isEmpty()) {
        for (int i = 0; i < size; i++) {
            int POS = (front + i) % MAX_SIZE;
            cout << waitList[POS];
        }
    }
}
