#ifndef MOVIE_H
#define MOVIE_H
#include "product.h"
#include "util.h"

class Movie : public Product {
    public:
        Movie(const std::string category, const std::string name, double price, int qty,
            const std::string genre, const std::string rating);
        ~Movie();
        std::set<string> keywords() const;
        std::string displayString() const; 
        bool isMatch(std::vector<std::string>& searchTerms) const;
        std::string displayString() const; 

        std::string getGenre() const;
        std::string getRating() const;
    private:
        std::string genre;
        std::string rating;

};
#endif

/* inherited data members:
std::string name_;
double price_;
int qty_;
std::string category_; */