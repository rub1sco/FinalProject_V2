#ifndef functions_hpp
#define functions_hpp

#include <stdio.h>
#include "BSTree.h"


static void AddActorRecord(BSTree<GeneralData, std::string> *ActorTree) {
    
    //initializes variables
    int _Year;
    string _Name, _Award, _Film;
    bool _bWinner = false;
    char _Winner;
    
    //takes in user input for node to be added
    cout << "Please enter actor/actress nominated: ";
    getline(cin, _Name);
    cin.ignore();
    
    cout << "Please enter title of film: ";
    getline(cin, _Film);
    cout << endl;
    
    cout << "Please enter year the film was released: ";
    cin >> _Year;
    cin.ignore();
    cout << endl;
    
    cout << "Please enter award title: " ;
    getline(cin, _Award);
    cout << endl;
    
    cout << "Did the actor/actress win? (T/F): ";
    cin >> _Winner;
    
    //creates newEntry of GeneralData type
    GeneralData* newEntry = new GeneralData(_Year, _Award, _bWinner, _Name, _Film);
    
    //adds node to actor tree
    ActorTree -> addNode(_Name, *newEntry);
}


static void AddMovieRecord(BSTree<GeneralData, std::string> *PicturesTree) {
    
        //initializes variables
        int _Year = 0, _Nominations = 0,_Duration = 0, _MetaCritic = 0;
        double _Rating = 0.0;
        string _Film, _Genre1, _Genre2, _Release, _Synopsis;
    
    
        //takes in user input for new movie node
        cout << "Please enter name of film: ";
        cin.ignore();
        getline(cin, _Film);
        cout << endl;
        
        cout << "Please enter year film was released: ";
        cin >> _Year;
        cout << endl;
        
        cout << "Please enter number of Nominations: ";
        cin >> _Nominations;
        cout << endl;
        
        cout << "Please enter duration of film: ";
        cin >> _Duration;
        cout << endl;
        
        cout << "Please enter rating of film: ";
        cin >> _Rating;
        cout << endl;
        
        cout << "Please enter metacritic rating: ";
        cin >> _MetaCritic;
        cout << endl;
        
        cout << "Please enter main genre film is classifed as: ";
        cin.ignore();
        getline(cin, _Genre1);
        cout << endl;
        
        cout << "Please enter secondary genre film is classifed as: ";
        cin.ignore();
        getline(cin, _Genre2);
        cout << endl;
        
        cout << "Please enter the month the film was released: ";
        cin.ignore();
        getline(cin, _Release);
        cout << endl;
        
        cout << "Please enter brief synopsis of film: ";
        cin.ignore();
        getline(cin, _Synopsis);
        cout << endl;
    
        //creates new Entry of GeneralData type
        GeneralData* newEntry = new GeneralData(_Film, _Year, _Nominations, _Rating, _Duration, _Genre1, _Genre2, _Release, _MetaCritic, _Synopsis);
    
        //adds new node to pictures tree
        PicturesTree -> addNode(_Film, *newEntry);
        
    }


static void AddNominationsRecord(BSTree<GeneralData, std::string> *NominationsTree) {
    
    //Initializes variables
    int _Year;
    string _Name, _Award, _Film;
    bool _bWinner = false;
    char _Winner;
    
    //takes in user input
    cout << "Please enter actor/actress nominated: ";
    getline(cin, _Name);
    cin.ignore();
    
    cout << "Please enter title of film: ";
    getline(cin, _Film);
    cout << endl;
    
    cout << "Please enter year the film was released: ";
    cin >> _Year;
    cin.ignore();
    cout << endl;
    
    cout << "Please enter award title: " ;
    getline(cin, _Award);
    cout << endl;
    
    cout << "Did the actor/actress win? (T/F): ";
    cin >> _Winner;
    
    //creates new Entry of GeneralData type
    GeneralData* newEntry = new GeneralData(_Year, _Award, _bWinner, _Name, _Film);
    
    //Creates new node in Nominations Tree
    NominationsTree -> addNode(_Name, *newEntry);
    
}

