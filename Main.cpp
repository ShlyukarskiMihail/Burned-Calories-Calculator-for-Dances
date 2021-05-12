#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"Classes.h"

//implementing the code for mergesort from 
//presentation 

template<class Comparable>
void merge(vector<Comparable>& a, vector<Comparable>& tmpArray, int leftPos, int rightPos, int rightEnd) {
	int leftEnd = rightPos - 1;
	int tmpPos = leftPos;
	int numElements = rightEnd - leftPos + 1;

	while (leftPos <= leftEnd && rightPos <= rightEnd)// main loop
		if (a[leftPos]->getBurntCalories() >= a[rightPos]->getBurntCalories()) //modification of the original code 
			//so that it works for my case
			tmpArray[tmpPos++] = a[leftPos++];
		else
			tmpArray[tmpPos++] = a[rightPos++];

	while (leftPos <= leftEnd)//copy rest of first half
		tmpArray[tmpPos++] = a[leftPos++];

	while (rightPos <= rightEnd)//copy rest of right half
		tmpArray[tmpPos++] = a[rightPos++];

	for (int i = 0; i < numElements; i++, rightEnd--)//copy tmpArray back
		a[rightEnd] = tmpArray[rightEnd];
}

template <class Comparable>
void mergeSort(vector <Comparable>& a, vector <Comparable>& tmpArray, int left, int right) {
	if (left < right) {
		int center = (left + right) / 2;
		mergeSort(a, tmpArray, left, center);
		mergeSort(a, tmpArray, center + 1, right);
		merge(a, tmpArray, left, center + 1, right);
	}
}

template <class Comparable>
void mergeSort(vector <Comparable>& a) {
	vector<Comparable> tmpArray(a.size());
	mergeSort(a, tmpArray, 0, a.size() - 1);
}

using namespace std;


