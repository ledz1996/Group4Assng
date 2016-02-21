#include "BookedFaci.h"
BookedFaci::BookedFaci(){
	refID = "";
	facID = "";
	memberID = "";
	date = "";
	time = "";
	duration = 0;
	discountRate = 0.0;
	totalCost = 0.0;
}
BookedFaci::~BookedFaci(){
	
}
BookedFaci::BookedFaci(string a, string b, string c, string d, string e, int f,double g, double h){
	refID = a;
	facID = b;
	memberID = c;
	date = d;
	time = e;
	duration = f;
	discountRate = g;
	totalCost = h;
}
void BookedFaci::setRef(string a){
	refID = a;
}
void BookedFaci::setFac(string a){
	facID = a;
}
void BookedFaci::setMem(string a){
	memberID = a;
}
void BookedFaci::setDate(string a){
	date = a;
}
void BookedFaci::setTime(string a){
	time = a;
}
void BookedFaci::setDur(int a){
	duration = a;
}
void BookedFaci::setDis(double a){
	discountRate = a;
}
void BookedFaci::setCost(double a){
	totalCost = a;
}
string BookedFaci::getRef(){
	return refID;
}
string BookedFaci::getFac(){
	return facID;
}
string BookedFaci::getMem(){
	return memberID;
}
string BookedFaci::getDate(){
	return date;
}
string BookedFaci::getTime(){
	return time;
}
int BookedFaci::getDur(){
	return duration;
}
double BookedFaci::getDis(){
	return discountRate;
}
double BookedFaci::getCost(){
	return totalCost;
}
void BookedFaci::display(){
	cout << refID << "	" << facID << "	" << memberID << "	" << date << "	" << time << "	" << duration << "	" << discountRate << "	" << totalCost << endl;
}
void printBookedFaci(vector<BookedFaci>& a){
	ofstream f1;
	vector<BookedFaci> ::iterator ite;
	
	f1.open("BookedFaci.txt",ios::trunc); 
	if (f1.fail()) {															// PROMPT USER TO ENTER FILE NAME
		cout << "Wrong file name or opening fail ( corrupted file ) " << endl;
		f1.close();																		// OPENED FILE IN IN MODE, IF THERE IS NO SUCH FILE THEN EXIT FUNCTION, DISPLAY ERROR
		return;
	}
	else{
		for (ite = a.begin();ite !=a.end();ite++){
		 f1 << (*ite).getRef() << ";" << (*ite).getFac() << ";"	  << (*ite).getMem() << ";"	     << (*ite).getDate() << ";"	 
		 << (*ite).getTime() << ";"	   << (*ite).getDur() << ";"	 << (*ite).getDis() << ";"<< (*ite).getCost() << endl;
		 }
		 
	}
	f1.close();
}
void readBookedFaci(vector<BookedFaci>& a){
	ifstream f2;
	f2.open("BookedFaci.txt",ios::in);
	if (f2.fail()) {															// PROMPT USER TO ENTER FILE NAME
		cout << "Wrong file name or opening fail ( corrupted file ) " << endl;
		f2.close();																		// OPENED FILE IN IN MODE, IF THERE IS NO SUCH FILE THEN EXIT FUNCTION, DISPLAY ERROR
		return;
	}
	string dumpline;
	string delimiter = ";";
	while(getline(f2,dumpline)){
		string refID = dumpline.substr(0, dumpline.find(delimiter));
		dumpline.erase(0, dumpline.find(delimiter) + delimiter.length());
		string facID = dumpline.substr(0, dumpline.find(delimiter));
		dumpline.erase(0, dumpline.find(delimiter) + delimiter.length());
		string memberID = dumpline.substr(0, dumpline.find(delimiter));
		dumpline.erase(0, dumpline.find(delimiter) + delimiter.length());
		string date = dumpline.substr(0, dumpline.find(delimiter));
		dumpline.erase(0, dumpline.find(delimiter) + delimiter.length());
		string time = dumpline.substr(0, dumpline.find(delimiter));
		dumpline.erase(0, dumpline.find(delimiter) + delimiter.length());
		string duration = dumpline.substr(0, dumpline.find(delimiter));
		dumpline.erase(0, dumpline.find(delimiter) + delimiter.length());
		string discountRate = dumpline.substr(0, dumpline.find(delimiter));
		dumpline.erase(0, dumpline.find(delimiter) + delimiter.length());
		string totalCost = dumpline.substr(0, dumpline.find(delimiter));
		dumpline.erase(0, dumpline.find(delimiter) + delimiter.length());
		int dur = 0;
		istringstream ( duration ) >> dur;
		double discount= 0.0;
		istringstream ( discountRate ) >>  discount;
		double total = 0.0;
		istringstream ( totalCost ) >> total;
		BookedFaci dump(refID,facID,memberID,date,time,dur,discount,total);
		a.push_back(dump);
	}
	f2.close();
	
}
string GenID(vector<BookedFaci>& a){
	string genarate;
	string original;
	int random;
	bool notFound = true;
	while (1){
	 random = rand() % 1000 + 1;
	 if (random < 10 ){
		original = static_cast<ostringstream*>( &(ostringstream() << random) )->str();
	 genarate = "BK00" + original;
	 }
	 else if (random < 100 ) {
	original = static_cast<ostringstream*>( &(ostringstream() << random) )->str();
	  genarate = "BK0" + original;	  
	 }
	 else if (random < 1000 ){
	 original = static_cast<ostringstream*>( &(ostringstream() << random) )->str();
	genarate = "BK" + original;	  
	 }
	vector<BookedFaci> ::iterator ite;
	for (ite = a.begin();ite !=a.end();ite++){
		if ( genarate.compare((*ite).getRef()) == 0 )
			notFound = false;
	 }
		if ( notFound == true ) break;
	}
	return genarate;
	
}
bool checkDate(string s){
   istringstream is(s);
  	int d,m,y;
    char delimiter;
    if (is >> d >> delimiter >> m >> delimiter >> y) {
        struct tm t = {0};
        t.tm_mday = d;
        t.tm_mon = m - 1;
        t.tm_year = y - 1900;
        t.tm_isdst = -1;

        // normalize:
        time_t when = mktime(&t);
        const struct tm *norm = localtime(&when);
        // the actual date would be:
        // m = norm->tm_mon + 1;
        // d = norm->tm_mday;
        // y = norm->tm_year;
        // e.g. 29/02/2013 would become 01/03/2013

        // validate (is the normalized date still the same?):
        return (norm->tm_mday == d    &&
                norm->tm_mon  == m - 1 &&
                norm->tm_year == y - 1900);
    }
    return false;
}
bool checkTime(string s){
	istringstream is(s);
    char delimiter;
	int h,m;
    if (is >> h >> delimiter >> m ) {
    	  return (((h >= 0) && (h < 24)) && 
                    ((m >= 0) && (m < 60)))
                    ; 
    }
    return false;
}
bool checkStatus(string s){
	if (s.compare("Available")!=0 && s.compare("Not Available") !=0)
		return false;
	else return true;
}
int getHour(string s){
	istringstream is(s);
    char delimiter;
	int h,m;
	is >> h >> delimiter >> m;
	return h;
}

