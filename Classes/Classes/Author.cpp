
#include<iostream>
#include<string.h>
#include<map>
#include<vector>

#include<fstream>

#include<boost/archive/text_iarchive.hpp>
#include<boost/archive/text_oarchive.hpp>

#include<boost/serialization/vector.hpp>
#include<boost/serialization/nvp.hpp>

#include <book>


class Author {
private:


	friend class boost::serialization::access;



	std::string name;
	std::vector<int> bookID;
	int* IDCounter = new int(0);


	template<class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& name;

		ar& (*IDCounter);
		ar& bookID;
	}

public:
	Author()
	{};
	Author(std::string AuthName)
	{
		std::cout << "\nConstructor of Author called";

		name = AuthName;
		IDCounter = new int(0);
	}
	Author(Author& newAuth)
	{
		std::cout << "\nCopy Constructor of Author called";

		name = newAuth.name;

		IDCounter = new int(0);
		IDCounter = newAuth.IDCounter;

		for (auto itr = newAuth.bookID.begin(); itr != newAuth.bookID.end(); itr++) {
			bookID.push_back(*itr);
			(*IDCounter)++;
		}

	}
	void setBookID(int id)
	{
		bookID.push_back(id);
		(*IDCounter)++;
	}
	std::vector<int> getBookIDs()
	{
		if ((*IDCounter) == 0)
		{
			std::cout << "\n" << this->getName() << " has no books yet";
			return std::vector<int>();
		}
		else
			return bookID;
	}
	std::vector<int> getbookids()
	{
		return bookID;
	}
	int getCounter()
	{
		return *IDCounter;
	}
	std::string getName()
	{
		std::cout << "\n\nSize of IDCounter: " << this->getCounter() << "\n";
		return name;
	}
	Author& operator*()
	{
		return *this;

	}
	Author* operator->()
	{
		return this;
	}
	~Author() {
		std::cout << "\n\nDestructor of Author called\n\n";
	}

};

#endif