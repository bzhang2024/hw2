#include "book.h"
#include "product.h"

using namespace std; 

Book::Book(const string category, const string name, double price, int qty, string isbn, string author) :
    Product(category, name, price, qty), isbn(isbn), author(author)
{

}

Book::~Book(){

}

set<string> Book::keywords() const{

    //set<string> bookSet = {isbn, author, name_}; 
    set<string> bookSet1 = parseStringToWords(isbn);
    set<string> bookSet2 = parseStringToWords(author);
    set<string> bookSet3 = parseStringToWords(name_);

    set<string> bookSet; 
    bookSet.insert(bookSet1.begin(), bookSet1.end());
    bookSet.insert(bookSet2.begin(), bookSet2.end());
    bookSet.insert(bookSet3.begin(), bookSet3.end());

    return bookSet; 
}

string Book::displayString() const {
    string strBook = name_ + "/n" + 
        "Author: " + author + " ISBN: " + isbn + "/n" + 
        to_string(price_) + " " + to_string(qty_) + " left.";
    return strBook;
}

string Book::getISBN() const {
    return isbn; 
}

string Book::getAuthor() const {
    return author;
}