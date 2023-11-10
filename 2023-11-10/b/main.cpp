#include <iostream>
#include <string>
#include <cmath>


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

#define PI acos(-1.0) // Important constant

double DEG_to_RAD(double d) {
    return d * PI / 180.0;
}

// Rotate point p by theta degrees CCW with respect to the origin (0, 0)
point rotate(point p, double theta) {
    double rad = DEG_to_RAD(theta); // Multiply theta with PI / 180.0
    return point(p.x * cos(rad) - p.y * sin(rad),
                 p.x * sin(rad) + p.y * cos(rad));
}


struct line {
    double a, b, c;
};


int main(){
  int N;
  std::cin >> N;
  while(N){
    N--;
    int T; 
    std::cin >> T;

    point Txy = point(0,0);
    point Tij = point(1,0);
    point tmp = point(0,0);

    //std::cout << "Tx: " << Txy.x << " Ty: " << Txy.y << std::endl;
    double ddist;

    while(T){
      T--;
      std::string cmd;
      double val;

      std::cin >> cmd >> val;

      if(cmd == "fd"){
        //std::cout << "fd " << val << std::endl; 
        tmp.x = Tij.x*val; tmp.y = Tij.y*val;
        Txy.x = Txy.x + tmp.x;
        Txy.y = Txy.y + tmp.y;
      }

      if(cmd == "bk"){
        //std::cout << "bk " << val << std::endl; 
        tmp.x = Tij.x*(-1*val); tmp.y = Tij.y*(-1*val);
        Txy.x = Txy.x + tmp.x;
        Txy.y = Txy.y + tmp.y;
      }

      if(cmd == "lt"){
        //std::cout << "lt " << val << std::endl; 
        tmp = rotate(Tij, val);
        Tij.x = tmp.x; Tij.y = tmp.y;
      }

      if(cmd == "rt"){
        //std::cout << "rt " << val << std::endl; 
        tmp = rotate(Tij, -1*val);
        Tij.x = tmp.x; Tij.y = tmp.y;
      }

      ddist = dist(Txy, point(0,0));
      //std::cout << "Tx: " << Txy.x << " Ty: " << Txy.y << std::endl;
      //std::cout << "Ti: " << Tij.x << " Tj: " << Tij.y << std::endl;
    }
    std::cout << int( ddist+0.5 )  << std::endl;
  
  
  }

}
