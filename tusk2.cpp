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
	std::vector<Film> kino;
	int count = kino.size();
};

void find_actor(string name,Cinemas& popa)
{
	vector<string> roles;
	vector<string> films;
	for (int i = 0; i < popa.kino.size(); ++i) {
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

	Cinemas a;
	vector<Film> films;

	for (auto& [movieName, movieData] : dict1.items()) {
		Film movie;
		movie.name = movieData["Name"];
		movie.country = movieData["Country"];
		movie.date = movieData["Date"];
		movie.producer = movieData["Producer"];
		movie.regiser = movieData["Regiser"];
		movie.man.name = movieData["Actor"]["name"];
		movie.man.surname = movieData["Actor"]["surname"];
		movie.man.Role = movieData["Actor"]["Role"];
		a.kino.push_back(movie);
		films.push_back(movie);
	}

	string name;
	cout << "Input name of actor: ";
	cin >> name;
	find_actor(name,a);

	file1.close();
}
