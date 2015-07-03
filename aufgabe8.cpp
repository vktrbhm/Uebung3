#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "circle.cpp"
#include <cmath>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

TEST_CASE("sort_circles", "aufgabe8")
{

  list<circle> l0(50);
  for (list<circle>::iterator it = l0.begin(); it != l0.end(); ++it)
    *it = circle{(double)(rand()%10)};

  l0.sort();
  REQUIRE(is_sorted(l0.begin(), l0.end()));
}

int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}