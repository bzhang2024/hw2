#ifndef CLOTHING_H
#define CLOTHING_H
#include "product.h"
#include "util.h"

class Clothing : public Product {
    public:
        Clothing(const std::string category, const std::string name, double price, int qty,
            const std::string size, const std::string brand);
        ~Clothing(); 
        std::set<std::string> keywords() const; //already inherited?
        std::string displayString() const; 
        bool isMatch(std::vector<std::string>& searchTerms) const;
        std::string displayString() const; 

        std::string getSize() const;
        std::string getBrand() const;
    private:
        std::string size;
        std::string brand;


};


#endif

/* inherited data members:
std::string name_;
double price_;
int qty_;
std::string category_; */