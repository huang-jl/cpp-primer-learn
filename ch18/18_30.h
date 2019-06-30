#pragma once
class Class
{};

class Base:public Class
{
public:
	Base() = default;
	Base(const Base&b):b_i(b.b_i) {}
	Base(int i) :b_i(i){}
private:
	int b_i;
};

class D1 :virtual public Base
{
public:
	D1() :Base() {}
	D1(const D1&d1) :Base(d1) {}
	D1(int i) :Base(i) {}
};

class D2 :virtual public Base
{
public:
	D2() :Base() {}
	D2(const D2&d2) :Base(d2) {}
	D2(int i) :Base(i) {}
};

class MI :public D1, public D2
{
public:
	MI() :Base() {}
	MI(const MI&mi) :Base(mi) {}
	MI(int i) :Base(i) {}
};

class Final :public MI, public Class
{
public:
	Final() :Base() {}
	Final(const Final&f) :Base(f) { }
	Final(int i) :Base(i) {}
};