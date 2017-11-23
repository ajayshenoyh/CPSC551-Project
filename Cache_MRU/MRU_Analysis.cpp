/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MRU_Analysis.cpp
 * Author: gary
 * 
 * Created on November 21, 2017, 3:59 PM
 */

#include "MRU_Analysis.h"
#include <iostream>
#include <vector>
#include <string>

const int max_page_number = 4;

void MRU_Analysis::set_accesses(std::vector<std::string> a) {
    if (!a.empty()) {
        for (int i = 0; i < a.size(); i++) {
            access new_access(a[i]);
            accesses.push_back(new_access);
        }
    }

}

void MRU_Analysis::print() {
    for (int i = 0; i < accesses.size(); i++) {
        std::cout << "address: " << accesses[i].get_name() << " last access: " << accesses[i].get_last_used() << std::endl;
    }
}

void MRU_Analysis::set_number_of_pages(int n) {
    if (n > 0) {
        number_of_pages = n;
    }
}

void MRU_Analysis::update_uses() {
    for (int i = 0; i < accesses.size(); i++) {
        accesses[i].increment_last_used();
    }
}

void MRU_Analysis::add_access(std::string a) {
    if (page_hit(a)) {
    } else if (accesses.size() != (number_of_pages)) {
        accesses.push_back(a);
        std::cout << "page fault " << a << " added\n";
    } else {
        int access_to_replace = find_MRU();
        std::cout << "page fault " << accesses[access_to_replace].get_name() << " replaced with " << a << std::endl;
        access newA(a);
        accesses.erase(accesses.begin() + access_to_replace);
        accesses.insert(accesses.begin() + access_to_replace, newA);
    }
    update_uses();
}

int MRU_Analysis::find_MRU() {
    int access_to_replace = 0;
    for (int i = 0; i < accesses.size(); i++) {
        if (accesses[access_to_replace].get_last_used() > accesses[i].get_last_used()) {
            access_to_replace = i;
        }
    }
    return access_to_replace;
}

bool MRU_Analysis::page_hit(std::string a) {
    for (int i = 0; i < accesses.size(); i++) {
        if (accesses[i].get_name() == a) {
            accesses[i].reset_last_used();
            std::cout << "page hit " << a << std::endl;
            return true;
        }
    }
    return false;
}

MRU_Analysis::MRU_Analysis() {
    set_number_of_pages(max_page_number);
}

MRU_Analysis::MRU_Analysis(const MRU_Analysis& orig) {
    set_number_of_pages(max_page_number);
}

MRU_Analysis::~MRU_Analysis() {
}

