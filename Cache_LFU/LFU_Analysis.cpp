/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LFU_Analysis.cpp
 * Author: gary
 * 
 * Created on November 22, 2017, 1:08 PM
 */

#include "LFU_Analysis.h"
#include <iostream>
#include <string>
#include <vector>

void LFU_Analysis::print() {
    for (int i = 0; i < accesses.size(); i++) {
        std::cout << "address: " << accesses[i].get_name() << " times used: " << accesses[i].get_times_used() << std::endl;
    }
}

void LFU_Analysis::set_number_of_pages(int n) {
    if (n > 0) {
        number_of_pages = n;
    }
}

int LFU_Analysis::get_number_of_pages() {
    return number_of_pages;
}

int LFU_Analysis::get_page_faults() {
    return page_faults;
}

void LFU_Analysis::add_access(std::string a) {
    if (page_hit(a)) {
    } else if (accesses.size() != (number_of_pages)) {
        accesses.push_back(a);
        page_faults++;
        std::cout << "page fault " << a << " added\n";
    } else {
        int access_to_replace = find_LFU();
        std::cout << "page fault " << accesses[access_to_replace].get_name() << " replaced with " << a << std::endl;
        page_faults++;
        access newA(a);
        accesses.erase(accesses.begin() + access_to_replace);
        accesses.insert(accesses.begin() + access_to_replace, newA);

    }
}

int LFU_Analysis::find_LFU() {
    int access_to_replace = 0;
    for (int i = 0; i < accesses.size(); i++) {
        if (accesses[access_to_replace].get_times_used() > accesses[i].get_times_used()) {
            access_to_replace = i;
        }
    }
    return access_to_replace;
}

bool LFU_Analysis::page_hit(std::string a) {
    for (int i = 0; i < accesses.size(); i++) {
        if (accesses[i].get_name() == a) {
            accesses[i].increment_times_used();
            std::cout << "page hit " << a << std::endl;
            return true;
        }
    }
    return false;
}

LFU_Analysis::LFU_Analysis() {
    set_number_of_pages(max_page_number);
    page_faults = 0;
}

LFU_Analysis::LFU_Analysis(const LFU_Analysis& orig) {
    set_number_of_pages(max_page_number);
    page_faults = 0;
}

LFU_Analysis::~LFU_Analysis() {
}

