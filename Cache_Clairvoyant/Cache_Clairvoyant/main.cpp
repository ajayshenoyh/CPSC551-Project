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
    int pages;
    char yes;
    char choice;
    cout << "Do you want input(i) custom accesses or use standard(s) ones?\n";
    cin >> choice;
    if (choice == 'i') {
        do {
            cout << "Input a string:\n";
            cin >> input;
            accesses.push_back(input);
            cout << "Do you want to continue?\n";
            cin >> yes;
        } while (yes != 'n');
    } else if (choice == 's') {
        cout << "How many pages are there?";
        cin >> pages;
        dowork.set_pages_in_phy_mem(pages);
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
//    dowork.print_data();
    cout << "Page Faults: " << dowork.get_page_faults();
    //    vector<string> inputs;
    //    string input;
    //    char proceed = 'n';
    //    do {
    //        cout << "Please input an access: ";
    //        cin >> input;
    //        inputs.push_back(input);
    //        cout << "Would you like to continue?\n";
    //        cin >> proceed;
    //        proceed = toupper(proceed);
    //    } while (proceed == 'y');
    //    for (int i = 0; i < int(inputs.size()); i++) {
    //        cout << inputs[i] << endl;
    //    }
    int pause;
    //    cin >> pause;
    return 0;
}

