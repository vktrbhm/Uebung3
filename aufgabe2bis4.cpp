# include <cstdlib>			// std::rand() 
# include <vector>			// std::vector<>
# include <list>			// std::list<>
# include <iostream>		// std::cout
# include <iterator>		// std::ostream_iterator<>
# include <algorithm>		// std::reverse , std :: generate
# include <map>

using namespace std;

int main ()
{

list<unsigned int> l0(100);												// Erzeugen der Liste l0 mit 100 Elementen  													

	for(list<unsigned int>::iterator i=l0.begin();i != l0.end();++i)	// Einfügen von zufälligen Werten von 0 bis 50
	{
		*i = rand() % 50;
	}

vector<unsigned int> v0(l0.size());										// Erzeugen eines Vektors v0 mit der Größe von l0
copy(begin(l0),end(l0),begin(v0));										// Einfügen der Werte von l0 in v0


/*--- Aufgabe 3.3 ---*/


list<unsigned int> l1(l0.size());										// Kopiere Liste l0 in Neue Liste l1
copy(begin(l0),end(l0),begin(l1));

l1.sort();																// Sortiere und schmeiße doppelte raus
l1.unique();

vector<unsigned int> v1(l1.size());										// Erstelle Vektor mit Werten zum weiterarbeiten
copy(begin(l1),end(l1),begin(v1));

cout<<"-------- Aufgabe 3.3 --------"<<endl;							// Ausgabe der unterschiedlichen Werte
cout<<"Die Liste hat " << l1.size()<< " unterschiedliche Werte"<< endl;
cout<<"--------"<<endl;

vector<unsigned int>::iterator it_v1;									// Iterator des Vektors v1

	for (int i=0;i<=50;++i)												// Welche Werte sind nicht in der Liste 
		{		
			it_v1 = find (v1.begin(), v1.end(), i);
			if (it_v1 == v1.end())
				cout << "Nicht enthalten: " << i << '\n';
		} 

/*--- Aufgabe 3.4 ---*/
cout<<"-------- Aufgabe 3.4 --------"<<endl;
cout<<"---- Häufigkeit der Zahlen ----"<<endl;

cout<<"--------"<<endl;
unsigned int counter; 													// Initialiesierung der Zählvariablen

vector<unsigned int> v2(l0.size());										// Neuer Vektor mit Werten aus l0
copy(begin(l0),end(l0),begin(v2));

map < unsigned int, unsigned int> m0;									// Ergebnis Map: Ne Map ist praktisch, weil sie zwei vektoren gegenüberstellt
	
	for (unsigned int i=0;i<=50;++i)									// Zählen der Werte
		{		
			counter = 0;
			for(unsigned int j = 0;j<=v2.size()-1;++j)
			{
				if (v2.at(j)==i)
				{
					++counter;
				}
			}						
			m0[i]=counter;
		} 

for (map<unsigned int,unsigned int>::iterator it=m0.begin(); it!=m0.end(); ++it) // Ausgebe der Map
    cout << it->first << " : " << it->second << '\n';

return 0;
}