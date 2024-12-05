#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>

using namespace std;

typedef struct elmBook *addressBook;
typedef struct Author *addressAuthor;
typedef struct Category *addressCategory;
typedef struct User *addressUser;


// Book Structure
struct elmBook {
    string title;
    addressAuthor author;
    addressCategory category;
    addressBook nextCategory;
    addressBook nextAuthor;
};

// Category Structure
struct Category {
    string name;
    addressBook bookHead;
    addressCategory next;
};

// Author Structure
struct Author {
    string name;
    addressBook bookHead;
    addressAuthor next;
};

// User Structure
struct User {
    string name;
    string userID;
    addressBook borrowedHead;
    addressUser next;
};



#endif // HEADER_H_INCLUDED
