/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: gary
 *
 * Created on November 19, 2017, 11:03 PM
 */

//#include <cstdlib>
#include <iostream>
#include "Analysis.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    cout << "Hello World\n";
    Analysis dowork;
    vector<string> accesses;
    string input;
    int frames;
    char yes;
    char choice;
    cout << "Demo Mode(y/n)\n";
    cin >> choice;
    if (choice == 'n') {
        cout << "How many pages are there?";
        cin >> frames;
        dowork.set_pages_in_phy_mem(frames);
        do {
            cout << "Please input a reference: ";
            cin >> input;
            accesses.push_back(input);
            cout << "Do you want to continue?\n";
            cin >> yes;
        } while (yes != 'n');
    } else if (choice == 'y') {
        dowork.set_pages_in_phy_mem(3);
        accesses.push_back("7");
        accesses.push_back("0");
        accesses.push_back("1");
        accesses.push_back("2");
        accesses.push_back("0");
        accesses.push_back("3");
        accesses.push_back("0");
        accesses.push_back("4");
        accesses.push_back("2");
        accesses.push_back("3");
        accesses.push_back("0");
        accesses.push_back("3");
        accesses.push_back("0");
        accesses.push_back("3");
        accesses.push_back("2");
        accesses.push_back("1");
        accesses.push_back("2");
        accesses.push_back("0");
        accesses.push_back("1");
        accesses.push_back("7");
        accesses.push_back("0");
        accesses.push_back("1");
    }
    dowork.setAccesses(accesses);
    dowork.calculations();

    cout << "The number of page faults are " << dowork.get_page_faults() << endl; 
    //int pause;
    //cin >> pause;
    return 0;
}

