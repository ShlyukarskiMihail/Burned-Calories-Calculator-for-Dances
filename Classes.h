#pragma once
#include <string>
#include <iostream>
using namespace std;

enum Speed { slow, medium, fast }; 
enum Level { amateur, professional };

class Dance 
	// this is the abstract class for all dances
	//it contains all kinds of dance - both bulgarian and sports dance
	//1-level Base class
{
public:
	virtual void display() = 0;  //abstract function
	virtual double getBurntCalories() // function for getting the real burnt calories
	{
		return calories; 
	}

	virtual void setExpCalories(double cal) //setting the expected burn calories
	{
		if (cal < 0) //checking whether the value is positive
		{
			cal = 0;
		}
		else
		{
			calories = cal;
		}
	}

private:
	double calories; // private variable about expected burnt calories while dancing
};  
 
class BGDance : public Dance //2-nd level of inheritance
							//containing only Bulgarian dances and inherits Dance class
{
private: //member variables 
	string description;
	Speed tempo; 
	int tiredIndex;

public: 
	//4 parameter constructor
	BGDance(double cal, Speed temp, string desc, int tInd)
	{
		setExpCalories(cal);
		description = desc;
		tempo = temp;
		tiredIndex = tInd;

	}
	//getters until line 70
	string getDescription() 
	{
		return description;
	}

	int getTiredIndex()
	{
		return tiredIndex;
	}

	Speed getSpeed()
	{
		return tempo;
	}

	virtual void display() 
		// display function in this class has the following body:
	{
		if (tempo == slow)
		{
			cout << "The Typical Tempo is slow" << endl;
		}
		if (tempo == medium)
		{
			cout << "The Typical Tempo is medium" << endl;
		}
		if (tempo == fast)
		{
			cout << " Typical Tempo is fast" << endl;
		}
	
		cout << "Description of The Dance: " << getDescription() << endl;
		cout << "The tired Index is:" << getTiredIndex() << endl;
		cout << "The burnt calories are :" << getBurntCalories() << endl;
	}
};

class SportsDance : public Dance
{
public:
	SportsDance(double cal, string k, int per, Speed temp)
	{
		setExpCalories(cal);
		kind = k;
		periods = per;
		tempo = temp;
	}
	string getKind() //getter
	{
		return kind;
	}
	int getPeriods() //getter
	{
		return periods;
	}
	Speed getTempo() //getter
	{
		return tempo;
	}


	virtual void display()
	{
		if (tempo == slow)
		{
			cout << "The tempo is slow" << endl;
		}
		if (tempo == medium)
		{
			cout << "Tempo is medium" << endl;
		}
		else
		{
			cout << "The tempo is fast" << endl;
		}
		cout << "Kind of SportsDance" << getKind() << endl;
		cout << "The repetitions are: " << getPeriods() << endl;
		cout << "The burnt calories are: " << getBurntCalories() << endl;
	}

private:
	string kind; // can be balroom or latin
	int periods; // how many repetitions has in one song
	Speed tempo;
};

class Shopski : public BGDance
{
private:
	BGDance* kind; // pointer to the category of the dance
	string name;   // name of the dance
	Speed tempo;

public:
	Shopski(BGDance* k, string nam, Speed temp) 
		: BGDance(k -> getBurntCalories(), k-> getSpeed(), k->getDescription(), k->getTiredIndex())
	{
		kind = k;
		name = nam;
		tempo = temp;
		setBcalories(getBurntCalories()); //getting the burnt calories, due to the valid information and calculations
	}
	void setBcalories(double cal)
	{
		if (tempo == slow)
		{
			Dance::setExpCalories(2*1.2 * cal);
		}
		if (tempo == medium)
		{
			Dance::setExpCalories(2*1.8 * cal);
		}
		if (tempo == fast)
		{
			Dance::setExpCalories(2*2.4 * cal);
		}

	}

	void display()
	{
		cout << "Name: " << name << endl;
		if (tempo == slow)
		{
			cout << "The tempo is slow"<<endl;
		}
		if (tempo == medium)
		{
			cout << "The tempo is medium" << endl;
		}
		if (tempo == fast)
		{
			cout << "The tempo is fast" << endl;
		}
		cout << "The Burnt Calories of this dance are: "<< getBurntCalories() << endl;
		cout << endl;
	}
	
};
 
