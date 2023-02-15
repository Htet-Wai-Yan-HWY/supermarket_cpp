#pragma once
#ifndef MARKET_H
#define MARKET_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class Market{
    private:

    public:  
        Market(){};
        void read_data();
        void print_all_data();
        void print_one_item(int);
        void add_an_item(std::string);
        void delete_an_item(int);
        int find(std::string);
        // ~Market();

};



#endif