static void SearchActorTreeModify(BSTree<GeneralData, std::string> *ActorTree) {

    //sets Key type to search for
    char userSelection;
    cout << "Which field would you like to Search by?" << endl
    << "A: Year" << endl
    << "B: Film" << endl
    << "C: Name" << endl
    << "D: Award" << endl;
    
    cin >> userSelection;
    userSelection = tolower(userSelection);
    
    // check for valid selection
    if(userSelection != 'a' &&
       userSelection != 'b' &&
       userSelection != 'c' &&
       userSelection != 'd'){
        cout << "Invalid Selection." << endl;

    }
    
    //sort according to user selection
    ActorTree->SortTree(userSelection);

    
    // get search term from user
    string SearchKey;
    cout << endl << "Please enter a search term: ";
    cin.ignore();
    getline(cin, SearchKey);
    
    
    // sets Search Veector to returned vector of MaxsSearch
    vector<Node<GeneralData, string>*> SearchVector;
    ActorTree->CompleteSearch(ActorTree->Root(), SearchKey, SearchVector);
    
    // respond appropriately if no results are found
    if(SearchVector.empty()){
        cout << "No results found." << endl;
    }
    // output search results
    else{
        cout << "Search Results: " << endl;
        for(int i = 1; i <= SearchVector.size(); i++){
            cout << i << ". ";
            SearchVector[i - 1]->printData();
        }
        
        cout << endl << "Which entry would you like to edit? (#) ";
        
        // get selection to edit field
        int choice;
        cin >> choice;
        
        // check for valid selection
        if(choice > 0 && choice <= SearchVector.size()){
            // get updated information from user
            int _Year;
            string _Name, _Award, _Film;
            bool _bWinner = false;
            char _Winner;
            cin.ignore();
            
            cout << "Please enter actor/actress nominated: ";
            getline(cin, _Name);
            cin.ignore();
            
            cout << "Please enter title of film: ";
            getline(cin, _Film);
            cout << endl;
            
            cout << "Please enter year the film was released: ";
            cin >> _Year;
            cin.ignore();
            cout << endl;
            
            cout << "Please enter award title: " ;
            getline(cin, _Award);
            cout << endl;
            
            cout << "Did the actor/actress win? (T/F): ";
            cin >> _Winner;
            
            if(_Winner == 'T' || _Winner == 't'){_bWinner = true;}
            //                _bWinner = false;
            cout << endl;
            
            
            //update node with new information
            GeneralData newEntry(_Year, _Award, _bWinner, _Name, _Film);
            SearchVector[choice-1]->setData(newEntry);
            
        }
        else{ //if invalid selection entered
            cout << "Invalid Selection." << endl << endl;
        }
    }
    
}

static void SearchMovieTreeModify(BSTree<GeneralData, std::string> *PicturesTree) {
    
    //sets search key
    char userSelection;
    cout << "Which field would you like to Search by?" << endl
    << "A: Year" << endl
    << "B: Film" << endl
    << "C: Number of Nominations" << endl
    << "D: Rating" << endl
    << "E: Duration" << endl
    << "F: Genre 1" << endl
    << "G: Genre 2" << endl
    << "H: Release (Month)" << endl
    << "I: MetaCritic" << endl;
    
    cin >> userSelection;
    userSelection = toupper(userSelection);
    
    // check for valid selection
    if(userSelection != 'A' &&
       userSelection != 'B' &&
       userSelection != 'C' &&
       userSelection != 'D' &&
       userSelection != 'E' &&
       userSelection != 'F' &&
       userSelection != 'G' &&
       userSelection != 'H' &&
       userSelection != 'I'){
        cout << "Invalid Selection." << endl;

    }
    
    // sort tree prior to search
    PicturesTree->SortTree(userSelection);
    
    // get search term from user
    string SearchKey;
    cout << endl << "Please enter a search term: ";
    cin.ignore();
    getline(cin, SearchKey);
    
    // create vector to hold found results
    vector<Node<GeneralData, string>*> SearchVector;
    
    // search tree
    PicturesTree->CompleteSearch(PicturesTree->Root(), SearchKey, SearchVector);
    
    // respond appropriately if no results are found
    if(SearchVector.empty()){
        cout << "No results found." << endl;
    }
    
    // output search results
    else{
        cout << "Search Results: " << endl;
        for(int i = 1; i <= SearchVector.size(); i++){
            cout << i << ". ";
            SearchVector[i - 1]->printData();
        }
        
        cout << endl << "Which entry would you like to edit? (#) ";
        
        // get selection to edit field
        int choice;
        cin >> choice;
        
        // check for valid selection
        if(choice > 0 && choice <= SearchVector.size()){
            
            // get updated information from user
            int _Year = 0, _Nominations = 0,_Duration = 0, _MetaCritic = 0;
            double _Rating = 0.0;
            string _Film, _Genre1, _Genre2, _Release, _Synopsis;
            
            cout << "Please enter name of film: ";
            cin.ignore();
            getline(cin, _Film);
            cout << endl;
            
            cout << "Please enter year film was released: ";
            cin >> _Year;
            cout << endl;
            
            cout << "Please enter number of Nominations: ";
            cin >> _Nominations;
            cout << endl;
            
            cout << "Please enter duration of film: ";
            cin >> _Duration;
            cout << endl;
            
            cout << "Please enter rating of film: ";
            cin >> _Rating;
            cout << endl;
            
            cout << "Please enter metacritic rating: ";
            cin >> _MetaCritic;
            cout << endl;
            
            cout << "Please enter main genre film is classifed as: ";
            cin.ignore();
            getline(cin, _Genre1);
            cout << endl;
            
            cout << "Please enter secondary genre film is classifed as: ";
            cin.ignore();
            getline(cin, _Genre2);
            cout << endl;
            
            cout << "Please enter the month the film was released: ";
            cin.ignore();
            getline(cin, _Release);
            cout << endl;
            
            cout << "Please enter brief synopsis of film: ";
            cin.ignore();
            getline(cin, _Synopsis);
            cout << endl;
            
            //update node with new information
            GeneralData newEntry(_Film, _Year, _Nominations, _Rating, _Duration, _Genre1, _Genre2, _Release, _MetaCritic, _Synopsis);
            
            SearchVector[choice-1]->setData(newEntry);
            
        }
        else{ //if invalid selection entered
            cout << "Invalid Selection." << endl << endl;
        }
    }
}


