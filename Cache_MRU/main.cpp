/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: gary
 *
 * Created on November 21, 2017, 11:53 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "MRU_Analysis.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    cout << "Hello World\n";
    MRU_Analysis analysis;
    char yes;
    char choice;
    cout << "Do you want input(i) custom accesses or use standard(s) ones?\n";
    cin >> choice;
    if (choice == 'i') {
        do {
            string input;
            cin >> input;
            analysis.add_access(input);
            cout << "do you want to continue?\n";
            cin >> yes;
        } while (yes != 'n');
    } else if (choice == 's') {
        analysis.add_access("aaaaaaaa");
        analysis.add_access("bbbbbbbb");
        analysis.add_access("cccccccc");
        analysis.add_access("hhhhhhhh");
        analysis.add_access("cccccccc");
        analysis.add_access("cccccccc");
        analysis.add_access("aaaaaaaa");
        analysis.add_access("dddddddd");
    }
    analysis.print();
    return 0;
}

