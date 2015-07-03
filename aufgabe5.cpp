# define CATCH_CONFIG_RUNNER
# include "catch.hpp"
# include <cmath>
# include <algorithm>
# include <iostream>

using namespace std;

bool is_even (unsigned int num)
{
	return ((num % 2)==0);
}

bool is_odd (unsigned int num)
{
	return ((num % 2)==1);
}


TEST_CASE ("describe_factorial","[aufgabe3]")
{

	vector<unsigned int> v0(100);										

	for(vector<unsigned int>::iterator i=v0.begin();i != v0.end();++i)	
	{
		*i = rand() % 50;
	}

	copy(v0.begin(),v0.end(),ostream_iterator<int>(cout,"\n"));
	cout<<"--------"<<endl;

	v0.erase( remove_if( begin(v0), end(v0), is_odd ), end(v0)); 


	copy(v0.begin(),v0.end(),ostream_iterator<int>(cout,"\n"));
	cout<<"--------"<<endl;


	REQUIRE(all_of (v0.begin (), v0.end (), is_even));

}

int main ( int argc , char * argv [])
{
	return Catch::Session().run(argc,argv);
}