static void SearchNominationTreeModify(BSTree<GeneralData, std::string> *NominationsTree) {
    //sets search key
    char userSelection;
    cout << "Which field would you like to Search by?" << endl
    << "A: Year" << endl
    << "B: Film" << endl
    << "C: Name" << endl
    << "D: Award" << endl;
    
    cin >> userSelection;
    userSelection = tolower(userSelection);
    
    // check for valid selection
    if(userSelection != 'a' &&
       userSelection != 'b' &&
       userSelection != 'c' &&
       userSelection != 'd'){
        cout << "Invalid Selection." << endl;
    }
    
    //sort according to user selection
    NominationsTree->SortTree(userSelection);
    
    // get search term from user
    string SearchKey;
    cout << endl << "Please enter a search term: ";
    cin.ignore();
    getline(cin, SearchKey);
    
    
    // sets Search Veector to returned vector of MaxsSearch
    vector<Node<GeneralData, string>*> SearchVector = NominationsTree->CompleteSearch(SearchKey);
    
    // respond appropriately if no results are found
    if(SearchVector.empty()){
        cout << "No results found." << endl;
    }
    // output search results
    else{
        cout << "Search Results: " << endl;
        for(int i = 1; i <= SearchVector.size(); i++){
            cout << i << ". ";
            SearchVector[i - 1]->printData();
        }
        
        cout << endl << "Which entry would you like to edit? (#) ";
        
        // get selection to edit field
        int choice;
        cin >> choice;
        
        // check for valid selection
        if(choice > 0 && choice <= SearchVector.size()){
            // get updated information from user
            int _Year;
            string _Name, _Award, _Film;
            bool _bWinner = false;
            char _Winner;
            cin.ignore();
            
            cout << "Please enter actor/actress nominated: ";
            getline(cin, _Name);
            cin.ignore();
            
            cout << "Please enter title of film: ";
            getline(cin, _Film);
            cout << endl;
            
            cout << "Please enter year the film was released: ";
            cin >> _Year;
            cin.ignore();
            cout << endl;
            
            cout << "Please enter award title: " ;
            getline(cin, _Award);
            cout << endl;
            
            cout << "Did the actor/actress win? (T/F): ";
            cin >> _Winner;
            
            if(_Winner == 'T' || _Winner == 't'){_bWinner = true;}
            cout << endl;
            
            
            //update node with new information
            GeneralData newEntry(_Year, _Award, _bWinner, _Name, _Film);
            SearchVector[choice-1]->setData(newEntry);
            
        }
        else{ //if invalid selection entered
            cout << "Invalid Selection." << endl << endl;
        }
    }
}

