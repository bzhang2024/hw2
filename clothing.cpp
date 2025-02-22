#include "clothing.h"
#include "product.h"

using namespace std; 

Clothing::Clothing(const string category, const string name, double price, int qty, string brand, string size) :
    Product(category, name, price, qty), brand(brand), size(size)
{

}

Clothing::~Clothing(){

}

set<string> Clothing::keywords() const{
    //set<string> clothingSet = {name_, brand, size}; 

    set<string> clothingSet1 = parseStringToWords(brand);
    set<string> clothingSet2 = parseStringToWords(size);
    set<string> clothingSet3 = parseStringToWords(name_);

    set<string> clothingSet; 
    clothingSet.insert(clothingSet1.begin(), clothingSet1.end());
    clothingSet.insert(clothingSet2.begin(), clothingSet2.end());
    clothingSet.insert(clothingSet3.begin(), clothingSet3.end());
    
    return clothingSet; 
}

string Clothing::displayString() const {
    string strBook = name_ + "/n" + 
        "Size: " + size + " Brand: " + brand + "/n" + 
        to_string(price_) + " " + to_string(qty_) + " left.";
    return strBook;
}

string Clothing::getBrand() const {
    return brand;
}

string Clothing::getSize() const {
    return size; 
}