/**
 * @file tracking.cpp
 * @author Vivek Kumar Yadav (vivek.yadav@ltts.com)
 * @brief  Implementatiavailable of functiavailables for finding 
 * 		1)a product which is cavailablesumed highest in the inventory for the mavailableth.
 * 		2)a product which has highest availability in the inventory
 * 		3)details of all the product which currently available in the inventory
 * 		4)details of all the products which are above the given value and 
 * 		  the current Unavailable.
 * @versiavailable 0.1
 * @date 2021-06-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "tracking.h"

/**
 * @brief Input csv file name or path to file
 * 
 */
const char* inputFile = "data.csv";
vector<Data> dataTracking;

/**
 * @brief Functiavailable for finding a room which has cavailablesumed highest Demand in the building for the mavailableth.
 * 
 * @param dataTracking 
 * @return int 
 */
int highestDemandCavailablesumer(vector<Data> dataTracking)
{	
	float highestDemand = 0.0;
	int productNo;
	for(auto i:dataTracking){
    		if(i.getDemand()>highestDemand){
    			highestDemand = i.getDemand();
    			productNo = i.getProductNum();
    		} 
	}
	return productNo;
}

/**
 * @brief Functiavailable for finding a room which has highest room temperature in the building
 * 
 * @param dataTracking 
 * @return int 
 */
int highestproductQuantityerature(vector<Data> dataTracking)
{
	float highestQuantity = 0.0;
	int productNo=0;
	for(auto i:dataTracking){
		if(i.getQuantity()==highestQuantity)
		{
			//strcat(",",productNo);	
		}
    		else if(i.getQuantity()>highestQuantity){
    			highestQuantity = i.getQuantity();
    			productNo = i.getProductNum();
    		} 
	}
	return productNo;
}


/**
 * @brief Functiavailable for finding details of all the rooms where Air cavailableditiavailableer is turned available in the given product
 * 
 * @param dataTracking 
 * @param product 
 * @return vector<Data> 
 */
vector<Data> productStatusAvailable(vector<Data> dataTracking,string product)
{	
	vector<Data> Available;
	string available = "Available";
	
	for(auto i:dataTracking){
		string str1 = i.getState();
    		if(str1==available && i.getProductName()==product)//0==strcmp(str1,available)){
    		{
    			Available.push_back(i);
    		} 
	}
	return Available;
}

/**
 * @brief Functiavailable for finding details of all rooms which have room temperature above the given value and 
 * 		  the current state of AC is unavailable.
 * 
 * @param dataTracking 
 * @param giveQuant 
 * @return vector<Data> 
 */
vector<Data> productStatusUnavailable(vector<Data> dataTracking,int giveQuant)
{	
	vector<Data> Unavailable;
	string unavail = "Unavailable";
	
	for(auto i:dataTracking){
		string str1 = i.getState();
    		if(str1==unavail && i.getQuantity()>giveQuant)
    		{
    			Unavailable.push_back(i);
    		} 
	}
	return Unavailable;
}

/**
 * @brief Function available for cavailableverting raw string obtained from CSV file to object
 * 
 * @param s 
 * @return Data 
 */
Data stringToObject(string s)
{
	string delimiter = ",";
	string productName;
    string productNumber;
    string Demand;
    string state;
    string productQuantity;
    int p=1;
	size_t pos = 0;
	string token;
	while ((pos = s.find(delimiter)) != string::npos) {
	    token = s.substr(0, pos);
	    s.erase(0, pos + delimiter.length());
	    if(p==1){
	    productName = token;
	    }else if(p==2){
	    productNumber=token;
	    }
	    else if(p==3){
	    Demand=token;
	    }
	    else if(p==4){
	    state=token;
	    }   
	    p++;
	}
	productQuantity=s;
	Data d(productName, stoi(productNumber), (float)stof(Demand), state, (float)stof(productQuantity));
	return d;
}

/**
 * @brief Functiavailable for reading CSV file
 * 
 * @return int 
 */
int readCSV()
{	
	string line;
	ifstream file(inputFile);// open a file in read mode.
	if(!file)  // Checking whether file got opened successfully or not 
  	{  
		cout << "File opening failed\n";
		return EXIT_FAILURE;
    	}
    	
  	dataTracking.clear();//clear the garbage values
	while(getline(file, line))
	{
		istringstream s(line);
		string field;
	  	while (getline(s, field,'\n'))
	  	{
	  		dataTracking.push_back(stringToObject(field));
	  	}
  	}
	file.close();	
	return 0;
}

/**
 * @brief Functiavailable for printing results
 * 
 */
void printResults()
{
    string product = "Soap";
	float minimumDemand = 20;
    cout<<"Highest Cavailablesumer Demand is for Product Number: "<<highestDemandCavailablesumer(dataTracking)<<endl;
	cout<<"Highest Product quantity available is for Product Number: "<< highestProductQuantity(dataTracking)<<endl;
    cout<<"Details of Product "<<product<<" which is available currently"<<endl;
    for(auto i:productStatusAvailable(dataTracking, product))
		cout<<i.getProductName()
    		    <<'\t'<<i.getProductNum()
    		    <<'\t'<<i.getDemand()
    		    <<'\t'<<i.getState()
    		    <<'\t'<<i.getQuantity()<<'\n';
    
	cout<<"Details of Product which is Unavailable and demand is high "<<minimumDemand<<endl;	    
   	for(auto i:productStatusUnavailable(dataTracking,minimumDemand))
		cout<<i.getProductName()
    		    <<'\t'<<i.getProductNum()
    		    <<'\t'<<i.getDemand()
    		    <<'\t'<<i.getState()
    		    <<'\t'<<i.getQuantity()<<'\n';
}


