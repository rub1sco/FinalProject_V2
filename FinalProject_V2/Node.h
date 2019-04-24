//To be used in conjunction with BSTree.h and BSTree.hpp
//If you modify this, please add your name and list any changes that you made
#ifndef NODE_
#define NODE_
#include <iostream>
#include <string>
using namespace std;

// A tree node class for ints

//Placeholder for a composite data type

//Datatype for Actor Tree
struct GeneralData
{
    int Year;
    string Award;
    bool Winner;
    string Name;
    string Film;
    GeneralData(){
        Year = 0;
        Award = "";
        Winner = "";
        Name = "";
        Film = "";
    }
    GeneralData(int _year, string _award, bool _winner, string _name, string _film){
        Year = _year;
        Award = _award;
        Winner = _winner;
        Name = _name;
        Film = _film;
    }
};

//DataType for Pictures Tree
struct GeneralData2{

    string Name;
    int Year;
    int Nominations;
    double Rating;
    int Duration;
    string Genre1;
    string Genre2;
    string Release;
    int MetaCritic;
    string Synopsis;
    
    //constructors
    GeneralData2(){
        Name = "";
        Year = 0;
        Nominations = 0;
        Rating =  0.0;
        Duration = 0;
        Genre1 = "";
        Genre2 = "";
        Release = "";
        MetaCritic = 0;
        Synopsis = "";
    }
    GeneralData2(string _Name, int _Year, int _Nominations, double _Rating, int _Duration, string _Genre1, string _Genre2, string _Release, int _MetaCritic, string _Synopsis){
        Name = _Name;
        Year = _Year;
        Nominations = _Nominations;
        Rating = _Rating;
        Duration = _Duration;
        Genre1 = _Genre1;
        Genre2 = _Genre2;
        Release = _Release;
        MetaCritic = _MetaCritic;
        Synopsis = _Synopsis;
    }
    
};


//Bina*ry Tree Node
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
    KEYTYPE Key() { return key; };
	DATATYPE Data() { return data; }
    Node<DATATYPE, KEYTYPE> * Left() { return left; };
    Node<DATATYPE, KEYTYPE> * Right() { return right; };
    Node<DATATYPE, KEYTYPE> * Parent() { return parent; };
};

#endif
