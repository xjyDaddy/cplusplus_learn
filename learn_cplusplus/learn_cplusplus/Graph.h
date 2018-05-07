#pragma once
class Graph
{
public:
	Graph();
	~Graph();

	virtual double GetArea() const = 0;
};


class Point
{
public:
	Point();
	Point(int x, int y);
	~Point();
	void setX(int x);
	void setY(int y);
	void set(int x, int y);
	int getX() const;
	int getY() const;
private:
	int x;
	int y;
};


class Cricle: public Graph
{
public:
	Cricle();
	Cricle(int x, int y, int r) :point(x, y), r(r){};
	~Cricle();
	virtual double GetArea() const;
private:
	int r;
	Point point;
};

void Graph_test();