#include <iostream>
#include "TP4.h"

using namespace std;
#define pi 3.14159265359

// EXERCICE 1

class A {	
public:
	A() { x = 0; cout << "1"; }					// Constructeur par défault			--> 1
	A(int px) { x = px; cout << "2"; }			// Constructeur avec 1 paramétre	--> 2
	A(const A& pa) { x = pa.x; cout << "3"; }	// constructeur avec 2 paramétre	--> 3
protected:
	int x;
};


class B {
public:
	B(const A& pa = A()) : a(pa) { cout << "4"; }				// Constructeur avec 1 paramétre	 --> 4
	B(const A& pa, int py) { a = pa; y = py; cout << "5"; }		// Constructeur avec 2 paramétre	 --> 5
protected:
	A a;
	int y;
};


class C : public B {
public:
	C(int pz = 1) { z = pz; cout << "6"; }					
	C(A pa) : B(pa) { z = 0; cout << "7"; }
	C(const B& pb) : B(pb), a(1) { z = 0; cout << "8"; }
protected:
	A a;
	int z;
};





int main() {
	//EXERCICE 1 
	cout << "-- A --\n";
	A a0; cout << endl;
	A a1(3); cout << endl;
	A a2(a1); cout << endl;
	A a3 = a2; cout << endl;
	a3 = a1; cout << endl;
	
	cout << "-- B --\n";
	B b0(a0, 3); cout << endl;
	B b1(a1); cout << endl;
	B b2; cout << endl;
	
	cout << "-- C --\n";
	C c0; cout << endl;
	C c1(a1); cout << endl;
	C c2(b2); cout << " \n" << endl;


	system("PAUSE");
	system("CLS");

	// EXERCICE 2

	float x, y, r;
	cout << "Entrez une valeur de x : ";
	cin >> x;
	cout << endl << "Entrez une valeur de y : ";
	cin >> y;
	cout << endl << "Entrez une valeur de r : ";
	cin >> r;
	Circle test(x, y, r);
	system("PAUSE");
	system("CLS");



	//EXERCICE 3 
	Point A, B, C, D;
	Vector Test1(A, B), Test2(C, D);
	cout << "Produit : ";
	Test1.Produit(10);
	cout << "La somme  : ";
	Test1.getSum(Test2);
	cout << "On verifie l'egualite pour voir s'il sont egaux : "<<Test1.verifyEquality(Test2) << endl;
	cout << "Test1 : ";
	Test1.print();
	cout << "Test2 : ";
	Test2.print();

	system("PAUSE");
	system("CLS");

	//Exercice 4 
	
	Polygon Triangle(3);
	Triangle.print();
	Triangle.setPXY(0, 1, 0);
	Triangle.setPXY(1, 1, 3);
	Triangle.setPXY(2, 3, 2);
	cout << "Triangle : " << Triangle.getArea() << endl;
	cout << endl;
	
	Polygon Carré(4);
	Carré.print();
	Carré.setPXY(0, 0, 0);
	Carré.setPXY(1, 10, 10);
	Carré.setPXY(2, 0, 10);
	Carré.setPXY(3, 10, 0);
	cout << "Carre : " << Carré.getArea() << endl;
	cout << endl;
	
	Polygon Rectangle(4);
	Rectangle.print();
	Rectangle.setPXY(0, 0, 0);
	Rectangle.setPXY(1, 10, 20);
	Rectangle.setPXY(2, 0, 20);
	Rectangle.setPXY(3, 10, 0);
	cout << "Rectangle : " << Rectangle.getArea() << endl;
	cout << endl;
	Polygon Pentagone(5);
	Pentagone.print();
	Pentagone.setPXY(0, 10, 0);
	Pentagone.setPXY(1, 30, 10);
	Pentagone.setPXY(2, 0, 20);
	Pentagone.setPXY(3, 30, 25);
	Pentagone.setPXY(4, 10, 30);
	cout << "Pentagone : " << Pentagone.getArea() << endl;
	cout << endl;

}
