#include<iostream>
#include<string.h>
#include<map>
#include<vector>

#include<fstream>

#include<boost/archive/text_iarchive.hpp>
#include<boost/archive/text_oarchive.hpp>

#include<boost/serialization/vector.hpp>
#include<boost/serialization/nvp.hpp>

#include"Teacher.h"

int main()
{
	Teacher t1;
	//std::cout << t1.getFirstname();

	const char* path = "../CommonFiles/OutFile.txt";
	std::ifstream inFile(path);

	boost::archive::text_iarchive inArchive(inFile);

	inArchive >> t1;

	std::cout << "\nGet ID : " << t1.getID();
	std::cout << "\nGet First Name : " << t1.getFirstname();
	std::cout << "\nGet First course : " << t1.getCourses()[1];


	



	return 0;
}