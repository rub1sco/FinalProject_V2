//To be used in conjunction with BSTree.h and Node.h
//When you modify this, please add your name and list any changes that you made
//A few member functions have been left blank so you, the student can implemement

/*Template Directions: #include "BSTREEInt.hpp"
but do NOT compile it (or add it to the project)*/
#include "BSTree.h"


// Constructor
template <typename DATATYPE, typename KEYTYPE>
BSTree<DATATYPE, KEYTYPE>::BSTree() {
	root = nullptr;
    
}
template <typename DATATYPE, typename KEYTYPE>
BSTree<DATATYPE, KEYTYPE>::BSTree(DATATYPE& _node){
    root = _node;
}

// Destructor
template <typename DATATYPE, typename KEYTYPE>
BSTree<DATATYPE, KEYTYPE>::~BSTree() {
    if (root !=nullptr)
        freeNode(root);
}

// Free the node
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::freeNode(Node<DATATYPE, KEYTYPE> * leaf)
{
	//Student must fill in
	//if the root is the leaf, delete that leaf
	// otherwise if the leaf is not null
		//recursive call of the leaf's left
		//recursive call of the leaf's right
		//now delete the leaf
    
    if (leaf == root){delete leaf; leaf = nullptr;}
    
    else if (leaf < root){
//        deleteNode(leaf, root-> Left() -> key);
//        deleteNode(leaf -> key);                      //TODO not sure if I should call delete or what to do with "free node" dupe of delete used in deestructor?
        freeNode(leaf -> Left());
    }
    else if (leaf > root) {
//        deleteNode(leaf, root -> Right() -> key);
//        deleteNode(leaf -> key);                      //TODO not sure if I should call delete or what to do with "free node" dupe of delete used in deestructor?
        freeNode(leaf -> Right());
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

	}
	else
		addNode(key, root, data);
}

// Add a node (private)         **Edited by Tom L.**
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::addNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * leaf, DATATYPE& data) {
    
    if(key == leaf -> Key()){
        //        cout << "value exists.." << endl; //Should we have error checking if key == root key? May cause duplicates.. right now it is unsorted. IE. Ruth Catterson 1929 and 1930.
        
        //TODO is this even necessary?
    }
    
    //if key is less than the root key, insert as left child
    if(key < leaf -> Key()){
        //if left node is empty, insert node.
        if (leaf -> Left() == nullptr){
            Node<DATATYPE,KEYTYPE>* LeftChild = new Node<DATATYPE,KEYTYPE>;
            LeftChild -> setData(data);
            LeftChild -> setKey(key);
            leaf -> setLeft(LeftChild);
            leaf -> setParent(leaf);            //TODO Fix.. not correct
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
            leaf -> setParent(leaf);               //TODO Fix.. not correct..use FindNode?
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

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::printInorder(Node<DATATYPE, KEYTYPE> * node)
{
	//Student must fill in.  Use recursive algorithm.
	//Note that this prints using an Inorder, Depth-first search
	//but you may want to do something else when "visiting" the node....
	//like moving visited data to another datastructure
	//Don't forget your base case!
    //TODO edit
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


// **Added by Tom L.
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE,KEYTYPE>::ReadCSVFile(string filename){
    //initializing variables
    std::ifstream infile;
    int _Year = 0;
    bool _Winner = 0;
    string _Award,_Name, _Film;

    //opening file
    infile.open(filename);

    //checks to see if file is open, provides simple error message
    if(!infile.is_open()){cout << "Error opening file." << endl;}

    //this gets the first line of the csv file and "trashes" it
    getline(infile, _Award,'\n');
    //reads until end of file.
    while (!infile.eof()) {
        //Year,Award,Winner,Name,Film
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
    
    infile.close();
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE,KEYTYPE>::SortTree(Node<DATATYPE, KEYTYPE> *node){
    

}
