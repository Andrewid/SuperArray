
// File: SuperArray
// Created by Hugo Valle on 10/31/2017.
// Copyright (c) 2017 WSU
// Edited by Andrew Merrell

#include "SuperArray.h"

/*!
 * Constructor
 * @param begIndex User's low index
 * @param capacity Maximum array capacity
 */
SuperArray::SuperArray(const int begIndex, const unsigned int capacity) {

    /* This is declaring a local variable, if you have data member
     * called int* arr, the code on line ## will NOT refer to the data
     * member, instead you created a second arr pointer, and this
     * second pointer dies and is lost forever when the constructor ends
     */
    arr = new int[capacity];
    setCapacity(capacity);
    setLowIndex(begIndex);
    setHighIndex(begIndex + capacity - 1);
    // Other info below
}

int SuperArray::getLowIndex() const {
    return lowIndex;
}

void SuperArray::setLowIndex(int lowIndex) {
    SuperArray::lowIndex = lowIndex;
}

int SuperArray::getHighIndex() const {
    return highIndex;
}

void SuperArray::setHighIndex(int highIndex) {
    SuperArray::highIndex = highIndex;
}

int SuperArray::getCapacity() const {
    return capacity;
}

void SuperArray::setCapacity(int capacity) {
    SuperArray::capacity = capacity;
}

/*!
 * Class Destructor
 */
SuperArray::~SuperArray() {
    delete[] arr;
}

/*! Convert array content to string
 *
 */
string arrayToString(const SuperArray &s);

string arrayToString(const SuperArray &s) {
    stringstream ss;

    for (int i = 0; i < s.length(); i++) {
        ss << s.arr[i] << " ";
    }
    string s1 = ss.str(); // Build a string from char stream
    return s1;
}

/*! Overload the [] */
int &operator[](const int index) {
    int realIndex = index - SuperArray::getLowIndex();
    return SuperArray::getArr()[realIndex];
}