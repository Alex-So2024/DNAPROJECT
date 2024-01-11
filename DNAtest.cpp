// File name: DNAtest.cpp
// Author: 
// VUnetid:
// Email:
// Class: CS2201
// Date:
// Honor statement:
// Assignment Number:
//
// Description: Testing of DNA_Strand ADT
//
//
// Last Changed:

#include <iostream>
#include <stdexcept>
#include "DNA_Strand.h"


int main()
{
    // testing functions of the DNA_Strand class

    DNA_Strand dna1, dna2;  // create 2 default-constructed strands

    if (dna1.size() != 0) {
        std::cout << "Test 1 FAIL. Expected zero but received: " << dna1.size() << std::endl;
    }

//    if (!dna1.isEqual(dna2)) {
//        std::cout << "Test 2 FAIL. Two empty strands were not equal." << std::endl;
//    }
//
//    if (!dna2.isEqual(dna1)) {
//        std::cout << "Test 3 FAIL. The reflective test of two empty strands also failed."
//                  << std::endl;
//    }

    //testing toString
    std::string ipStr = "ABCCTG";
    DNA_Strand dna3(ipStr);

    //should return the contents of the strand as a string value
    if(dna3.toString() != ipStr) {
        std::cout << "Test 4 FAIL. Expected: " << ipStr << "but received: " << dna3.toString() << std::endl;
    }

    //create DNA Strand with length 60
    std::string longStr = "CACCATTAACCTTCCTGAGAACCGGGAGGTGGGAATCCGTCACATATGAGAAGGTATTTG";
    DNA_Strand dna4(longStr);
    if(longStr.length() > MAX_DNA) {
        std::cout << "Test 5 SUCCESS. This is a long string. Expected: " << "60" << "and received: " << longStr.length();
        std::cout << "Expected size is: " << "60" << "and received size is: " << longStr.size();
    }

    //create DNA Strand with length 40
    std::string shortStr = "CCCGATAATCAATACTCCAGGCTTCTAACTTTTTCCACTC";
    DNA_Strand dna5(shortStr);
    if(shortStr.length() < MAX_DNA) {
        std::cout << "Test 6 SUCCESS. This is a short string. Expected: " << "40" << "and received: " << shortStr.length();
        std::cout << "Expected size is: " << "40" << "and received size is: " << shortStr.size();

    }


    std::string randomDNA = "ATT";
    DNA_Strand dna6(randomDNA);

    try {
        std::cout << "trying to get the 2nd index of randomDNA: " << "received: " << dna6.get(2) << std::endl;
    }
    catch (std::out_of_range& excpt){
        std::cout << "Error was thrown and caught :: Cannot seach index value greater than length of DNA Strand" << std::endl;
    }


    //testing setter
    std::string newDNA = "ATTGC";
    DNA_Strand dna7(newDNA);
    try {
        std::cout << "trying to replace the G with an A @index 3" << "received: ";
        dna7.set('A', 3);
        std::cout << dna7.get(3) << std::endl;
    }
    catch (std::out_of_range& excpt) {
        std::cout << "Error was thrown and caught :: cannot replace char with an index greater than size";
    }



    std::cout << "testing enzymeCount targeting char T. expected 2. received: " << dna7.countEnzyme('T') << std::endl;


    //testing isEqual
    std::cout << std::boolalpha;
    std::string isEqualStrOne = "ATGGCT";
    std::string isEqualStrTwo = "ATGGCT";
    std::string isEqualStrThree = "ATGGCTG";
    std::string isEqualStrFour = "ATGGCA";
    DNA_Strand DNATestOne(isEqualStrOne);
    DNA_Strand DNATestTwo(isEqualStrTwo);
    DNA_Strand DNATestThree(isEqualStrThree);
    DNA_Strand DNATestFour(isEqualStrFour);
    std::cout << "testing isEqual. Expected: True bc same values & length. Received: " << DNATestOne.isEqual(DNATestTwo) << std::endl;

    std::cout << "testing isEqual. Expected: False bc diff length. Received: " << DNATestOne.isEqual(DNATestThree) << std::endl;

    std::cout << "testing isEqual. Expected: False bc same length diff values. Received: " << DNATestOne.isEqual(DNATestFour) << std::endl;

    std::string searchStr = "";
    DNA_Strand searchStrOne(searchStr);
    std::string targetSeq = "GCT";
    std::string targetSeq2 = "AAA";
    std::cout << "Testing search. Expected: 3. Received: " << DNATestOne.search(targetSeq) << std::endl;
    std::cout << "Testing search. Expected: -1. Received: " << searchStrOne.search(searchStr) << std::endl;
    std::cout << "Testing search. Expected: -1. Received: " << DNATestFour.search(targetSeq2) << std::endl;


    std::cout << "Testing search2. Expected: -1. Received: " << DNATestOne.search(4, targetSeq) << std::endl;
    std::cout << "Testing search2. Expected: -1. Received: " << DNATestOne.search(20, targetSeq) << std::endl;
    std::cout << "Testing search2. Expected: 3. Received: " << DNATestOne.search(3, targetSeq) << std::endl;


    //testing cleave
    std::string dna8 = "ATTGCCATTGAA";
    DNA_Strand cleaveDna8(dna8);
    cleaveDna8.cleave("TTG");
    std::cout << "Testing cleave with multiple TTG occurences. Received: " << cleaveDna8.toString() << std::endl;

    std::string dna9 = "TTGAAAAA";
    DNA_Strand cleaveDna9(dna9);
    cleaveDna9.cleave("TTG");
    std::cout << "Testing cleave with first 3 letters being 'TTG'. Received: " << cleaveDna9.toString() << std::endl;

    cleaveDna9.cleave("");
    std::cout << "Testing cleave with empty target seq. Received: " << cleaveDna9.toString() << std::endl;

    std::string dna10 = "AAAAATTG";
    DNA_Strand cleaveDna10(dna10);
    cleaveDna10.cleave("TTG");
    std::cout << "Testing cleave with first target seq occurence at end of string. Received: " << cleaveDna10.toString() << std::endl;

    //testing cleave with starting pos constraint
    std::string dna11 = "AATTGAAAATTGAAAATTG";
    DNA_Strand cleaveDna11(dna11);
    std::cout << "Testing cleave with constraint. Expected: 12, Received: " << cleaveDna11.cleave(3, "TTG") << std::endl;

    std::cout << "Testing cleave with constraint. Target empty. Expected: -1, Received: " << cleaveDna11.cleave(4, "") << std::endl;

    std::string dna12 = "TTGAAATTGAAAAATTG";
    DNA_Strand cleaveDna12(dna12);
    std::cout << "Testing cleave with constraint. Expected: 3, Received: " << cleaveDna12.cleave(0, "TTG") << std::endl;
    std::cout << "Testing cleave with constraint. Expected: -1, Received: " << cleaveDna12.cleave(0, "") << std::endl;


    //testing cleaveAll
    std::string dna13 = "ACTTGATTGGGTTGCTTGCC";
    DNA_Strand cleaveAllDna13(dna13);
    cleaveAllDna13.cleaveAll("TTG");
    std::cout << "Testing cleaveAll. Expected: ACTTGGGTTGCC, Received: " << cleaveAllDna13.toString() << std::endl;








    std::cout << "Done testing" << std::endl;

// uncomment the following lines if you are running the program in a
// DOS or terminal window and you want the window to stay open when
// the testing is done.
//    std::cout << "Press enter to end pgm" << std::endl;
//    char tt;
//    tt = cin.get();


    return 0;
}

