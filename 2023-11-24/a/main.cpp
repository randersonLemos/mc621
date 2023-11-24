#include <cmath>
#include <vector>
#include <iostream>


#define PI acos(-1.0) // Important constant


using namespace std;


const double EPS = 1e-9; // Use EPS (1e−9) when comparing two floating points
// Function to convert degrees to radians
double DEG_to_RAD(double d) {
    return d * PI / 180.0;
}


struct point {
    double x, y; // Coordinates

    // Default constructor
    point() {
        x = y = 0.0;
    }

    // User-defined constructor
    point(double _x, double _y) : x(_x), y(_y) {}

    // Override less than operator for sorting
    // Useful for sorting points based on x and y coordinates
    bool operator<(point other) const {
        if (fabs(x - other.x) > EPS)
            return x < other.x; // First criteria, by x-coordinate
        else if (fabs(y - other.y) > EPS)
            return y < other.y; // Second criteria, by y-coordinate
        return false; // Equals
    }

    // Override equality operator
    bool operator==(point other) const {
        return (fabs(x - other.x) < EPS && fabs(y - other.y) < EPS);
    }
};


struct vec {
    double x, y;

    // Constructor for initializing the vector with given x and y values
    vec(double _x, double _y) : x(_x), y(_y) {}
};


double dist(point p1, point p2) {
    // Euclidean distance formula: sqrt((dx * dx) + (dy * dy))
    return hypot(p1.x - p2.x, p1.y - p2.y);
}


// Function to convert two points to a vector (a -> b)
vec toVec(point a, point b) {
    return vec(b.x - a.x, b.y - a.y);
}

// Function to scale a vector by a scalar value
vec scale(vec v, double s) {
    return vec(v.x * s, v.y * s);
}

// Function to translate a point by a vector
point translate(point p, vec v) {
    return point(p.x + v.x, p.y + v.y);
}


// Function to rotate a point by a given angle in degrees
point rotate(point p, double theta) {
    double rad = DEG_to_RAD(theta); // Convert degrees to radians
    return point(
        p.x * cos(rad) - p.y * sin(rad),
        p.x * sin(rad) + p.y * cos(rad)
    );
}


// Function to calculate the dot product of two vectors
double dot(vec a, vec b) {
    return (a.x * b.x + a.y * b.y);
}

// Function to calculate the squared magnitude (squared norm) of a vector
double norm_sq(vec v) {
    return (v.x * v.x + v.y * v.y);
}

// Function to calculate the distance from a point to a line defined by two points
double distToLine(point p, point a, point b, point &c) {
    // Formulas: c = a + u * ab
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u)); // Translate a to c
    return dist(p, c); // Euclidean distance between p and c
}


double angle(point a, point o, point b) {
    // Define vectors OA and OB
    vec oa = toVec(o, a), ob = toVec(o, b);

    // Calculate the dot product of OA and OB
    double dotProduct = dot(oa, ob);

    // Calculate the magnitudes (squared norms) of OA and OB
    double normOaSq = norm_sq(oa);
    double normObSq = norm_sq(ob);

    // Calculate the angle between OA and OB using the dot product and magnitudes
    return acos(dotProduct / sqrt(normOaSq * normObSq));
}


// Function to calculate the cross product of two vectors (a and b)
double cross(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}

// Predicate to check if point r is on the left side of the line defined by points p and q
bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0;
}

// Predicate to check if point r is on the same line as the line defined by points p and q
bool collinear(point p, point q, point r) {
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

bool isConvex(const vector<point>& P) {
    int sz = (int)P.size();

    // If the number of points is less than or equal to 3, the polygon is not convex.
    if (sz <= 3)
        return false;

    // Check the orientation of the first three points.
    bool isLeft = ccw(P[0], P[1], P[2]);

    // Compare the orientation of the remaining points.
    for (int i = 1; i < sz - 1; i++) {
        if (ccw(P[i], P[i + 1], P[(i + 2) == sz ? 1 : i + 2]) != isLeft)
            return false; // Different sign indicates a concave polygon.
    }

    return true; // If all checks pass, the polygon is convex.
}


// Function to check if a point pt is inside a polygon P
bool inPolygon(point pt, const vector<point> &P) {
    if (P.size() == 0) return false;

    double sum = 0; // Assume the first vertex is equal to the last vertex

    for (int i = 0; i < (int)P.size() - 1; i++) {
        if (ccw(pt, P[i], P[i + 1]))
            sum += angle(P[i], pt, P[i + 1]); // Left turn (counterclockwise)
        else
            sum -= angle(P[i], pt, P[i + 1]); // Right turn (clockwise)
    }

    return fabs(fabs(sum) - 2 * PI) < EPS; // Check if the absolute value of the sum is close to 2*pi
}


int main(){
  while(true){
    int N;
    std::cin >> N; 

    if(N == 0)
      break;

    double x,y; 
    std::vector<point> points;

    while(N){
      N--;
      std::cin >> x >> y;
      point _point(x,y);
      points.push_back(_point);
    }
  
    points.push_back(point(points[0].x, points[0].y));
    std::cin >> x >> y;
    point P(x,y);

    //for (point element : points) {
    //      cout << element.x <<  " " << element.y << " ";
    //      cout << endl;
    //  } 

    //cout << P.x << " " << P.y << endl;

    if( inPolygon( P, points ) ){
      std::cout << "T" << std::endl;
    }
    else{
      std::cout << "F" << std::endl;
    }
  
  }
  return 0;
}
