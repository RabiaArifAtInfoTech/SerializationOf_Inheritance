#include<iostream>
#include<string.h>
#include<map>
#include<vector>

#include<fstream>

#include<boost/archive/text_iarchive.hpp>
#include<boost/archive/text_oarchive.hpp>

#include<boost/serialization/vector.hpp>
#include<boost/serialization/nvp.hpp>

#include"Classes/Author.h"
#include"Classes/Book.h"

class Author;

class Book;

int main()
{
	Author newAuth;
	Book newBook1;
	Book newBook2;
	Book newBook3;
	Book newBook4;
	{
		std::ifstream ifs("Author&BookDetail");
		boost::archive::text_iarchive ia(ifs);
		ia >> newAuth >> newBook1 >> newBook2 >> newBook3 >> newBook4;
	}
	std::cout << newAuth.getName();

	std::cout << "\n\nGet Author's 2nd book ID: " << (newAuth.getBookIDs())[0];
	std::cout << "\n\nGet Author's 2nd book ID: " << (newAuth.getBookIDs())[1];
	std::cout << "\n\nGet Author's 2nd book ID: " << (newAuth.getBookIDs())[2];
	std::cout << "\nTotal number of books written by this Author: " << (newAuth.getCounter());


	std::cout << "\n\nNewBook1 Title: " << newBook1.getBookTitle() << "\n";
	std::cout << "\nNewBook1 Number: " << newBook1.getISBN() << "\n";
	std::cout << "\nNewBook1 Year: " << newBook1.getPublishyear() << "\n";
	std::cout << "\nNewBook1 Detail: " << newBook1.getBookDetail() << "\n";

	std::cout << "\n\nNewBook2 Title: " << newBook2.getBookTitle() << "\n";
	std::cout << "\nNewBook2 Number: " << newBook2.getISBN() << "\n";
	std::cout << "\nNewBook2 Year: " << newBook2.getPublishyear() << "\n";
	std::cout << "\nNewBook2 Detail: " << newBook2.getBookDetail() << "\n";

	std::cout << "\n\nNewBook4 Title: " << newBook4.getBookTitle() << "\n";
	std::cout << "\nNewBook4 Number: " << newBook4.getISBN() << "\n";
	std::cout << "\nNewBook4 Year: " << newBook4.getPublishyear() << "\n";
	std::cout << "\nNewBook4 Detail: " << newBook4.getBookDetail() << "\n";


	return 0;
}