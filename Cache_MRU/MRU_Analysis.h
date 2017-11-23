/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MRU_Analysis.h
 * Author: gary
 *
 * Created on November 21, 2017, 3:59 PM
 */

#ifndef MRU_ANALYSIS_H
#define MRU_ANALYSIS_H
#include <vector>
#include <string>

struct access {
private:
    std::string access_name;
    int last_used;

public:

    std::string get_name() {
        return access_name;
    }

    int get_last_used() {
        return last_used;
    }

    void set_name(std::string s) {
        if (s != "") {
            access_name = s;
        }
    }

    void increment_last_used() {
        last_used++;
    }

    void reset_last_used() {
        last_used = 0;
    }

    access() {
        access_name = "";
        last_used = 0;
    }

    access(std::string s) {
        set_name(s);
        last_used = 0;
    }
};

class MRU_Analysis {
public:
    void set_accesses(std::vector<std::string> a);
    void print();
    void set_number_of_pages(int n);

    int get_number_of_pages() {
        return number_of_pages;
    }

    void update_uses();

    void add_access(std::string a);
    int find_MRU();
    bool page_hit(std::string a);
    MRU_Analysis();
    MRU_Analysis(const MRU_Analysis& orig);
    virtual ~MRU_Analysis();
private:
    std::vector<access> accesses;
    int number_of_pages;
};

#endif /* MRU_ANALYSIS_H */

