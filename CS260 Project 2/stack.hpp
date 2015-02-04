/* 
 * File:   stack.hpp
 * Author: Brandan Tyler Lasley
 * Project: CS260 Project 2
 *
 * Created on October 15, 2014, 11:46 AM
 */

#ifndef STACK_HPP
#define	STACK_HPP
#include "house.hpp"
#include <string.h>
#include <fstream>
#include <sstream> 
#include <stdlib.h> 
#include <iostream>

#ifdef	__cplusplus
extern "C" {
#endif

    class stack {
    public:
        stack();
        stack(char * filename);
        stack(const stack& obj);
        ~stack();

        bool push(const House& obj);
        bool pop(House& obj);


        bool peek(House& obj) const;
        bool isEmpty() const;
        bool SaveToDisk(char * filename);
        const stack& operator=(const stack& obj);
    private:
        House * revistList;
        int compaticy;
        int top;
        static const int MAX_SIZE = 100;
        void expandArray();
    };


#ifdef	__cplusplus
}
#endif

#endif	/* STACK_HPP */
