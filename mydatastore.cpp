#include <iostream>
#include <string>
#include <functional> 
#include <algorithm>

#include "mydatastore.h"
#include "datastore.h"
#include "product.h"
#include "book.h"
#include "clothing.h"
#include "movie.h"
#include "util.h"

using namespace std; 

MyDataStore::MyDataStore(){
    
}

MyDataStore::~MyDataStore(){
    
}

void MyDataStore::addProduct(Product* p){
    products.push_back(p);
}
void MyDataStore::addUser(User* u){
    users.push_back(u);
}
vector<Product*> MyDataStore::search(vector<string>& terms, int type){ //type: 0 = and, 1 = or
    /*
    iterate through product list
    for AND:
        check if all terms are in product keywords
        - set intersection of 2 sets
        - if intersection size is equal to terms size:
        - add product to suitable products
    for OR:
        check if at least 1 term is in product keywords
        - set intersection of 2 sets
        - if intersection size is >= 1
        - add product to suitable products
    
    */
    vector<Product*> fittingProducts; 
    
    //convert terms to a set
    vector<string>::iterator it;
    set<string> termSet; 
    for (it = terms.begin(); it != terms.end(); ++it){
        termSet.insert(*it);
    }

    vector<Product*>::iterator pt; 
    for (pt = products.begin(); pt != products.end(); ++pt){
        Product* product = *pt;
        set<string> keywords = product->keywords(); 

        set<string> intersection = setIntersection(termSet, keywords); 
        if (type){ //OR
            if (intersection.size() >= 1){
                fittingProducts.push_back(product); 
            }
        }
        else { //AND
            if (intersection.size() == terms.size()){
                fittingProducts.push_back(product); 
            }
        }
    }

    return fittingProducts; 

}

void MyDataStore::dump(std::ostream& ofile){
    //TODO
    /* 
    - updated user info
    - updated product info
    */
    vector<User*>::iterator it; 
    for (it = users.begin(); it != users.end(); ++it){
        (*it)->dump(ofile); 
    }
    vector<Product*>::iterator pt; 
    for (pt = products.begin(); pt != products.end(); ++pt){
        (*pt)->dump(ofile); 
    }
}

void MyDataStore::addToCart(string username, Product* product){
    vector<User*>::iterator it;
    User* user;
    for (it = users.begin(); it != users.end(); ++it){
        if ((*it)->getName() == username){
            user = *it;
            break; 
        }
    }
    userData[user].push(product); 
    
}

void MyDataStore::viewCart(string username){
    //find user
    vector<User*>::iterator it;
    User* user;
    for (it = users.begin(); it != users.end(); ++it){
        if ((*it)->getName() == username){
            user = *it;
            break; 
        }
    }
    queue<Product*> temp = userData[user]; //creates a copy of the queue
    int itemNum = 1; 
    while (!temp.empty()) {
        cout << itemNum << " " << temp.front() << endl;
        temp.pop();
    }
}

void MyDataStore::buyCart(string username){
    vector<User*>::iterator it;
    User* user;
    for (it = users.begin(); it != users.end(); ++it){
        if ((*it)->getName() == username){
            user = *it;
            break; 
        }
    }
    /* 
    iterate through products in cart
    if item in stock AND user has enough money to purchase
    - stock-1
    - price of product deducted from user balance
    else
    - leave item in cart
    - move on to next product
     */
    queue<Product*> *temp = &(userData[user]);
    for (int i = 0; i < temp->size(); i++) {
        Product* product = temp->front(); 
        if (product->getQty() > 0 || user->getBalance() > product->getPrice()){ //in stock and enough money
            user->deductAmount(product->getPrice());
            product->subtractQty(1); 
            temp->pop(); //remove from cart
        }
    }
}

bool MyDataStore::isUserValid(string username){
    vector<User*>::iterator it;
    for (it = users.begin(); it != users.end(); ++it){
        if ((*it)->getName() == username){
            return true; //username is in users
        }
    }
    return false; 
}


//It might be a good idea to have one member function in this class that corresponds to and performs each command from the menu options.