#ifndef ___Sys__
#define ___Sys__
#include "Admin.h"
#include "Facilities.h"
#include "BookedFaci.h"
#include "ClubMember.h"
#include "ClubManager.h"
class System{
	private:
		vector<Facilities> vecFac;
		vector<BookedFaci> vecBook;
		vector<ClubMember> vecMem;
		vector<ClubManager> vecMan;
		vector<Admin> vecAd;
	public:
		System();
		~System();
		bool verifyMem(string,string);
		bool verifyMan(string,string);
		bool verifyAdmin(string,string);
		void logInMem();
		void logInMan();
		void logInAdmin();
		void logInMenu();
};
#endif

