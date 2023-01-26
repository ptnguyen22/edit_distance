// Copyright 2021 Peter Nguyen
/*
Peter Nguyen
Last Updated: 11/8/21
main.cpp: main function to read in a file with 2 strings.
          Then uses EDistance to calculate and display 
          edit distance along with run time from sfml.
*/

#include <iostream>
#include <SFML/System.hpp>
#include "EDistance.h"

int main(int argc, char** argv) {
    std::string x,y;
    sf:: Clock clock;
    sf:: Time t;

    std::cin >> x >> y;

    EDistance test(x,y);
    std::cout<<"Edit distance = "<<test.OptDistance()<<std::endl;
    std::cout<<test.alignment()<<std::endl;
    t=clock.getElapsedTime();
    std::cout<<"Execution time is " << t.asSeconds() << " seconds\n";
}
