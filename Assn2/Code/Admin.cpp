#include "Admin.h"
Admin::Admin(){
	username = "";
	password = "";
}
Admin::Admin(string a,string b){
	username = a;
	password = b;
}
Admin::~Admin(){

}
void Admin::setUser(string a){
	username = a;
}
void Admin::setPass(string b){
	password = b;
}
string Admin::getUser(){
	return username;
}
string Admin::getPass(){
	return password;
}
void Admin::addMember(vector<ClubMember>& b){
	vector<ClubMember>::iterator ite1;
	string memberID;
	string memberPass;
	string memberName;
	string memberEmail;
	string memberPhone;
	int rank;
	cout << "Add a Member sub menu" << endl << endl;
	cout << "Please enter the following information: " << endl;
	cout << "Member ID: ";
	cin >> memberID;
	for (ite1 = b.begin();ite1 !=b.end();ite1++){
		if ( memberID.compare((*ite1).getID()) == 0){
			cout << "Member ID already exist !!!!!!" << endl;
			printReturn();
			return;
		}
	}
	cout << "Member Pass: ";
	cin >> memberPass;
	cin.ignore(100, '\n');
	cout << "Member Name: ";
	getline(cin,memberName);
	cout << "Member Email: ";
	cin >> memberEmail;
	cout << "Member Phone: ";
	cin >> memberPhone;
	cout << "Member Ranking( 1 to 10 ): ";
	cin >> rank;
	if ( cin.fail() ) {
		cin.clear();cin.ignore();cerr << endl << "         -----*Error!!: Invalid input*-----" <<endl;
		rank = -999;
		printReturn();
		return;
	}
	if (rank < 1 && rank > 10) {
		cerr << endl << "         -----*Error!!: Invalid input*-----" <<endl;
		rank = -999;
		printReturn();
		return;
	}
	ClubMember dump(memberID,memberPass,memberName,memberEmail,memberPhone,rank);
	b.push_back(dump);
	cout << "Succesfully added member " << memberID << " !!! " << endl;
	printReturn();
}
void Admin::deleteMember(vector<ClubMember>& b){
	string memberID;
	char choice = '=';
	bool found = false;
	vector<ClubMember>::iterator ite1;
	vector<ClubMember>::iterator ite2;
	cout << "Delete a Member sub menu" << endl << endl;
	cout << "Please enter the following information: " << endl;
	cout << "Member ID: ";
	cin >> memberID;
	for (ite1 = b.begin();ite1 !=b.end();ite1++){
		if ( memberID.compare((*ite1).getID()) == 0){
			cout << "Member Name: " << (*ite1).getName() << endl;;
			found = true;
			
			cout << "Please confirm to delete this member(y/n): ";
			cin >> choice;
			if (choice == 'y') {
				ite2 = ite1;
				cout <<" Member has been deleted !!! " << endl;
			}
			else if ( choice == 'n') cout << "You have chosen to not delete this member " << endl;
			else cout << "Wrong choice !!!!!!!!" << endl;
			printReturn();
		}
	}
	if (found == false) {cout << "There is no such Member with that ID!!!! " << endl;
	printReturn();}
	if ( choice == 'y'){
		b.erase(ite2);
	}
}
void Admin::editID(ClubMember& b,vector<ClubMember>& a){
cin.ignore(100,'\n');
	string ID;
	vector<ClubMember>::iterator ite1;
	cout << "Member current ID: " << b.getID() << endl;
	cout << "Please enter new ID for this member( enter cancel to cancel the process ): ";
	cin >> ID;
	for (ite1 = a.begin();ite1 !=a.end();ite1++){
		if ( ID.compare((*ite1).getID()) == 0){
			cout << "Member ID already exist !!!!!!" << endl;
			printReturn();
			return;
		}
	}
	if ( ID.compare("cancel") == 0 ){
		cout << "Cancelled process !!!" << endl;
		printReturn();
		return;
	}
	b.setID(ID);
	cout << "Succesfully change ID for this member!" << endl;
	printReturn();
}
void Admin::editName(ClubMember& b){
cin.ignore(100,'\n');
	string name;
	cout << "Member current name: " << b.getName() << endl;
	cout << "Please enter new name for this member( enter cancel to cancel the process ): ";
	getline(cin,name);
	if ( name.compare("cancel") == 0 ){
		cout << "Cancelled process !!!" << endl;
		printReturn();
		return;
	}
	else{
	b.setName(name);
	cout << "Succesfully change name for this member!" << endl;
		printReturn(); }
}
void Admin::editEmail(ClubMember& b){
cin.ignore(100,'\n');
	string email;
	cout <<"Member current email: " << b.getEmail() << endl;
	cout << "Please enter new email for this member( enter cancel to cancel the process ): ";
	cin>>email;
	if ( email.compare("cancel") == 0 ){
		cout << "Cancelled process !!!" << endl;
		printReturn();
		return;
	}
	else{
	b.setEmail(email);
	cout << "Successfully change email for this member!" << endl;
		printReturn();}

}
void Admin::editPhone(ClubMember& b){
cin.ignore(100,'\n');
	string phone;
	cout << "Member current phone: " << b.getPhone() << endl;
	cout << "Please enter new phone for this member( enter cancel to cancel the process ): " ;
	cin>> phone;
	if ( phone.compare("cancel") == 0 ){
		cout << "Cancelled process !!!" << endl;
		printReturn();
		return;
	}
	else{
	b.setPhone(phone);
	cout << "Successfully change phone for this member!" << endl;
		printReturn();}
}
void Admin::editRanking(ClubMember& b){
cin.ignore(100,'\n');
	int rank;
	cout << "Member current rank: " << b.getRanking() << endl;
	cout << "Please enter new rank for this member( 1 - 10 ): ";
	cin >> rank;
	if ( cin.fail() ) {
		cin.clear();cin.ignore();cerr << endl << "         -----*Error!!: Invalid input*-----" <<endl;
		rank = -999;
		printReturn();
		return;
	}
	if (rank < 1 && rank > 10) {
		cerr << endl << "         -----*Error!!: Invalid input*-----" <<endl;
		rank = -999;
		printReturn();
		return;
	}
	b.setRank(rank);
	cout << "Successfully change rank for this member" << endl;
	printReturn();
	
}
void Admin::editPass(ClubMember& b){
cin.ignore(100,'\n');
	string pass;
	cout <<"Member current pass: " << b.getPass() << endl;
	cout << "Please enter new pass for this member( enter cancel to cancel ): ";
	cin>>pass;
	if ( pass.compare("cancel") == 0 ){
		cout << "Cancelled process !!!" << endl;
		printReturn();
		return;
	}
	b.setPass(pass);
	cout << "Successfully change email for this member!" << endl;
		printReturn();

}
void Admin::updateMember(vector<ClubMember>& b){
	string memberID;
	bool found = false;
	int count = 0;
	int choice;
	vector<ClubMember>::iterator ite1;
	vector<ClubMember>::iterator ite2;
	cout << "Update a Member sub menu" << endl << endl;
	cout << "Please enter the following information: " << endl;
	cout << "Member ID: ";
	cin >> memberID;
	for (ite1 = b.begin();ite1 !=b.end();ite1++){
		if ( memberID.compare((*ite1).getID()) == 0){
			cout << "Member found!!" << endl;
			found = true;
			while (true){
			if (count != 0 )
			cout << string( 50, '\n' );
			cout << "Updating member subsystem" << endl << endl;
			cout << "Your are changing member information" << endl;
			cout << "1)	 Change member ID" << endl;
			cout << "2)	 Change member name" << endl;
			cout << "3)	 Change member email" << endl;
			cout << "4)	 Change member phone" << endl;
			cout << "5)	 Change member ranking" << endl;
			cout << "6)	 Change member password" << endl;
			cout << "7)	Quit" << endl<<endl;
			cout << "Please enter your choice : ";
			cin >> choice;                   // prompt user to enter choice which is an integer
			cout << endl;
			if (choice == 7) break;         // if user selected 5 then it quit the loop.Hence, quit the program
			switch (choice)
			{
				case 1:editID((*ite1),b);
						break;
				case 2:editName((*ite1));
						break;
				case 3:editEmail((*ite1));
						break;
				case 4:editPhone((*ite1));
						break;
				case 5:editRanking((*ite1));
						break;
				case 6:editPass((*ite1));
						break;
				default:
					cout << "You have entered a wrong choice!!!!" << endl;break;
			}
			count++;
			}
			
		}
	}
	if (found == false){cout << "There is no such Member with that ID!!!! " << endl;
	printReturn();}
	
}
void Admin::searchMember(vector<ClubMember>& b){
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
void Admin::addManager(vector<ClubManager>& c){
	vector<ClubManager>::iterator ite1;
	string memberID;
	string memberPass;
	string memberName;
	string memberEmail;
	string memberPhone;
	string date;
	cout << "Add a Manager sub menu" << endl << endl;
	cout << "Please enter the following information: " << endl;
	cout << "Manager ID: ";
	cin >> memberID;
	for (ite1 = c.begin();ite1 !=c.end();ite1++){
		if ( memberID.compare((*ite1).getID()) == 0){
			cout << "Manager ID already exist !!!!!!" << endl;
			printReturn();
			return;
		}
	}
	cout << "Manager Pass: ";
	cin >> memberPass;
	cout << "Manager Name: ";
	getline(cin,memberName);
	cin.ignore(100, '\n');
	cout << "Manager Email: ";
	cin >> memberEmail;
	cout << "Manager Phone: ";
	cin >> memberPhone;
	cout << "Manager end of contract date(dd/mm/yyyy): ";
	cin >> date;
	ClubManager dump(memberID,memberPass,memberName,memberEmail,memberPhone,date);
	c.push_back(dump);
	cout << "Succesfully added manager " << memberID << " !!! " << endl;
	printReturn();
}
void Admin::deleteManager(vector<ClubManager>& c){
	string memberID;
	bool found = false;
	char choice = '=';
	vector<ClubManager>::iterator ite1;
	vector<ClubManager>::iterator ite2;
	cout << "Delete a Manager sub menu" << endl << endl;
	cout << "Please enter the following information: " << endl;
	cout << "Manager ID: ";
	cin >> memberID;
	for (ite1 = c.begin();ite1 !=c.end();ite1++){
		if ( memberID.compare((*ite1).getID()) == 0){
			cout << "Manager Name: " << (*ite1).getName();
			found = true;
		
			cout << "Please confirm to delete this member(y/n): ";
			cin >> choice;
			if (choice == 'y') {
			ite2 = ite1;
			cout << "Succesfully deleted!!!" << endl;
			}
			else if ( choice == 'n') cout << "You have chosen to not delete this member " << endl;
			else cout << "Wrong choice !!!!!!!!" << endl;
			printReturn();
		}
	}
	if (found == false) {cout << "There is no such Manager with that ID!!!! " << endl;
	printReturn();}
	if ( choice == 'y'){
		c.erase(ite2);
	}

}
void Admin::searchManager(vector<ClubManager>& c){
	string memberID;
	bool found = false;
	vector<ClubManager>::iterator ite1;
	cout << "Query Manager Menu " << endl << endl;
	cout << "Please enter the following information: " << endl;
	cout << "Manager ID: ";
	cin >> memberID;
	for (ite1 = c.begin();ite1 !=c.end();ite1++){
		if ( memberID.compare((*ite1).getID()) == 0){
			found = true;
		}
	}
	if (found == false) {
		cout << "No such manager with that ID " << endl;
		printReturn();
		return;
	}
	else {
		for (ite1 = c.begin();ite1 !=c.end();ite1++){
		if ( memberID.compare((*ite1).getID()) == 0){
			cout << " Manager found!!! " << endl;
			cout << "Manager name: " << (*ite1).getName() << endl;
			cout << "Manager email: " << (*ite1).getEmail() << endl;
			cout << "Manager phone: " << (*ite1).getPhone() << endl;
			cout << "Manager end of contract date: " << (*ite1).getEndOfContractDate() << endl;
			}
		}
	}
	printReturn();
	
}
void Admin::reportByMonth(vector<BookedFaci>& a,vector<Facilities>& b){
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
void Admin::reportRecent(vector<BookedFaci>& a,vector<Facilities>& b){
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
void Admin::AdminMenu(vector<ClubMember>& a,vector<ClubManager>& b,vector<BookedFaci>& c, vector<Facilities>& d){
	int count = 0;
	int choice;
	while(true){
			if (count != 0 )
			cout << string( 50, '\n' );
			cout << "Admin Menu" << endl << endl;
			cout << "1)	  Add a member" << endl;
			cout << "2)	  Search a member" << endl;   
			cout << "3)	  Update a member" << endl;
			cout << "4)	  Delete a member" << endl;
			cout << "5)	  Add a manager" << endl;   
			cout << "6)	  Search a manager" << endl;    
			cout << "7)	  Delete a manager" << endl;        
			cout << "8)	  Report subsystem - monthly report" << endl;  
			cout << "9)	  Report subsystem - recent booking" << endl;                      
			cout << "10)  Quit" << endl<<endl;
			cout << "Please enter your choice : ";
			cin >> choice;                   // prompt user to enter choice which is an integer
			cout << endl;
			if (choice == 10) break;         // if user selected 5 then it quit the loop.Hence, quit the program
			switch (choice)
			{
				case 1:addMember(a);
						break;
				case 2:searchMember(a);
						break;
				case 3:updateMember(a);
						break;
				case 4:deleteMember(a);
						break;
				case 5:addManager(b);
						break;
				case 6:searchManager(b);
						break;
				case 7:deleteManager(b);
						break;
				case 8:reportByMonth(c,d);
						break;
				case 9:reportRecent(c,d);
						break;
				default:
					cout << "You have entered a wrong choice!!!!" << endl;break;
			}
			count++;
	}
	
}
void readAdmin(vector<Admin>& b){
	ifstream f2;
	int i =0;
	f2.open("Admin.txt",ios::in);
	if (f2.fail()) {														
		cout << "Wrong file name or opening fail ( corrupted file ) " << endl;
		f2.close();																		// OPENED FILE IN IN MODE, IF THERE IS NO SUCH FILE THEN EXIT FUNCTION, DISPLAY ERRO
		return;
	}
	string dumpline;
	string delimiter = ";";
	while(getline(f2,dumpline)){
		string user = dumpline.substr(0,dumpline.find(delimiter));
		dumpline.erase(0, dumpline.find(delimiter) + delimiter.length());
		string pass = dumpline.substr(0,dumpline.find(delimiter));
		dumpline.erase(0, dumpline.find(delimiter) + delimiter.length());
		Admin dumpAd(user,pass);
		b.push_back(dumpAd);
		}
	f2.close();
}
void printAdmin(vector<Admin>& b){
	ofstream f1;
	vector<Admin> ::iterator ite;
	int i = 0;
	f1.open("Admin.txt",ios::trunc); 
	if (f1.fail()) {															
		cout << "Wrong file name or opening fail ( corrupted file ) " << endl;
		f1.close();																		// OPENED FILE IN IN MODE, IF THERE IS NO SUCH FILE THEN EXIT FUNCTION, DISPLAY ERROR
		return;
	}
	for (ite = b.begin();ite !=b.end();ite++){
		f1 << (*ite).getUser() << ";" << (*ite).getPass() << endl;
	}
	f1.close();
}
void Admin::display(){
	cout << username << "	" << password << endl;
}


