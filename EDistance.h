// Copyright 2021 Peter Nguyen
/*
Peter Nguyen
Last Updated: 11/8/21
EDistance.h: Header file for EDistance. A class to create 
             a matrix from 2 strings that calculates the edit distance.
             Matrix is represented by a vector of vector<int>
*/

#include <vector>
#include <string>

class EDistance {
 public:
    EDistance (std::string s1, std::string s2);
    static int penalty(char a, char b);
    static int min(int a, int b, int c);
    int OptDistance();
    std::string alignment();

private:
    std::vector<char> one, two;
    std::vector<std::vector<int>> matrix;
};
