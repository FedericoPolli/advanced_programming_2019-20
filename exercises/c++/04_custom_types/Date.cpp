#include <iostream>

enum class month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

class Date {
  int day;
  month m;
  int year;
  
public:
  Date(const int day, const month m, const int year);
  int current_day() const {return day;}
  int current_month() const {return static_cast<int>(m);}
  int current_year() const {return year;}
  void add_day();
  void add_days(const int n);
};

Date::Date(const int _day, const month _m, const int _year):
  day{_day}, m{_m}, year{_year}
{
}

bool is_leap(const int y) {
  if (y%400 == 0)
    return 1;
  else
    if ((y%4 == 0) && (y%100 != 0))
      return 1;
  return 0;
}


void Date::add_day()
{
  ++day;
  int mon=static_cast<int>(m);
  switch(mon)
    {
    case 1: case 3: case 5: case 7: case 8: case 10:
      if (day==32) {
	day=1;
	m=month(static_cast<int>(m)+1);
      }
      break;
    
    case 12:
      if (day==32) {
	day=1;
	m=month::jan;
	++year;
      }
      break;
    
    case 4: case 6: case 9: case 11:
      if (day==31) {
	day=1;
	m=month(static_cast<int>(m)+1);
      }
      break;
    
    case 2:
      if (is_leap(year)) {
	  if (day==30) {
	    day=1;
	    m=month(static_cast<int>(m)+1);
	  }
	}
      else
	{
	  if (day==29) {
	    day=1;
	    m=month(static_cast<int>(m)+1);
	  }	
	}
      break;
    
    default:
      std::cout << "Unknown month \n";
      break;
    }  
}

void Date::add_days(const int n)
{
  for (std::size_t i=0; i<n; ++i)
    Date::add_day();     
}

bool operator==(const Date& lhs, const Date& rhs) {
  return lhs.current_day()==rhs.current_day() && lhs.current_month()==rhs.current_month() && lhs.current_year()==rhs.current_year();
}

bool operator!=(const Date& lhs, const Date& rhs) {
  return !(lhs==rhs);
}

std::ostream& operator<<(std::ostream& os, const Date& d) {
  os << d.current_day() << "/" << d.current_month() << "/" << d.current_year() << std::endl;
  return os;
}

int main() {
  Date a=Date(31, month::dec, 1998);
  a.add_days(60);
  std::cout << a;
}
