//To be used in conjunction with BSTree.h and BSTree.hpp
//If you modify this, please add your name and list any changes that you made
#ifndef NODE_
#define NODE_
#include <iostream>
#include <string>
using namespace std;

// A tree node class for ints

//Placeholder for a composite data type


struct GeneralData
{
    int year;
    string Award;
    bool Winner;
    string Name;
    string Film;
    GeneralData(){
        year = 0;
        Award = "";
        Winner = "";
        Name = "";
        Film = "";
    }
    GeneralData(int _year, string _award, bool _winner, string _name, string _film){
        year = _year;
        Award = _award;
        Winner = _winner;
        Name = _name;
        Film = _film;
    }
};


//Binary Tree Node
template <typename DATATYPE, typename KEYTYPE>
class Node {
private:
    string key; //This should be the datatype of your key...sorted field in tree
    DATATYPE data;
    Node<DATATYPE, KEYTYPE> * left;
    Node<DATATYPE, KEYTYPE> * right;
    Node<DATATYPE, KEYTYPE> * parent;
public:
    Node() {left=nullptr; right=nullptr; parent = nullptr;};
    void setKey(KEYTYPE aKey) { key = aKey; };
	void setData(DATATYPE aData) { data = aData; }
    void setLeft(Node<DATATYPE, KEYTYPE> * aLeft) { left = aLeft; };
    void setRight(Node<DATATYPE, KEYTYPE> * aRight) { right = aRight; };
    void setParent(Node<DATATYPE, KEYTYPE> * aParent) { parent = aParent; };
    string Key() { return key; };
	GeneralData Data() { return data; }
    Node<DATATYPE, KEYTYPE> * Left() { return left; };
    Node<DATATYPE, KEYTYPE> * Right() { return right; };
    Node<DATATYPE, KEYTYPE> * Parent() { return parent; };
};

#endif
