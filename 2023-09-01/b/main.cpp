#include <cmath>
#include <iostream>

int main()
{
  int t; 
  std::cin >> t; 
  while(t)
  {
    t = t - 1; 
    int year_day;
    std::cin >> year_day;

    double birthday_match_probability = 1/double( year_day );
    double birthday_not_match_probability = 1 - birthday_match_probability;

    int people = 2;

    while(true)
    {
      int combinations = people*(people-1) / 2;
      double not_match_probability = std::pow(birthday_not_match_probability, combinations);
      double birth_match_probability = 1 - not_match_probability;
      if(birth_match_probability > 0.5)
      {
        std::cout << people - 1 << std::endl;  
        break;
      }
      people = people + 1;
    }
  }
  return 0;
}
