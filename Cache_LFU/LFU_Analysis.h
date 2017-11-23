/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LFU_Analysis.h
 * Author: gary
 *
 * Created on November 22, 2017, 1:08 PM
 */

#ifndef LFU_ANALYSIS_H
#define LFU_ANALYSIS_H
#include <string>
#include <vector>
struct access {
private:
    std::string access_name;
    int times_used;

public:

    std::string get_name() {
        return access_name;
    }

    int get_times_used() {
        return times_used;
    }

    void set_name(std::string s) {
        if (s != "") {
            access_name = s;
        }
    }

    void increment_times_used() {
        times_used++;
    }

    void reset_last_used() {
        times_used = 0;
    }

    access() {
        access_name = "";
        times_used = 1;
    }

    access(std::string s) {
        set_name(s);
        times_used = 1;
    }
};

const int max_page_number = 4;

class LFU_Analysis {
public:
    void print();
    void set_number_of_pages(int n);
    int get_number_of_pages() { return number_of_pages; }

    void add_access(std::string a);
    int find_LFU();
    bool page_hit(std::string a);

    LFU_Analysis();
    LFU_Analysis(const LFU_Analysis& orig);
    virtual ~LFU_Analysis();
private:
    std::vector<access> accesses;
    int number_of_pages;
};

#endif /* LFU_ANALYSIS_H */

