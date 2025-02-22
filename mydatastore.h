#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include "datastore.h"
#include <map>
#include <queue>

class MyDataStore : public DataStore {
    public:
        MyDataStore();
        ~MyDataStore();
        void addProduct(Product* p);
        void addUser(User* u);
        std::vector<Product*> search(std::vector<std::string>& terms, int type); //type: 0 = and, 1 = or
        void dump(std::ostream& ofile);

        void addToCart(std::string username, Product* product);
        void viewCart(std::string username);
        void buyCart(std::string username); 

        bool isUserValid(std::string username);
        
    private:
        std::map<User*, std::queue<Product*>> userData; 
        std::vector<Product*> products;
        std::vector<User*> users; 

};

#endif