static void SearchActorTreeDelete(BSTree<GeneralData, std::string> *ActorTree) {
    string SearchKey;
    int selection;
    
    //sets search key
    char userSelection;
    cout << "Which field would you like to sort by?" << endl
    << "A: Year" << endl
    << "B: Film" << endl
    << "C: Name" << endl
    << "D: Award" << endl;
    
    cin >> userSelection;
    userSelection = tolower(userSelection);
    
    //sorts ActorTree by userSelection
    ActorTree -> SortTree(userSelection);
    
    //searches user entry to delete
    cout << "Enter search term to delete:  ";
    cin.ignore();
    getline(cin, SearchKey);
    
    //stores nodes found into vector of pointers
    vector<Node<GeneralData, string>*> SearchVector = ActorTree -> CompleteSearch(SearchKey);
    
    
    //if vector is empty
    if(SearchVector.empty()){
        cout << "No results found." << endl;
    }
    // output search results
    else{
        cout << "Search Results: " << endl;
        
        //if there are multiple nodes found with user search input, must select specific node
        if (SearchVector.size() > 1){
            for(int i = 1; i <= SearchVector.size(); i++){
                cout << "Multiple enteries found." << endl;
                cout << i << ". ";
                SearchVector[i - 1]->printData();
                
            }
            //selects which vector item to delete
            cout << "Select number of entry you would like to delete: ";
            cin >> selection;
            
            //Sorts by new key
            ActorTree -> SortTree('b');
            //deletes node with unique key
            ActorTree -> deleteNode(SearchVector[selection-1] -> Data().Film);
            
        }
        
        else{
            //there is only one node found,
            cout << "Node to be deleted..." << endl;
            
            //prints out node found
            SearchVector[0]-> printData();
            
            //deletes the node
            ActorTree -> deleteNode(SearchVector[0] -> Data().Name);
        }
    }
}

static void SearchPicturesTreeDelete(BSTree<GeneralData, std::string> *PicturesTree) {
    string SearchKey;
    int selection;
    
    //user input for search key
    char userSelection;
    cout << "Which field would you like to sort by?" << endl
    << "A: Year" << endl
    << "B: Film" << endl
    << "C: Nominations" << endl
    << "D: Rating" << endl
    << "E: Duration" << endl
    << "F: Genre1" << endl
    << "G: Genre2" << endl
    << "H: Release" << endl
    << "I: MetaCritic" << endl;
    
    cin.ignore();
    
    cin >> userSelection;
    userSelection = toupper(userSelection);
    
    //sorts picture tree by user selection
    PicturesTree -> SortTree(userSelection);

    
    //user input for search key
    cout << "Enter Actor/Actress entry you would like to delete:  ";
    cin.ignore();
    getline(cin, SearchKey);
    
    //stores Node pointers in vector
    vector<Node<GeneralData, string>*> SearchVector = PicturesTree -> CompleteSearch(SearchKey);
    
    //if no vector items
    if(SearchVector.empty()){
        cout << "No results found." << endl;
    }
    // output search results
    else{
        cout << "Search Results: " << endl;
        //if vector contains more than one node found
        if (SearchVector.size() > 1){
            for(int i = 1; i <= SearchVector.size(); i++){
                cout << "Multiple enteries found." << endl;
                cout << i << ". ";
                SearchVector[i - 1]->printData();
                
            }
            //selects node to delete
            cout << "Select number of entry you would like to delete: ";
            cin >> selection;
            
            //sorts by unique Key and sorts to that key
            PicturesTree -> SortTree('B');
            
            //deletes node with unique key
            PicturesTree -> deleteNode(SearchVector[selection-1] -> Data().Film);
            
        }
        
        else{
            
            //only one node found
            cout << "Node to be deleted..." << endl;
            
            //prints node found
            SearchVector[0]-> printData();

            //deletes node found
            PicturesTree -> deleteNode(SearchVector[0] -> Data().Film);
        }
    }
}


static void SortActorTree(BSTree<GeneralData, std::string> *ActorTree) {
    char userSelection;
    cout << "Which field would you like to sort by?" << endl
    << "A: Year" << endl
    << "B: Film" << endl
    << "C: Name" << endl
    << "D: Award" << endl;
    
    cin >> userSelection;
    userSelection = tolower(userSelection);
    
    //sorts by key
    ActorTree -> SortTree(userSelection);
    
    //prints in order
    ActorTree -> printInorder();
    
}


