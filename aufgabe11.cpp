#define CATCH_CONFIG_RUNNER 
#include "catch.hpp" 
#include <cmath>
#include <algorithm>

using namespace std;


// Funktionen gerade ungerade
bool is_odd(int const& i) 
{
  return ((i%2)==1);
}

bool is_even(int const& i)
{
  return ((i%2)==0);
}

// Funktionstamplate für Filter

template<typename T1, typename T2>
T1 filter(T1 c, T2 const& Predicate)
{
  c.erase(remove_if(c.begin(), c.end(), Predicate), c.end());
  return c;
}


// Tests

TEST_CASE("filter0", "[filter]")
{
  vector<int> v{1,2,3,4,5,6};
  vector<int> even = filter(v, is_odd);

  REQUIRE(all_of(even.begin(), even.end(), is_even));
}

int main(int argc, char* argv[])
{
	return Catch::Session().run(argc, argv); 
}