#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>  // For std::pair


#define PI acos(-1.0) // Important constant

double DEG_to_RAD(double d) {
    return d * PI / 180.0;
}

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


// Rotate point p by theta degrees CCW with respect to the origin (0, 0)
point rotate(point p, double theta) {
    double rad = DEG_to_RAD(theta); // Multiply theta with PI / 180.0
    return point(p.x * cos(rad) - p.y * sin(rad),
                 p.x * sin(rad) + p.y * cos(rad));
}

double dist(point p1, point p2) {
    // Euclidean distance: hypot(dx, dy) returns sqrt(dx*dx + dy*dy)
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

int main(){
  int N;
  while(std::cin >> N){
    if(N==0) 
      break;
 
    std::vector<point> points;

    while(N){
      N--;
      point Txy = point(0,0);
      point Tij = point(1,0);
      point tmp = point(0,0);

      std::cin >> Txy.x >> Txy.y;

      std::string command; 
      std::getline(std::cin, command);

      std::string word; double val;
      std::istringstream iss(command);
      while (iss >> word >> val) {
        if( word == "start"){
          Tij = rotate(Tij, val);
        }
        if( word == "walk"){
          tmp.x = Tij.x*val; tmp.y = Tij.y*val;
          Txy.x = Txy.x + tmp.x;
          Txy.y = Txy.y + tmp.y;
        }
        if( word == "turn"){
          Tij = rotate(Tij, val);
        }
        //std::cout << word << " " << val << " ";
        //std::cout << "(" << Txy.x << " " << Txy.y << ") (" << Tij.x << " " << Tij.y << ") " << std::endl;
      }   
      //std::cout << "---" << std::endl;
      points.push_back(Txy);
    }

    int size = points.size();
    point mean = point(0,0);
    for ( int i=0; i<size; i++ ) {
        mean.x = mean.x + points[i].x;
        mean.y = mean.y + points[i].y;
        //std::cout << points[i].x << " " << points[i].y << std::endl;
    }
    mean.x = mean.x/size;
    mean.y = mean.y/size;

    double distMax = 0;
      
    for ( int i=0; i<size; i++ ) {
      double _dist = dist(mean, points[i]);
      if(_dist > distMax){
        distMax = _dist; 
      }
    }
 

    std::cout <<  mean.x << " " << mean.y <<  " " << distMax << std::endl;

    //std::cout << "===" << std::endl;
  }
  return 0;
}
