///.............Serialization Example with Author and Book Classes...........


#include<iostream>
#include<string.h>
#include<map>
#include<vector>

#include<fstream>

#include<boost/archive/text_iarchive.hpp>
#include<boost/archive/text_oarchive.hpp>

#include<boost/serialization/vector.hpp>
#include<boost/serialization/nvp.hpp>

#include"Author.h"
#include"Book.h"


class Book;
class Author;



int main()
{
	std::ofstream ofsAuth("Author&BookDetail");
	Book book1("BOOK1", 100, 2023, "\"New Book to be written\"\n");
	Book book2("BOOK2", 101, 2023, "\"New Book2 to be written\"");
	Book book3("BOOK3", 303, 20223, "\"New Book333 to be written\"");
	Book book4("BOOK4", 444, 2024, "\"New Book444 to be written\"");


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