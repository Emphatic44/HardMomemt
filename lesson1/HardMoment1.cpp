#include <iostream>
#include <string>
#include <optional>
#include <tuple>
#include <vector>
#include <fstream>
#include <any>



using namespace std;


// -------Task1---------

struct Person {
	string SecondName;
	string Name;
	optional<string> Surname;
};

ostream& operator<<(ostream& getout, const Person p)

{
	getout << p.SecondName << " " << p.Name << " " << p.Surname.value_or(" ");

	return getout;
}

bool operator<(const Person& p1, const Person& p2)
{
	return tie(p1.SecondName, p1.Name, p1.Surname) <tie(p2.SecondName, p2.Name, p2.Surname);
}

bool operator==(const Person& p1, const Person& p2)
{
	return tie(p1.SecondName, p1.Name, p1.Surname) == tie(p2.SecondName, p2.Name, p2.Surname);
}



//-----Task2-----

struct Phonenumber {

	int country;
	int city;
	string  number;
	optional<int> adnumber ;

};

ostream& operator<<(ostream& numberout, const Phonenumber n)

{
	numberout << " + " << n.country << "(" << n.city << ")" << n.number << " " ;

	if (n.adnumber.has_value())
	{
		numberout << ' ' << n.adnumber.value();
	}

	return numberout;
}




bool operator<(const Phonenumber& n1, const Phonenumber& n2)
{
	return tie(n1.country, n1.city, n1.number, n1.adnumber) < tie(n2.country, n2.city, n2.number, n2.adnumber);
}

bool operator==(const Phonenumber& n1, const Phonenumber& n2)
{
	return tie(n1.country, n1.city, n1.number, n1.adnumber) == tie(n2.country, n2.city, n2.number, n2.adnumber);
}


// -----Task3-------

class Phonebook {
private:
	vector<pair< Person, Phonenumber>> info;
public:
	Phonebook(ifstream& file)
	{
		if (!file)
		{
			cout << "Couldn`t open file" << endl;
			exit(-1);
		}
	}
		
int main()

{
	ifstream file("PhoneBook.txt");
	Phonebook book(file);
	cout << book;

}

