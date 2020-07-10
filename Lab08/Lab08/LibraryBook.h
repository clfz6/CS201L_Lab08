#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

using namespace std;

class LibraryBook
{
public:
	LibraryBook();
	LibraryBook(string title, string author, string ISBN);
	string getTitle();
	string getAuthor();
	string getISBN();
	void checkOut();
	void checkIn();
	bool isCheckedOut();
private:
	string title, author, isbn;
	bool checkedOut;
};
