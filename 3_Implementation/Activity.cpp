#include "Activity.h"

Activity::Activity(){

}
    vector <int> Activity::get_roomno(){
          return RoomNo;
     }
    vector <double>Activity::get_power(){
         return Power;

     }
    vector <double> Activity::get_roomtmp(){
         return RoomTemp;

     }
     vector <string> Activity::get_floor(){
         return Floor;

     }
     vector <string> Activity:: get_status(){
         return Status;
     }

  void Activity::read_data_set(){
         fstream file;
         file.open("sensor.csv", ios::in);
         vector<string> row;
         string line;
         int room,pwr;
         double rmtmp;
         while(getline(file,line)){
            string bit;            
            stringstream linestream(line);
            while(getline(linestream,bit,',')){
               row.push_back(bit);
            }
            Floor.push_back(row[0]);
            RoomNo.push_back(stoi(row[1]));
            Power.push_back(stoi(row[2]));

            Status.push_back(row[3]);
            RoomTemp.push_back(stod(row[4]));
             
            row.clear(); 
           /*cout<<row[0];
            cout<<row[1];
            cout<<row[2];
            cout<<row[3];
            cout<<row[4]<<endl;
           */
        }
           /* cout<<Floor[0];
            cout<<RoomNo[1];
            cout<<RoomTemp[4];
            cout<<Status[3];
            cout<<Power[4]<<endl;  
            */  
}

double Activity::highest_power(){                   // finding the highest power consumed rooms                            
  int max_index,max;
  max_index = max_element(Power.begin(),Power.end())- Power.begin();
  max= *max_element(Power.begin(),Power.end());
   // cout<<room[2];
  return RoomNo[max_index];
}

int Activity::highest_roomTemp(){               // function defintion for finding highest temperature
     int max_index;
  max_index = max_element(RoomTemp.begin(),RoomTemp.end())- RoomTemp.begin();
 // cout<<RoomNo[max_index]<<endl;
  return RoomNo[max_index];
}

vector<int> Activity::AirON(){
    vector<int> room;
    for(int i=0;i<Status.size();i++){
            if(Status[i]=="ON")
            { room.push_back(RoomNo[i]);
            }
    }
  //  cout<<room[4];
    return room;
}
vector<int> Activity::TempOFF(double temp){
    vector<int> room;
    for(int i=0;i<RoomTemp.size();i++){
            if(RoomTemp[i]>temp &&Status[i]=="OFF")
            { room.push_back(RoomNo[i]);
            }
    }
  //  cout<<room[2];
    return room;
}

Activity::~Activity()
{
}