int main()
{
	vector <Dance*> instances;
	ifstream input;

	vector<BGDance> kind1;			//inputing the 4 parameter constructor, containing the first type of dance
	vector<Shopski> Shopskilist;    //collecting the other members of the last class of the pyramid
	
	input.open("Shopski.txt");     //opening the 1rst file
	if (input.is_open())
	{
		while (!input.eof())  //using char-% like to keep track on the type of input for kind of dance for the
		{					//second level of inheritance and char - $ for the 3rd level of inheritance 
			char flag;		//and finally '!' for the end of the file
			input >> flag;
			input.ignore();

			if (flag == '%')
			{
				//creating a kind instance acc to the members
				double cals;
				input >> cals;
				input.ignore();

				string tempo;
				Speed t;
			std:getline(input, tempo);
				if (tempo == "slow")
				{
					t = slow;
				}
				if (tempo == "medium")
				{
					t = medium;
				}
				
				if (tempo == "fast")
				{
					t = fast;
				}

				string desc;
				string d;
				std::getline(input, d);
				desc.append(d);

				int Tind;
				input >> Tind;
				input.ignore();
				 
				BGDance ShopskiKind(cals, t, d, Tind);
				kind1.push_back(ShopskiKind);
				input >> flag;

				while (flag == '$') // after processing the kind it has to process the dance
				{
					string name;
					string tempo;
					input.ignore();
					getline(input, name);
					Speed temp;
					getline(input, tempo);
					if (tempo == "slow")
					{
						temp = slow;
					}
					if (tempo == "medium")
					{
						temp = medium;
					}

					if (tempo == "fast")
					{
						temp = fast;
					}

					Shopski dance1(&ShopskiKind, name, temp);
					Shopskilist.push_back(dance1);
					input >> flag;
														
				}		
			}
		}
	}
	input.close();
	input.clear();
	// with 2 for loops, moving the kinds and the dancelist into vectors of pointers,
	// which will be processed later with mergesort function
	for (int i = 0; i < kind1.size(); i++)
	{
		instances.push_back(&kind1[i]); 
	}
	for (int i = 0; i < Shopskilist.size(); i++)
	{
		instances.push_back(&Shopskilist[i]);
	}
	//-----------------------------------------------------------------------------------------------------

	vector<BGDance> kind2; // will contain the second type/kind of bulgarian dances
	vector<Thracian> Thracianlist; // vector with class Thracian properties
	input.open("Thracian.txt"); //2nd Opening and processing the information from the file
	if (input.is_open())
	{
		while (!input.eof()) // the same as the previous input with the help of chars
		{						
			char flag;
			input >> flag;
			input.ignore();
			if (flag == '%')
			{
				double cal;
				input >> cal;
				input.ignore();

				string tempo;
				Speed t;
				getline(input, tempo);
				if (tempo == "slow")
				{
					t = slow;
				}
				if (tempo == "medium")
				{
					t = medium;
				}

				if (tempo == "fast")
				{
					t = fast;
				}

				string desc;
				string d;
				std::getline(input, d);
				desc.append(d);

				int Tind;
				input >> Tind;
				input.ignore();

				BGDance ThracianKind(cal, t, d, Tind); // 4 line constructor
				kind2.push_back(ThracianKind);
				input >> flag;

				while (flag == '$')
				{
					string name;
					string tempo;
					input.ignore();

					getline(input, name);
					Speed temp;
					getline(input, tempo);
					if (tempo == "slow")
					{
						temp = slow;
					}
					if (tempo == "medium")
					{
						temp = medium;
					}
					if (tempo == "fast")
					{
						temp = fast;
					}
					Thracian dance2(&ThracianKind, name, temp);
					Thracianlist.push_back(dance2);
					input >> flag;
				}
			}
		}
	}
	input.close();
	input.clear();
	// with 2 for loops, moving the kinds and the dancelist into vectors of pointers,
	// which will be processed later with mergesort function
	for (int i = 0; i < kind2.size(); i++)
	{
		instances.push_back(&kind2[i]);
	}
	for (int i = 0; i < Thracianlist.size(); i++)
	{
		instances.push_back(&Thracianlist[i]);
	}

	//-------------------------------------------------------------------------------------------------------------

	vector<SportsDance> kind3; //containing the 1st kind of sports dance (or 3rd in the sequence)
	vector <Balroom> Balroomlist;
	input.open("Balroom.txt"); //opening and processing the third file
	if (input.is_open())
	{
		while (!input.eof()) //again the same characters as the previous inputsp %, $ and !
		{
			char flag;
			input >> flag;
			input.ignore();

			if (flag == '%')
			{
				double cal;
				input >> cal;
				input.ignore();

				string kind;
				string type;
				getline(input, type);
				kind.append(type);

				int periods;
				input >> periods;
				input.ignore();

				string tempo;
				Speed temp;
				getline(input, tempo);
				if (tempo == "slow")
				{
					temp = slow;
				}
				if (tempo == "medium")
				{
					temp = medium;
				}
				if (tempo == "fast")
				{
					temp = fast;
				}
				input.ignore();
				SportsDance BalroomKind(cal, kind, periods, temp);
				kind3.push_back(BalroomKind);
				input >> flag;

				while (flag == '$')
				{
					string name;
					getline(input, name);
					input.ignore();
					
					string lvl;
					Level level;

					if (lvl == "amateur")
					{
						level == amateur;
					}

					if (lvl == "profesional")
					{
						level = professional;
					}

					string tempo;
					Speed temp;

					if (tempo == "slow")
					{
						temp = slow;
					}
					if (tempo == "medium")
					{
						temp = medium;
					}
					if (tempo == "fast")
					{
						temp = fast;
					}

					Balroom dance3(name, level, temp, &BalroomKind);
					Balroomlist.push_back(dance3);
					input >> flag;
				}
			}
		}
	}
	input.close();
	input.clear();
	// with 2 for loops, moving the kinds and the dancelist into vectors of pointers,
	// which will be processed later with mergesort function
	for (int i = 0; i < kind3.size(); i++)
	{
		instances.push_back(&kind3[i]);
	}
	for (int i = 0; i < Balroomlist.size(); i++)
	{
		instances.push_back(&Balroomlist[i]);
	}

	//------------------------------------------------------------------------------------

	vector<SportsDance> kind4; //containing the 2st kind of sports dance (or 4th in the sequence)
	vector <Latin> LatinList;
	input.open("Latin.txt"); //opening and processing the fourth file
	if (input.is_open())
	{
		while (!input.eof()) //again the same characters as the previous inputsp %, $ and !
		{
			char flag;
			input >> flag;
			input.ignore();

			if (flag == '%')
			{
				double cal;
				input >> cal;
				input.ignore();

				string kind;
				string type;
				getline(input, type);
				kind.append(type);

				int periods;
				input >> periods;
				input.ignore();

				string tempo;
				Speed temp;
				getline(input, tempo);
				if (tempo == "slow")
				{
					temp = slow;
				}
				if (tempo == "medium")
				{
					temp = medium;
				}
				if (tempo == "fast")
				{
					temp = fast;
				}
				input.ignore();
				SportsDance LatinKind(cal, kind, periods, temp);
				kind4.push_back(LatinKind);
				input >> flag;

				while (flag == '$')
				{
					string name;
					getline(input, name);
					input.ignore();

					string lvl;
					Level level;

					if (lvl == "amateur")
					{
						level == amateur;
					}

					if (lvl == "profesional")
					{
						level = professional;
					}

					string tempo;
					Speed temp;

					if (tempo == "slow")
					{
						temp = slow;
					}
					if (tempo == "medium")
					{
						temp = medium;
					}
					if (tempo == "fast")
					{
						temp = fast;
					}

					Latin dance4(name, level, temp, &LatinKind);
					LatinList.push_back(dance4);
					input >> flag;
				}
			}
		}
	}
	input.close();
	input.clear();
	// with 2 for loops, moving the kinds and the dancelist into vectors of pointers,
	// which will be processed later with mergesort function
	for (int i = 0; i < kind4.size(); i++)
	{
		instances.push_back(&kind4[i]);
	}
	for (int i = 0; i < LatinList.size(); i++)
	{
		instances.push_back(&LatinList[i]);
	}

	mergeSort(instances);
	//sorting all elements (dances with their properties) in the vector and 
	//outputing them using Mergesort - by the Burnt Calories of every dance in decsending order

	cout << endl;
	for (int i = 0; i < instances.size(); i++)
		instances[i]->display();

	return 0;

}