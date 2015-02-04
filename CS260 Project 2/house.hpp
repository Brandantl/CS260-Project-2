/* 
 * File:   house.hpp
 * Author: Brandan Tyler Lasley
 * Project: CS260 Project 2
 *
 * Created on October 15, 2014, 11:45 AM
 */

#ifdef _MSC_VER // Disables Microsofts Cross-platform restriction warning. 
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef HOUSE_HPP
#define	HOUSE_HPP
#include <string.h>
#include <iostream>
#include <iomanip>
using namespace std;

class House {
public:
public:
    House(void);
    ~House(void);
    
    float getSquareFoot(void) const;
    char * getAddress(void) const;
    char * getDescription(void) const;
    int getBed(void) const;
    float getBath(void) const;
    
    void setSquareFoot(float _sqrfoot);
    void setAddress(const char * _address);
    void setDescription(const char * _description);
    void setBed(int _bed);
    void setBath(float _bath);
    
    bool operator==(const House& obj) const;
    const House& operator=(const House& obj);
    friend ostream& operator<< (ostream& , const House&);
private:
    char * address;
    char * description;
    float squareFoot;
    int Bed;
    float Bath;
};


#endif	/* HOUSE_HPP */