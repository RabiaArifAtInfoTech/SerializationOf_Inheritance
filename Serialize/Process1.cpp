#include<iostream>
#include<string.h>
#include<map>
#include<vector>

#include<fstream>

#include<boost/archive/text_iarchive.hpp>
#include<boost/archive/text_oarchive.hpp>

#include<boost/serialization/vector.hpp>
#include<boost/serialization/nvp.hpp>

#include"Classes/Author.cpp"
#include"Classes/Book.cpp"


class Author;

class Book;

int main()
{
	std::ofstream ofsAuth("Author&BookDetail");
	Book book1("BOOK1", 100, 2023, "\"New Book to be written\"\n");
	Book book2("BOOK2", 101, 2023, "\"New Book2 to be written\"");
	Book book3("BOOK3", 303, 20223, "\"New Book333 to be written\"");
	//Book book4("BOOK4", 444, 2024, "\"New Book444 to be written\"");


	Author author1("Author1");


	author1.setBookID(book1->getISBN());
	author1.setBookID(book2->getISBN());
	author1.setBookID(book3->getISBN());
	author1.setBookID(book4->getISBN());

	{
		boost::archive::text_oarchive oaAuth(ofsAuth);
		oaAuth << author1 << book1 << book2 << book3 << book4;
	}

	std::cout << author1.getName();

	std::cout << "\n\nGet Author's 2nd book ID: " << (author1.getBookIDs())[1];
	std::cout << "\nTotal number of books written by this Author: " << (author1.getCounter());

	return 0;
}