static void SortMovieTree(BSTree<GeneralData, std::string> *PicturesTree) {
    char userSelection;
    cout << "Which field would you like to sort by?" << endl
    << "A: Year" << endl
    << "B: Film" << endl
    << "C: Nominations" << endl
    << "D: Rating" << endl
    << "E: Duration" << endl
    << "F: Genre1" << endl
    << "G: Genre2" << endl
    << "H: Release" << endl
    << "I: MetaCritic" << endl;
    
    cin >> userSelection;
    userSelection = toupper(userSelection);
    
    //sorts by key
    PicturesTree -> SortTree(userSelection);
    
    //prints in order
    PicturesTree -> printInorder();
}


static void CompleteSearchActorTree(BSTree<GeneralData, std::string> *ActorTree) {
    char userSelection;
    cout << "Which field would you like to Search by?" << endl
    << "A: Year" << endl
    << "B: Film" << endl
    << "C: Name" << endl
    << "D: Award" << endl;
    
    cin >> userSelection;
    userSelection = tolower(userSelection);
    
    // check for valid selection
    if(userSelection != 'a' &&
       userSelection != 'b' &&
       userSelection != 'c' &&
       userSelection != 'd'){
        cout << "Invalid Selection." << endl;
        return;
    }
    
    //sort according to user selection
    ActorTree->SortTree(userSelection);
    
    // get search term from user
    string SearchKey;
    cout << endl << "Please enter a search term: ";
    cin.ignore();
    getline(cin, SearchKey);
    
    
    // sets Search Veector to returned vector of MaxsSearch
    vector<Node<GeneralData, string>*> SearchVector = ActorTree->CompleteSearch(SearchKey);
    
    // respond appropriately if no results are found
    if(SearchVector.empty()){
        cout << "No results found." << endl;
    }
    // output search results
    else{
        cout << "Search Results: " << endl;
        for(int i = 1; i <= SearchVector.size(); i++){
            cout << i << ". ";
            SearchVector[i - 1]->printData();
        }
    }
}


static void CompleteSearchMovieTree(BSTree<GeneralData, std::string> *PicturesTree) {
    string SearchKey;
    
    char userSelection;
    cout << "Which field would you like to sort by?" << endl
    << "A: Year" << endl
    << "B: Film" << endl
    << "C: Nominations" << endl
    << "D: Rating" << endl
    << "E: Duration" << endl
    << "F: Genre1" << endl
    << "G: Genre2" << endl
    << "H: Release" << endl
    << "I: MetaCritic" << endl;
    
    cin >> userSelection;
    userSelection = toupper(userSelection);
    
    // check for valid selection
    if(userSelection != 'A' &&
       userSelection != 'B' &&
       userSelection != 'C' &&
       userSelection != 'D' &&
       userSelection != 'E' &&
       userSelection != 'F' &&
       userSelection != 'G' &&
       userSelection != 'H' &&
       userSelection != 'I'){
        cout << "Invalid Selection." << endl;
        return;
    }
    
    //sorts picture tree by userSelection
    PicturesTree -> SortTree(userSelection);
    
    cout << "Enter search info:  ";
    cin.ignore();
    getline(cin, SearchKey);
    
    //stores nodes into vector
    vector<Node<GeneralData, string>*> SearchVector = PicturesTree -> CompleteSearch(SearchKey);
    
    
    if(SearchVector.empty()){
        cout << "No results found." << endl;
    }
    // output search results
    else{
        cout << "Search Results: " << endl;
        
        if (SearchVector.size() > 1){
            cout << "Multiple enteries found." << endl;
            for(int i = 1; i < SearchVector.size(); i++){
                cout << i << ". ";
                SearchVector[i]->printData();
                
            }
        }
        else if(SearchVector.size() == 1){
           SearchVector[0] -> printData();
        }
    }
}


