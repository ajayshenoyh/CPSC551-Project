/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Analysis.h
 * Author: gary
 *
 * Created on November 19, 2017, 11:39 PM
 */

#ifndef ANALYSIS_H
#define ANALYSIS_H
#include <vector>
#include <string>
using namespace std;
const int last_occurrence = -2;

struct access {
    string access_id;
    int next_access;
    //int total;
    double next_access_ratio;
    int occurrences;
    double removability_ratio;

    void set_name(std::string n) {
        if (n != "") {
            access_id = n;
        }
    }

    std::string get_name() {
        return access_id;
    }

    int get_next_access() {
        return next_access;
    }

    void set_occurrences(int o) {
        occurrences = o;
    }

    int get_occurrences() {
        return occurrences;
    }

    void decriment_next_access() {
        if (next_access > 0) {
            next_access--;
        }
    }

    void calculate_ratio() {
        if (next_access > 0) {
            next_access_ratio = (1 / (double) next_access);
            removability_ratio = (1 - (next_access_ratio * occurrences));
        } else {
            next_access_ratio = -1;
            removability_ratio = 1;
        }
    }

    //    void decrement_and_recalculate() {
    //        decrement_next_access();
    //        calculate_ratio();
    //    }

    void add_occurrence() {
        occurrences++;
    }

    void sub_occurrence() {
        if (occurrences > 0) {
            occurrences--;
        }
    }

    void set_to_last_occurence() {
        occurrences = last_occurrence;
    }

    void set_next_access(int n) {
        if (n > 0 || n == -2) {
            next_access = n;
        }
    }

    access(string a) {
        if (a != "") {
            access_id = a;
            occurrences = 1;
            next_access = 0;
        }
        occurrences = -1;
        next_access = -1;
    }

    //    access(const access orig) {
    //        this->set_next_access(orig.get_next_access());
    //        this->set_occurrences(orig.get_occurrences());
    //        this->set_name(orig.get_name());
    //    }
};

class Analysis {
public:
    void setAccesses(vector<string> a);
    void print_accesses();
    void print_data();
    void set_pages_in_phy_mem(int p);
    int get_pages_in_phy_mem();
    void calculations();
    void handle_access(int current_index);
    void simulate();
    void update_next_accesses(int i);
    void update_occurances(int i);
    bool page_hit(std::string a);
    int find_replacee(int i);

    int size();

    Analysis();
    Analysis(const Analysis& orig);
    virtual ~Analysis();
private:
    int pages_in_phy_mem;
    vector<access> accesses;
    vector<access *> memory;

};

#endif /* ANALYSIS_H */

