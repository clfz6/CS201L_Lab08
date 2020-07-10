//Cristian Lopez

#include "LibraryBook.h"

int main()
{
	string title, author, isbn, isbnsList, out_str;
	char quotemark = '"';
	ifstream fin("books.txt"), fin2("isbns.txt");
	ofstream fout("checkedout.csv");
	vector<string> checkedOutList;
	vector<string>::iterator iter;

	if (fin.fail() || fin2.fail())
	{
		cout << "Input file failed to open" << endl;
	}
	if (fout.fail())
	{
		cout << "Output file faile to open" << endl;
	}

	while (fin.good())
	{
		//reads in from books.txt and creates an object with the parameters
		getline(fin, title);
		getline(fin, author);
		getline(fin, isbn);
		LibraryBook myBook(title, author, isbn);

		//reads in from isbns.txt and pushes the list into a vector
		while (fin2.good())
		{
			fin2 >> isbnsList;
			checkedOutList.push_back(isbnsList);
		}

		//iterates through the vector to check books in and out
		for (iter = checkedOutList.begin(); iter != checkedOutList.end(); ++iter)
		{
			if (myBook.getISBN() == *iter)
			{
				if (myBook.isCheckedOut() == true)
				{
					myBook.checkIn();
				}
				else
				{
					myBook.checkOut();
				}
			}
		}

		//if a book is checked out at the end of the list, this will output the info to checkedout.csv
		if (myBook.isCheckedOut() == true)
		{
			out_str = quotemark + myBook.getTitle() + quotemark + "," + quotemark + myBook.getAuthor()
				+ quotemark + "," + quotemark + myBook.getISBN() + quotemark;
			fout << out_str << endl;
		}
	}

	//closing all the opened files
	fin.close();
	fin2.close();
	fout.close();

	return 0;
}