#include "System.h"
System::System(){
	readFacilities(vecFac);
	readBookedFaci(vecBook);
	readClubMember(vecMem);
	readClubManager(vecMan);
	readAdmin(vecAd);
}
System::~System(){
	printFacilities(vecFac);
	printBookedFaci(vecBook);
	printClubMember(vecMem);
	printClubManager(vecMan);
	printAdmin(vecAd);
}
bool System::verifyMem(string a, string b){
	bool found = false;
	vector<ClubMember>::iterator ite1;
	for (ite1 = vecMem.begin();ite1 != vecMem.end();ite1++){
		if ( a.compare((*ite1).getID()) == 0 && b.compare((*ite1).getPass()) == 0 )
			return true;
	}
	return false;
}
bool System::verifyMan(string a,string b){
	bool found = false;
	vector<ClubManager>::iterator ite1;
	for (ite1 = vecMan.begin();ite1 != vecMan.end();ite1++){
		if ( a.compare((*ite1).getID()) == 0 && b.compare((*ite1).getPass()) == 0 )
			return true;
	}
	return false;
}
bool System::verifyAdmin(string a,string b){
	bool found = false;
	vector<Admin>::iterator ite1;
	for (ite1 = vecAd.begin();ite1 != vecAd.end();ite1++){
		if ( a.compare((*ite1).getUser()) == 0 && b.compare((*ite1).getPass()) == 0 )
			return true;
	}
	return false;
}
void System::logInMem(){
	string username;
	string password;
	string dump;
	cout << "Member Log-in" << endl <<endl;
	cout << "Please enter the following information: " << endl;
	cout << "	User name:";
	cin >> username;
	cout << "	Password:";
	cin >> password;
	vector<ClubMember>::iterator ite1;
	if (!verifyMem(username,password)){
		cout << "Wrong log-in information" << endl;
		printReturn();
	}
	else{
		cout << "Log-in successfully as member! " << endl;
		cout << "Enter anything to proceed to the next menu"  << endl;
		cin.ignore(100,'\n');
		getline(cin,dump);
		for (ite1 = vecMem.begin();ite1 != vecMem.end();ite1++){
			if ( username.compare((*ite1).getID()) == 0)
				(*ite1).memMenu(vecFac,vecBook);
		}
	}
}
void System::logInMan(){
	string username;
	string password;
	string dump;
	cout << "Manager Log-in" << endl <<endl;
	cout << "Please enter the following information: " << endl;
	cout << "	User name:";
	cin >> username;
	cout << "	Password:";
	cin >> password;
	vector<ClubManager>::iterator ite1;
	if (!verifyMan(username,password)){
		cout << "Wrong log-in information" << endl;
		printReturn();
	}
	else{
		cout << "Log-in successfully as manager! " << endl;
		cout << "Enter anything to proceed to the next menu"  << endl;
		cin.ignore(100,'\n');
		getline(cin,dump);
		for (ite1 = vecMan.begin();ite1 != vecMan.end();ite1++){
			if ( username.compare((*ite1).getID()) == 0)
				(*ite1).ClubManagerMenu(vecBook,vecFac,vecMem);
		}
	}
}
	
void System::logInAdmin(){
	string username;
	string password;
	string dump;
	cout << "Admin Log-in" << endl <<endl;
	cout << "Please enter the following information: " << endl;
	cout << "	User name:";
	cin >> username;
	cout << "	Password:";
	cin >> password;
	vector<Admin>::iterator ite1;
	if (!verifyAdmin(username,password)){
		cout << "Wrong log-in information" << endl;
		printReturn();
		return;
	}
	else{
		cout << "Log-in successfully as admin! " << endl;
		cout << "Enter anything to proceed to the next menu"  << endl;
		cin.ignore(100,'\n');
		getline(cin,dump);
		for (ite1 = vecAd.begin();ite1 != vecAd.end();ite1++){
			if ( username.compare((*ite1).getUser()) == 0)
				(*ite1).AdminMenu(vecMem,vecMan,vecBook,vecFac);
		}
	}
}
	
void System::logInMenu(){
	int count = 0;
	int choice;
	while(true){
			if (count != 0 )
			cout << string( 50, '\n' );
			cout << "****************************************************" << endl;
			cout << "  	    COUNTRY CLUB FACILITIES BOOKING SYSTEM "<< endl;
			cout << "****************************************************" << endl << endl;
			
			cout << "Log-in menu" << endl << endl;
			cout << "1)	  Log-in as Member" << endl;
			cout << "2)	  Log-in as Manager" << endl; 
			cout << "3)	  Log-in as Admin" << endl;               
			cout << "4) Quit" << endl<<endl;
			cout << "Please enter your choice : ";
			cin >> choice;                   // prompt user to enter choice which is an integer
			cout << endl;
			if (choice == 4) break;         // if user selected 5 then it quit the loop.Hence, quit the program
			switch (choice)
			{
				case 1:logInMem();
						break;
				case 2:logInMan();
						break;
				case 3:logInAdmin();
						break;
				default:
					cout << "You have entered a wrong choice!!!!" << endl;break;
			}
			count++;
	}
	
}
int main(){
srand(time(NULL));
System a;
a.logInMenu();
}

