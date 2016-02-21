#ifndef ___Admin__
#define ___Admin__
#include "Facilities.h"
#include "BookedFaci.h"
#include "ClubMember.h"
#include "ClubManager.h"
class Admin{
	private:
		string username;
		string password;
	public:
		Admin();
		Admin(string,string);
		~Admin();
		void setUser(string);
		void setPass(string);
		string getUser();
		string getPass();
		void display();
		void editID(ClubMember& b,vector<ClubMember>& a);
		void editName(ClubMember& b);
		void editEmail(ClubMember& b);
		void editPhone(ClubMember& b);
		void editRanking(ClubMember& b);
		void editPass(ClubMember& b);
		void addMember(vector<ClubMember>& b);
		void deleteMember(vector<ClubMember>& b);
		void updateMember(vector<ClubMember>& b);
		void searchMember(vector<ClubMember>& b);
		void addManager(vector<ClubManager>& c);
		void deleteManager(vector<ClubManager>& c);	   
		void searchManager(vector<ClubManager>& c);
		void AdminMenu(vector<ClubMember>& a,vector<ClubManager>& b,vector<BookedFaci>& c, vector<Facilities>& d);
		void reportByMonth(vector<BookedFaci>& a,vector<Facilities>& b);
		void reportRecent(vector<BookedFaci>& a,vector<Facilities>& b);
};
void printAdmin(vector<Admin>& a);
void readAdmin(vector<Admin>& b);
#endif

