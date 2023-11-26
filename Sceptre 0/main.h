#pragma once

using namespace std;

class CCountry {
private:
	std::string countryTag;
	std::string countryName;
	int countryID;
	bool isAI = false;
	bool isPlayer = true;

public:
	CCountry(const std::string& countryTag);
	
	int getCountryID() const
	{
		return countryID;
	};

	std::string getCountryNameFromID()
	{
		
	};

	int isAIorPlayer() // 0 - Player, 1 - AI
	{
		if (isPlayer == true)
		{
			isAI = false;
			return 0;
		}
		else
		{
			isAI = true;
			return 1;
		}
	};
};

class CPlayer {
private:
	CCountry* playerTag;
	int numProvinces = 0;
	int numArmies = 0;
	int numPops = 1;
	int power = 0; // like prestige but not spendable, just an index, calculated using numProvinces and numArmies
	float money = 0;
	float balance = 0;
	float income = 0;
	float spending = 0;
public:
	CPlayer(const std::string& playerTag);

};

class CAi {
	std::string aiTag;
	int numProvinces = 0;
	int numArmies = 0;
	int numPops = 1;
	int relationToPlayer = 0;
	int relationToAI = 0;
	float strategy = 0.00; // from 1 aggressive to -1 passive
	float fensive = 0.00; // from 1 offensive to -1 defensive
	int power = 0; // like prestige but not spendable, just an index, calculated using numProvinces and numArmies
	float money = 0;
	float balance = 0;
	float income = 0;
	float spending = 0;
public:
	CAi(const std::string& aiTag);
};


class CCharacter {
private:
	// as in a family or a government
	std::string firstName;
	std::string dynasty;
	int origin; // country tag id of origin
	int status = 0; // ruler, politician, inventor, commander, child
	int wealth = 0;
public:
	CCharacter(const std::string& firstName, const std::string& dynasty);
};

class CProvince {
private:
	int provinceID;
	std::string provinceName;
public:
	CProvince(const int provinceID, const std::string provinceName);

	CCountry* provinceOwner;
	CCountry* provinceOccupier;

	bool provinceIsOccupied()
	{
		if (provinceOccupier != provinceOwner)
		{
			return true;
		}
	};
	
	bool provinceIsAbandoned()
	{
		if (provinceOwner == 0)
		{
			return true;
		}
	};
	
};

class CPop {
private:
	std::string popNeed;
	std::string popType;
	std::string popCulture;
	std::string popReligion;
	std::string popAddress; // which province, country
	std::string popProduce; // whatever the pop provides

public:
	CPop(const std::string& popAddress);
};

class CArmy {
private:
	int armyLeader; // character id

};