class Thracian : public BGDance
{
private:
	BGDance* kind;
	Speed tempo;
	string name;

public:
	Thracian(BGDance* k, string nam, Speed temp) 
		: BGDance(k -> getBurntCalories(), k->getSpeed(), k->getDescription(), k->getTiredIndex())
	{
		kind = k;
		name = nam;
		tempo = temp;
		setBcalories(getBurntCalories()); //getting the burnt calories, due to the valid information and calculations
	}
	void setBcalories(double cal)
	{
		if (tempo == slow)
		{
			Dance::setExpCalories(2.34 * cal);
		}
		if (tempo == medium)
		{
			Dance::setExpCalories(4.8 * cal);
		}
		if (tempo == fast)
		{
			Dance::setExpCalories(9.6 * cal);
		}

	}

	void display()
	{
		cout << "Name: " << name << endl;
		if (tempo == slow)
		{
			cout << "The tempo is slow" << endl;
		}
		if (tempo == medium)
		{
			cout << "The tempo is medium" << endl;
		}
		if (tempo == fast)
		{
			cout << "The tempo is fast" << endl;
		}
		cout << "The Burnt Calories of this dance are: " << getBurntCalories() << endl;
		cout << endl;
	}
};

class Balroom : public SportsDance
{
private:
	string name;
	Level level;  // could be either amateur or professional
	Speed tempo;
	SportsDance* kind;
public:
	Balroom(string nam, Level lvl, Speed tmp, SportsDance* k) :
		SportsDance(k->getBurntCalories(), k-> getKind(), k->getPeriods(), k-> getTempo())
	{
		name = nam;
		level = lvl;
		tempo = tmp;
		kind = k;
		setBcalories(getBurntCalories());
	}

	void setBcalories(double cal)
	{
		if (tempo == slow)
		{
			if (level == professional)
			{Dance::setExpCalories((0.6 * cal)*2);}
			if (level == amateur) 
			{ Dance::setExpCalories(0.6 * cal);}
		}
		if (tempo == medium)
		{
			if (level == professional)
			{
				Dance::setExpCalories((1.2 * cal)*2);
			}
			if(level == amateur)
			{ Dance::setExpCalories(1.2 * cal); }
		}
		if (tempo == fast)
		{
			if (level == professional)
			{
				Dance::setExpCalories((0.6 * cal)* 2);
			}
			if (level == amateur) 
			{ Dance::setExpCalories(0.6 * cal); }
		}
	}

	void display()
	{
		cout << "Name is: " << name << endl;
		if (tempo == slow)
		{
			cout << "The tempo is slow" << endl;
		}
		if (tempo == medium)
		{
			cout << "The tempo is medium" << endl;
		}
		if (tempo == fast)
		{
			cout << "The tempo is fast" << endl;
		}
		if (level == amateur)
		{
			cout << "The level is amateur" << endl;
		}
		if (level == professional)
		{
			cout << "The level is professional" << endl;
		}
		cout << "The Burnt calorires are: " << getBurntCalories()<<endl;
		cout << endl;
	}
};

class Latin : public SportsDance
{
private:
	string name;
	Level level;  // could be either amateur or professional
	Speed tempo;
	SportsDance* kind;
public:
	Latin(string nam, Level lvl, Speed tmp, SportsDance* k) :
		SportsDance(k->getBurntCalories(), k-> getKind(), k->getPeriods(), k-> getTempo())
	{
		name = nam;
		level = lvl;
		tempo = tmp;
		kind = k;
		setBcalories(getBurntCalories());

	}

	void setBcalories(double cal)
	{
		if (tempo == slow)
		{
			if (level == professional)
			{
				Dance::setExpCalories((0.5 * cal) * 2);
			}
			if (level == amateur)
			{
				Dance::setExpCalories(1.0 * cal);
			}
		}
		if (tempo == medium)
		{
			if (level == professional)
			{
				Dance::setExpCalories((1.0 * cal) * 2);
			}
			if (level == amateur)
			{
				Dance::setExpCalories(1.5 * cal);
			}
		}
		if (tempo == fast)
		{
			if (level == professional)
			{
				Dance::setExpCalories((1.5 * cal) * 2);
			}
			if (level == amateur)
			{
				Dance::setExpCalories(2.0 * cal);
			}
		}
	}

	void display()
	{
		cout << "Name is: " << name << endl;
		if (tempo == slow)
		{
			cout << "The tempo is slow" << endl;
		}
		if (tempo == medium)
		{
			cout << "The tempo is medium" << endl;
		}
		if (tempo == fast)
		{
			cout << "The tempo is fast" << endl;
		}
		if (level == amateur)
		{
			cout << "The level is amateur" << endl;
		}
		if (level == professional)
		{
			cout << "The level is professional" << endl;
		}
		cout << "The Burnt calorires are: " << getBurntCalories() << endl;
		cout << endl;
	}
};
