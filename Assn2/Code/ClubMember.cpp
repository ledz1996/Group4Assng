#include "ClubMember.h"
ClubMember::ClubMember(){
	memberID = "";
	memberPass = "";
	memberName = "";
	memberEmail = "";
	memberPhone = "";
	memberRanking = 0;
	discountServ.clear();
}
ClubMember::~ClubMember(){
	discountServ.clear();
}
ClubMember::ClubMember(string a,string b, string c, string d,string e,int g){
	memberID = a;
	memberPass = b;
	memberName = c;
	memberEmail = d;
	memberPhone = e;
	memberRanking = g;
}
void ClubMember::setID(string a){
	memberID = a;
}
void ClubMember::setPass(string a){
	memberPass = a;
}
void ClubMember::setName(string a){
	memberName = a;
}
void ClubMember::setEmail(string a){
	memberEmail = a;
}
void ClubMember::setPhone(string a){
	memberPhone = a;
}
void ClubMember::setRank(int a){
	memberRanking = a;
}
void ClubMember::addDiscount(DiscountServ a){
	discountServ.push_back(a);
}
string ClubMember::getID(){
	return memberID;
}
string ClubMember::getPass(){
	return memberPass;
}
string ClubMember::getName(){
	return memberName;
}
string ClubMember::getEmail(){
	return memberEmail;
}
string ClubMember::getPhone(){
	return memberPhone;
}
int ClubMember::getRanking(){
	return memberRanking;
}
void ClubMember::display(){
	vector<DiscountServ>::iterator ite;
	cout << memberID << "	" << memberPass << "	" << memberName << "	" << memberEmail << "	" << memberPhone << "	" 
	<< memberRanking << "	"
	<< discountServ.size() << "	";
	for ( ite = discountServ.begin(); ite != discountServ.end(); ite ++ ){
		cout << (*ite).serName << "	" << (*ite).rate << " " ;
	}
	cout<< endl;
}
int ClubMember::getNoOfDis(){
	return discountServ.size();
}
string ClubMember::getServ(int pos){
	return discountServ[pos].serName;
}
double ClubMember::getRate(int pos){
	return discountServ[pos].rate;
}
void printClubMember(vector<ClubMember>& a){
	ofstream f1;
	vector<ClubMember> ::iterator ite;
	int i = 0;
	f1.open("ClubMember.txt",ios::trunc); 
	if (f1.fail()) {															// PROMPT USER TO ENTER FILE NAME
		cout << "Wrong file name or opening fail ( corrupted file ) " << endl;
		f1.close();																		// OPENED FILE IN IN MODE, IF THERE IS NO SUCH FILE THEN EXIT FUNCTION, DISPLAY ERROR
		return;
	}
	for (ite = a.begin();ite !=a.end();ite++){
		
		f1 << (*ite).getID() << ";" << (*ite).getPass() << ";" << (*ite).getName()  << ";" <<(*ite).getEmail() << ";"
		 << (*ite).getPhone() << ";" << (*ite).getRanking() << ";"
		<< (*ite).getNoOfDis() << ";";   
		for ( i = 0 ; i < (*ite).getNoOfDis(); i++  ){
			f1 << (*ite).getServ(i) << ";"<< (*ite).getRate(i) << ";" ;
		}	
		f1 << endl;	   
	}
	f1.close();
}
void ClubMember::searchByID(vector<Facilities>& a){
	bool found = false;
	int count;
	string ID;
	vector<Facilities>::iterator ite;
	cin.ignore(100,'\n');
	cout << "Please enter Facility ID: ";
	cin >> ID;
	for (ite = a.begin();ite !=a.end();ite++){
		if ( ID.compare((*ite).getFac()) == 0){
			count ++;
			found = true;
		}
	}
	if (found == false) {
		cout << "			ERROR:There is no such facility with that ID" << endl;
	}
	else{
	for (ite = a.begin();ite !=a.end();ite++){
		if ( ID.compare((*ite).getFac()) == 0)
			{
				cout << "Facility ID: " << (*ite).getFac() << endl;
				cout << "Facility Name: " << (*ite).getName() << endl;
				cout << "Facility Status: " << (*ite).getStatus() << endl;
				cout << "Facility Normal Rate: " <<(*ite).getNormal() << endl;
				cout << "Facility Peak Rate: " << (*ite).getPeak() << endl;
				cout << "Facility Rank Required: " << (*ite).getRank() << endl << endl;
			}
		}
	}
	printReturn();
}
void ClubMember::searchByName(vector<Facilities>& a){
	bool found = false;
	string name;
	int count = 0;
	int pos = 0;
	vector<Facilities>::iterator ite;
	cin.ignore(100,'\n');
	cout << "Please enter Facility Name( can be part of ) : ";
	getline(cin,name);
	for (ite = a.begin();ite !=a.end();ite++){
		if ( ((*ite).getName()).find(name) != string::npos){
			count ++;
			found = true;
			}
	}
	if (found == false) {
		cout << "			ERROR:There is no such facility contain that string" << endl;
	}
	else{
	cout << " Found " << count << " Facilities(Facility)" << endl;
	for (ite = a.begin();ite !=a.end();ite++){
		if ( ((*ite).getName()).find(name) != string::npos)
			{
				cout << "Facility found no: " << pos+1 << endl;
				cout << "Facility ID: " << (*ite).getFac() << endl;
				cout << "Facility Name: " << (*ite).getName() << endl;
				cout << "Facility Status: " << (*ite).getStatus() << endl;
				cout << "Facility Normal Rate: " <<(*ite).getNormal() << endl;
				cout << "Facility Peak Rate: " << (*ite).getPeak() << endl;
				cout << "Facility Rank Required: " << (*ite).getRank() << endl << endl;
				pos ++;
			}
		}
	}
	printReturn();
}
void ClubMember::searchByStatus(vector<Facilities>& a) {
	bool found = false;
		string avai = "Available";
		string notavai = "Not Available";
		int pos = 0;
	int choice = 0;
		vector<Facilities>::iterator ite;
	cout << "Please select the status you want to choose: "<< endl;
	cout << "	1. Available" << endl;
	cout << "	2. Not Available" << endl;
	cout << "Your choice: " << endl;
	cin >> choice;
	if ( cin.fail() ) {
		cin.clear();cin.ignore();cerr << endl << "         -----*Error!!: Invalid input*-----" <<endl;
		choice = -999;
	}
	if ( choice == 1) {	
		for (ite = a.begin();ite !=a.end();ite++){
		if ( avai.compare((*ite).getStatus()) == 0 )
			{
				cout << "Facility found no: " << pos+1 << endl;
				cout << "Facility ID: " << (*ite).getFac() << endl;
				cout << "Facility Name: " << (*ite).getName() << endl;
				cout << "Facility Status: " << (*ite).getStatus() << endl;
				cout << "Facility Normal Rate: " <<(*ite).getNormal() << endl;
				cout << "Facility Peak Rate: " << (*ite).getPeak() << endl;
				cout << "Facility Rank Required: " << (*ite).getRank() << endl << endl;
				pos ++;
			}
		}
	}
	else if (choice == 2){
		for (ite = a.begin();ite !=a.end();ite++){
		if ( notavai.compare((*ite).getStatus()) == 0)
			{
				cout << "Facility found no: " << pos+1 << endl;
				cout << "Facility ID: " << (*ite).getFac() << endl;
				cout << "Facility Name: " << (*ite).getName() << endl;
				cout << "Facility Status: " << (*ite).getStatus() << endl;
				cout << "Facility Normal Rate: " <<(*ite).getNormal() << endl;
				cout << "Facility Peak Rate: " << (*ite).getPeak() << endl;
				cout << "Facility Rank Required: " << (*ite).getRank() << endl << endl;
				pos ++;
			}
		}
	}
	else cout << "Invalid choice" << endl;
	printReturn();
}
void ClubMember::searchByNorRate(vector<Facilities>& a) {
	bool found = false;
	bool less = false;
	int count = 0;
	int pos = 0;
	vector<Facilities>::iterator ite;
	int choice = 0;
	cout << "Please select the option you want to choose: "<< endl;
	cout << "	1. Less than" << endl;
	cout << "	2. More than" << endl;
	cout << "Your choice: ";
	cin >> choice;
	if ( cin.fail() ) {
		cin.clear();cin.ignore();cerr << endl << "         -----*Error!!: Invalid input*-----" <<endl;
		choice = -999;
	}
	if ( choice == 1 ) less = true;
	else if ( choice == 2 ) less = false;
	else 
	{
	cout << "Invalid choice" << endl;printReturn(); return;
		
	}
	cin.ignore(100,'\n');
	double rate;
	cout << "Please enter Normal Rate that you want to search";
	if (less == true) cout << "(less than): ";
	else cout << "(more than): ";
	cin >> rate;
	for (ite = a.begin();ite !=a.end();ite++){
		if ( less == true) {
			if ( (*ite).getNormal() < rate ) {
				found = true;
				count ++;
			}
		}
		else {
			if ( (*ite).getNormal() > rate ) {
				found = true;
				count ++;
			}
		
		}
	}
	if (found == false) {
		cout << "			ERROR:There is no such facility that meet the requirement" << endl;
	}
	else{
	cout << " Found " << count << " Facilities(Facility)" << endl;
	for (ite = a.begin();ite !=a.end();ite++){
			if ( less == true) {
			if ( (*ite).getNormal() < rate ) {
				cout << "Facility found no: " << pos+1 << endl;
				cout << "Facility ID: " << (*ite).getFac() << endl;
				cout << "Facility Name: " << (*ite).getName() << endl;
				cout << "Facility Status: " << (*ite).getStatus() << endl;
				cout << "Facility Normal Rate: " <<(*ite).getNormal() << endl;
				cout << "Facility Peak Rate: " << (*ite).getPeak() << endl;
				cout << "Facility Rank Required: " << (*ite).getRank() << endl << endl;
				pos ++;
			}
		}
			else {
			if ( (*ite).getNormal() > rate ) {
				cout << "Facility found no: " << pos+1 << endl;
				cout << "Facility ID: " << (*ite).getFac() << endl;
				cout << "Facility Name: " << (*ite).getName() << endl;
				cout << "Facility Status: " << (*ite).getStatus() << endl;
				cout << "Facility Normal Rate: " <<(*ite).getNormal() << endl;
				cout << "Facility Peak Rate: " << (*ite).getPeak() << endl;
				cout << "Facility Rank Required: " << (*ite).getRank() << endl << endl;
				pos ++;
				}
			}
	
	}
	}
	printReturn();
}
void ClubMember::searchByPeakRate(vector<Facilities>& a) {
	bool found = false;
	bool less = false;
	int count = 0;
	int pos = 0;
	vector<Facilities>::iterator ite;
	int choice = 0;
	cout << "Please select the option you want to choose: "<< endl;
	cout << "	1. Less than" << endl;
	cout << "	2. More than" << endl;
	cout << "Your choice: " ;
	cin >> choice;
	if ( cin.fail() ) {
		cin.clear();cin.ignore();cerr << endl << "         -----*Error!!: Invalid input*-----" <<endl;
		choice = -999;
	}
	if ( choice == 1 ) less = true;
	else if ( choice == 2 ) less = false;
	else 
	{
	cout << "Invalid choice" << endl;printReturn(); return;
		
	}
	cin.ignore(100,'\n');
	double rate;
	cout << "Please enter Peak Rate that you want to search";
	if (less == true) cout << "(less than): ";
	else cout << "(more than): ";
	cin >> rate;
	for (ite = a.begin();ite !=a.end();ite++){
		if ( less == true) {
			if ( (*ite).getPeak() < rate ) {
				found = true;
				count ++;
			}
		}
		else {
			if ( (*ite).getPeak() > rate ) {
				found = true;
				count ++;
			}
		
		}
	}
	if (found == false) {
		cout << "			ERROR:There is no such facility that meet the requirement" << endl;
	}
	else{
	cout << " Found " << count << " Facilities(Facility)" << endl;
	for (ite = a.begin();ite !=a.end();ite++){
			if ( less == true) {
			if ( (*ite).getPeak() < rate ) {
				cout << "Facility found no: " << pos+1 << endl;
				cout << "Facility ID: " << (*ite).getFac() << endl;
				cout << "Facility Name: " << (*ite).getName() << endl;
				cout << "Facility Status: " << (*ite).getStatus() << endl;
				cout << "Facility Normal Rate: " <<(*ite).getNormal() << endl;
				cout << "Facility Peak Rate: " << (*ite).getPeak() << endl;
				cout << "Facility Rank Required: " << (*ite).getRank() << endl << endl;
				pos ++;
			}
		}
			else {
			if ( (*ite).getPeak() > rate ) {
				cout << "Facility found no: " << pos+1 << endl;
				cout << "Facility ID: " << (*ite).getFac() << endl;
				cout << "Facility Name: " << (*ite).getName() << endl;
				cout << "Facility Status: " << (*ite).getStatus() << endl;
				cout << "Facility Normal Rate: " <<(*ite).getNormal() << endl;
				cout << "Facility Peak Rate: " << (*ite).getPeak() << endl;
				cout << "Facility Rank Required: " << (*ite).getRank() << endl << endl;
				pos ++;
			}
			}
	
	}
	}
	printReturn();
}
void ClubMember::searchByReqRank(vector<Facilities>& a){
	bool found = false;
	bool less = false;
	int count = 0;
	int pos = 0;
	vector<Facilities>::iterator ite;
	int choice = 0;
	cout << "Please select the option you want to choose: "<< endl;
	cout << "	1. Less than" << endl;
	cout << "	2. More than" << endl;
	cout << "Your choice: ";
	cin >> choice;
	if ( cin.fail() ) {
		cin.clear();cin.ignore();cerr << endl << "         -----*Error!!: Invalid input*-----" <<endl;
		choice = -999;
	}
	if ( choice == 1 ) less = true;
	else if ( choice == 2 ) less = false;
	else 
	{
	cout << "Invalid choice" << endl;printReturn(); return;
		
	}
	cin.ignore(100,'\n');
	int rank;
	cout << "Please enter rank that you want to search";
	if (less == true) cout << "(less than): ";
	else cout << "(more than): ";
	cin >> rank;
	for (ite = a.begin();ite !=a.end();ite++){
		if ( less == true) {
			if ( (*ite).getRank() < rank ) {
				found = true;
				count ++;
			}
		}
		else {
			if ( (*ite).getRank() > rank ) {
				found = true;
				count ++;
			}
		
		}
	}
	if (found == false) {
		cout << "			ERROR:There is no such facility that meet the requirement" << endl;
	}
	else{
	cout << " Found " << count << " Facilities(Facility)" << endl;
	for (ite = a.begin();ite !=a.end();ite++){
			if ( less == true) {
			if ( (*ite).getRank() < rank ) {
				cout << "Facility found no: " << pos+1 << endl;
				cout << "Facility ID: " << (*ite).getFac() << endl;
				cout << "Facility Name: " << (*ite).getName() << endl;
				cout << "Facility Status: " << (*ite).getStatus() << endl;
				cout << "Facility Normal Rate: " <<(*ite).getNormal() << endl;
				cout << "Facility Peak Rate: " << (*ite).getPeak() << endl;
				cout << "Facility Rank Required: " << (*ite).getRank() << endl << endl;
				pos ++;
			}
		}
			else {
			if ( (*ite).getRank() > rank ) {
				cout << "Facility found no: " << pos+1 << endl;
				cout << "Facility ID: " << (*ite).getFac() << endl;
				cout << "Facility Name: " << (*ite).getName() << endl;
				cout << "Facility Status: " << (*ite).getStatus() << endl;
				cout << "Facility Normal Rate: " <<(*ite).getNormal() << endl;
				cout << "Facility Peak Rate: " << (*ite).getPeak() << endl;
				cout << "Facility Rank Required: " << (*ite).getRank() << endl << endl;
				pos ++;
			}
			}
	
	}
	}
	printReturn();
}
void ClubMember::searchFacilities(vector<Facilities>& a){
	int count = 0;
	int choice;
	while (true)
	{	
			if (count != 0 )
			 cout << string( 50, '\n' );
			cout << "Search Facilities sub menu "<< endl;
			cout << endl << endl;
			cout << "1)	  Search by ID" << endl;
			cout << "2)	  Search by Name" << endl;                                
			cout << "3)	  Search by Status " << endl;
			cout << "4)	  Search by Normal Rate "  << endl;               /// Interface of the user
			cout << "5)	  Search by Peak Rate" << endl;
			cout << "6)	  Search by Rank Required" << endl;
			cout << "7)	  Quit" << endl<<endl;
			cout << "Please enter your choice : ";
			cin >> choice;                   // prompt user to enter choice which is an integer
			cout << endl;
			if (choice == 7) break;         // if user selected 5 then it quit the loop.Hence, quit the program
			switch (choice)
			{
				case 1:searchByID(a);
						break;
				case 2:searchByName(a);
						break;
				case 3:searchByStatus(a);
						break;
				case 4:searchByNorRate(a);
						break;
				case 5:searchByPeakRate(a);
						break;
				case 6:searchByReqRank(a);
						break;
			}
			count++;
	}

}
void ClubMember::BookFacility(vector<Facilities>& a, vector<BookedFaci>& b){
	string facID;
	bool found = false;
	string facStatus;
	string date;
	string time;
	string refID;
	int duration;
	int reqRank;
	vector<Facilities>::iterator ite1;
	vector<BookedFaci>::iterator ite2;
	cout << "Book Facility sub menu " << endl << endl;
	cout << "You are booking as: " << memberID << endl;
	cout << "Please enter the following information: " << endl;
	cout << "Facility ID: ";
	cin >> facID;
	
	for (ite1 = a.begin();ite1 !=a.end();ite1++){
		if ( facID.compare((*ite1).getFac()) == 0){
			facStatus = (*ite1).getStatus();
			reqRank = (*ite1).getRank();
			found = true;
		}
	}
	if ( found == true ){
		if (facStatus.compare("Not Available") == 0 )
			{
				cout << "Sorry that Facility is currently not available" <<endl << endl;
				printReturn();
				return;
			}
		if (reqRank > memberRanking ){
				cout << "Sorry your rank is not high enough to book this facility." <<endl << endl;
				printReturn();
				return;
		}
		cout << "Date(dd/mm/yyyy): ";
		cin >> date;
		if (!checkDate(date)){
			cout << "You have entered a wrong date format" << endl;
			printReturn();
			return;
		}
		cout << "Time(HH:MM): ";
		cin >> time;
		if (!checkTime(time)){
			cout << "You have entered a wrong time format" << endl;
			printReturn();
			return;
		}
		cout << "Duration: ";
		cin >> duration;
		refID = GenID(b);
		BookedFaci dump(refID,facID,memberID,date,time,duration,0.0,0.0);
		b.push_back(dump);
		cout << "Your booking ref. no: " << refID <<" is succesfully booked"
		 << ", The total cost will be 0 until our manager process it, Thank you! "<< endl;
		printReturn();
	}
	else{
		cout << "Please check your Facility ID entered, there is no such Facility exists with that ID!" << endl;
		printReturn();
	}
}
void ClubMember::changeName(){
	cin.ignore(100,'\n');
	string name;
	cout << "Your current name: " << memberName << endl;
	cout << "Enter your new name in system( enter cancel to cancel the process ): " ;
	getline(cin,name);
	if ( name.compare("cancel") == 0 ){
		cout << "Cancelled process !!!" << endl;
		printReturn();
		return;
	}
	else
	{
		memberName = name;
		cout <<"You have changed your name successfully!" << endl;
		printReturn();
	}
}
void ClubMember::changeEmail(){
	cin.ignore(100,'\n');
	string email;
	cout << "Your current email: " << memberEmail << endl;
	cout << "Enter your new email in system( enter cancel to cancel the process ): " ;
	getline(cin,email);
	if ( email.compare("cancel") == 0 ){
		cout << "Cancelled process !!!" << endl;
		printReturn();
		return;
	}
	else
	{
		memberEmail = email;
		cout <<"You have changed your email successfully!" << endl;
		printReturn();
	}
	
}
void ClubMember::changePass(){
	cin.ignore(100,'\n');
	string checkPass;
	string newPass;
	string newPass2;
	cout << "Please Enter your current password to check: ";
	getline(cin,checkPass);
	if (checkPass.compare(memberPass) != 0 )
	{
		cout << "You have entered a wrong password!" << endl;
		printReturn();
		return;
	}
	cout << "Please enter new password( enter cancel to cancel ): " << endl;
	getline(cin,newPass);
	if ( newPass.compare("cancel") == 0 ){
		cout << "Cancelled process !!!" << endl;
		printReturn();
		return;
	}
	cout << "Please re-enter the password to check: " << endl;
	getline(cin,newPass2);
	if (newPass2.compare(newPass) != 0 ){
		cout << "The second entered password is not the same as the first one!!";
		printReturn();
		return;
	}
	else{
		memberPass = newPass;
		cout <<"You have changed your password successfully!" << endl;
		printReturn();
	}
	
}
void ClubMember::changePhone(){
	cin.ignore(100,'\n');
	string phone;
	cout << "Your current phone: " << memberPhone << endl;
	cout << "Enter your new phone in system( enter cancel to cancel the process ): " ;
	getline(cin,phone);
	if ( phone.compare("cancel") == 0 ){
		cout << "Cancelled process !!!" << endl;
		printReturn();
		return;
	}
	else
	{
		memberPhone = phone;
		cout <<"You have changed your phone successfully!" << endl;
		printReturn();
	}
}
void ClubMember::viewYourBooking(vector<BookedFaci>& b){
	bool found = false;
	cout << "Member Profile Subsystem" << endl << endl;
	cout << "You are logging in as: " << memberID << endl;
	cout << "Note*: Total Cost is 0.0 if the booking is not processed" << endl<< endl;
	cout << "Your Booking list: " << endl;
	vector<BookedFaci>::iterator ite;
	for (ite = b.begin();ite !=b.end();ite++){
		if ( memberID.compare((*ite).getMem()) == 0){
			found = true;
		}
	}
	if (found == true){
		cout << "Booking ID Facility ID  Date       Time  Duration  Disc. Rate  Total Cost " << endl;
		cout << "-------------------------------------------------------------------------------" << endl;
		for (ite = b.begin();ite !=b.end();ite++){
		if ( memberID.compare((*ite).getMem()) == 0){
		cout << setw(11) << left << (*ite).getRef() << setw(13) << (*ite).getFac() << setw(11) << (*ite).getDate()
		 << setw(7) << (*ite).getTime()  << (*ite).getDur() << setw(11) << " hours"  << setw(9) << (*ite).getDis()
		 << setw(8) << (*ite).getCost() << endl;
			}
		}
		printReturn();
	}
	else {
		cout << "You have no booking!!" << endl;
		printReturn();
	}
	
	
}
void ClubMember::viewInfo(){
	string replaceName;
	string replaceEmail;
	string replacePhone;
	string replacePass;
	int count = 0;
	int choice;
	while(true){
		if (count != 0 )
		cout << string( 50, '\n' );
		cout << "Member Profile Subsystem" << endl << endl;
		cout << "Your are logging in as: " << memberID << endl;
		cout << "Your are changing your information" << endl;
		cout << "1)	 Change my name" << endl;
		cout << "2)	 Change my phone" << endl;
		cout << "3)	 Change my email" << endl;
		cout << "4)	 Change my password" << endl;
		cout << "5)	Quit" << endl<<endl;
		cout << "Please enter your choice : ";
		cin >> choice;                   // prompt user to enter choice which is an integer
			cout << endl;
			if (choice == 5) break;         // if user selected 5 then it quit the loop.Hence, quit the program
			switch (choice)
			{
				case 1:changeName();
						break;
				case 2:changePhone();
						break;
				case 3:changeEmail();
						break;
				case 4:changePass();
						break;
				default:
					cout << "You have entered a wrong choice!!!!" << endl;break;
			}
			count++;
		}
}
void ClubMember::viewDiscount(){
	cout << "Member Profile Subsystem" << endl << endl;
	cout << "Your are logging in as: " << memberID << endl;
	cout << "Your discount entitlement list: " << endl;
	int count = 0;
	
	vector<DiscountServ>::iterator ite;
	if (discountServ.empty()){
	cout << "You have no discount entitlement to club services!! " <<endl;
	printReturn();
	return;
	}
	else {
		for (ite = discountServ.begin();ite !=discountServ.end();ite++){
			cout << "Discount service entitlement num: " << ++count << endl;
			cout <<"Service name: " << (*ite).serName << endl;
			cout <<"Discount rate: " << (*ite).rate << endl << endl;
		}
	}
	printReturn();
	
}
void ClubMember::editInfo(vector<BookedFaci>& b){
	int count = 0;
	int choice;
	while(true){
			if (count != 0 )
			cout << string( 50, '\n' );
			cout << "Member Profile Subsystem" << endl << endl;
			cout << "You are logging in as: " << memberID << endl;
			cout << "1)	  Edit my information" << endl;
			cout << "2)	  View my booking" << endl;   
			cout << "3)	  View my list of discount entitlement" << endl;                             
			cout << "4)	  Quit" << endl<<endl;
			cout << "Please enter your choice : ";
			cin >> choice;                   // prompt user to enter choice which is an integer
			cout << endl;
			if (choice == 4) break;         // if user selected 5 then it quit the loop.Hence, quit the program
			switch (choice)
			{
				case 1:viewInfo();
						break;
				case 2:viewYourBooking(b);
						break;
				case 3:viewDiscount();
						break;
				default:
					cout << "You have entered a wrong choice!!!!" << endl;break;
			}
			count++;
	}
}
void ClubMember::memMenu(vector<Facilities>a, vector<BookedFaci>& b){
	int count = 0;
	int choice;
	while(true){
			if (count != 0 )
			cout << string( 50, '\n' );
			cout << "Member Profile Subsystem" << endl << endl;
			cout << "Your are logging in as: " << memberID << endl;
			cout << "1)	  Go to Member Profile subsystem" << endl;
			cout << "2)	  Search Facility" << endl;   
			cout << "3)	  Book a Facility" << endl;                             
			cout << "4)	  Quit" << endl<<endl;
			cout << "Please enter your choice : ";
			cin >> choice;                   // prompt user to enter choice which is an integer
			cout << endl;
			if (choice == 4) break;         // if user selected 5 then it quit the loop.Hence, quit the program
			switch (choice)
			{
				case 2:searchFacilities(a);
						break;
				case 3:BookFacility(a,b);
						break;
				case 1:editInfo(b);
						break;
				default:
					cout << "You have entered a wrong choice!!!!" << endl;break;
			}
			count++;
	}
	
}
void readClubMember(vector<ClubMember>& a){
	ifstream f2;
	int i =0;
	f2.open("ClubMember.txt",ios::in);
	if (f2.fail()) {															// PROMPT USER TO ENTER FILE NAME
		cout << "Wrong file name or opening fail ( corrupted file ) " << endl;
		f2.close();																		// OPENED FILE IN IN MODE, IF THERE IS NO SUCH FILE THEN EXIT FUNCTION, DISPLAY ERROR
		return;
	}
	string serName;
	string rate;
	string dumpline;
	string delimiter = ";";
	while(getline(f2,dumpline)){
		string memberID = dumpline.substr(0,dumpline.find(delimiter));
		dumpline.erase(0, dumpline.find(delimiter) + delimiter.length());
		string memberPass = dumpline.substr(0,dumpline.find(delimiter));
		dumpline.erase(0, dumpline.find(delimiter) + delimiter.length());
		string memberName = dumpline.substr(0,dumpline.find(delimiter));
		dumpline.erase(0, dumpline.find(delimiter) + delimiter.length());
		string memberEmail = dumpline.substr(0,dumpline.find(delimiter));
		dumpline.erase(0, dumpline.find(delimiter) + delimiter.length());
		string memberPhone = dumpline.substr(0,dumpline.find(delimiter));
		dumpline.erase(0, dumpline.find(delimiter) + delimiter.length());
		string memberRanking = dumpline.substr(0,dumpline.find(delimiter));
		dumpline.erase(0, dumpline.find(delimiter) + delimiter.length());
		int rank = 0;
		istringstream ( memberRanking ) >>  rank;
		ClubMember dump(memberID,memberPass,memberName,memberEmail,memberPhone,rank);
		string noOfDis = dumpline.substr(0,dumpline.find(delimiter));
		dumpline.erase(0, dumpline.find(delimiter) + delimiter.length());
		int no = 0;
		istringstream ( noOfDis ) >>  no;
		for ( i = 0 ; i < no ; i ++ ){
			DiscountServ dumpDis;
			dumpDis.serName = dumpline.substr(0,dumpline.find(delimiter));
			dumpline.erase(0, dumpline.find(delimiter) + delimiter.length());
			rate = dumpline.substr(0,dumpline.find(delimiter));
			dumpline.erase(0, dumpline.find(delimiter) + delimiter.length());
			istringstream ( rate ) >>  dumpDis.rate;
			dump.addDiscount(dumpDis);
		}
		a.push_back(dump);
	}
	f2.close();
}


