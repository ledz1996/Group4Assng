#ifndef ___ClubManager__
#define ___ClubManager__
#include "Facilities.h"
#include "BookedFaci.h"
#include "ClubMember.h"
class ClubManager: public ClubMember{
	private:
		string endOfContractDate;
	public:
		ClubManager();
		ClubManager(string,string,string,string,string,string);
		~ClubManager();
		void displayMan();
		void setEndOfContractDate(string);
		string getEndOfContractDate();
		void addFacilities(vector<Facilities>& a);
		void deleteFacilities(vector<Facilities>& a);
		void updateFacilities(vector<Facilities>& a);
		void editMemberMenu(vector<ClubMember>& b);
		void editMemberRank(ClubMember& b);
		void queryMemberInformation(vector<ClubMember>& b);
		void reportByMonth(vector<BookedFaci>& a,vector<Facilities>& b);
		void reportRecent(vector<BookedFaci>& a,vector<Facilities>& b);
		void processBooking(vector<BookedFaci>& a,vector<Facilities>& b);
		void ClubManagerMenu(vector<BookedFaci>& a,vector<Facilities>& b,vector<ClubMember>& c);
};
void printClubManager(vector<ClubManager>& a);
void readClubManager(vector<ClubManager>& a);
#endif

