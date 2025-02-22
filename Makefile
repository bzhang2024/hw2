CXX=g++
CXXFLAGS=-g -Wall -std=c++11
# Uncomment for parser DEBUG
#DEFS=-DDEBUG

OBJS=amazon.o user.o db_parser.o product.o product_parser.o util.o book.o clothing.o movie.o mydatastore.o 

all: amazon

amazon: $(OBJS)
    $(CXX) $(CXXFLAGS) $(DEFS) -o $@ $(OBJS)

amazon.o: amazon.cpp db_parser.h datastore.h product_parser.h book.h clothing.h movie.h mydatastore.h 
    $(CXX) $(CXXFLAGS) $(DEFS) -c $< -o $@
user.o: user.cpp user.h 
    $(CXX) $(CXXFLAGS) $(DEFS) -c $< -o $@
db_parser.o: db_parser.cpp db_parser.h product.h product_parser.h user.h datastore.h 
    $(CXX) $(CXXFLAGS) $(DEFS) -c $< -o $@
product.o: product.cpp product.h 
    $(CXX) $(CXXFLAGS) $(DEFS) -c $< -o $@
product_parser.o: product_parser.cpp product_parser.h product.h 
    $(CXX) $(CXXFLAGS) $(DEFS) -c $< -o $@
util.o: util.cpp util.h
    $(CXX) $(CXXFLAGS) $(DEFS) -c $< -o $@

book.o: book.cpp book.h
    $(CXX) $(CXXFLAGS) $(DEFS) -c $< -o $@
clothing.o: clothing.cpp clothing.h
    $(CXX) $(CXXFLAGS) $(DEFS) -c $< -o $@
movie.o: movie.cpp movie.h
    $(CXX) $(CXXFLAGS) $(DEFS) -c $< -o $@

mydatastore.o: mydatastore.cpp mydatastore.h datastore.h
    $(CXX) $(CXXFLAGS) $(DEFS) -c $< -o $@

clean:
    rm -f *.o amazon