//To be used in conjunction with Node.h and BSTree<DATATYPE, KEYTYPE>.cpp
//If you modify this, please add your name and list any changes that you made
#ifndef BSTREEINT_H
#define BSTREEINT_H
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

#include "Node.h"




// Binary Search Tree class
template <typename DATATYPE, typename KEYTYPE>
class BSTree {
private:
    Node<DATATYPE, KEYTYPE> * root;
    void addNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * leaf, DATATYPE& data);
    Node<DATATYPE, KEYTYPE> * deleteNode(Node<DATATYPE, KEYTYPE> * node, KEYTYPE key);
    void freeNode(Node<DATATYPE, KEYTYPE> * leaf);
	void printInorder(Node<DATATYPE, KEYTYPE> * node);
    Node<DATATYPE, KEYTYPE> * findNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * node);
    int treeSize; //Note: Added this, didn't end up using it, left it in case it's useful later
    void DepthFirstSearch(BSTree<DATATYPE,KEYTYPE>const & Tree, int index,vector<bool> &visited);
    vector<bool> visited;

public:
    BSTree<DATATYPE, KEYTYPE>();
    BSTree<DATATYPE, KEYTYPE> (DATATYPE& _node);
    ~BSTree<DATATYPE, KEYTYPE>();
    Node<DATATYPE, KEYTYPE> * Root() { return root; }
    void setRoot(Node<DATATYPE, KEYTYPE> * _root) {root = _root;}
    void addNode(KEYTYPE key, DATATYPE &data);
	Node<DATATYPE, KEYTYPE> * findNode(KEYTYPE key);
	void printInorder();
	void print(ostream & out, const DATATYPE & data);
    void deleteNode(KEYTYPE key);
	Node<DATATYPE, KEYTYPE> * min(Node<DATATYPE, KEYTYPE> * node);
	Node<DATATYPE, KEYTYPE> * max(Node<DATATYPE, KEYTYPE> * node);
    
    //Added functions by Max M. and Tom L.
    void ReadCSVFile(string filename);
    void ReadActorCSVFile(string filename);
    void ReadPictureCSVFile(string filename);
    void inorderQueue(Node<DATATYPE, KEYTYPE> * node, queue<DATATYPE> &heapQueue);
    void SortTree(Node<DATATYPE, KEYTYPE>* node, char sortType);
    void DepthFirstSearch(string _SearchField);
    
};
#endif  //BST
