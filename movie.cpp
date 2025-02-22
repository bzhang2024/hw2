#include "movie.h"
#include "product.h"

using namespace std;

Movie::Movie(const string category, const string name, double price, int qty, const string genre, const string rating) :
    Product(category, name, price, qty), genre(genre), rating(rating)
{

}

Movie::~Movie(){

}

set<string> Movie::keywords() const{
    //setmovie<string> movieSet = {name_, genre, rating}; 
    set<string> movieSet1 = parseStringToWords(genre);
    set<string> movieSet2 = parseStringToWords(rating);
    set<string> movieSet3 = parseStringToWords(name_);

    set<string> movieSet; 
    movieSet.insert(movieSet1.begin(), movieSet1.end());
    movieSet.insert(movieSet2.begin(), movieSet2.end());
    movieSet.insert(movieSet3.begin(), movieSet3.end());

    return movieSet; 
}

string Movie::displayString() const {
    string strBook = name_ + "/n" + 
        "Genre: " + genre + " Rating: " + rating + "/n" + 
        to_string(price_) + " " + to_string(qty_) + " left.";
    return strBook;
}

string Movie::getGenre() const {
    return genre;
}

string Movie::getRating() const {
    return rating;
}