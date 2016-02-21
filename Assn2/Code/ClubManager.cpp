#include "ClubManager.h"
ClubManager::ClubManager(){
	endOfContractDate = "";
}
ClubManager::ClubManager(string a,string b,string c, string d, string e,string g) : ClubMember(a,b,c,d,e,10){
	endOfContractDate = g;
}
ClubManager::~ClubManager(){
}
void ClubManager::setEndOfContractDate(string a){
	endOfContractDate = a;
}
string ClubManager::getEndOfContractDate(){
	return endOfContractDate;
}
void printClubManager(vector<ClubManager>& a){
	ofstream f1;
	vector<ClubManager> ::iterator ite;
	int i = 0;
	f1.open("ClubManager.txt",ios::trunc); 
	if (f1.fail()) {															
		cout << "Wrong file name or opening fail ( corrupted file ) " << endl;
		f1.close();																		// OPENED FILE IN IN MODE, IF THERE IS NO SUCH FILE THEN EXIT FUNCTION, DISPLAY ERROR
		return;
	}
	for (ite = a.begin();ite !=a.end();ite++){
		f1 << (*ite).getID() << ";" << (*ite).getPass() << ";" << (*ite).getName()  << ";" <<(*ite).getEmail() << ";"
		 << (*ite).getPhone() << ";"
		<< (*ite).getEndOfContractDate() << ";" << endl;
	}
	f1.close();
}
void readClubManager(vector<ClubManager>& a){
	ifstream f2;
	int i =0;
	f2.open("ClubManager.txt",ios::in);
	if (f2.fail()) {														
		cout << "Wrong file name or opening fail ( corrupted file ) " << endl;
		f2.close();																		// OPENED FILE IN IN MODE, IF THERE IS NO SUCH FILE THEN EXIT FUNCTION, DISPLAY ERRO
		return;
	}
	string dumpline;
	string delimiter = ";";
	while(getline(f2,dumpline)){
		string manID = dumpline.substr(0,dumpline.find(delimiter));
		dumpline.erase(0, dumpline.find(delimiter) + delimiter.length());
		string manPass = dumpline.substr(0,dumpline.find(delimiter));
		dumpline.erase(0, dumpline.find(delimiter) + delimiter.length());
		string manName = dumpline.substr(0,dumpline.find(delimiter));
		dumpline.erase(0, dumpline.find(delimiter) + delimiter.length());
		string manEmail = dumpline.substr(0,dumpline.find(delimiter));
		dumpline.erase(0, dumpline.find(delimiter) + delimiter.length());
		string manPhone = dumpline.substr(0,dumpline.find(delimiter));
		dumpline.erase(0, dumpline.find(delimiter) + delimiter.length());
		string manContract = dumpline.substr(0,dumpline.find(delimiter));
		dumpline.erase(0, dumpline.find(delimiter) + delimiter.length());
		ClubManager dumpMan(manID,manPass,manName,manEmail,manPhone,manContract);
		a.push_back(dumpMan);
		}
	f2.close();
}
void ClubManager::displayMan(){
	 cout << memberID << "	 " << memberPass << "	 " << memberName << "	 " << memberEmail << "	 " << memberPhone << "	 " 
	<< memberRanking << "	" << endOfContractDate << endl;
}
void ClubManager::addFacilities(vector<Facilities>& a){
	string facID;
	string facName;
	string facStatus;
	double norRate;
	double peakRate;
	bool found = false;
	int reqRank;
	vector<Facilities>::iterator ite1;
	cout << "Facility adding sub menu " << endl << endl;
	cout << "Please enter the following information: " << endl;
	cout << "Facility ID: ";
	cin >> facID;
	for (ite1 = a.begin();ite1 !=a.end();ite1++){
		if ( facID.compare((*ite1).getFac()) == 0){
			found = true;
			cout << "Facility already exists!!! " << endl;
			printReturn();
			return;
		}
	}	   
	cout << "Facility Name: ";
		cin.ignore(100,'\n');
	getline(cin,facName);
	cout << "Facility Status(Available or Not Available): ";
	getline(cin,facStatus);
	if (!checkStatus(facStatus)){
		cout << "You have entered a wrong status!!! " << endl;
		printReturn();
		return;
	}
	cout << "Enter Facility normal rate: " ;
	cin >> norRate;
	if ( cin.fail() ) {
		cin.clear();cin.ignore();cerr << endl << "         -----*Error!!: Invalid input*-----" <<endl;
		norRate = -999;
		printReturn();
		return;
	}
	cout << "Enter Facility peak rate: " ;
	cin >> peakRate;
	if ( cin.fail() ) {
		cin.clear();cin.ignore();cerr << endl << "         -----*Error!!: Invalid input*-----" <<endl;
		peakRate = -999;
		printReturn();
		return;
	}
	cout << "Enter required rank(1 - 10): " ;
	cin >> reqRank;
	if ( cin.fail() ) {
		cin.clear();cin.ignore();cerr << endl << "         -----*Error!!: Invalid input*-----" <<endl;
		reqRank = -999;
		printReturn();
		return;
	}
	if (reqRank < 1 || reqRank > 10) {
		cerr << endl << "         -----*Error!!: Invalid input*-----" <<endl;
		reqRank = -999;
		printReturn();
		return;
	}
	Facilities dump(facID,facName,facStatus,norRate,peakRate,reqRank);
	a.push_back(dump);
	cout << "You have successfully added Facility name: " << facName << endl;
	printReturn();
	
}
void ClubManager::deleteFacilities(vector<Facilities>& a){
	string facID;
	vector<Facilities>::iterator ite1;
	vector<Facilities>::iterator ite2;
	char choice = 'a';
	cout << "Facility deleting sub menu " << endl << endl;
	cout << "Please enter the following information: " << endl;
	cout << "Facility ID: ";
	cin >> facID;
	bool found = false;
	for (ite1 = a.begin();ite1 !=a.end();ite1++){
		if ( facID.compare((*ite1).getFac()) == 0){
			cout << "Facility Name: " << (*ite1).getName() << endl;
			found = true;
			
			cout << "Please confirm to delete this facility(y/n): ";
			cin >> choice;
			if (choice == 'y') {
			ite2 = ite1;
			cout << "Succesfully deleted!!!" << endl;
			}
			else if ( choice == 'n') cout << "You have chosen to not delete this facility " << endl;
			else cout << "Wrong choice !!!!!!!!" << endl;
			printReturn();
		}
	}
	if (found == false) {cout << "There is no such Facility with that ID!!!! " << endl;
	printReturn();}
	if (choice == 'y'){
		a.erase(ite2);
	}
}
void ClubManager::updateFacilities(vector<Facilities>& a){
	string facID;
	vector<Facilities>::iterator ite1;
	cout << "Facility updating sub menu " << endl << endl;
	cout << "Please enter the following information: " << endl;
	cout << "Facility ID: ";
	cin >> facID;
 	bool found = false;
	for (ite1 = a.begin();ite1 !=a.end();ite1++){
		if ( facID.compare((*ite1).getFac()) == 0){
			found = true;
		}
	}
	if (found == false) {
		cout << "There is no such Facility with that ID!!!! " << endl;
		printReturn();
		return;
	}
	else{
		for (ite1 = a.begin();ite1 !=a.end();ite1++){
		if ( facID.compare((*ite1).getFac()) == 0){
			(*ite1).changeMenu(a);
			}
		}
	}
	printReturn();
}
void ClubManager::queryMemberInformation(vector<ClubMember>& b){
	string memberID;
	bool found = false;
	vector<ClubMember>::iterator ite1;
	vector<DiscountServ>:: iterator ite2;
	cout << "Query Member Menu " << endl << endl;
	cout << "Please enter the following information: " << endl;
	cout << "Member ID: ";
	cin >> memberID;
	for (ite1 = b.begin();ite1 !=b.end();ite1++){
		if ( memberID.compare((*ite1).getID()) == 0){
			found = true;
		}
	}
	if (found == false) {
		cout << "No such member with that ID " << endl;
		printReturn();
		return;
	}
	else {
		for (ite1 = b.begin();ite1 !=b.end();ite1++){
		if ( memberID.compare((*ite1).getID()) == 0){
			cout << " Member found!!! " << endl;
			cout << "Member name: " << (*ite1).getName() << endl;
			cout << "Member email: " << (*ite1).getEmail() << endl;
			cout << "Member phone: " << (*ite1).getPhone() << endl;
			cout << "Member ranking(1-10): " << (*ite1).getRanking() << endl;
			}
		}
	}
	printReturn();
}
void ClubManager::editMemberRank(ClubMember& b ){
	int rank;
	cout << "Current ranking: " << b.getRanking() << endl;
	cout << "Please enter new rank value(1-10): ";
	cin >> rank;
		if ( cin.fail() ) {
		cin.clear();cin.ignore();cerr << endl << "         -----*Error!!: Invalid input*-----" <<endl;
		rank = -999;
		return;
	}
	if (rank < 1 && rank > 10) {
		cerr << endl << "         -----*Error!!: Invalid input*-----" <<endl;
		rank = -999;
		return;
	}
	b.setRank(rank);
	cout << "Member ID " << b.getID() << " 's rank changed successfully ! " << endl;

}
void ClubManager::editMemberMenu(vector<ClubMember>& b){
	string memberID;
	vector<ClubMember>::iterator ite1;
	vector<DiscountServ>:: iterator ite2;
	bool found = false;
	cout << "Editing member ranking menu " << endl << endl;
	cout << "Please enter the following information: " << endl;
	cout << "Member ID: ";
	cin >> memberID;
	for (ite1 = b.begin();ite1 !=b.end();ite1++){
		if ( memberID.compare((*ite1).getID()) == 0){
			found = true;
		}
	}
	if (found == false) {
		cout << "No such member with that ID " << endl;
		printReturn();
		return;
	}
	else{
		for (ite1 = b.begin();ite1 !=b.end();ite1++){
		if ( memberID.compare((*ite1).getID()) == 0){
			editMemberRank((*ite1));
				}
			}
		printReturn();
	}
}
void ClubManager::reportByMonth(vector<BookedFaci>& a,vector<Facilities>& b){
	string monthY;
	cout << "Report subsystem - Monthly report" << endl;
	cout << "Generate report if the month of booking is in the input month" << endl;
	cout << "Note*: Total Cost is 0.0 if the booking is not processed" << endl;
	cout << "Please enter the month in format (mm/yyyy): ";
	cin >> monthY;
	cout << endl;
	bool found = false;
	vector<BookedFaci>::iterator ite;
	for (ite = a.begin();ite !=a.end();ite++){
		if ( ((*ite).getDate()).find(monthY) != string::npos){
			found = true;
		}
	}
	if (found == true){
		cout << "Booking ID Facility ID  UserID     Date       Time   Dur.  Disc. Rate  Tot. Cost " << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		for (ite = a.begin();ite !=a.end();ite++){
		if (  ((*ite).getDate()).find(monthY) != string::npos){
		cout << setw(11) << left << (*ite).getRef() << setw(13) << (*ite).getFac() << setw(11) << (*ite).getMem() << setw(11) << (*ite).getDate()
		 << setw(7) << (*ite).getTime()  << (*ite).getDur() << setw(11) << " hours"  << setw(9) << (*ite).getDis()
		 << setw(8) << (*ite).getCost() << endl;
			}
		}
		printReturn();
	}
	else {
		cout << "No booking at that month!!" << endl;
		printReturn();
	}
	
}
void ClubManager::reportRecent(vector<BookedFaci>& a,vector<Facilities>& b){
	cout << "Report subsystem - Recent report" << endl;
	cout << "Generate recent booking report" << endl;
	int count = 0;
	cout << "Note*: Total Cost is 0.0 if the booking is not processed" << endl<< endl;
	vector<BookedFaci>::reverse_iterator ite;
	cout << "Booking ID Facility ID  UserID     Date       Time   Dur.  Disc. Rate  Tot. Cost " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	for (ite = a.rbegin();ite !=a.rend();ite++){
		cout << setw(11) << left << (*ite).getRef() << setw(13) << (*ite).getFac() << setw(11) << (*ite).getMem() << setw(11) << (*ite).getDate()
		 << setw(7) << (*ite).getTime()  << (*ite).getDur() << setw(11) << " hours"  << setw(9) << (*ite).getDis()
		 << setw(8) << (*ite).getCost() << endl;
		 count ++ ;
		 if ( count == 5 ) break;
	}
		
	printReturn();
}
void ClubManager::processBooking(vector<BookedFaci>& a,vector<Facilities>& b){
	string refID;
	int choice = 0;
	bool found = false;
	cout << "Process booking menu" << endl;
	cout << "Please enter booking ref. ID: " << endl;
	cin >> refID;
	vector<BookedFaci>::iterator ite;
	vector<BookedFaci>::iterator ite1;
	for (ite = a.begin();ite !=a.end();ite++){
		if (refID.compare((*ite).getRef()) == 0){
			found = true;
			cout << "1) Deny the booking " << endl;
			cout << "2) Process the booking" << endl;
			cin >> choice;
			if ( choice == 1 ) {
				ite1 = ite;
				cout << "The Booking is denied and deleted in the system!! " << endl; 
			}
			else if (choice == 2) {
				double discount = 0;
				cout << "Please enter discount rate ( lower than 1 ): ";
				cin >> discount;
				if (cin.fail()){
					cin.clear();cin.ignore();cerr << endl << "         -----*Error!!: Invalid input*-----" <<endl;
					printReturn();
					return;
					
				}
				if ( discount > 1 || discount <0 ){
					cout << "Discount rate must be lower than 1 and more than 0 " << endl;
					printReturn();
					return;
				}
				(*ite).setDis(discount);
				double cost = getNorPeak(b,(*ite).getFac());
				cost =  (1 -  discount) * cost;
				(*ite).setCost(cost);
				cout << "The booking is processed with a total cost of " << cost << "dollars" << endl;
			}
			else cout << "Wrong choice !!! " << endl;
			
		}
	}
	if (found == false) {
		cout << "There is no such booking with that ref. id" << endl;
	}
	if ( choice == 1 ){
		a.erase(ite1);
	}
	printReturn();
}
void ClubManager::ClubManagerMenu(vector<BookedFaci>& a,vector<Facilities>& b,vector<ClubMember>& c){
	int count = 0;
	int choice;
	while(true){
			if (count != 0 )
			cout << string( 50, '\n' );
			cout << "Club Manager Menu" << endl << endl;
			cout << "1)	  Add a Facility" << endl;
			cout << "2)	  Search Facility" << endl; 
			cout << "3)	  Delete Facility" << endl;
			cout << "4)	  Update Facility" << endl;
			cout << "5)	  Process a booking" << endl;
			cout << "6)	  Query member info" << endl;   
			cout << "7)	  Edit member ranking" << endl;           
			cout << "8)	  Report subsystem - monthly report" << endl;  
			cout << "9)	  Report subsystem - recent booking" << endl;                      
			cout << "10) Quit" << endl<<endl;
			cout << "Please enter your choice : ";
			cin >> choice;                   // prompt user to enter choice which is an integer
			cout << endl;
			if (choice == 10) break;         // if user selected 5 then it quit the loop.Hence, quit the program
			switch (choice)
			{
				case 1:addFacilities(b);
						break;
				case 2:searchFacilities(b);
						break;
				case 3:deleteFacilities(b);
						break;
				case 4:updateFacilities(b);
						break;
				case 5:processBooking(a,b);
						break;
				case 6:queryMemberInformation(c);
						break;
				case 7:editMemberMenu(c);
						break;
				case 8:reportByMonth(a,b);
						break;
				case 9:reportRecent(a,b);
						break;
				default:
					cout << "You have entered a wrong choice!!!!" << endl;break;
			}
			count++;
	}
	
}


