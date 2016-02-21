#ifndef ___Facilities__
#define ___Facilities__
#include "BookedFaci.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace std;
class Facilities{
	private:
		string facID;
		string facName;
		string facStatus;
		double normalRate;
		double peakRate;
		int reqRank;  // the rank require for member
	public:
		void changeID(vector<Facilities>& a);
		void changeName(vector<Facilities>& a);
		void changeStatus();
		void changeNormalRate();
		void changePeakRate();
		void changeReqRank();
		void changeMenu(vector<Facilities>& a);
		Facilities();
		~Facilities();
		Facilities(string,string,string,double,double,int);
		void setFac(string);
		void setName(string);
		void setStatus(string);
		void setNormal(double);
		void setPeak(double);
		void setRank(int);
		string getFac();
		string getName();
		string getStatus();
		double getNormal();
		double getPeak();
		int getRank();
		void display();
		
};
void getfacNamebyID(vector<Facilities>&,string);
void printFacilities(vector<Facilities>&);
void readFacilities(vector<Facilities>&);
void printReturn();
double getNorPeak(vector<Facilities>&,string);

#endif

