#include <cmath>
#include <iostream>

const double INF = 1e9;
const double EPS = 1e-9;

struct point {
    double x, y; // coordinates of the point, with double precision

    // Default constructor
    point() {
        x = y = 0.0;
    }

    // Parameterized constructor
    point(double _x, double _y) : x(_x), y(_y) {}

    // Less than operator
    // Useful for sorting points
    // Use EPS (1e−9) when comparing two floating points
    bool operator < (point other) const {
        if (fabs(x - other.x) > EPS)
            return x < other.x; // First criteria, compare by x-coordinate
        else if (fabs(y - other.y) > EPS)
            return y < other.y; // Second criteria, compare by y-coordinate
        return 0; // Equals
    }

    // Equal to operator
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && fabs(y - other.y) < EPS);
    }
};



double dist(point p1, point p2) {
    // Euclidean distance: sqrt(dx^2 + dy^2)
    return hypot(p1.x - p2.x, p1.y - p2.y);
}


// Definition of the 'vec' struct
struct vec {
    double x, y; // x and y components of the vector

    // Constructor for the 'vec' struct
    vec(double _x, double _y) : x(_x), y(_y) {}
};

// Function to convert two points to a vector a->b
vec toVec(point a, point b) {
    return vec(b.x - a.x, b.y - a.y);
}

// Function to scale a vector 'v' by a non-negative factor 's'
vec scale(vec v, double s) {
    return vec(v.x * s, v.y * s);
}

// Function to translate a point 'p' according to a vector 'v'
point translate(point p, vec v) {
    return point(p.x + v.x, p.y + v.y);
}


// Definition of the 'line' struct
struct line {
    double a, b, c; // Coefficients of the line equation ax + by + c = 0
};


double dot(vec a, vec b) {
    return (a.x * b.x + a.y * b.y);
}


double norm_sq(vec v) {
    return v.x * v.x + v.y * v.y;
}


double distToLine(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u)); // translate 'a' to 'c'
    return dist(p, c); // Euclidean distance between 'p' and 'c'
}


// Returns the distance from point 'p' to the line segment ab defined by points 'a' and 'b'
// The closest point is stored in the 4th parameter (by reference)
double distToLineSegment(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);

    if (u < 0.0) {
        c = point(a.x, a.y); // Closer to 'a'
        return dist(p, a);   // Euclidean distance between 'p' and 'a'
    }

    if (u > 1.0) {
        c = point(b.x, b.y); // Closer to 'b'
        return dist(p, b);   // Euclidean distance between 'p' and 'b'
    }

    return distToLine(p, a, b, c); // Run distToLine for points within the segment
}


int main(){

  double x,y;

  while(std::cin >> x >> y){
    point M(x,y);

    int npoints;
    std::cin >> npoints;

    double minDist = +INF;
    point closest;

    double xa, ya;
    std::cin >> xa >> ya;
    point a(xa, ya);

    while(npoints--){
      point b,c; 
      std::cin >> b.x >> b.y;

      double dist = distToLineSegment(M,a,b,c);

      if (dist<minDist){
        minDist = dist;
        closest = c; 
      }
      a=b;
    }
    printf("%4.4lf\n%4.4lf\n", closest.x, closest.y);
    //printf("%4lf\n", minDist);
  }
  return 0;
}
