#define CATCH_CONFIG_RUNNER 

#include "circle.cpp"
#include "catch.hpp"

#include <algorithm>
#include <vector>
#include <list>
#include <cstdlib>


// Funktionstamplate swap (Vertauscht Objekte)

template<typename T>
void swap(T *a, T *b)                            // Parameterübergabe mit Zeigern
{
  T temp = a;
  a = b;
  b = temp;
}


TEST_CASE("swap1", "[aufgabe9]")
{
  
  int a = 5;
  int b = 10;
  swap(a,b);

  REQUIRE(a == 10);
  REQUIRE(b == 5);
}


// Swap test für circle

TEST_CASE("swap2", "[aufgabe9]")
{

  circle a{34};
  circle b{1};
  swap(a,b);

  REQUIRE(a == 1);
  REQUIRE(b == 34);
}


// Funktionstamplate zum konkatinieren ..... 

template<typename T>
T conca(T const &a, T const &b)                // Parameterübergabe durch konstante Referenz 
{
  T temp(a.begin(), a.end());
  temp.insert(temp.end(), b.begin(), b.end());
  return temp;
}

//  ..... Und der Test dafür

TEST_CASE("concatenate0", "[aufgabe10]")
{
 
  vector<int> v{1,2,3,4,5};
  vector<int> k{6,7,8,9,10};

  auto m = conca(v,k);
  REQUIRE(m.size() == 10);
  REQUIRE(m[7] == 8);
}

// Conca test für verschiedene Container 

TEST_CASE("concatenate1", "[aufgabe10]")
{
  
  list<int> v{1,2,3,4,5};
  list<int> k{6,7,8,9,10};

  auto m = conca(v,k);
  REQUIRE(m.size() == 10);

  auto it = m.begin();
  advance(it, 6);
  REQUIRE(*it == 7);
}



circle circleGenerator() 
{
  return circle{(double)(rand()%50)};
}


// conca test für cricle

TEST_CASE("concatenate2", "[aufgabe10]")
{
  vector<circle> v(10);
  generate(begin(v), end(v), circleGenerator);
  vector<circle> k(10);
  generate(begin(k), end(k), circleGenerator);
  REQUIRE(conca(v,k).size() == 20);
}

int main(int argc, char* argv[])
{

  return Catch::Session().run(argc, argv); 
}


