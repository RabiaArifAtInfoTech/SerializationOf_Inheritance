//#ifndef Book
//#define Book

/* Your function statement here */

#include<iostream>
#include<string.h>
#include<map>
#include<vector>

#include<fstream>

#include<boost/archive/text_iarchive.hpp>
#include<boost/archive/text_oarchive.hpp>

#include<boost/serialization/vector.hpp>
#include<boost/serialization/nvp.hpp>

class Book {

private:
	friend class boost::serialization::access;

	template<class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& BOOST_SERIALIZATION_NVP(bookTitle);
		ar& BOOST_SERIALIZATION_NVP(ISBN);
		ar& BOOST_SERIALIZATION_NVP(publishYear);
		ar& BOOST_SERIALIZATION_NVP(bookDetail);
	}
	std::string bookTitle;
	int ISBN;
	int publishYear;
	std::string bookDetail;
public:
	Book()
	{
		std::cout << "\nDefault Constructor of Book called";
	}
	Book(std::string bTitle, int ID, int year, std::string detail)
	{

		std::cout << "\nConstructor of Book called";

		bookTitle = bTitle;
		ISBN = ID;
		publishYear = year;
		bookDetail = detail;

	}
	int getPublishyear()
	{
		return publishYear;
	}
	int getISBN()
	{
		return ISBN;
	}
	std::string getBookTitle()
	{
		return bookTitle;
	}
	std::string getBookDetail()
	{
		return bookDetail;
	}
	Book& operator*()
	{
		return *this;

	}
	Book* operator->()
	{
		return this;
	}
	~Book()
	{
		std::cout << "\nDestructor of Book called\n";
	}
};


//#endif
