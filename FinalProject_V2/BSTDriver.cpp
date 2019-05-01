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
    
    ActorTree -> ReadActorCSVFile(ActorFile);
    PicturesTree -> ReadPictureCSVFile(PicturesFile);
    NominationsTree -> ReadActorCSVFile(NominationsFile);   //TODO Not working.. """ exists in file, must modify existing error cather for multiple """

    NominationsTree -> printInorder();
    
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
        
            case 'F':{
                
                SearchNominationTreeModify(NominationsTree);
                break;
            }
            case 'G':{
                
                SearchActorTreeDelete(ActorTree);
                break;
            }
            case 'H':
                //TODO search for a record in movie database and DELETE field

                SearchPicturesTreeDelete(PicturesTree);
                
                break;

            case 'I':
                //TODO search for a record in the Nominations Database and DELETE field --extra credit--

                break;

            case 'J':{
    
                SortActorTree(ActorTree);
                break;
            }
            case 'K':{
                
                SortMovieTree(PicturesTree);
                break;
            }
            case 'L':
                //TODO Sort the Nominations databse by any field --extra credit--

                SortActorTree(NominationsTree);
                break;

            case 'M':{
                
                CompleteSearchActorTree(ActorTree);
                break;
            }
            case 'N':{
            
                CompleteSearchMovieTree(PicturesTree);
                break;
            }
            case 'O':
                //TODO complete search the Nominations database --extra credit--
                
                //function status: not working..
                SearchNominationTree(NominationsTree);
                break;
    
            case 'P':{
                PartialSearchActorTree(ActorTree);
                break;
            }

            case 'Q':{
                PartialSearchPicturesTree(PicturesTree);
                break;
            }
            case 'R':
                //TODO Partial search the nomiations Database --Extra credit--
                 PartialSearchActorTree(NominationsTree);
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
