//------------------------------------------------------------------------------
//Copyright Robert Pelloni.
//All Rights Reserved.
//------------------------------------------------------------------------------


#pragma once
#include "oktypes.h"
class Logger;




#include "src/Engine/network/ServerObject.h"

class FlagData;

class Flag : public ServerObject, public std::enable_shared_from_this<Flag>
{
private:
	bool value = false;
	long long timeSet = -1;

	sp<FlagData> data = nullptr;


public:


	static Logger log;
	Flag(sp<Engine> g, int id);


	Flag(sp<Engine> g, sp<FlagData> data);


	//The following method was originally marked 'synchronized':
	void setData_S(sp<FlagData> data);


	sp<FlagData> getData();


	int getID();
	string& getName();
	string getTYPEIDString();


	void setID(int id);
	void setName(const string& name);


	//The following method was originally marked 'synchronized':
	void setValue_S(bool b); //sendServerValueUpdate(boolean b)


	//The following method was originally marked 'synchronized':
	void initValueFromGameSave_S(bool b, long long timeSet); //sendServerValueUpdate(boolean b)


	//The following method was originally marked 'synchronized':
	bool getValue_S();


	long long getTimeSet();
};

