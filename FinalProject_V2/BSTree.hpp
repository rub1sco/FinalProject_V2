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
            //sets left child's Data
            LeftChild -> setData(data);
            //sets left child's Key
            LeftChild -> setKey(key);
            
            //sets leaf to left Child
            leaf -> setLeft(LeftChild);
            
            //sets left Child's parent to leaf
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
            //sets Right Child's data
            RightChild -> setData(data);
            
            //sets Right child key
            RightChild -> setKey(key);
            
            //sets leaf's right child to RightChild
            leaf -> setRight(RightChild);
            
            //Sets Right Child's Parent to leaf
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
    if(node->Key() != ""){ //ensures blank fields are not printed 
        cout << node->Key() << endl;
    }
    
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



template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::deleteNode(KEYTYPE key)
{
    deleteNode(root, key);
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
        
        //handles issues in regards to "_Name, Jr."
        if(_Name[0] == '"'){
            _Name.erase(0,1);
            string temp = _Name;
            string temp2;
            getline(infile, _Name, '"');
            _Name = temp + ", " + _Name;
            
            //error handles if Name has multiple """
            if(_Name[0] == '"'){
                //stores _Name as temp
                temp = _Name;
                //deletes first two chars of temp
                temp.erase(0,2);
                
                //creates stringstream variable of temp
                istringstream stringstream(temp);
                
                //parses _Name without """ in front, stops at "
                getline(stringstream, _Name, '"');
                //ignores ','
                stringstream.ignore();
                //reads rest of title
                getline(stringstream, temp2, '"');
                
                //adds the two strings together for full Name
                _Name = _Name + temp2;
                //ignores ','
                stringstream.ignore();
                //reads _Film info
                getline(stringstream, _Film, '\n');
            }
        }
        //if no erros, reads _Film
        getline(infile,_Film,'\n');
        

        //generates new General Data entry
        GeneralData* newEntry = new GeneralData(_Year, _Award, _Winner, _Name, _Film);
        
        //adds node to tree
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
    
            //reads in values of csv until end of file
            while(!infile.eof()){
                getline(infile, _Name, ',');
                _Name.erase(_Name.begin());
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
                if (_MetaCritic == NULL) {_MetaCritic = 0.0; infile.clear();}
                infile.ignore();
                getline(infile, _Synopsis, '\n');
                if(_Synopsis[0] == '7'){
                    
                    //creates a string stream of _Synopsis which has the error
                    istringstream stringstream(_Synopsis);
                    
                    //Parses _Rating from stringstream
                    stringstream >> _Rating;
                    
                    //ignores ','
                    stringstream.ignore();
                    
                    //parses _Duration
                    stringstream >> _Duration;
                    //ignores ','
                    stringstream.ignore();
                    
                    //gets genres and Release info with getline
                    getline(stringstream, _Genre1, ',');
                    getline(stringstream, _Genre2, ',');
                    getline(stringstream, _Release, ',');
                    
                    //parses metacritic info
                    stringstream >> _MetaCritic;
                    
                    //error handles if value is blank, fills in 0.0 if so.
                    if (_MetaCritic == NULL) {_MetaCritic = 0.0; stringstream.clear();}
                    stringstream.ignore();
                    //parses expected synopsis
                    getline(stringstream, _Synopsis, '\n');
                }
                
                //creates new GeneralData entry
                GeneralData* newEntry = new GeneralData(_Name, _Year, _Nominations, _Rating, _Duration, _Genre1, _Genre2, _Release, _MetaCritic, _Synopsis);
    
                //Adds node to tree
                addNode(_Name, *newEntry);
                treeSize++;
    
            }
            infile.close();

}


template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE,KEYTYPE>::SortTree(char sortType){
    //checks to ensure root is not null, then sorts
    if(root != nullptr){
        SortTree(root, sortType);
    }
}



