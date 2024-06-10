/*
    Author: Eddy Koundjou
    Date 06/10/2024

    This program creates a class called Circle that has a default constructor and a parameterized constructor.
    The class has a method that returns the area of the circle and a method that returns the radius of the circle.
    The class also has a method that sets the radius of the circle to a variable. 
    The class has relational operators that determine which circle is bigger than the other in terms of area. 
    The program creates two circles and checks to see which circle is smaller, which circle is bigger, and if 
    the circles are the same size.
*/

#include <iostream>
#include <cmath>
using namespace std;

class Circle {
    public:
        Circle(); //default constructor
        Circle(double); // parameterized constructor
        double getArea(); //returns the area of the circle
        double getRadius(); //returns the radius
        void setRadius(double); //sets the radius to a variable
     //relational operators that determines which circle is bigger than the other in terms of area
        bool operator < (Circle &c);
        bool operator <= (Circle& c);
        bool operator == (Circle& c);
        bool operator != (Circle& c);
        bool operator >= (Circle& c);
        bool operator > (Circle& c);
    
    private:
        double radius;
};


int main() {
    //Creating the two circles
    Circle firstCircle(5);
    Circle secondCircle(6);
    
    //checking to see which circle is smaller
    if(firstCircle < secondCircle) {
        cout << "The radius of the smaller circle is: " << firstCircle.getRadius() << endl;
        cout << "The area of the smaller circle is: " << firstCircle.getArea() << endl;
    }
    else {
        cout << "The radius of the smaller circle is: " << secondCircle.getRadius() << endl;
        cout << "The area of the smaller circle is: " << secondCircle.getArea() << endl;
    }
    //checking to see which circle is bigger
    if (firstCircle > secondCircle) {
        cout << "The radius of the larger circle is: " << firstCircle.getRadius() << endl;
        cout << "The area of the larger circle is: " << firstCircle.getArea() <<endl;
    }
    else {
        cout << "The radius of the larger circle is: " << secondCircle.getRadius() << endl;
        cout << "The area of the larger circle is: " << secondCircle.getArea() << endl;
    }
    //Checking to see if they are the same size
    if(firstCircle == secondCircle) {
        cout << "They have the same radius and therfore the same area" <<  endl;
    }
}

Circle :: Circle() {
    double radius = 1;
}

Circle :: Circle(double rCircle) {
    radius = rCircle;
}

double Circle :: getArea() {
    return 3.14 * pow(radius,2);
}

double Circle :: getRadius() {
    return radius;
}

void Circle :: setRadius(double rCircle) {
    radius = rCircle;
}

bool Circle :: operator<(Circle& c) {
    bool isLessThan = (this -> radius < c.radius);
    return isLessThan;
}

bool Circle :: operator<=(Circle& c) {
    bool isLessThanEqualTo = (this->radius <= c.radius);
    return isLessThanEqualTo;
}

bool Circle :: operator==(Circle& c) {
    bool isEqualTo = (this->radius == c.radius);
    return isEqualTo;
}

bool Circle :: operator!=(Circle& c) {
    bool isNotEqualTo = (this-> radius != c.radius);
    return isNotEqualTo;
}

bool Circle :: operator >= (Circle& c) {
    bool isGreaterThanEqualTo = (this -> radius >= c.radius);
    return isGreaterThanEqualTo;
}

bool Circle :: operator > (Circle& c) {
    bool isGreaterThan = (this -> radius > c.radius);
    return isGreaterThan;
}