static void SearchNominationTree(BSTree<GeneralData, std::string> *NominationsTree) {
    string SearchKey;
    
    char userSelection;
    cout << "Which field would you like to Search by?" << endl
    << "A: Year" << endl
    << "B: Film" << endl
    << "C: Name" << endl
    << "D: Award" << endl;
    
    cin >> userSelection;
    userSelection = tolower(userSelection);
    
    //sorts by userSelection
    NominationsTree -> SortTree(userSelection);
    
    // check for valid selection
    if(userSelection != 'a' &&
       userSelection != 'b' &&
       userSelection != 'c' &&
       userSelection != 'd'){
        cout << "Invalid Selection." << endl;
        return;
    }
    cout << "Enter search term: ";
    cin.ignore();
    getline(cin, SearchKey);
    
    //Stores Nodes into vector of pointers
    vector<Node<GeneralData, string>*> SearchVector = NominationsTree -> CompleteSearch(SearchKey);
    
    
    if(SearchVector.empty()){
        cout << "No results found." << endl;
    }
    // output search results
    else{
        cout << "Search Results: " << endl;
        
        if (SearchVector.size() > 1){
            for(int i = 1; i <= SearchVector.size(); i++){
                cout << "Multiple enteries found." << endl;
                cout << i << ". ";
                SearchVector[i - 1]->printData();
                
            }
        }
    }
}

void PartialSearchActorTree(BSTree<GeneralData, std::string> *ActorTree){
    char userSelection;
    cout << "Which field would you like to search?" << endl
    << "A: Year" << endl
    << "B: Film" << endl
    << "C: Name" << endl
    << "D: Award" << endl;
    
    cin >> userSelection;
    userSelection = tolower(userSelection);
    
    // check for valid selection
    if(userSelection != 'a' &&
       userSelection != 'b' &&
       userSelection != 'c' &&
       userSelection != 'd'){
        cout << "Invalid Selection." << endl;
        return;
    }
    
    //sort according to user selection
    ActorTree->SortTree(userSelection);
    
    // get search term from user
    string SearchKey;
    cout << endl << "Please enter a search term: ";
    cin.ignore();
    getline(cin, SearchKey);
    
    // initialize vector to hold found nodes
    vector<Node<GeneralData, string>*> SearchVector;
    
    // partial search of tree
    ActorTree->PartialSearch(ActorTree->Root(), SearchKey, SearchVector);
    
    // respond appropriately if no results are found
    if(SearchVector.empty()){
        cout << "No results found." << endl;
    }
    // output search results
    else{
        cout << "Search Results: " << endl;
        for(int i = 1; i <= SearchVector.size(); i++){
            cout << i << ". ";
            SearchVector[i - 1]->printData();
        }
    }
}

void PartialSearchPicturesTree (BSTree<GeneralData, std::string> *PicturesTree){
    string SearchKey;
    
    char userSelection;
    cout << "Which field would you like to sort by?" << endl
    << "A: Year" << endl
    << "B: Film" << endl
    << "C: Nominations" << endl
    << "D: Rating" << endl
    << "E: Duration" << endl
    << "F: Genre1" << endl
    << "G: Genre2" << endl
    << "H: Release" << endl
    << "I: MetaCritic" << endl
    << "J: Synopsis" << endl;
    
    cin >> userSelection;
    userSelection = toupper(userSelection);
    
    // check for valid selection
    if(userSelection != 'A' &&
       userSelection != 'B' &&
       userSelection != 'C' &&
       userSelection != 'D' &&
       userSelection != 'E' &&
       userSelection != 'F' &&
       userSelection != 'G' &&
       userSelection != 'H' &&
       userSelection != 'I' &&
       userSelection != 'J'){
        cout << "Invalid Selection." << endl;
        return;
    }
    
    PicturesTree -> SortTree(userSelection);
    
    cout << "Enter search term:  ";
    cin.ignore();
    getline(cin, SearchKey);
    
    // initialize vector to hold found nodes
    vector<Node<GeneralData, string>*> SearchVector;
    
    // partial search of tree
    PicturesTree->PartialSearch(PicturesTree->Root(), SearchKey, SearchVector);

    if(SearchVector.empty()){
        cout << "No results found." << endl;
    }
    // output search results
    else{
        cout << "Search Results: " << endl;
        
        if (SearchVector.size() > 1){
            cout << "Multiple enteries found." << endl;
            for(int i = 1; i < SearchVector.size(); i++){
                cout << i << ". ";
                SearchVector[i]->printData();
                
            }
        }
        else if(SearchVector.size() == 1){
            SearchVector[0] -> printData();
        }
    }
}


#endif /* functions_hpp */
