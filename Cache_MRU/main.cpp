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
    MRU_Analysis analysis;
    char yes;
    char choice;
    int frames;
    cout << "Demo Mode(y/n)\n";
    cin >> choice;
    if (choice == 'n') {
        cout << "How many frames are there?";
        cin >> frames;
        analysis.set_number_of_pages(frames);
        do {
            string input;
            cout << "Please input a reference: ";
            cin >> input;
            analysis.add_access(input);
            cout << "do you want to continue?\n";
            cin >> yes;
        } while (yes != 'n');
    } else if (choice == 'y') {
        analysis.set_number_of_pages(3);
        analysis.add_access("7");
        analysis.add_access("0");
        analysis.add_access("1");
        analysis.add_access("2");
        analysis.add_access("0");
        analysis.add_access("3");
        analysis.add_access("0");
        analysis.add_access("4");
        analysis.add_access("2");
        analysis.add_access("3");
        analysis.add_access("0");
        analysis.add_access("3");
        analysis.add_access("0");
        analysis.add_access("3");
        analysis.add_access("2");
        analysis.add_access("1");
        analysis.add_access("2");
        analysis.add_access("0");
        analysis.add_access("1");
        analysis.add_access("7");
        analysis.add_access("0");
        analysis.add_access("1");
    }
    //analysis.print();
    cout << "The number of page faults are " << analysis.get_page_faults() << endl;
    return 0;
}

