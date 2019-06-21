#pragma once
#define PI 3.1415926
#include<cmath>
class Shape
{
public:
	Shape(double edge = 0.0) :m_edge(edge) {}
	~Shape() = default;
	virtual double getArea() = 0;

protected:
	double m_edge;
};

class Square :public Shape
{
public:
	Square(double edge = 0.0) :Shape(edge) {}
	~Square() = default;

	double getArea() override { return m_edge * m_edge; }
};

class Circle :public Shape
{
public:
	Circle(double edge = 0.0) :Shape(edge) {}
	~Circle() = default;

	double getArea() override { return PI*m_edge * m_edge; }
};

class Globe :public Shape
{
public:
	Globe(double edge = 0.0) :Shape(edge) {}
	~Globe()=default;

	double getArea() override { return 4 * PI*m_edge*m_edge; }
	double getVolume() { return 4 * PI*m_edge*m_edge*m_edge / 3; }
};

class Cone :public Shape
{
public:
	Cone(double edge = 0.0,double high=0.0) :Shape(edge),m_high(high) {}
	~Cone() = default;

	double getArea() override { return PI * m_edge*sqrt(m_high*m_high + m_edge * m_edge); }
	double getVolume() { return PI*m_edge*m_edge*m_high / 3; }
private:
	double m_high;
};