// Copyright 2021 Peter Nguyen
/*
Peter Nguyen
Last Updated: 11/8/21
EDistance.cpp: Implementation file for EDistance. A class to create 
             a matrix from 2 strings that calculates the edit distance.
             Matrix is represented by a vector of vector<int>
*/

#include <iostream>
#include <sstream>
#include "EDistance.h"

// Constructor that copies strings into vector members
EDistance::EDistance(std::string s1, std::string s2) {
    // Copy the strings into vector members
    copy(s1.begin(), s1.end(), std::back_inserter(one));
    copy(s2.begin(), s2.end(), std::back_inserter(two));
    // Set number of rows in matrix to be size of first string +1
    matrix.resize(one.size()+1);
}

// Find the penalty by comparing 2 chars
int EDistance::penalty(char a, char b) {
    return (a == b) ? 0 : 1;
}

// Find the minimum of 3 int values
int EDistance::min(int a, int b, int c) {
    return std::min(std::min(a, b), c);
}

int EDistance::OptDistance() {
    // Set index values based on the 2 string sizes
    int i = one.size();
    int j = two.size();
    
    // Create and fill last row of matrix
    int p = 0;
    std::vector<int> bottom(j+1);
    for (int x = j;x >= 0; x--) {
        bottom[x] = p;
        p+=2;
    } 

    matrix[i] = bottom;
    
    // Fill last column of matrix
    for (int q = i-1; q >= 0; q--) {
        std::vector<int> add(j+1);
        add[j] = (matrix[q+1])[j] + 2;
        matrix[q] = add; 
    }

    // Change indexes to work with unfilled matrix
    i-=1;
    j-=1;
    
    // Fill in rest of matrix by rows
    // Variables to hold values at r=right, d=diagonal, b=bottom of matrix index
    int r, d, b;
    for (i; i >= 0; i--) {
        for (int l = j; l >= 0; l--) {
            r = (matrix[i])[l+1];
            d = (matrix[i+1])[l+1];
            b = (matrix[i+1])[l];
            int opt;
            
            // If characters match
            if (penalty(one[i], two[l]) == 0) {
                opt = d;
            }
            // If characters don't match find min and set opt
            else if (penalty(one[i], two[l] == 1)) {
                opt = min(d+1,r+2,b+2);
            }

            // Set opt value in matrix
            (matrix[i])[l] = opt;
        }
    }
    
    return (matrix[0])[0];
}

// Function to find the alignment of the two strings
std::string EDistance:: alignment() {
    std::stringstream ss;
    int i=0, j=0;

    // While indexes are not at bounds
    while(i<one.size()&&j<two.size()) {
        // If the chars are equal, align and advance diagonally
        if (one[i] == two[j]) {
            ss<<one[i]<<" "<<two[j]<<" 0\n";
            i++;
            j++;
        }
        // If chars are not equal, test which direction to go
        else {
            if ((matrix[i])[j] == (matrix[i+1])[j+1]+1) {
                ss<<one[i]<<" "<<two[j]<<" 1\n";
                i++;
                j++;
            }
            else if ((matrix[i])[j] == (matrix[i])[j+1]+2) {
                ss<<"- "<<two[j]<<" 2\n";
                j++;
            }

            else if((matrix[i])[j] == (matrix[i+1])[j]+2){
                ss<<one[i]<<" - 2\n";
                i++;
            }
        }
    }
    // If last element is not diagonal from previous
    if (i!=one.size()) ss<<one[i]<<" - 2\n";
    else if (j!=two.size()) ss<<"- "<<two[j]<<" 2\n";

    return ss.str();
}
