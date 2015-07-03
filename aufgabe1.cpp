# include <cstdlib>			// std::rand() 
# include <vector>			// std::vector<>
# include <list>			// std::list<>
# include <iostream>		// std::cout
# include <iterator>		// std::ostream_iterator<>
# include <algorithm>		// std::reverse , std :: generate


using namespace std;
int main ()
{
	vector<int> v0(10);											// Der Vektor v0 mit der länge 10 wird erzeugt (Datentype int)

	for(vector<int>::iterator i=v0.begin();i != v0.end();++i)	// Der erzeugte Vektor wird mit hilfe eines Iterators (Datentyp int) zufälligen Zahlen gefüllt
	{
		*i = rand();
	}
copy (begin(v0),end(v0),ostream_iterator<int>(cout, "\n"));		// Ausgabe des Vektors v0
cout<<"--------"<<endl;



list<int> l0(v0.size());										// Die Liste l0 (Datentyp int) mit der größe von v0 wird erzeugt
copy(begin(v0),end(v0),begin(l0));								// Der Vektor v0 wird in die Liste l0 kopiert

list<int> l1(begin(l0),end(l0));								// Die Liste l1 wird mit den Werten von l0 erzeugt
reverse(begin(l1),end(l1));										// Anfang und Ende der liste werden vertauscht.
copy(begin(l1),end(l1),ostream_iterator<int>(cout, "\n"));		// Ausgabe der Liste l1 mit hilfe eines Iterators (Datentyp int)
cout<<"--------"<<endl;
l1.sort();														// Die Werte in der Liste l1 werden ihrer größe nach sortiert
copy(l1.begin(),l1.end(),ostream_iterator<int>(cout,"\n"));		// Ausgabe der sortierten Liste l1 mit hilfe eines Iterators (Datentyp int)
cout<<"--------"<<endl;
generate(begin(v0),end(v0),rand);								// ?generate? Im vektor v0 werden zufällige werte erzeugt
//copy(v0.begin(),v0.end(),ostream_iterator<int>(cout,"\n"));
//cout<<"--------"<<endl;
copy(v0.rbegin(),v0.rend(),ostream_iterator<int>(cout,"\n"));	//?rbegin/rend? Ausgabe des Vektors v0 mit hilfe eines Iterators (Datentyp int)

return 0;
}