
#include <iostream>

using namespace std;
#define pi 3.14159265359

class Point {
private:
	float x, y;
public:

	Point();  // Par defaut
	Point(const float& newx, const float& newy);  // avec 2 parametre 
	// Les setters
	void setXY(const float& newx, const float& newy);
	void setX(const float& newx);
	void setY(const float& newy);
	// Les getters
	float getX();
	float getY();
	void print();

	float distanceTo(const Point& otherPoint);
};

Point::Point()
{
	x = (float)(rand() % 99);
	y = (float)(rand() % 99);
}

Point::Point(const float& newx, const float& newy)
{
	x = newx;
	y = newy;
}

void Point::setXY(const float& newx, const float& newy)
{
	x = newx;
	y = newy;
}

void Point::setX(const float& newx)
{
	x = newx;
}

void Point::setY(const float& newy)
{
	y = newy;
}

float Point::getX()
{
	return x;
}

float Point::getY()
{
	return y;
}

void Point::print()
{
	cout << "X : " << x << "  Y : " << y << endl;
}

float Point::distanceTo(const Point& otherPoint)
{
	float rx = (otherPoint.x - x) * (otherPoint.x - x);
	float ry = (otherPoint.y - y) * (otherPoint.y - y);
	return sqrt(rx + ry);
}


class Circle
{
private:
	Point center;
	float radius;
public:
	Circle(float, float, float);
	float getRadius();
	void setRadius(float r);
	float getCenterX();
	float getCenterY();
	float getArea();
	float getPerimeter();
};

Circle::Circle(float x, float y, float r) :
	center(x, y), radius(r)
{
	center.setXY(x, y);
	setRadius(r);
}

float Circle::getRadius()
{
	return radius;
}

void Circle::setRadius(float r)
{
	radius = r;
}

float Circle::getCenterX()
{
	return center.getX();
}

float Circle::getCenterY()
{
	return center.getY();
}

float Circle::getArea()
{
	return ((float)pi * radius * radius);
}

float Circle::getPerimeter()
{
	return (2 * (float)pi * radius);
}

class Vector
{
private:
	float x, y;
public:
	Vector(Point A, Point B);
	Vector getSum(Vector& otherVector);
	Vector Produit(int r);
	bool verifyEquality(Vector& otherVector);
	void print();
};

void Vector::print()
{
	cout << "X : " << x << "  Y : " << y << endl;
}

Vector::Vector(Point A, Point B)
{
	x = B.getX() - A.getX();
	y = B.getY() - A.getY();
}

Vector Vector::getSum(Vector& otherVector)
{
	Point P, Q;
	Vector sum(P, Q);
	sum.x = (otherVector.x + x);
	sum.y = (otherVector.y + y);
	sum.print();
	return sum;
}

Vector Vector::Produit(int r)
{
	Point P, Q;
	Vector sum(P, Q);
	sum.x = (x * r);
	sum.y = (y * r);
	sum.print();
	return sum;
}

bool Vector::verifyEquality(Vector& otherVector)
{
	if (otherVector.x == x && otherVector.y == y) return true;
	else return false;
}



class Polygon
{
private:
	Point* points;
	int nbpts = 0;
public:
	Polygon(int size);
	float getArea();
	void print();
	void setPXY(int pt, float x, float y);
};

Polygon::Polygon(int size)
{
	points = new Point[size];
	nbpts = size;
}

void Polygon::print()
{
	for (int i = 0; i <= nbpts - 1; i++)
	{
		cout << "Point n = " << i << "  X : " << points[i].getX() << "  Y : " << points[i].getY() << endl;
	}
}

void Polygon::setPXY(int pt, float x, float y)
{
	points[pt].setXY(x, y);
}

float Polygon::getArea()
{
	float area = 0;
	for (int i = 0; i < nbpts - 2; i++)
	{
		area = area + (((points[i].getX()) * (points[i + 1].getY())) - ((points[i + 1].getX()) * (points[i].getY())) / 2);
	}
	return area;
}
