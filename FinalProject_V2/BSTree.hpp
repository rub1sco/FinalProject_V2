//To be used in conjunction with BSTree.h and Node.h
//When you modify this, please add your name and list any changes that you made
//A few member functions have been left blank so you, the student can implemement

/*Template Directions: #include "BSTREEInt.hpp"
but do NOT compile it (or add it to the project)*/
#include "BSTree.h"
#include <queue>


// Constructor
template <typename DATATYPE, typename KEYTYPE>
BSTree<DATATYPE, KEYTYPE>::BSTree() {
	root = nullptr;
    treeSize = 0;
    
}

template <typename DATATYPE, typename KEYTYPE>
BSTree<DATATYPE, KEYTYPE>::BSTree(DATATYPE& _node){
    root = _node;
    treeSize = 1;
}

// Destructor
template <typename DATATYPE, typename KEYTYPE>
BSTree<DATATYPE, KEYTYPE>::~BSTree() {
    if (root !=nullptr)
        freeNode(root);
    cout << "Destructor called" << endl;
}

// Free the node
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::freeNode(Node<DATATYPE, KEYTYPE> * leaf)
{

    //if the root is the leaf, delete that leaf
    if (root == leaf){
        delete root;
        root = nullptr;
        treeSize = 0;
        return;
        
    }
    //if the leaf does not == null pointer, check left and right branches recurrsively.
    if(leaf != nullptr){
        //recursive call of the leaf's left
        if(leaf -> Left() != nullptr){
            freeNode(leaf -> Left());
        }
        //recursive call of the leaf's right
        if(leaf -> Right() != nullptr){
            freeNode(leaf -> Right());
        }
        
        //now delete the leaf
        delete leaf;
        leaf = nullptr;
     
    }
   

}

// Add a node
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::addNode(KEYTYPE key, DATATYPE &data)
{
	if (Root() == nullptr)
	{
		Node<DATATYPE, KEYTYPE> * newNodePtr = new Node<DATATYPE, KEYTYPE>;
		newNodePtr->setKey(key);
		newNodePtr->setData(data);
		root = newNodePtr;
		root->setParent(root);
        treeSize++;
	}
	else
		addNode(key, root, data);
}

// Add a node (private)         **Edited by Tom L.**
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::addNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * leaf, DATATYPE& data) {
    
    //if key is less than the root key, insert as left child
    if(key < leaf -> Key()){
        //if left node is empty, insert node.
        if (leaf -> Left() == nullptr){
            Node<DATATYPE,KEYTYPE>* LeftChild = new Node<DATATYPE,KEYTYPE>;
            LeftChild -> setData(data);
            LeftChild -> setKey(key);
            leaf -> setLeft(LeftChild);
            LeftChild -> setParent(leaf);
        }
        else{
            //if left child is not empty, calls overloaded InsertNode function
            addNode(key, leaf -> Left(), data);
        }
    }
    else{
        //if right node is empty, insert as right child
        if (leaf -> Right() == nullptr){
            Node<DATATYPE,KEYTYPE>* RightChild = new Node<DATATYPE,KEYTYPE>;
            RightChild -> setData(data);
            RightChild -> setKey(key);
            leaf -> setRight(RightChild);
            RightChild -> setParent(leaf);
        }
        else{
            //if right child is not empty, calls overloaded InsertNode function
            addNode(key, leaf -> Right(), data);
        }
    }
}

template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::findNode(KEYTYPE key)
{
	return findNode(key, root);
}

