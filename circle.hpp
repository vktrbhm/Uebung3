#ifndef circle_HPP
#define circle_HPP

#include <iostream>


using namespace std;

class circle
{
public:
  circle();
  circle(double const radius);
  ~circle();

  double radius() const;
  double circumference() const;

  friend bool operator<(circle const& c1, circle const& c2);
  friend bool operator>(circle const& c1, circle const& c2);
  friend bool operator==(circle const& c1, circle const& c2);
  friend ostream& operator<<(ostream& os, circle const& c);

private:
  double radius_;

  };

<<<<<<< HEAD
#endif // circle_HPP
=======
#endif // circle_HPP
>>>>>>> 578a359807c39258a38a99c95d113bc35ace199e
