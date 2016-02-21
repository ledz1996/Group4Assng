#ifndef ___BookedFaci__
#define ___BookedFaci__
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <time.h>
using namespace std;
class BookedFaci{
	private:
		string refID;
		string facID;   //facID from Facilities
		string memberID;  // member from Facilities
		string date;
		string time;      // 3 input attribitues
		int duration;
		double discountRate;   // empty w8 for manager process
		double totalCost;
	public:
		BookedFaci();
		~BookedFaci();
		BookedFaci(string,string,string,string,string,int,double,double);
		void setRef(string);
		void setFac(string);
		void setMem(string);
		void setDate(string);
		void setTime(string);
		void setDur(int);
		void setDis(double);
		void setCost(double);
		string getRef();
		string getFac();
		string getMem();
		string getDate();
		string getTime();
		int getDur();
		double getDis();
		double getCost();
		void display();
};
void printBookedFaci(vector<BookedFaci>&);
void readBookedFaci(vector<BookedFaci>&);
string GenID(vector<BookedFaci>&);
bool checkDate(string);
bool checkTime(string);
bool checkStatus(string);
int getHour(string);
#endif

