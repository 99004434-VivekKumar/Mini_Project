

#ifndef _Bill_H
#define _Bill_H

#include<iostream>
#include<string.h>
#include<fstream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;
class Bill
{
private:
    /* data */
 vector<string> ProductName;        
 vector<int> ProductNumber;
 vector<double> Demand;
 vector<string> Status;
 vector<double> Price;

public:
     Bill();
     void read_data_set();
     double get_product_price(int);
     string get_product_name(int);
     void display_bill();
     void get_details(Bill);
      ~Bill();
};

#endif

