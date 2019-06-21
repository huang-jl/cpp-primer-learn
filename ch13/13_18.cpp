#include<string>

class Employee
{
public:
	Employee();
	Employee(const std::string&);
	/*
	*13.19
	Employee(const Employee&) = delete;
	Employee& operator =(const Employee&) = delete;
	*/
private:
	static unsigned identity;
	std::string name;
	unsigned ID_number;
};

unsigned Employee::identity = 1;

Employee::Employee()
{
	ID_number = identity++;
}

Employee::Employee(const std::string& str)
{
	name = str;
	ID_number = identity++;
}