/*
    Creating a circle and calculating the area and circumference
*/

#include &lt;iostream&gt;
#include &lt;cmath&gt;
using namespace std;

class Circle
{
public:
Circle(); //default constructor
Circle(double); // parameterized constructor
double getArea(); //returns the area of the circle
double getRadius(); //returns the radius
void setRadius(double); //sets the radius to a variable
//relational operators that determines which circle is bigger than the other in terms of area
bool operator&lt;(Circle&amp; c);
bool operator &lt;=(Circle&amp; c);
bool operator == (Circle&amp; c);
bool operator != (Circle&amp; c);
bool operator &gt;= (Circle&amp; c);
bool operator &gt; (Circle&amp; c);
private:
double radius;
};

COSC 214
Spring 2022
int main()
{
//Creating the two circles
Circle firstCircle(5);
Circle secondCircle(6);
//checking to see which circle is smaller
if(firstCircle &lt; secondCircle)
{
cout &lt;&lt; &quot;The radius of the smaller circle is: &quot; &lt;&lt; firstCircle.getRadius() &lt;&lt; endl;
cout &lt;&lt; &quot;The area of the smaller circle is: &quot; &lt;&lt; firstCircle.getArea() &lt;&lt; endl;
}
else
{
cout &lt;&lt; &quot;The radius of the smaller circle is: &quot; &lt;&lt; secondCircle.getRadius() &lt;&lt; endl;
cout &lt;&lt; &quot;The area of the smaller circle is: &quot; &lt;&lt; secondCircle.getArea() &lt;&lt; endl;
}
//checking to see which circle is bigger
if(firstCircle &gt; secondCircle)
{
cout &lt;&lt; &quot;The radius of the larger circle is: &quot; &lt;&lt; firstCircle.getRadius() &lt;&lt; endl;
cout &lt;&lt; &quot;The area of the larger circle is: &quot; &lt;&lt; firstCircle.getArea() &lt;&lt; endl;
}
else
{
cout &lt;&lt; &quot;The radius of the larger circle is: &quot; &lt;&lt; secondCircle.getRadius() &lt;&lt; endl;
cout &lt;&lt; &quot;The area of the larger circle is: &quot; &lt;&lt; secondCircle.getArea() &lt;&lt; endl;
}
//Checking to see if they are the same size
if(firstCircle == secondCircle)
{
cout &lt;&lt; &quot;They have the same radius and therfore the same area &quot; &lt;&lt; endl;
}
else
{

COSC 214
Spring 2022
cout &lt;&lt; &quot;The radius of the larger circle is: &quot; &lt;&lt; secondCircle.getRadius() &lt;&lt; endl;
cout &lt;&lt; &quot;The area of the larger circle is: &quot; &lt;&lt; secondCircle.getArea() &lt;&lt; endl;
}
}
Circle :: Circle()
{
double radius = 1;
}
Circle :: Circle(double rCircle)
{
radius = rCircle;
}
double Circle :: getArea()
{
return 3.14 * pow(radius,2);
}
double Circle :: getRadius()
{
return radius;
}
void Circle :: setRadius(double rCircle)
{
radius = rCircle;
}
bool Circle :: operator&lt;(Circle&amp; c)
{
bool isLessThan = (this-&gt;radius &lt; c.radius);
return isLessThan;
}
bool Circle :: operator&lt;=(Circle&amp; c)
{
bool isLessThanEqualTo = (this-&gt;radius &lt;= c.radius);

COSC 214
Spring 2022

return isLessThanEqualTo;
}
bool Circle :: operator==(Circle&amp; c)
{
bool isEqualTo = (this-&gt;radius == c.radius);
return isEqualTo;
}
bool Circle :: operator!=(Circle&amp; c)
{
bool isNotEqualTo = (this-&gt; radius != c.radius);
return isNotEqualTo;
}
bool Circle :: operator &gt;= (Circle&amp; c)
{
bool isGreaterThanEqualTo = (this -&gt; radius &gt;= c.radius);
return isGreaterThanEqualTo;
}
bool Circle :: operator &gt; (Circle&amp; c)
{
bool isGreaterThan = (this -&gt; radius &gt;= c.radius);
return isGreaterThan;
}