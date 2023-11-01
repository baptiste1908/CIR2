
#include "Point3D.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

// définit srand() pour générer des nombres aléatoires

Point3D::Point3D() {
	x = rand() % 100;
	y = rand() % 100;
	z = rand() % 100;
}

// comment definir des setteurs

Point3D::Point3D(const float &newx, const float &newy, const float &newz) {
	x = newx;
	y = newy;
	z = newz;
}

//float Point3D::distanceTo(const Point3D &otherPoint3D) {
//	float dx = x - otherPoint3D.x;
//	float dy = y - otherPoint3D.y;
//	float dz = z - otherPoint3D.z;
//	return sqrt(dx * dx + dy * dy + dz * dz);
//}
float Point3D::distanceTo(const Point3D& otherPoint3D) {
	float distance = sqrt((x - otherPoint3D.x) * (x - otherPoint3D.x) + (y - otherPoint3D.y) * (y - otherPoint3D.y) + (z - otherPoint3D.z) * (z - otherPoint3D.z));
	return distance;
}


void Point3D::setX(const float &newx) {
		x = newx;
}

void Point3D::setY(const float& newy) {
	y = newy;
}

void Point3D::setZ(const float& newz) {
	z = newz;
}

// comment définir des getters

float Point3D::getX() {
	return x;
}

float Point3D::getY() {
	return y;
}

float Point3D::getZ(){
	return z; 
}

void Point3D::print() {
	cout << "x = " << x << " | " << " y = " << y << " | " << " z = " << z << endl;
}



// EXO 2

void Trajectory::print() {
	for (int i = 0; i < numberOfPoints; i++) {
		cout << "Point " << i << " : " << points[i].getX() << " " << points[i].getY() << " " << points[i].getZ() << endl;
	}
}

Point3D& Trajectory::getPoint(const int& n) {
	return points[n];
}

float Trajectory::getTotalDistance() {
	
	float totalDistance = 0;
	for (int i = 0; i < numberOfPoints - 1; i++) {
		totalDistance += points[i].distanceTo(points[i + 1]);
	}
	return totalDistance;
}

//Modifier l’ensemble des points pour qu’ils soient sur une droite. Comparer la distance totale avec la distance entre le premier et le dernier point

int Trajectory::setPointsOnLine() {
	for (int i = 0; i < numberOfPoints; i++) {
		points[i].setX(i);
		points[i].setY(i);
		points[i].setZ(i);
	}
	return 0;
}
// definit :setPointsOnLine()









int main() {
	srand(time(NULL));
	Point3D p1;
	Point3D p2(1, 2, 3);
	p1.print(); 
	p2.print();
	cout << "distance entre p1 et p2 = " << p1.distanceTo(p2) << endl;
	
	system("PAUSE");
	system("CLS");
	
	Trajectory total;
	total.print();
	cout << "Total distance = " << total.getTotalDistance() << endl;
	total.setPointsOnLine();
	total.print();
	cout << "Distance totale : " << total.getTotalDistance() << endl;
	return 0;
}