// sorts tree based on a given sort type            **modified by Max M.
// second parameter:
//  'a' to sort by Year (actors)
//  'b' ''  ''  '' Film (actors)
//  'c' ''  ''  '' Name (actors)
//  'd' ''  ''  '' Award (actors)
//  'A' ''  ''  '' Year (pictures)
//  'B' ''  ''  '' Film (pictures)
//  'C' ''  ''  '' Nominations (pictures)
//  'D' ''  ''  '' Rating (pictures)
//  'E' ''  ''  '' Duration (pictures)
//  'F' ''  ''  '' Genre1 (pictures)
//  'G' ''  ''  '' Genre2 (pictures)
//  'H' ''  ''  '' Release (pictures)
//  'I' ''  ''  '' MetaCritic (pictures)
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE,KEYTYPE>::SortTree(Node<DATATYPE, KEYTYPE> *node, char sortType)
{
    // create queue to store heap
    queue<DATATYPE> tempQueue;
    
    // create heap
    inorderQueue(node, tempQueue);
    
    // deletes original tree: currently just sets root to nullptr, does not actually free all nodes
    freeNode(this->Root());
    
    // build new tree from heap using key type selection
    switch(sortType){
        case 'a': //sorts by year
            while(!tempQueue.empty()){
                addNode(to_string(tempQueue.front().Year), tempQueue.front());
                tempQueue.pop();
            }
            break;
        case 'A': //sorts by year
            while(!tempQueue.empty()){
                addNode(to_string(tempQueue.front().Year), tempQueue.front());
                tempQueue.pop();
            }
            break;
        case 'b': //sorts by film
            while(!tempQueue.empty()){
                addNode(tempQueue.front().Film, tempQueue.front());
                tempQueue.pop();
            }
            break;
        case 'B': //sorts by film
            while(!tempQueue.empty()){
                addNode(tempQueue.front().Film, tempQueue.front());
                tempQueue.pop();
            }
            break;
        case 'c': //sorts by name
            while(!tempQueue.empty()){
                addNode(tempQueue.front().Name, tempQueue.front());
                tempQueue.pop();
            }
            break;
        case 'd': //sorts by award
            while(!tempQueue.empty()){
                addNode(tempQueue.front().Award, tempQueue.front());
                tempQueue.pop();
            }
            break;
        case 'C': //sorts by Nominations
            while(!tempQueue.empty()){
                addNode(to_string(tempQueue.front().Nominations), tempQueue.front());
                tempQueue.pop();
            }
            break;
        case 'D': //sorts by Rating
            while(!tempQueue.empty()){
                addNode(to_string(tempQueue.front().Rating), tempQueue.front());
                tempQueue.pop();
            }
            break;
        case 'E': //sorts by Duration
            while(!tempQueue.empty()){
                addNode(to_string(tempQueue.front().Duration), tempQueue.front());
                tempQueue.pop();
            }
            break;
        case 'F': //sorts by Genre1
            while(!tempQueue.empty()){
                addNode(tempQueue.front().Genre1, tempQueue.front());
                tempQueue.pop();
            }
            break;
        case 'G': //sorts by Genre2
            while(!tempQueue.empty()){
                addNode(tempQueue.front().Genre2, tempQueue.front());
                tempQueue.pop();
            }
            break;
        case 'H': //sorts by MetaCritic
            while(!tempQueue.empty()){
                addNode(tempQueue.front().Release, tempQueue.front());
                tempQueue.pop();
            }
            break;
        case 'I': //sorts by MetaCritic
            while(!tempQueue.empty()){
                addNode(to_string(tempQueue.front().MetaCritic), tempQueue.front());
                tempQueue.pop();
            }
            break;
        case 'J': //sorts by Synopsis
            while(!tempQueue.empty()){
                addNode(tempQueue.front().Synopsis, tempQueue.front());
                tempQueue.pop();
            }
        default:
            cout << "Invalid sort selction, tree not sorted." << endl;
            break;
    }
    
    //Frees tempQueue Tree and sets TempQueue to nullptr
//    freeNode(tempQueue);
//    tempQueue = nullptr;
    

    
    
    return;
}



template <typename DATATYPE, typename KEYTYPE>
vector<Node<DATATYPE,KEYTYPE>*> BSTree<DATATYPE, KEYTYPE>::CompleteSearch(string SearchKey){
    vector<Node<DATATYPE, KEYTYPE>*> searchVector;
    
    if(root != nullptr){
        CompleteSearch(root, SearchKey, searchVector);
    }
    
    return searchVector;
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::CompleteSearch(Node<DATATYPE, KEYTYPE> *Node, string SearchKey, vector<::Node<DATATYPE, KEYTYPE>*> &ReturnVector){
    
    //Base Case (end once leaf is reached)
    if(Node == nullptr){
        return;
    }
    
    // if node key matches search key
    if(Node->Key() == SearchKey){
        // add node to vector
        ReturnVector.push_back(Node);
        
        // recurse down left branch (to find multiples)
        CompleteSearch(Node->Left(), SearchKey, ReturnVector);
        
        // recurse down right branch (to find multiples
        CompleteSearch(Node->Right(), SearchKey, ReturnVector);
    }
    
    // if nod key does not match search key
    else if(Node->Key() < SearchKey){
        
        // recurse down right branch
        CompleteSearch(Node->Right(), SearchKey, ReturnVector);
    }
    else{
        
        // recurse down left branch
        CompleteSearch(Node->Left(), SearchKey, ReturnVector);
    }
}


template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::PartialSearch(Node<DATATYPE, KEYTYPE> *Node, string SearchKey, vector<::Node<DATATYPE, KEYTYPE>*> &ReturnVector){
    
    
    //Base Case (end once leaf is reached)
    if(Node == nullptr){
        return;
    }
    
    // determine if SearchKey is in Node Key
    size_t found = Node->Key().find(SearchKey);
    
    // if found is not empty add node to return vector
    if(found != string::npos){
        // add node to vector
        ReturnVector.push_back(Node);
        
    }
    
    // recurse down right branch
    PartialSearch(Node->Left(), SearchKey, ReturnVector);
    
    // recurse down left branch
    PartialSearch(Node->Right(), SearchKey, ReturnVector);
}

