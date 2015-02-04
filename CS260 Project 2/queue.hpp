/* 
 * File:   queue.hpp
 * Author: Brandan Tyler Lasley
 * Project: CS260 Project 2
 * 
 * Created on October 15, 2014, 11:46 AM
 */

#ifndef QUEUE_HPP
#define	QUEUE_HPP
#include "house.hpp"
#include <string.h>
#include <fstream>
#include <sstream> 
#include <stdlib.h> 
#include <iostream>

using namespace std;

class queue {
public:
    queue(void);
    queue(char * filename);
    bool enqueue(const House& obj);
    bool dequeue(House& obj);
    bool peek(House& obj) const;
    bool isEmpty(void)const;
    bool SaveToDisk(char * filename);
    int getSize(void);
    void DisplayAll();
private:
    static const int MAX_SIZE = 100;
    House waitList[MAX_SIZE];
    int front;
    int rear;
    int size;
};


#endif	/* QUEUE_HPP */