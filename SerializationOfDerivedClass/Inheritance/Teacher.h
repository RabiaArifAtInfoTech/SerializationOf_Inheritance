#pragma once
#ifndef Teacher

#include"Employee.h"
//#include <boost/serialization/base_object.hpp>
#include<vector>

class Teacher : public Employee
{
	std::vector<std::string> courses;

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& boost::serialization::base_object<Employee>(*this);
		ar& courses;
	}

public:
	Teacher()
	{
		std::cout << "\nDefault Constructor of Teacher\n";

	}
	Teacher(std::string fName, std::string lName, int id, double sal, std::vector<std::string> cours) : Employee(fName, lName, id, sal)
	{
		setSalary(cours);

		std::cout << "\nConstructor of Teacher\n";
	}
	void setSalary(std::vector<std::string> cours)
	{
		for (auto itr = cours.begin(); itr != cours.end(); itr++) {
			courses.push_back(*itr);
			
		}
	}
	std::vector<std::string> getCourses()
	{
		return courses;
	}
	~Teacher()
	{
		std::cout << "\n\nDestructor of Teacher\n";
	}
};






#endif // !Teacher
