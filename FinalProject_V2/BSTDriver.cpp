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
    //Initializes files and menu option
    char menu = 0;
    string ActorFile = "InputFiles/actor-actress.csv";
    string PicturesFile = "InputFiles/pictures.csv";
    string NominationsFile = "InputFiles/nominations.csv";
 
    //initializes new trees
    BSTree<GeneralData, string>* ActorTree = new BSTree<GeneralData, string>;
    BSTree<GeneralData, string>* PicturesTree = new BSTree<GeneralData, string>;
    BSTree<GeneralData, string>* NominationsTree = new BSTree<GeneralData, string>;
    
    //Builds initial trees before any functions are called.
    ActorTree -> ReadActorCSVFile(ActorFile);
    PicturesTree -> ReadPictureCSVFile(PicturesFile);
    NominationsTree -> ReadActorCSVFile(NominationsFile);   //TODO Not working.. """ exists in file, must modify existing error cather for multiple """

    //runs menu until x or X
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
        
        //takes in user input
        cin >> menu;
        
        //allows both a and A to be entered and interpreted the same
        menu = toupper(menu);
        cout << endl;

        switch (menu) {
            case 'A':
                //adds new actor Record to Actor Tree
                AddActorRecord(ActorTree);
                break;
            
                case 'B':
                 //adds new actor Record to Pictures Tree
                AddMovieRecord(PicturesTree);
                break;
                
                case 'C':
                 //adds new actor Record to Nominations Tree
                AddNominationsRecord(NominationsTree);
                break;

                case 'D':
                //Searches Actor tree and allows user to modify
                SearchActorTreeModify(ActorTree);
                break;
                
            case 'E':
                //Searches Movie tree and allows User to modify
                SearchMovieTreeModify(PicturesTree);

                break;
        
            case 'F':
                //Searches Nomination tree and allows user to modify
                SearchNominationTreeModify(NominationsTree);
                break;
            
            case 'G':
                //Searches actor tree and allows user to delete entry
                SearchActorTreeDelete(ActorTree);
                break;
            
            case 'H':
                //Searches Pictures tree and allows user to delete entry
                SearchPicturesTreeDelete(PicturesTree);
                
                break;

            case 'I':
                //Searches Nominations tree and allows user to delete entry
                SearchActorTreeDelete(NominationsTree);
                break;

            case 'J':
                //Sorts actor tree by various keys
                SortActorTree(ActorTree);
                break;
            case 'K':
                //Sorts Movie tree by various keys
                SortMovieTree(PicturesTree);
                break;
            
            case 'L':
                //Sorts Nominations tree by various keys
                SortActorTree(NominationsTree);
                break;

            case 'M':
                //Searches Actor Tree for exact string
                CompleteSearchActorTree(ActorTree);
                break;
            
            case 'N':
                //Searches Movie Tree for exact string
                CompleteSearchMovieTree(PicturesTree);
                break;
            
            case 'O':
                //Searches Nominations Tree for exact string
                CompleteSearchActorTree(NominationsTree);
                break;
    
            case 'P':
                //Searches Actor Tree for partial string
                PartialSearchActorTree(ActorTree);
                break;
            

            case 'Q':
                //Searches Pictures Tree for partial string
                PartialSearchPicturesTree(PicturesTree);
                break;
            
            case 'R':
                //Searches Nominations Tree for partial string
                 PartialSearchActorTree(NominationsTree);
                break;

            case 'X':
                //Deletes Trees
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
