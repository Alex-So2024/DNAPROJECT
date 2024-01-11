// File name: DNA_Strand.cpp
// Author: 
// VUnetid: 
// Email: 
// Class: CS2201
// Date: 
// Honor statement:
// Assignment Number: 
// Description: This will be an DNA_Strand implemented with a static 
//              array of chars.
#include <iostream>
#include "DNA_Strand.h"
#include <stdexcept>

// Constructor
// Create an empty DNA_Strand.
DNA_Strand::DNA_Strand ()
{
    mySize = 0;
}


// Constructor
// Create an initialized DNA_Strand.
// If the string ipStr is larger than MAX_DNA, then only the first MAX_DNA
// characters of ipStr are used to initialize the DNA_Strand
DNA_Strand::DNA_Strand (const std::string & ipStr)
{
    // add your code here and/or on base member initialization list
    if (ipStr.length() > MAX_DNA) {
        mySize = MAX_DNA;
    }
    else {
        mySize = ipStr.length();
    }

    for (size_t i = 0; i < mySize; i++) {
        myDNA[i] = ipStr.at(i);
    }
}


//toString
//Returns string equivalent of the DNA
std::string DNA_Strand::toString() const
{
    std::string sent = "";
    for (size_t i = 0; i < mySize; i++) {
        sent += myDNA[i];
    }
    return sent;
}


// Set an item in the DNA_Strand at location index. Throws
// <std::out_of_range> if index is out of range, i.e., larger than or 
// equal to the current size of the DNA_Strand.
// Uses zero-based indexing.
void DNA_Strand::set (char new_item, size_t index) {
    if(index >= mySize) {
        throw std::out_of_range(0);
    }
    else {
        myDNA[index] = new_item;
    }
}


// Get an item in the DNA_Strand at location index. Throws
// <std::out_of_range> if index is out of range, i.e., larger than or 
// equal to the current size of the DNA_Strand.
// Uses zero-based indexing.
char DNA_Strand::get (size_t index) const
{
    if(index >= mySize) {
        throw std::out_of_range(0);
    }
    else {
        std::string sent(std::to_string(index));
    }
    return myDNA[index];
}


// Returns the current size of the DNA.
size_t DNA_Strand::size () const
{
    return mySize;
}


// isEqual
// Compare this DNA_Strand with s for equality. Returns true if the
// size()'s of the two DNA_Strands are equal and all the elements from 0
// .. size()-1 are equal, else false.
bool DNA_Strand::isEqual (const DNA_Strand &s) const
{
    bool isEqual;
    if(s.size() == mySize) {
        for(size_t i = 0; i < s.size(); i++) {
            if(s.get(i) == myDNA[i])
            {
                isEqual = true;
            }
            else {
                return false;
            }
        }
        return isEqual;
    } else {
        return false;
    }
    return false;

}


// search
// Look for target in current DNA strand and return index.
// Return -1 if not found.
int DNA_Strand::search(const std::string & target) const
{
    if(target.length() == 0) {
        return -1;
    }
    if(target.length() > mySize) {
        return -1;
    }
    size_t matchValue = 0;
    for(unsigned long i = 0; i < mySize; i++) {
        for (unsigned long j = 0, k = i; j < target.length(); j++, k++) {
            if (myDNA[k] == target.at(j)) {
                matchValue++;
            }
            else {
                break;
            }
        }
        if (matchValue == target.length()) {
            return i;
        }
        matchValue = 0;
    }
    return -1;










}


// search
// search with start position specified
// Look for target in current DNA strand and return index.
// Return -1 if not found. If pos is past end of strand, return -1.
// "A B C D" " A B" 2
int DNA_Strand::search(size_t pos, const std::string & target) const
{
    if(target.length() == 0) {
        return -1;
    }
    if(target.length() > mySize) {
        return -1;
    }
    if(pos > size())
    {
        return -1;
    }
    size_t matchValue = 0;
    for(unsigned long i = pos; i < mySize; i++) {
        for (unsigned long j = 0, k = i; j < target.length(); j++, k++) {
            if (myDNA[k] == target.at(j)) {
                matchValue++;
            }
            else {
                break;
            }
        }
        if (matchValue == target.length()) {
            return i;
        }
        matchValue = 0;
    }
    return -1;

}


// cleave
// Removes from current DNA strand the sequence between the end of the
// first occurrence of passed target sequence (e.g. "TTG"), through the end
// of the second occurence of the target sequence.
// pre: Array e.g. ACTTGACCTTGA and target e.g. "TTG"
// post: ACTTGA  (ACCTTG removed)
void DNA_Strand::cleave(const std::string & target)
{
    int firstIndex = search(target);
    int secondIndex = search(firstIndex + target.length(), target);

    size_t indexSize = mySize;
    if (secondIndex > firstIndex) {
        for (size_t i = firstIndex + target.length(), j = 0; j < indexSize - (secondIndex + target.length()); i++, j++) {
            myDNA[i] = myDNA[secondIndex + target.length() + j];
        }
        mySize = mySize - ((secondIndex + target.length()) - (firstIndex + target.length()));
    }

}

// cleave with start position specified
// cleave starting from an index, returns the index after the cleaved DNA
// or -1 if no cleaving was performed
// pre: Array e.g. ACTTGACCTTGA and target e.g. "TTG", pos = 1
// post: ACTTGA  (ACCTTG removed) and return value = 5
int DNA_Strand::cleave(size_t pos, const std::string & target) {
    int firstIndex = search(pos, target);
    int secondIndex = search(firstIndex + target.length(), target);
    size_t indexSize = mySize;

    if (secondIndex > firstIndex) {
        for (size_t i = firstIndex + target.length(), j = 0;
             j < indexSize - (secondIndex + target.length()); i++, j++) {
            myDNA[i] = myDNA[secondIndex + target.length() + j];
        }
        mySize = mySize - ((secondIndex + target.length()) - (firstIndex + target.length()));
        return firstIndex + target.length();
    }
    else {
            return -1;
        }

}


// cleaveAll
// Removes from current DNA strand the sequence between pairs of target 
// sequence, i.e. from the end 1 through the end of 2, from the end of 3 
// through the end of 4, etc, but NOT from the end of 2 through the end 3,
// or from the end of 4 through the end of 5.
// (Make sure that you understand the specification)
// pre: Array e.g. ACTTGATTGGGTTGCTTGCC and target e.g. "TTG"
// post: ACTTGGGTTGCC (ATTG and CTTG removed)
void DNA_Strand::cleaveAll(const std::string & target)
{
    int firstIndex = search(target);
    int secondIndex = search(firstIndex + target.length(), target);
    while(secondIndex != -1) {
     cleave(firstIndex, target);
     firstIndex = search(firstIndex + target.length(), target);
     secondIndex = search(secondIndex + target.length(), target);
    }
}


 //countEnzyme
 //Counts the number of occurences of a single character target sequence
 //in the DNA strand.
size_t DNA_Strand::countEnzyme(char target) const
{
    size_t enzymeCount = 0;
    for(size_t i = 0; i < mySize; i++) {
        if (myDNA[i] == target) {
            enzymeCount++;
        }
    }
    return enzymeCount;
}

 //inRange : helper function
 //Returns true if index is within range, i.e., 0 <= index < mySize
 //else returns false.
bool DNA_Strand::inRange (size_t index) const
{
    if (index < mySize) {
        return true;
    }
    else {
        return false;
    }
}

