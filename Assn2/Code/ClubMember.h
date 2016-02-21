#ifndef ___ClubMembers__
#define ___ClubMembers__
#include "Facilities.h"
#include "BookedFaci.h"
struct DiscountServ{
	string serName;
	double rate;
};
class ClubMember{
	protected: 
		string memberID;
		string memberPass;
		string memberName;
		string memberEmail;
		string memberPhone;
		int memberRanking;
		vector<DiscountServ> discountServ;
	public:
		void changeName();
		void changeEmail();
		void changePass();
		void changePhone();
		ClubMember();
		~ClubMember();
		ClubMember(string,string,string,string,string,int);
		void setID(string);
		void setPass(string);
		void setName(string);
		void setEmail(string);
		void setPhone(string);
		void setRank(int);
		void addDiscount(DiscountServ);
		string getID();
		string getPass();
		string getName();
		string getEmail();
		string getPhone();
		int getRanking();
		int getNoOfDis();
		string getServ(int);
		double getRate(int);
		void display(); // testing the member attributes
		void searchFacilities(vector<Facilities>& a);
		void searchByID(vector<Facilities>& a);
		void searchByName(vector<Facilities>& a);           // search functions
		void searchByStatus(vector<Facilities>& a);
		void searchByNorRate(vector<Facilities>& a); // the user input the search rate and then choose less than or more than
		void searchByPeakRate(vector<Facilities>& a);
		void searchByReqRank(vector<Facilities>& a); // less than the rank
		void BookFacility(vector<Facilities>& a, vector<BookedFaci>& b);
		void editInfo(vector<BookedFaci>& b);
		void viewInfo();
		void viewDiscount();
		void viewYourBooking(vector<BookedFaci>& b);
		void memMenu(vector<Facilities>a, vector<BookedFaci>& b);

};
void printClubMember(vector<ClubMember>& a);
void readClubMember(vector<ClubMember>& a);

#endif