// Find a node          **modified by Tom L.
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::findNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * node)
{
    // trap nullptr first in case we've hit the end unsuccessfully.
    if (node == nullptr){
        return nullptr;
    }
    //base case
    else if (key == node -> Key()){
        return node;
    }
    //searches left branch recurrsively
    else if(key < node -> Key()){
        Node<GeneralData, string>* temp = new Node<GeneralData, string>;
         temp = findNode(key, node -> Left());
        return temp;
    }
    //searches right branch recurrsively
    else if (key > node -> Key()){
        Node<GeneralData, string>* temp = new Node<GeneralData, string>;
        temp = findNode(key, node -> Right());
        
        return temp;
        
    }
    
    
    return node;
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::printInorder()
{
	printInorder(root);
}

// prints out the tree's nodes using inorder ordering
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::printInorder(Node<DATATYPE, KEYTYPE> * node)
{
	// base case
    if(node == nullptr)
        return;
    
    // recurse to left child
    printInorder(node->Left());
    
    // print node key
    cout << node->Key() << endl;
    
    // recurse to right child
    printInorder(node->Right());
}

// creates an inorder queue of the tree's nodes' data       **modified by Max M.
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::inorderQueue(Node<DATATYPE, KEYTYPE> * node, queue<DATATYPE> &heapQueue){
    
    // base case
    if(node == nullptr)
        return;
    
    // recurse to left child
    inorderQueue(node->Left(), heapQueue);
    
    // add Data to queue
    heapQueue.push(node->Data());
    
    // recurse to right child
    inorderQueue(node->Right(), heapQueue);
}


//Prints one Actor node's info  Need to expand for other tree info
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::print(ostream & out, const DATATYPE & data)
{
    //TODO this should be expandable for other trees?
    out << data.Year << endl;
    out << data.Name << endl;
  
    out << data.Award << endl;
    out << data.Film << endl;
//    out << data << endl;
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::deleteNode(KEYTYPE key)
{
	setRoot(deleteNode(Root(), key));
}

//deleteNode (Private)
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::deleteNode(Node<DATATYPE, KEYTYPE> * aRoot,KEYTYPE value)
{
   
	/* Given a binary search tree and a key, this function deletes the key
	and returns the new root */
	
	// base case
	if (aRoot == nullptr) return aRoot;

	// If the key to be deleted is smaller than the aRoot's key,
	// then it lies in left subtree
	if (value < aRoot->Key())
		aRoot->setLeft(deleteNode(aRoot->Left(), value));

	// If the key to be deleted is greater than the root's key,
	// then it lies in right subtree
	else if (value > aRoot->Key())
		root->setRight(deleteNode(aRoot->Right(), value));

	// if key is same as root's key, then This is the node
	// to be deleted
	else
	{
		// node with only one child or no child
		if (aRoot->Left() == nullptr)
		{
			Node<DATATYPE, KEYTYPE> *temp = aRoot->Right();
			delete aRoot;	
			return temp;
		}
		else if (aRoot->Right() == nullptr)
		{
			Node<DATATYPE, KEYTYPE> *temp = aRoot->Left();
			delete aRoot;
			return temp;
		}

		// node with two children: Get the inorder successor (smallest
		// in the right subtree)
		Node<DATATYPE, KEYTYPE> * temp = min(aRoot->Right());

		// Copy the inorder successor's content to this node
		aRoot->setKey(temp->Key());
		aRoot->setData(temp->Data());

		// Delete the inorder successor
		aRoot->setRight(deleteNode(aRoot->Right(), temp->Key()));
	}
	return aRoot;
}


// Find the node with min key
// Traverse the left sub-BSTree recursively
// till left sub-BSTree is empty to get min
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::min(Node<DATATYPE, KEYTYPE> * node)
{
	Node<DATATYPE, KEYTYPE> * current = node;

	/* loop down to find the leftmost leaf */
	while (current->Left() != nullptr)
		current = current->Left();

	return current;
}

// Find the node with max key
// Traverse the right sub-BSTree recursively
// till right sub-BSTree is empty to get max
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::max(Node<DATATYPE, KEYTYPE> * node)
{
	Node<DATATYPE, KEYTYPE> * tempNode = node;
	if (node == nullptr)
		tempNode = nullptr;
	else if (node->Right())
		tempNode = max(node->Right());
	else
		tempNode = node;

	return tempNode;
}


// **Added by Tom L.... Not functioning with Multiple datatypes... Broke into two functions per Tree
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE,KEYTYPE>::ReadCSVFile(string filename){
    //initializing variables
    std::ifstream infile;
    double _Rating = 0.0;
    int _Year = 0, _Nominations = 0, _Duration = 0, _MetaCritic = 0;
    bool _Winner = 0;
    string _Award,_Name, _Film, _Genre1, _Genre2, _Release, _Synopsis;

    //opening file
    infile.open(filename);

    //checks to see if file is open, provides simple error message
    if(!infile.is_open()){cout << "Error opening file." << endl;}

    //this gets the first line of the csv file and "trashes" it
    getline(infile, _Award,'\n');
    
    if(filename == "actor-actress.csv"){
        //reads until end of file.
        while (!infile.eof()) {
            infile >> _Year;
            infile.ignore();
            getline(infile,_Award,',');
            infile >> _Winner;
            infile.ignore();
            getline(infile,_Name,',');
            getline(infile,_Film,'\n');
            GeneralData* newEntry = new GeneralData(_Year, _Award, _Winner, _Name, _Film);
            addNode(_Name, *newEntry);
        }
    }
    else if (filename == "pictures.csv"){
        while(!infile.eof()){
            getline(infile, _Name, ',');
            infile >> _Year;
            infile >> _Nominations;
            infile >> _Rating;
            infile >> _Duration;
            infile.ignore();
            getline(infile, _Genre1, ',');
            getline(infile, _Genre2, ',');
            getline(infile, _Release, ',');
            infile >> _MetaCritic;
            infile.ignore();
            getline(infile, _Synopsis, '\n');

            GeneralData2* newEntry = new GeneralData2(_Name, _Year, _Nominations, _Rating, _Duration, _Genre1, _Genre2, _Release, _MetaCritic, _Synopsis);

//            addNode(_Name, *newEntry);

        }
        infile.close();
        return;
    }
    infile.close();
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE,KEYTYPE>::ReadActorCSVFile(string filename){
    //initializing variables
    std::ifstream infile;
    int _Year = 0;
    bool _Winner = 0;
    string _Award,_Name, _Film, _Genre1, _Genre2, _Release, _Synopsis;
    
    //opening file
    infile.open(filename);
    
    //checks to see if file is open, provides simple error message
    if(!infile.is_open()){cout << "Error opening file." << endl;}
    
    //this gets the first line of the csv file and "trashes" it
    getline(infile, _Award,'\n');
    //reads until end of file.
    while (!infile.eof()) {
        infile >> _Year;
        infile.ignore();
        getline(infile,_Award,',');
        infile >> _Winner;
        infile.ignore();
        getline(infile,_Name,',');
        getline(infile,_Film,'\n');
        GeneralData* newEntry = new GeneralData(_Year, _Award, _Winner, _Name, _Film);
        addNode(_Name, *newEntry);
        treeSize++;
    }
    infile.close();
}

//Function is used by the Picture tree.. TODO, merge seperate READCSV files into one function... currently, there is an error with datatype in the combined when trying to add
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE,KEYTYPE>::ReadPictureCSVFile(string filename){
    //initializing variables
    std::ifstream infile;
    double _Rating = 0.0;
    int _Year = 0, _Nominations = 0, _Duration = 0, _MetaCritic = 0;
    string _Award,_Name, _Film, _Genre1, _Genre2, _Release, _Synopsis;
    
    //opening file
    infile.open(filename);
    
    //checks to see if file is open, provides simple error message
    if(!infile.is_open()){cout << "Error opening file." << endl;}
    
    //this gets the first line of the csv file and "trashes" it
    getline(infile, _Award,'\n');
            while(!infile.eof()){
                getline(infile, _Name, ',');
                
                infile >> _Year;
                infile.ignore();
                infile >> _Nominations;
                infile.ignore();
                infile >> _Rating;
                infile.ignore();
                infile >> _Duration;
                infile.ignore();
                getline(infile, _Genre1, ',');
                getline(infile, _Genre2, ',');
                getline(infile, _Release, ',');
                infile >> _MetaCritic;
                
                //handles if there are blank values in MetaCritic value 
                if (_MetaCritic == NULL) {_MetaCritic = 0; infile.clear();}
                infile.ignore();
                getline(infile, _Synopsis, '\n');
    
               
                GeneralData2* newEntry = new GeneralData2(_Name, _Year, _Nominations, _Rating, _Duration, _Genre1, _Genre2, _Release, _MetaCritic, _Synopsis);
    
                addNode(_Name, *newEntry);
                treeSize++;
    
            }
            infile.close();

}

// sorts tree based on a given sort type            **modified by Max M.
// second parameter:
//  'a' to sort by year
//  'b' to sort by award
//  'c' to sort by name
//  'd' to sorty by film
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE,KEYTYPE>::SortTree(Node<DATATYPE, KEYTYPE> *node, char sortType)
{
    // create queue to store heap
    queue<DATATYPE> tempQueue;
    
    // create heap
    inorderQueue(node, tempQueue);
    
    //TODO this deletes the tempQueue tree and sets tempQueue to nullptr...
//    freeNode(tempQueue);
//    tempQueue = nullptr;
    
    // build new tree using key type selection
    switch(sortType){
        case 'a': //sorts by year
            while(!tempQueue.empty()){
                addNode(to_string(tempQueue.front().Year), tempQueue.front());
                tempQueue.pop();
            }
            break;
        case 'b': //sorts by award
            while(!tempQueue.empty()){
                addNode(tempQueue.front().Award, tempQueue.front());
                tempQueue.pop();
            }
            break;
        case 'c': //sorts by name
            while(!tempQueue.empty()){
                addNode(tempQueue.front().Name, tempQueue.front());
                tempQueue.pop();
            }
            break;
        case 'd': //sorts by film
            while(!tempQueue.empty()){
                addNode(tempQueue.front().Film, tempQueue.front());
                tempQueue.pop();
            }
            break;
    }
    
    // print new tree
//    printInorder();
    
    
    return;
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE,KEYTYPE>::DepthFirstSearch(string _SearchField){
    if(root != nullptr){
        DepthFirstSearch(this, visited);
    }
    
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE,KEYTYPE>::DepthFirstSearch(const BSTree<DATATYPE, KEYTYPE> &Tree, int index,vector<bool> &visited){
    
    visited[index] = true;
    

    
}
