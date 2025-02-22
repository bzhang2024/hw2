#ifndef BOOK_H
#define BOOK_H   
#include "product.h"
#include "util.h"

class Book : public Product {
    public:
        Book(const std::string category, const std::string name, double price, int qty,
            const std::string isbn, const std::string author);
        ~Book();
        std::set<string> keywords() const;
        std::string displayString() const; 
        bool isMatch(std::vector<std::string>& searchTerms) const;
        std::string displayString() const; 


        std::string getISBN() const; 
        std::string getAuthor() const;
    private:
        std::string isbn;
        std::string author; 
};
#endif


/* inherited data members:
std::string name_;
double price_;
int qty_;
std::string category_; */