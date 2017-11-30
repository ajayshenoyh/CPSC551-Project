/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Analysis.cpp
 * Author: gary
 * 
 * Created on November 19, 2017, 11:39 PM
 */

#include "Analysis.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

void dbg(string message) {
    //cout << message;
}

void Analysis::setAccesses(vector<string> a) {
    if (a.size() > 0) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != "") {
                access new_access(a[i]);
                accesses.push_back(new_access);
            }
        }
    }
}

void Analysis::print_accesses() {
    cout << "Memory\n";
    if (memory.size() > 0) {
        for (int i = 0; i < memory.size(); i++) {
            cout << memory[i]->get_name() << ": " << "next_access: " << memory[i]->get_next_access() << " occurrences: " << memory[i]->get_occurrences() << endl;
        }
    }
}

void Analysis::print_data() {
    cout << "Accesses\n";
    if (accesses.size() > 0) {
        for (int i = 0; i < accesses.size(); i++) {
            cout << accesses[i].get_name() << ": " << "next_access: " << accesses[i].get_next_access() << " occurrences: " << accesses[i].get_occurrences() << endl;
        }
    }
    cout << "Memory\n";
    if (memory.size() > 0) {
        for (int i = 0; i < memory.size(); i++) {
            cout << memory[i]->get_name() << ": " << "next_access: " << memory[i]->get_next_access() << " occurrences: " << memory[i]->get_occurrences() << endl;
        }
    }
}

void Analysis::set_pages_in_phy_mem(int p) {
    if (p > 0) {
        pages_in_phy_mem = p;
    }
}

int Analysis::get_pages_in_phy_mem() {
    return pages_in_phy_mem;
}

int Analysis::get_page_faults() {
    return page_faults;
}

void Analysis::calculations() {
    int size = accesses.size();
    if (size > 0) {
        for (int i = 0; i < size; i++) {
            handle_access(i);
            //find_next(i);
        }
    }
    simulate();
}

void Analysis::handle_access(int current_index) {
    if (accesses.size() > 0) {
        for (int j = current_index; j < accesses.size(); j++) {
            if ((accesses[current_index].access_id == accesses[j].access_id)) {
                if (accesses[current_index].next_access == -1) {
                    accesses[current_index].set_next_access(j - current_index);
                    accesses[current_index].add_occurrence();
                } else {
                    accesses[current_index].add_occurrence();
                }
            } else if (j == (accesses.size() - 1)) {
                dbg("at the end of the list: ");
                if (accesses[current_index].next_access == -1) {
                    dbg("next_access not set\n");
                    accesses[current_index].set_next_access(last_occurrence);
                } else {
                    dbg("\n");
                }
            }
        }
    } else {
        access new_data(accesses[current_index].access_id);
        accesses.push_back(new_data);
    }
}

void Analysis::simulate() {
    int access_to_replace;
    for (int i = 0; i < accesses.size(); i++) {
        accesses[i].calculate_ratio();
        //cout << accesses[i].next_access_ratio << ' ' << accesses[i].removability_ratio << endl;
        if (!page_hit(accesses[i].get_name())) {
            if (memory.size() != (pages_in_phy_mem)) {
                memory.push_back(&accesses[i]);
                std::cout << "page fault " << accesses[i].get_name() << " added\n";
                page_faults++;
            } else {
                access_to_replace = find_replacee(i);
                std::cout << "page fault " << memory[access_to_replace]->get_name() << " replaced with " << accesses[i].get_name() << std::endl;
                //access newA(accesses[i]);
                //std::cout << "name " << newA.get_name() << "  next access " << newA.get_next_access() << " occurrences " << newA.get_occurrences() << std::endl;
                memory[access_to_replace] = &accesses[i];
                page_faults++;
            }
        }
        update_next_accesses(i);
        update_occurances(i);
    }
}

void Analysis::update_next_accesses(int i) {
    for (; i >= 0; i--) {
        if (accesses[i].next_access > 0) {
            accesses[i].decriment_next_access();
        }
    }
}

void Analysis::update_occurances(int i) {
    int this_index = 0;
    for (; i < accesses.size(); i++) {
        if (accesses[this_index].get_name() == accesses[i].get_name()) {
            accesses[i].sub_occurrence();
        }
    }
}

bool Analysis::page_hit(std::string a) {
    for (int i = 0; i < memory.size(); i++) {
        if (memory[i]->get_name() == a) {
            std::cout << "page hit " << a << std::endl;
            return true;
        }
    }
    return false;
}

int Analysis::find_replacee(int i) {
    int access_to_replace = 0;
    for (int i = 0; i < memory.size(); i++) {
        if (memory[access_to_replace]->removability_ratio < memory[i]->removability_ratio) {
            access_to_replace = i;
        }
    }
    return access_to_replace;
}

int Analysis::size() {
    return accesses.size();
}

Analysis::Analysis() {
    set_pages_in_phy_mem(4);
    page_faults = 0;
}

Analysis::Analysis(const Analysis& orig) {
}

Analysis::~Analysis() {
}

