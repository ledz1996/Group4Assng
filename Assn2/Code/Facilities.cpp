#include "Facilities.h"
Facilities::Facilities(){
	facID = "";
	facName = "";
	facStatus = "";
	normalRate = 0.0;
	peakRate = 0.0;
	reqRank = 0;
}
Facilities::~Facilities(){
}
Facilities::Facilities(string a, string b, string c,double d, double e,int f){
	facID = a;
	facName = b;
	facStatus = c;
	normalRate = d;
	peakRate = e;
	reqRank = f;
}
void Facilities::setFac(string a){
	facID = a;
}
void Facilities::setName(string a){
	facName = a;
}
void Facilities::setStatus(string a){
	facStatus = a;
}
void Facilities::setNormal(double d){
	normalRate = d;
}
void Facilities::setPeak(double e){
	peakRate = e;
}
void Facilities::setRank(int f){
	reqRank = f;
}
string Facilities::getFac(){
	return facID;
}
string Facilities::getName(){
	return facName;
}
string Facilities::getStatus(){
	return facStatus;
}
double Facilities::getNormal(){
	return normalRate;
}
double Facilities::getPeak(){
	return peakRate;
}
int Facilities::getRank(){
	return reqRank;
}
void Facilities::display(){
	cout << facID << "	" << facName << "	" << facStatus << "	" << normalRate << "	" << peakRate << "	" << reqRank << endl;
}
void printFacilities(vector<Facilities>& a){
	ofstream f1;
	vector<Facilities> ::iterator ite;
	f1.open("Facilities.txt",ios::trunc); 
	if (f1.fail()) {															// PROMPT USER TO ENTER FILE NAME
		cout << "Wrong file name or opening fail ( corrupted file ) " << endl;
		f1.close();																		// OPENED FILE IN IN MODE, IF THERE IS NO SUCH FILE THEN EXIT FUNCTION, DISPLAY ERROR
		return;
	}
	else
	{
	for (ite = a.begin();ite !=a.end();ite++){
		f1 << (*ite).getFac() << ";" << (*ite).getName() << ";" << (*ite).getStatus() << ";" << (*ite).getNormal() << ";" 
		<< (*ite).getPeak() << ";" << (*ite).getRank()<< endl;
	}
		
	}
	f1.close();
}
void readFacilities(vector<Facilities>& a){
	ifstream f2;
	f2.open("Facilities.txt",ios::in);
	if (f2.fail()) {															// PROMPT USER TO ENTER FILE NAME
		cout << "Wrong file name or opening fail ( corrupted file ) " << endl;
		f2.close();																		// OPENED FILE IN IN MODE, IF THERE IS NO SUCH FILE THEN EXIT FUNCTION, DISPLAY ERROR
		return;
	}
	string dumpline;
	string delimiter = ";";
	while(getline(f2,dumpline)){
		string facID = dumpline.substr(0,dumpline.find(delimiter));
		dumpline.erase(0, dumpline.find(delimiter) + delimiter.length());
		string facName = dumpline.substr(0,dumpline.find(delimiter));
		dumpline.erase(0, dumpline.find(delimiter) + delimiter.length());
		string facStatus = dumpline.substr(0,dumpline.find(delimiter));
		dumpline.erase(0, dumpline.find(delimiter) + delimiter.length());
		string normalRate = dumpline.substr(0,dumpline.find(delimiter));
		dumpline.erase(0, dumpline.find(delimiter) + delimiter.length());
		string peakRate = dumpline.substr(0,dumpline.find(delimiter));
		dumpline.erase(0, dumpline.find(delimiter) + delimiter.length());
		string reqRank = dumpline.substr(0,dumpline.find(delimiter));
		dumpline.erase(0, dumpline.find(delimiter) + delimiter.length());
		double normal= 0.0;
		istringstream ( normalRate ) >>  normal;
		double peak = 0.0;
		istringstream ( peakRate ) >>  peak;
		int rank = 0;
		istringstream ( reqRank ) >>  rank;
		Facilities dump(facID,facName,facStatus,normal,peak,rank);
		a.push_back(dump);
	}
	f2.close();
}
void printReturn(){
 	string dump;
 	cout<<"\nEnter anything to return to previous"<<endl;
	cin.clear();
	cin.ignore();                /// This function just to print a message to prompt user to enter anything then press enter to return to main menu
	getline(cin,dump);
}
void Facilities::changeID(vector<Facilities>& a){
	cin.ignore(100,'\n');
	vector<Facilities>::iterator ite1;
	string ID;
	cout << "Facility current ID: " << facID << endl;
	cout << "Enter new Facility ID in system( enter cancel to cancel the process ): " ;
	getline(cin,ID);
	if (ID.compare("cancel") == 0 ){
		cout << "Cancelled process !!!" << endl;
		printReturn();
		return;
	}
	else
	{
		for (ite1 = a.begin();ite1 !=a.end();ite1++){
		if ( ID.compare((*ite1).getFac()) == 0){
				cout << "Facility ID already exists!!! " << endl;
				printReturn();
				return;
			}
		}
		facID = ID;
		cout << "You have changed the Facility ID succesfully " << endl;	  
	}
	printReturn();
}
void Facilities::changeName(vector<Facilities>& a){
	cin.ignore(100,'\n');
	string name;
	vector<Facilities>::iterator ite1;
	cout << "Facility name: " << facName << endl;
	cout << "Enter new Facility name in system( enter cancel to cancel the process ): " ;
	getline(cin,name);
	if ( name.compare("cancel") == 0 ){
		cout << "Cancelled process !!!" << endl;
		printReturn();
		return;
	}
	else
	{
		for (ite1 = a.begin();ite1 !=a.end();ite1++){
		if ( name.compare((*ite1).getName()) == 0){
				cout << "Facility name already exists!!! " << endl;
				printReturn();
				return;
			}
		}
		facName = name;
		cout << "You have changed the Facility name succesfully " << endl;	    
	}
	printReturn();
}
void Facilities::changeStatus(){
	cin.ignore(100,'\n');
	string status;
	cout << "Facility status: " << facStatus << endl;
	cout << "Enter new Facility Status in system( enter cancel to cancel the process ): " ;
	getline(cin,status);
	if ( status.compare("cancel") == 0 ){
		cout << "Cancelled process !!!" << endl;
		printReturn();
		return;
	}
 	else if (!checkStatus(status))
	{
		cout << "You have entered a wrong status!!" << endl;
		printReturn();
		return;
	}
	else
	{
		facStatus = status;
		cout << "You have changed the Facility status succesfully " << endl;	  
	}
	printReturn();

}
void Facilities::changeNormalRate(){
		cin.ignore(100,'\n');
	double rate;
	cout << "Facility normal rate: " << normalRate << endl;
	cout << "Enter new Facility normal rate in system( enter 999 to cancel the process ): " ;
	cin >> rate;
	if ( rate == 999 ){
		cout << "Cancelled process !!!" << endl;
		printReturn();
		return;
	}
 	else if (cin.fail())
	{
		cin.clear();cin.ignore();cerr << endl << "         -----*Error!!: Invalid input*-----" <<endl;
		rate = 999;
		printReturn();
	}
	else
	{
		normalRate = rate;
		cout << "You have changed the Facility normal rate succesfully " << endl;	   
	}
	printReturn();

}
void Facilities::changePeakRate(){
		cin.ignore(100,'\n');
	double rate;
	cout << "Facility peak rate: " << peakRate << endl;
	cout << "Enter new Facility peak rate in system( enter 999 to cancel the process ): " ;
	cin >> rate;
	if ( rate == 999 ){
		cout << "Cancelled process !!!" << endl;
		printReturn();
		return;
	}
 	else if (cin.fail())
	{
		cin.clear();cin.ignore();cerr << endl << "         -----*Error!!: Invalid input*-----" <<endl;
		rate = 999;
		printReturn();
	}
	else
	{
		peakRate = rate;
		cout << "You have changed the Facility peak rate succesfully " << endl;	     
	}
	printReturn();
}
void Facilities::changeReqRank(){
	cin.ignore(100,'\n');
	int rank;
	cout << "Facility req. rank: " << reqRank << endl;
	cout << "Enter new Facility req. rank in system( enter 999 to cancel the process ): " ;
	cin >> rank;
	if ( rank == 999 ){
		cout << "Cancelled process !!!" << endl;
		printReturn();
		return;
	}
 	else if (cin.fail())
	{
		cin.clear();cin.ignore();cerr << endl << "         -----*Error!!: Invalid input*-----" <<endl;
		rank = 999;
		printReturn();
	}
	else
	{
		reqRank = rank;
		cout << "You have changed the Facility req. rank succesfully " << endl;	     
	}
	printReturn();
}
void Facilities::changeMenu(vector<Facilities>& a){
	int count = 0;
	int choice;
	while(true){
		if (count != 0 )
		cout << string( 50, '\n' );
		cout << "Facility update sub menu" << endl << endl;
		cout << "Your are updating facility ID: " << facID << endl;
		cout << "Your are changing facility information" << endl;
		cout << "1)	 Change Facility ID" << endl;
		cout << "2)	 Change Facility Name" << endl;
		cout << "3)	 Change Facility Status" << endl;
		cout << "4)	 Change Facility normal Rate" << endl;
		cout << "5)	 Change Facility peak Rate" << endl;
		cout << "6)	 Change Facility req. rank" << endl;
		cout << "7)	Quit" << endl<<endl;
		cout << "Please enter your choice : ";
		cin >> choice;                   // prompt user to enter choice which is an integer
			cout << endl;
			if (choice == 7) break;         // if user selected 5 then it quit the loop.Hence, quit the program
			switch (choice)
			{
				case 1:changeID(a);
						break;
				case 2:changeName(a);
						break;
				case 3:changeStatus();
						break;
				case 4:changeNormalRate();
						break;
				case 5:changePeakRate();
						break;
				case 6:changeReqRank();
						break;
				default:
					cout << "You have entered a wrong choice!!!!" << endl;break;
			}
			count++;
		}
}
double getNorPeak(vector<Facilities>& a ,string b){
	vector<Facilities>::iterator ite;
	for (ite = a.begin();ite !=a.end();ite++){
		if ( b.compare((*ite).getFac()) == 0){
			return((*ite).getNormal());
		}
	}
	
}

