# include <vector>			// std::vector<>
# include <map>
# include <iostream>
#include <string>
# include <iterator>


using namespace std;

int main(int argc, char const *argv[])
{
	
	map< string ,string >personen;
	string name, adresse;
	int num;

	cout<< "-------Bitte nur den Nachnamen eingeben und keine Leerzeichen verwenden-------" << endl;
	cout<< "Wieviele Personen sollen eingetragen werden?" << endl;
	cin >> num;


	for(int i=1;i<=num;++i)
	{
		cout<< "Name der Person: " << endl;
		cin >> name; 	
		cout<< "Die Adresse von " << name << " :" << endl;
		cin >> adresse;	

		personen.insert(pair<string,string>(name,adresse));

	}


	cout<<"----Personen Suche----"<<endl;

	string pers_search;	
	cout<<"Name der gesuchten Person: "<<endl;
	cin>> pers_search;
	cout<< "--------------" <<endl;

	map<string,string>::iterator i = personen.find(pers_search);
	
	if (i != personen.end())
	{
		cout<<"Die gesuchte Person mit Adresse: "<<endl;	
		cout<< personen.find(pers_search)->first << " : "<<personen.find(pers_search)->second <<endl;
	}
	else
	{
		cout<< "Die gesuchte Person befindet sich nicht in der Liste" <<endl;	 	
	}
	


	cout<< "--------------" <<endl;
	cout<< "------Liste eingetragener Personen--------" <<endl;
	for (map<string,string>::iterator it=personen.begin(); it!=personen.end(); ++it) // Ausgebe der Map
    cout << it->first << " : " << it->second << '\n';

	cout<<"--------"<<endl;	 

	return 0;
}