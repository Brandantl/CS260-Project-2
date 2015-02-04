/* 
 * File:   house.cpp
 * Author: Brandan Tyler Lasley
 * Project: CS260 Project 2
 *
 * Created on October 15, 2014, 11:45 AM
 */
#include "house.hpp"

House::House(void) {
    address = NULL;
    description = NULL;
    squareFoot = 0;
    Bed = 0;
    Bath = 0;
}

House::~House(void) {
    if (this->address) {
        delete [] this->address;
    }
    if (this->description) {
        delete [] this->description;
    }
}

float House::getSquareFoot(void) const {
    return this->squareFoot;
}

char * House::getAddress(void) const {
    return this->address;
}

char * House::getDescription(void) const {
    return this->description;
}

int House::getBed(void) const {
    return this->Bed;
}

float House::getBath(void) const {
    return this->Bath;
}

void House::setSquareFoot(float _sqrfoot) {
    this->squareFoot = _sqrfoot;
}

void House::setAddress(const char * _address) {
    if (this->address) {
        delete [] this->address;
    }
    this->address = new char[strlen(_address) + 1];
    strcpy(this->address, _address);
}

void House::setDescription(const char * _description) {
    if (this->description) {
        delete [] this->description;
    }
    this->description = new char[strlen(_description) + 1];
    strcpy(this->description, _description);
}

void House::setBed(int _bed) {
    this->Bed = _bed;
}

void House::setBath(float _bath) {
    this->Bath = _bath;
}

bool House::operator==(const House& obj) const {
    if (strcmp(obj.address, this->address) < 0) {
        if (strcmp(obj.description, this->description) < 0) {
            if (this->Bath == obj.Bath) {
                if (this->Bed == obj.Bed) {
                    if (this->squareFoot == obj.squareFoot) {
                        return true;
                    }
                }
            }

        }
    }
    return false;
}

const House& House::operator=(const House& obj) {
    if (this->description) {
        delete [] this->description;
    }
    if (this->address) {
        delete [] this->address;
    }
    this->address = new char[strlen(obj.address) + 1];
    this->description = new char[strlen(obj.description) + 1];
    strcpy(this->address, obj.address);
    strcpy(this->description, obj.description);
    this->Bed = obj.Bed;
    this->Bath = obj.Bath;
    this->squareFoot  = obj.squareFoot;
    return *this;
}

ostream& operator<<(ostream& out, const House& obj) {
	out << left << setw(25) << obj.address << left << setw(30) << obj.description << left << setw(9) << obj.squareFoot << left << setw(5) << obj.Bed << left << setw(5) << obj.Bath << endl;
    return out;
}