//To be used in conjunction with BSTree.h and BSTree.hpp
//If you modify this, please add your name and list any changes that you made
#ifndef NODE_
#define NODE_
#include <iostream>
#include <string>
using namespace std;

// A tree node class for ints

//Composite data type for BSTs
struct GeneralData
{
    int Year;
    string Award;
    bool Winner;
    string Name;
    string Film;
    int Nominations;
    double Rating;
    int Duration;
    string Genre1;
    string Genre2;
    string Release;
    int MetaCritic;
    string Synopsis;
    
    //constructors
    GeneralData(){
        Year = 0;
        Award = "";
        Winner = "";
        Name = "";
        Film = "";
        Nominations = 0;
        Rating =  0.0;
        Duration = 0;
        Genre1 = "";
        Genre2 = "";
        Release = "";
        MetaCritic = 0;
        Synopsis = "";
    }
    
    // for actor-actress tree
    GeneralData(int _year, string _award, bool _winner, string _name, string _film){
        Year = _year;
        Award = _award;
        Winner = _winner;
        Name = _name;
        Film = _film;
        Nominations = 0;
        Rating =  0.0;
        Duration = 0;
        Genre1 = "";
        Genre2 = "";
        Release = "";
        MetaCritic = 0;
        Synopsis = "";
    }
    
    // for pictures tree
    GeneralData(string _Film, int _Year, int _Nominations, double _Rating, int _Duration, string _Genre1, string _Genre2, string _Release, int _MetaCritic, string _Synopsis){
        Film = _Film;
        Year = _Year;
        Nominations = _Nominations;
        Rating = _Rating;
        Duration = _Duration;
        Genre1 = _Genre1;
        Genre2 = _Genre2;
        Release = _Release;
        MetaCritic = _MetaCritic;
        Synopsis = _Synopsis;
        Award = "";
        Winner = "";
        Name = "";
    }
    
    //overload << operator to print all non-empty fields
    friend ostream &operator<< (ostream &output, const GeneralData &_GD) {
        
        //If Genre1 is empty, print Actor Tree data
        if(_GD.Genre1 == ""){
            output << "Name: " << _GD.Name << endl
            << "Film: " << _GD.Film << endl
            << "Award: " << _GD.Award << endl;
            
            if(_GD.Winner == true)
                output << "Win: Yes " << endl;
            else
                output << "Win: No " << endl;
            
            output << "Year: " << _GD.Year << endl << endl;
        }
        
        // otherwise print Picture tree data NOTE: Does not print synopsis because that seemed obnoxious
        else{
            output << "Film: " << _GD.Film << endl
            << "Year: " << _GD.Year << endl
            << "Nominations: " << _GD.Nominations << endl
            << "Rating: " << _GD.Rating << endl
            << "Duration: " << _GD.Duration << " min" << endl
            << "Genre 1: " << _GD.Genre1 << endl
            << "Genre 2: " << _GD.Genre2 << endl
            << "Release: " << _GD.Release << endl
            << "MetaCritic: " << _GD.MetaCritic << endl << endl;
        }
            
        return output;
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
    KEYTYPE Key() { return key; };
	DATATYPE Data() { return data; }
    Node<DATATYPE, KEYTYPE> * Left() { return left; };
    Node<DATATYPE, KEYTYPE> * Right() { return right; };
    Node<DATATYPE, KEYTYPE> * Parent() { return parent; };
    
    void printData(){std::cout << data;};
};

#endif
