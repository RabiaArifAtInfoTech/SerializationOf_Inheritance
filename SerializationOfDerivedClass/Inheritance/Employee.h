#pragma once
#ifndef Employee

#include<iostream>
#include<chrono>
#include <boost/serialization/base_object.hpp>

class Employee
{
	std::string firstName;
	std::string lastName;
	int ID;
	double salary;
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		// serialize base class information
		ar& firstName;
		ar& lastName;
		ar& ID;
		ar& salary;
		
	}
public:
	Employee()
	{
		/*firstName = "A";
		lastName = "B";
		ID = 0;
		salary = 0;*/
		std::cout << "\nDefault constructor of Employee\n";
	}
	Employee(std::string fName, std::string lName, int id, double sal) {
		firstName = fName;
		lastName = lName;
		ID = id;
		salary = sal;
		std::cout << "\nConstructor of Employee\n";
	}
	void setFirstname(std::string fname)
	{
		firstName = fname;
	}
	void setLastname(std::string lname)
	{
		lastName = lname;
	}
	void setID(int id)
	{
		ID = id;
	}
	void setSalary(int sal)
	{
		salary = sal;
	}
	std::string getFirstname()
	{
		return firstName;
	}
	std::string getLastname()
	{
		return lastName;
	}
	int getID()
	{
		return ID;
	}
	double getSalary()
	{
		return salary;
	}

	~Employee()
	{
		std::cout << "\nDestructor of Employee\n";
	}

};




#endif // !Employee
