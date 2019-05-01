//
//  functions.hpp
//  FinalProject_V2
//
//  Created by Tom Lucero on 4/30/19.
//  Copyright © 2019 Tom Lucero. All rights reserved.
//

#ifndef functions_hpp
#define functions_hpp

#include <stdio.h>
#include "BSTree.h"


static void AddActorRecord(BSTree<GeneralData, std::string> *ActorTree) {
    
    //Add a record to Actor-Actress Database.... TODO must test!!
    int _Year;
    string _Name, _Award, _Film;
    bool _bWinner = false;
    char _Winner;
    
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
    
    GeneralData* newEntry = new GeneralData(_Year, _Award, _bWinner, _Name, _Film);
    ActorTree -> addNode(_Name, *newEntry);
    //                ActorTree -> printInorder();
    
}


static void AddMovieRecord(BSTree<GeneralData, std::string> *PicturesTree) {
    //Add a record to movie database.... TODO must test!!
        
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
        
        GeneralData* newEntry = new GeneralData(_Film, _Year, _Nominations, _Rating, _Duration, _Genre1, _Genre2, _Release, _MetaCritic, _Synopsis);
        
        PicturesTree -> addNode(_Film, *newEntry);
        
    }



static void AddNominationsRecord(BSTree<GeneralData, std::string> *NominationsTree) {
    
    int _Year;
    string _Name, _Award, _Film;
    bool _bWinner = false;
    char _Winner;
    
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
    
    GeneralData* newEntry = new GeneralData(_Year, _Award, _bWinner, _Name, _Film);
    NominationsTree -> addNode(_Name, *newEntry);
    
}

template <typename DATATYPE, typename KEYTYPE>
static void SearchActorTreeModify(BSTree<DATATYPE, KEYTYPE> *ActorTree) {
    // testing status: only vaguely tested
    // test notes: removed the first character from Genre2 for some reason
    // determine which field user would like to search
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
        //        break;
    }
    
    //sort according to user selection
    ActorTree->SortTree(userSelection);
    //                ActorTree->printInorder();
    
    // get search term from user
    string SearchKey;
    cout << endl << "Please enter a search term: ";
    cin.ignore();
    getline(cin, SearchKey);
    
    
    // sets Search Veector to returned vector of MaxsSearch
    vector<Node<GeneralData, string>*> SearchVector;
    ActorTree->MaxsSearch(ActorTree->Root(), SearchKey, SearchVector);
    
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
//        break;
    }
    
    // sort tree prior to search
    PicturesTree->SortTree(userSelection);
    //                PicturesTree->printInorder();
    
    // get search term from user
    string SearchKey;
    cout << endl << "Please enter a search term: ";
    cin.ignore();
    getline(cin, SearchKey);
    
    // create vector to hold found results
    vector<Node<GeneralData, string>*> SearchVector;
    
    // search tree
    PicturesTree->MaxsSearch(PicturesTree->Root(), SearchKey, SearchVector);
    
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
        //        break;
    }
    
    //sort according to user selection
    NominationsTree->SortTree(userSelection);
    
    // get search term from user
    string SearchKey;
    cout << endl << "Please enter a search term: ";
    cin.ignore();
    getline(cin, SearchKey);
    
    
    // sets Search Veector to returned vector of MaxsSearch
    vector<Node<GeneralData, string>*> SearchVector = NominationsTree->MaxsSearch(SearchKey);
    
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

static void SearchActorTreeDelete(BSTree<GeneralData, std::string> *ActorTree) {
    string SearchKey;
    int selection;
    
    char userSelection;
    cout << "Which field would you like to sort by?" << endl
    << "A: Year" << endl
    << "B: Film" << endl
    << "C: Name" << endl
    << "D: Award" << endl;
    
    cin >> userSelection;
    userSelection = tolower(userSelection);
    
    ActorTree -> SortTree(userSelection);
    
    cout << "Enter Actor/Actress entry you would like to delete:  ";
    cin.ignore();
    getline(cin, SearchKey);
    
    vector<Node<GeneralData, string>*> SearchVector = ActorTree -> MaxsSearch(SearchKey);
    
    
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
            cout << "Select number of entry you would like to delete: ";
            cin >> selection;
            
            ActorTree -> SortTree('b');
            ActorTree -> deleteNode(SearchVector[selection-1] -> Data().Film);
            
        }
        
        else{
            
            cout << "Node to be deleted..." << endl;
            SearchVector[0]-> printData();
            //testing delete using provided key... will only work for one node at the moment.
            
            ActorTree -> deleteNode(SearchVector[0] -> Data().Name);
        }
    }
}

static void SearchPicturesTreeDelete(BSTree<GeneralData, std::string> *PicturesTree) {
    string SearchKey;
    int selection;
    
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
    
    PicturesTree -> SortTree(userSelection);
    PicturesTree -> SortTree(userSelection);
    
    cout << "Enter Actor/Actress entry you would like to delete:  ";
    cin.ignore();
    getline(cin, SearchKey);
    
    vector<Node<GeneralData, string>*> SearchVector = PicturesTree -> MaxsSearch(SearchKey);
    
    
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
            cout << "Select number of entry you would like to delete: ";
            cin >> selection;
            
            PicturesTree -> SortTree('B');
            PicturesTree -> deleteNode(SearchVector[selection-1] -> Data().Film);
            
        }
        
        else{
            
            cout << "Node to be deleted..." << endl;
            SearchVector[0]-> printData();
            //testing delete using provided key... will only work for one node at the moment.
            
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
    
    ActorTree -> SortTree(userSelection);
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
    
    PicturesTree -> SortTree(userSelection);
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
    //                ActorTree->printInorder();
    
    // get search term from user
    string SearchKey;
    cout << endl << "Please enter a search term: ";
    cin.ignore();
    getline(cin, SearchKey);
    
    
    // sets Search Veector to returned vector of MaxsSearch
    vector<Node<GeneralData, string>*> SearchVector = ActorTree->MaxsSearch(SearchKey);
    
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
    
    PicturesTree -> SortTree(userSelection);
    
    cout << "Enter search info:  ";
    cin.ignore();
    getline(cin, SearchKey);
    
    vector<Node<GeneralData, string>*> SearchVector = PicturesTree -> MaxsSearch(SearchKey);
    
    
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
    cout << "Enter Actor/Actress entry you would like to delte:  ";
    cin.ignore();
    getline(cin, SearchKey);
    
    NominationsTree -> SortTree('C');
    
    vector<Node<GeneralData, string>*> SearchVector = NominationsTree -> MaxsSearch(SearchKey);
    
    
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
    ActorTree->MaxsPartialSearch(ActorTree->Root(), SearchKey, SearchVector);
    
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
    
    cout << "Enter search info:  ";
    cin.ignore();
    getline(cin, SearchKey);
    
    // initialize vector to hold found nodes
    vector<Node<GeneralData, string>*> SearchVector;
    
    // partial search of tree
    PicturesTree->MaxsPartialSearch(PicturesTree->Root(), SearchKey, SearchVector);

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


/*static void SearchNominationTree(BSTree<GeneralData, std::string> *NominationsTree) {
    string SearchKey;
    cout << "Enter Actor/Actress entry you would like to delte:  ";
    cin.ignore();
    getline(cin, SearchKey);
    
    NominationsTree -> SortTree('C');
    
    vector<Node<GeneralData, string>*> SearchVector = NominationsTree -> MaxsSearch(SearchKey);
    
    
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
    
}*/

#endif /* functions_hpp */
