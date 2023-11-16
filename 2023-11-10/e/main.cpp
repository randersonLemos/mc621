#include <iostream>
#include <cmath>
#include <iomanip> // Needed for setprecision
                   //
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


double dist(point p1, point p2) {
    // Euclidean distance: hypot(dx, dy) returns sqrt(dx*dx + dy*dy)
    return hypot(p1.x - p2.x, p1.y - p2.y);
}



int main(){
  int x[10];
  int y[10];

  int a,b,c;

  std::cin >> a >> b >> c; // (0,0) (1,0) (2,0)
  x[a] = 0; y[a] = 0;
  x[b] = 1; y[b] = 0;
  x[c] = 2; y[c] = 0;

  std::cin >> a >> b >> c; // (0,1) (1,1) (2,1)
  x[a] = 0; y[a] = 1;
  x[b] = 1; y[b] = 1;
  x[c] = 2; y[c] = 1;

  std::cin >> a >> b >> c; // (0,2) (1,2) (2,2)
  x[a] = 0; y[a] = 2;
  x[b] = 1; y[b] = 2;
  x[c] = 2; y[c] = 2;


  double totalDist = 0;


  for(int i=1; i<9; i++){
    //std::cout << i << " " << i+1 << std::endl;
    //std::cout << x[i] << " " << y[i]  << " " << x[i+1] << " " << y[i+1] << std::endl;
    point A = point(x[i], y[i]);
    point B = point(x[i+1], y[i+1]);

  
   totalDist +=  dist(A, B);                                                                                                                                                                   

  }

  std::cout << std::fixed << std::setprecision(7) << totalDist << std::endl;


return 0;
}
