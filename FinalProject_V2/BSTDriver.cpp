/*Driver program demonstrating creating a tree, adding, finding and deleting nodes
Dr. Augustine 10/30/2017
Status: works with completed and correct BSTree.cpp
*/

/*Template Directions: #include "BSTREEInt.hpp"
but do NOT compile it (or add it to the project)*/
#include <iostream>
#include <cctype>
#include "functions.hpp"
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
//    ActorTree -> ReadCSVFile(ActorFile);
    
    ActorTree -> ReadActorCSVFile(ActorFile);
    PicturesTree -> ReadPictureCSVFile(PicturesFile);
//    NominationsTree -> ReadActorCSVFile(NominationsFile);   //TODO Not working.. """ exists in file, must modify existing error cather for multiple """
    
    // test print tree function
    PicturesTree -> printInorder();
    
    
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
                AddActorRecord(ActorTree);
                break;
            
                case 'B':
                AddMovieRecord(PicturesTree);
                break;
                
                case 'C':
                AddNominationsRecord(NominationsTree);
                break;

                case 'D':
                SearchActorTreeModify(ActorTree);
                break;
                
            case 'E':
                // testing status: only vaguely tested
                // determine which field user would like to search
                SearchMovieTreeModify(PicturesTree);
                
                // exit switch
                break;
        
            case 'F':
            {
                //TODO search for a record in Nominations Database and MODIFY field. --extra credit--
                
                // testing status: works with Award search.. Name, film might have issues related to ","
                // test notes: does not work with Name field... probably relates to the "Cuba Gooding, Jr." error with the "," as delimiter
                // determine which field user would like to search
                SearchNominationTreeModify(NominationsTree);
                
                break;
            }
            case 'G':
                //TODO search for record in Actor Actress Database and DELETE the field
                SearchActorTreeDelete(ActorTree);
                
                break;

            case 'H':
                //TODO search for a record in movie database and DELETE field


                
                break;

            case 'I':
                //TODO search for a record in the Nominations Database and DELETE field --extra credit--

                break;

            case 'J':
    
                SortActorTree(ActorTree);
                break;
        
            case 'K':
            {
                SortMovieTree(PicturesTree);
        
                break;
            }
            case 'L':
                //TODO Sort the Nominations databse by any field --extra credit--

//                SortActorTree(NominationsTree);
                break;

            case 'M':
                //TODO complete search the Actor-Actress database
            {
                // testing status: only vaguely tested
                // test notes: removed the first character from Genre2 for some reason
                // determine which field user would like to search
                CompleteSearchActorTree(ActorTree);
                break;
            }
            case 'N':
                //TODO complete search the movie database
            
                CompleteSearchMovieTree(PicturesTree);
            

                break;

            case 'O':
                //TODO complete search the Nominations database --extra credit--
                
                //function status: not working..
//                SearchNominationTree(NominationsTree);
                break;
    
            case 'P':
                //TODO Partial search the Actor-Actress database
            {
                string SearchKey;
                cin.ignore();
                cout << "Enter partial string to search: " << endl;
                getline(cin, SearchKey, '\n');
                
                // sets Search Veector to returned vector of MaxsSearch
                vector<Node<GeneralData, string>*> SearchVector = ActorTree->PartialSearch(SearchKey);
                
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
