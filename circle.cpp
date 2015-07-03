#include "circle.hpp"
#include <cmath>


using namespace std;


circle::circle()
  : radius_{0.0}
{}

circle::circle(double const radius)
  : radius_{radius}
{}

circle::~circle(){}

double circle::radius() const {
  return radius_;
}

double circle::circumference() const {
  return 2 * M_PI * radius_;
}

bool operator< (circle const& p1, circle const& p2) {
  return p1.radius() < p2.radius();
}
bool operator> (circle const& p1, circle const& p2) {
  return p1.radius() > p2.radius();
}
bool operator== (circle const& p1, circle const& p2) {
  return p1.radius() == p2.radius();
}
ostream& operator<<(ostream& os, circle const& c) {
  os << "Radius: " << c.radius();
  return os;
<<<<<<< HEAD
}
=======
}
>>>>>>> 578a359807c39258a38a99c95d113bc35ace199e
