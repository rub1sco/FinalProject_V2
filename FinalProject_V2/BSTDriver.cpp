/*Driver program demonstrating creating a tree, adding, finding and deleting nodes
Dr. Augustine 10/30/2017
Status: works with completed and correct BSTree.cpp
*/

/*Template Directions: #include "BSTREEInt.hpp"
but do NOT compile it (or add it to the project)*/
#include <iostream>
#include <cctype>
//#include "functions.hpp"
#include "Node.h"
#include "BSTree.hpp"


using namespace std;

int main()
{
    char menu = 0;
    string ActorFile = "actor-actress.csv";
    string PicturesFile = "pictures.csv";
    string NominationsFile = "nominations.csv";
 
    BSTree<GeneralData, string>* ActorTree = new BSTree<GeneralData, string>;
    BSTree<GeneralData, string>* PicturesTree = new BSTree<GeneralData, string>;
    BSTree<GeneralData, string>* NominationsTree = new BSTree<GeneralData, string>;
   
//    ActorTree -> ReadCSVFile(ActorFile);      //Does not work... delete if cannot fix.
    ActorTree -> ReadActorCSVFile(ActorFile);
    PicturesTree -> ReadPictureCSVFile(PicturesFile);
    NominationsTree -> ReadActorCSVFile(NominationsFile);   //TODO for some entries """ appears? ie. """hush...Hush sweet caroline
    
    // test print tree function
    //PicturesTree -> printInorder();
    
    
    //test of finding node based on string value.
//    Node<GeneralData, string> fNode = *ActorTree -> findNode("Louise Dresser");

    
    while (menu != 'x' || menu != 'X'){
        cout << "Binary Search tree for Film Database" << endl;
        cout << "A: Add a record to Actor-Actress Database" << endl;
        cout << "B: Add a record to movie database" << endl;
        cout << "C: Add a record to nominations Database --extra credit--" << endl;
        cout << "D: Search for a record in Actor-Actress Database and MODIFY field" << endl;
        cout << "E: Search for a record in movie database and MODIFY field." << endl;
        cout << "F: Search for a record in Nominations Database and MODIFY field. --extra credit--" << endl;
        cout << "G: Search for record in Actor Actress Database and DELETE the field" << endl;
        cout << "H: Search for a record in movie database and DELETE field" << endl;
        cout << "I: Search for a record in the Nominations Database and DELETE field --extra credit--" << endl;
        cout << "J: Sort the Actor-Actress database by any field" << endl;
        cout << "K: Sort the movie database by any field" << endl;
        cout << "L: Sort the Nominations databse by any field --extra credit--" << endl;
        cout << "M: Complete search the Actor-Actress database" << endl;
        cout << "N: Complete search the movie database" << endl;
        cout << "O: Complete search the Nominations database --extra credit--" << endl;
        cout << "P: Partial search the Actor-Actress database" << endl;
        cout << "Q: Partial search the Movie database" << endl;
        cout << "R: Partial search the nomiations Database --Extra credit--" << endl;
        cout << "X: Exit" << endl;

        cout << "Please enter your selection: ";
        
        cin >> menu;
        menu = toupper(menu); //allows menu to still function if a lowercase letter is entered by user
        
        cout << endl;

        switch (menu) {
            case 'A':
                //Add a record to Actor-Actress Database.... TODO must test!!
            {
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
            
              break;
            }

            case 'B':
                //Add a record to movie database.... TODO must test!!
            {
                
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
                
                break;
            }
            case 'C':
                //TODO add a record to nominations Database --extra credit--

                break;

            case 'D':{
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
                    break;
                }
                
                //sort according to user selection
                ActorTree->SortTree(userSelection);
                ActorTree->printInorder();
                
                // get search term from user
                string SearchKey;
                cout << endl << "Please enter a search term: ";
                cin.ignore();
                getline(cin, SearchKey);
                
                // create vector to hold found results
                vector<Node<GeneralData, string>*> SearchVector;
                
                // search tree
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
                
                // exit switch
                break;
            }
            case 'E':{
                // testing status: only vaguely tested
                // determine which field user would like to search
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
                    break;
                }
                
                // sort tree prior to search
                PicturesTree->SortTree(userSelection);
                PicturesTree->printInorder();
                
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
                
                // exit switch
                break;
            }
            case 'F':
                //TODO search for a record in Nominations Database and MODIFY field. --extra credit--
                break;

            case 'G':
                //TODO search for record in Actor Actress Database and DELETE the field

                break;

            case 'H':
                //TODO search for a record in movie database and DELETE field

                break;

            case 'I':
                //TODO search for a record in the Nominations Database and DELETE field --extra credit--

                break;

            case 'J':
            {
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

                break;
                
            }
            case 'K':
            {
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
        
                break;
            }
            case 'L':
                //TODO Sort the Nominations databse by any field --extra credit--

                break;

            case 'M':
                //TODO complete search the Actor-Actress database

                break;

            case 'N':
                //TODO complete search the movie database

                break;

            case 'O':
                //TODO complete search the Nominations database --extra credit--

                break;

            case 'P':
                //TODO Partial search the Actor-Actress database

                break;

            case 'Q':
                //TODO partial search the Movie database

                break;

            case 'R':
                //TODO Partial search the nomiations Database --Extra credit--

                break;

            case 'X':
                delete ActorTree;
                delete PicturesTree;
                delete NominationsTree;
                return 0;
                break;

            default:
                cout << "Please select valid input" << endl;

                break;
        }
    }
    
   
    return 0;

}
