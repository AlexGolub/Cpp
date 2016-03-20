#include "stdafx.h"
#include <iostream>

using namespace std;


class Box
{
public:
	double getVolume (void)
	{
		return length * breadth * height;
	}

	void setLength (double len)
	{
		length = len;
	}

	void setBreadth (double bre)
	{
		breadth = bre;
	}

	void setHeight (double hei)
	{
		height = hei;
	}

	// Overload + operator to add two box objects.
	Box operator + (Box &b)
	{
		Box box;
		box.length = this -> length + b.length;
		box.breadth = this -> breadth + b.breadth;
		box.height = this -> height + b.height;
		return box;
	}

private:
	double length;
	double breadth;
	double height;
};

void main ()
{
	Box Box1;
	Box Box2;
	Box Box3;
	Box Box4;
	Box Box5;
	double volume = 0.0;

	// box 1 specifications
	Box1.setLength (6.0);
	Box1.setBreadth (7.0);
	Box1.setHeight (5.0);

	// box 2 specifications
	Box2.setLength (12.0);
	Box2.setBreadth (13.0);
	Box2.setHeight (10.0);

	// box 4 specifications
	Box4.setLength (16.0);
	Box4.setBreadth (8.0);
	Box4.setHeight (17.0);

	// box 5 specifications
	Box5.setLength (23.0);
	Box5.setBreadth (32.0);
	Box5.setHeight (21.0);
	// volume of box 1
	volume = Box1.getVolume ();
	cout << "Volume of Box1 : " << volume << endl;

	// volume of box 2
	volume = Box2.getVolume ();
	cout << "Volume of Box2 : " << volume << endl;

	// add two objects
	Box3 = Box1 + Box2 + Box4 + Box5; //call box 3 times

	// volume of box 3
	volume = Box3.getVolume ();
	cout << "Volume of Box3 : " << volume << endl;
}

