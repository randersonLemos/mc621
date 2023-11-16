#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <map>


const double EPS = 1e-9; // Use EPS (1e−9) when comparing two floating points

struct point {
    double x, y;

    // Default constructor
    point() : x(0.0), y(0.0) {}

    // User-defined constructor
    point(double _x, double _y) : x(_x), y(_y) {}

    // Override less than operator for sorting
    bool operator < (const point& other) const {
        if (fabs(x - other.x) > EPS)
            return x < other.x; // First criteria, by x-coordinate
        else if (fabs(y - other.y) > EPS)
            return y < other.y; // Second criteria, by y-coordinate
        return false; // Equals
    }

    // Override equality operator
    bool operator == (const point& other) const {
        return (fabs(x - other.x) < EPS && fabs(y - other.y) < EPS);
    }
};



int main(){
  int C;
  std::cin >> C;
  while(C){
    C--; 

    //std::cout << C <<  std::endl;

    int T, N;
    std::cin >> T;
    N = T;

    std::vector<point>  points;
    std::map<point, int> pointsMap;

    point mean = point(0,0);
    while(T){
      T--; 
      int x, y;
      std::cin >> x >> y;
      mean.x = mean.x + x;
      mean.y = mean.y + y;
      points.push_back(point(x,y));
    
    }

    mean.x = mean.x/N;
    mean.y = mean.y/N;

    for(auto& _point : points) {
        _point.x = _point.x - mean.x;
        _point.y = _point.y - mean.y;
        pointsMap.insert(std::make_pair(_point, 1));
    }
    bool isYes = true;
    for (const auto& pair : pointsMap) {
        double x = pair.first.x; 
        double y = pair.first.y; 

        if(x!=0){
          if ( !( pointsMap.count(point(-x,y)) > 0 ) ) {
            std::cout << "NO" << std::endl;
            isYes = false;
            break;
          }
        }
    }
    if(isYes)
      std::cout << "YES" << std::endl;
  }

 return 0;
}
