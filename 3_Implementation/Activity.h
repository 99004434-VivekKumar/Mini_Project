

#ifndef _ACTIVITY_H
#define _ACTIVITY_H

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;
class Activity
{
private:
    /* data */
 vector<string> Floor;        
 vector<int> RoomNo;
 vector<double> Power;
 vector<string> Status;
 vector<double> RoomTemp;

public:
     Activity();
     vector<int> get_roomno();
     vector<double> get_power();
     vector<double> get_roomtmp();
     vector<string> get_floor();
     vector<string> get_status();
     void read_data_set();
      ~Activity();
};

#endif

