#include "LibraryBook.h"

//default constructor
LibraryBook::LibraryBook()
{
	title = "";
	author = "";
	isbn = "";
	checkedOut = false;
}

//constructor
LibraryBook::LibraryBook(string title, string author, string ISBN)
{
	this->title = title;
	this->author = author;
	isbn = ISBN;
	checkedOut = false;
}

//getters
string LibraryBook::getTitle()
{
	return this->title;
}
string LibraryBook::getAuthor()
{
	return this->author;
}
string LibraryBook::getISBN()
{
	return this->isbn; 
}

//setters
void LibraryBook::checkOut()
{
	checkedOut = true;
}
void LibraryBook::checkIn()
{
	checkedOut = false;
}

bool LibraryBook::isCheckedOut()
{
	if (checkedOut == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}