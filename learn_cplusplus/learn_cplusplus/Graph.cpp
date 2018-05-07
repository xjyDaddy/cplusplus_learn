#include "stdafx.h"
#include "Graph.h"
#include <iostream>
const double pi = 3.1415926;
using namespace std;
Graph::Graph()
{
}


Graph::~Graph()
{
}


void Point::setX(int x)
{
	this->x = x;
}

void Point::setY(int y)
{
	this->y = y;
}

void Point::set(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Point::getX() const
{
	return x;
}

int Point::getY() const
{
	return y;
}

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

Point::~Point()
{

}

double Cricle::GetArea() const
{
	return pi*r*r;
}

Cricle::~Cricle()
{

}

void Graph_test()
{
	Cricle a(1,2,3);
	cout << a.GetArea() << endl;
}
