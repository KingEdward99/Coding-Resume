/*
The MyPoint class has the properties x and y that represent x- and y-
coordinates, two get functions for x and y, and the function for returning the distance between
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
//base class for the original points
class MyPoint {
 protected:
    double x; // stores the x point
    double y; // stores the y point 
 public: 
    MyPoint() {
        x = 0.0;
        y = 0.0;
    }
    
    // parameterized constructor
    MyPoint(double xPoint, double yPoint) {
        x = xPoint;
        y = yPoint;
    }

    //function prototype for the points
    double distance(MyPoint&);
    
    //function prototype to get x
    double getX();
    
    //function prototype to get y
    double getY();
};

//derived class for the 3D points
class ThreeDPoint:public MyPoint {
    protected:
        double z;
    
    //default constructor to set origins to 0
    public:
        ThreeDPoint() {
            x = 0;
            y = 0;
            z = 0;
        }

//parameterized constructor
ThreeDPoint(double xPoint, double yPoint, double zPoint) {
    x = xPoint;
    y = yPoint;
    z = zPoint;
}

//function prototype to get z
    double getz();
//function prototype to calculate the distance within a 3D space
    double threeDistance(const ThreeDPoint&, zPoint&);
};

int main() {
    //creating the object
    MyPoint twoD;
    cout << "The distance between the two points is: " << endl;
    
    //the calculated distance between (0,0) and (10.5,25.5)
    double originPoint = twoD.distance(twoD);
    cout << originPoint;

    //Creating the object for the 3D points
    MyPoint threeD;
    cout << "The distance between the two 3D points is: " << endl;
    double threeDPoint = threeD.threeDistance(threeD);
    return 0;
}
//function to get the x
double MyPoint::getX() {
    double x = 10.5;
    return x;
}

//function to get the y
double MyPoint::getY() {
    double y = 25.5;
    return y;
}

//function to calculate the distance between two points
double MyPoint::distance(MyPoint& firstPoint) {
    double firstX = getX();
    double firstY = getY();
    double secondX = firstPoint.x;
    double secondY = firstPoint.y;
    
    double xDistance = pow((secondX-firstX),2);
    double yDistance = pow((secondY-firstY),2);
    double pointDistance = sqrt((xDistance + yDistance));
    
    return pointDistance;
}

//function to get the z
double ThreeDPoint::getz() {
    return z;
}

//function to calculate the distance within a 3D space
double ThreeDPoint::threeDistance(const ThreeDPoint&, zPoint&) {
    double firstX = x;
    double firstY = y;
    double firstZ = z;
    double secondX = zPoint.x;
    double secondY = zPoint.y;
    double secondZ = zPoint.z;
    double xDistance = pow((secondX-firstX),2);
    double yDistance = pow((secondY-firstY),2);
    double zDistance = pow((secondZ - firstZ),2);
    double point3Distance = sqrt((xDistance + yDistance + zDistance));
    
    return point3Distance;
}