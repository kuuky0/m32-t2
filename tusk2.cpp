#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include "nlohmann/json.hpp"

using namespace std;

struct actors {
	string name;
	string surname;
	string Role;
};

struct Film {
	string name;
	string country;
	string date;
	string producer;
	string regiser;
	actors man;
};

struct Cinemas {
	Film kino[5];
	int count = 5;
};

void find_actor(string name,Cinemas& popa)
{
	vector<string> roles;
	vector<string> films;
	for (int i = 0; i < popa.count; ++i) {
		if (popa.kino[i].man.name == name)
		{
			string role = popa.kino[i].man.Role;
			string film = popa.kino[i].name;
			roles.push_back(role);
			films.push_back(film);
		}
	}

	if (roles.size() > 0)
	{
		for (int i = 0; i < roles.size(); i++)
		{
			cout << "--------------------------------------------------------" << endl;
			cout << "Film: " << films[i] << endl << "His role: " << roles[i] << endl;
		}
	}
	else
	{
		cout << "Unknowk actor sorry~~" << endl;
	}
}

int main()
{
	nlohmann::json Actor = { {"name","Ryan"},{"surname"," Gosling"},{"Role","Driver"}};
	nlohmann::json drive = {
		{"Name","Drive"},{"Country","USA"},{"Date","2011"},
		{"Producer","Somebody"},{"Regiser","Nicolas"},
		{"Actor",Actor}
	};

	nlohmann::json Actor1 = { {"name","Ryan"},{"surname"," Gosling"},{"Role","Biker"} };
	nlohmann::json PlaceBeyondThePines = {
		{"Name","PlaceBeyondThePines"},{"Country","USA"},{"Date","2012"},
		{"Producer","Mayk Patton"},{"Regiser","Derek sienfrens"},
		{"Actor",Actor1}
	};
	nlohmann::json Actor2 = { {"name","Vasya"},{"surname","Frenchov"},{"Role","Prisoner"} };
	nlohmann::json ClockworkOrange = {
		{"Name","ClockworkOrange"},{"Country","UK"},{"Date","1971"},
		{"Producer","Stanley Kubrick"},{"Regiser","John Olkot"},
		{"Actor",Actor2}
	};
	nlohmann::json Actor3 = { {"name","Tobi"},{"surname","Maguire"},{"Role","Spider-man"} };
	nlohmann::json SpiderMan = {
		{"Name","SpiderMan"},{"Country","USA"},{"Date","2002"},
		{"Producer","Avi Aradk"},{"Regiser","Sam Reyimi"},
		{"Actor",Actor3}
	};
	nlohmann::json Actor4 = { {"name","Ryan"},{"surname","Gosling"},{"Role","Kaneki ken"} };
	nlohmann::json Barbie = {
		{"Name","Barbie"},{"Country","USA"},{"Date","2023"},
		{"Producer","Tom Akerley"},{"Regiser","Greta Gervig"},
		{"Actor",Actor4}
	};
	nlohmann::json dict =
	{
		{"Drive",drive},{"PlaceBeyondThePines", PlaceBeyondThePines},
		{"ClockworkOrange",ClockworkOrange},{"Spider-Man",SpiderMan},
		{"Barbie",Barbie}
	};
	ofstream file("C:\\Users\\Dorim\\projects\\module32\\tusk2\\record.json");
	file << dict;

	file.close();

	ifstream file1("C:\\Users\\Dorim\\projects\\module32\\tusk2\\record.json");
	nlohmann::json dict1;
	file1 >> dict1;
	file1.close();

	Cinemas kinoteatr;
	kinoteatr.kino[0].name = dict1["Drive"]["Name"];
	kinoteatr.kino[0].country = dict1["Drive"]["Country"];
	kinoteatr.kino[0].date = dict1["Drive"]["Date"];
	kinoteatr.kino[0].producer = dict1["Drive"]["Producer"];
	kinoteatr.kino[0].regiser = dict1["Drive"]["Regiser"];
	kinoteatr.kino[0].man.name = dict1["Drive"]["Actor"]["name"];
	kinoteatr.kino[0].man.Role = dict1["Drive"]["Actor"]["Role"];
	kinoteatr.kino[1].name = dict1["Barbie"]["Name"];
	kinoteatr.kino[1].country = dict1["Barbie"]["Country"];
	kinoteatr.kino[1].date = dict1["Barbie"]["Date"];
	kinoteatr.kino[1].producer = dict1["Barbie"]["Producer"];
	kinoteatr.kino[1].regiser = dict1["Barbie"]["Regiser"];
	kinoteatr.kino[1].man.name = dict1["Barbie"]["Actor"]["name"];
	kinoteatr.kino[1].man.Role = dict1["Barbie"]["Actor"]["Role"];
	kinoteatr.kino[2].name = dict1["PlaceBeyondThePines"]["Name"];
	kinoteatr.kino[2].country = dict1["PlaceBeyondThePines"]["Country"];
	kinoteatr.kino[2].date = dict1["PlaceBeyondThePines"]["Date"];
	kinoteatr.kino[2].producer = dict1["PlaceBeyondThePines"]["Producer"];
	kinoteatr.kino[2].regiser = dict1["PlaceBeyondThePines"]["Regiser"];
	kinoteatr.kino[2].man.name = dict1["PlaceBeyondThePines"]["Actor"]["name"];
	kinoteatr.kino[2].man.Role = dict1["PlaceBeyondThePines"]["Actor"]["Role"];
	kinoteatr.kino[3].name = dict1["ClockworkOrange"]["Name"];
	kinoteatr.kino[3].country = dict1["ClockworkOrange"]["Country"];
	kinoteatr.kino[3].date = dict1["ClockworkOrange"]["Date"];
	kinoteatr.kino[3].producer = dict1["ClockworkOrange"]["Producer"];
	kinoteatr.kino[3].regiser = dict1["ClockworkOrange"]["Regiser"];
	kinoteatr.kino[3].man.name = dict1["ClockworkOrange"]["Actor"]["name"];
	kinoteatr.kino[3].man.Role = dict1["ClockworkOrange"]["Actor"]["Role"];
	kinoteatr.kino[4].name = dict1["Spider-Man"]["Name"];
	kinoteatr.kino[4].country = dict1["Spider-Man"]["Country"];
	kinoteatr.kino[4].date = dict1["Spider-Man"]["Date"];
	kinoteatr.kino[4].producer = dict1["Spider-Man"]["Producer"];
	kinoteatr.kino[4].regiser = dict1["Spider-Man"]["Regiser"];
	kinoteatr.kino[4].man.name = dict1["Spider-Man"]["Actor"]["name"];
	kinoteatr.kino[4].man.Role = dict1["Spider-Man"]["Actor"]["Role"];

	string name;
	cout << "Input name of actor: ";
	cin >> name;
	find_actor(name,kinoteatr);

	file1.close();
}
