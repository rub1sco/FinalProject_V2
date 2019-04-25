/*Driver program demonstrating creating a tree, adding, finding and deleting nodes
Dr. Augustine 10/30/2017
Status: works with completed and correct BSTree.cpp
*/

/*Template Directions: #include "BSTREEInt.hpp"
but do NOT compile it (or add it to the project)*/
#include <iostream>
#include "BSTree.hpp"



using namespace std;

int main()
{
    char menu = 0;
    string ActorFile = "actor-actress.csv";
    string PicturesFile = "pictures.csv";
    string NominationsFile = "nominations.csv";
 
    BSTree<GeneralData, string>* ActorTree = new BSTree<GeneralData, string>;
    BSTree<GeneralData2, string>* PicturesTree = new BSTree<GeneralData2, string>;
    BSTree<GeneralData, string>* NominationsTree = new BSTree<GeneralData, string>;
   
//    ActorTree -> ReadCSVFile(ActorFile);      //Does not work... delete if cannot fix.
    ActorTree -> ReadActorCSVFile(ActorFile);
    PicturesTree -> ReadPictureCSVFile(PicturesFile);
    NominationsTree -> ReadActorCSVFile(NominationsFile);   //TODO for some entries """ appears? ie. """hush...Hush sweet caroline
    
    
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
        cout << endl;

        switch (menu) {
            case 'a':
            case 'A':
                //Add a record to Actor-Actress Database.... TODO must test!!
            {
                int _Year;
                string _Name, _Award, _Film;
                bool _bWinner = false;
                char _Winner;
                cin.ignore();
                cout << "Please enter Name of film:";
                getline(cin, _Film);
                cout << endl;
                cout << "Please enter year the film was released: ";
                cin >> _Year;
                cin.ignore();
                cout << endl;
                cout << "Please enter Award nominated: " ;
                getline(cin, _Award, '\n');
                cout << endl;
                cout << "Did the film win an award?(T/F)";
                cin >> _Winner;
                cin.ignore();
                if(_Winner == 'T'){_bWinner = true;}
//                _bWinner = false;
                cout << endl;
                cout << "Please enter Actor nominated: ";
                getline(cin, _Name, '\n');
                
                GeneralData* newEntry = new GeneralData(_Year, _Award, _bWinner, _Name, _Film);
                ActorTree -> addNode(_Name, *newEntry);
//                ActorTree -> printInorder();
            
              break;
            }

            case 'b':
            case 'B':
                //Add a record to movie database.... TODO must test!!
            {
                int _Year = 0, _Nominations = 0,_Duration = 0, _MetaCritic = 0;
                double _Rating = 0.0;
                string _Name, _Genre1, _Genre2, _Release, _Synopsis;
                
                cout << "Please enter name of film: ";
                cin >> _Name;
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
                cin >> _Genre1;
                cout << endl;
                
                cout << "Please enter secondary genre film is classifed as: ";
                cin >> _Genre2;
                cout << endl;
                
                cout << "Please enter brief synopsis of film: ";
                cin >> _Synopsis;
                cout << endl;
                
                GeneralData2* newEntry = new GeneralData2(_Name, _Year, _Nominations, _Rating, _Duration, _Genre1, _Genre2, _Release, _MetaCritic, _Synopsis);
                
                PicturesTree -> addNode(_Name, *newEntry);
                
                
                break;
            }
            case 'c':
            case 'C':
                //TODO add a record to nominations Database --extra credit--

                break;

            case 'd':
            case 'D':
                //TODO search for a record in Actor-Actress Database and MODIFY field

                break;

            case 'e':
            case 'E':
                //TODO search for a record in movie database and MODIFY field.

                break;

            case 'f':
            case 'F':
                //TODO search for a record in Nominations Database and MODIFY field. --extra credit--
                break;

            case 'g':
            case 'G':
                //TODO search for record in Actor Actress Database and DELETE the field

                break;

            case 'h':
            case 'H':
                //TODO search for a record in movie database and DELETE field

                break;

            case 'i':
            case 'I':
                //TODO search for a record in the Nominations Database and DELETE field --extra credit--

                break;

            case 'j':
            case 'J':
                //TODO Sort the Actor-Actress database by any field... test!!!
            {
                char userSelection;
                cout << "Which field would you like to search from? a: year, b: award, c: name, d: film" << endl;
                cin >> userSelection;
                
                ActorTree -> SortTree(userSelection);
//                ActorTree -> printInorder();
                break;
            }
            case 'k':
            case 'K':
                //TODO Sort the movie database by any field
                char userSelection;
                cout << "Which field would you like to search from? a: year, b: award, c: name, d: film" << endl;
                cin >> userSelection;
//                PicturesTree -> SortTree(userSelection);  //TODO, cases don't work for PicturesTree
        
                break;

            case 'l':
            case 'L':
                //TODO Sort the Nominations databse by any field --extra credit--

                break;

            case 'm':
            case 'M':
                //TODO complete search the Actor-Actress database

                break;

            case 'n':
            case 'N':
                //TODO complete search the movie database

                break;

            case 'o':
            case 'O':
                //TODO complete search the Nominations database --extra credit--

                break;

            case 'p':
            case 'P':
                //TODO Partial search the Actor-Actress database

                break;

            case 'q':
            case 'Q':
                //TODO partial search the Movie database

                break;

            case 'r':
            case 'R':
                //TODO Partial search the nomiations Database --Extra credit--

                break;

            case 'x':
            case 'X':
                delete ActorTree;
                delete PicturesTree;
                return 0;
                break;

            default:
                cout << "Please select valid input" << endl;

                break;
        }
    }
    
   
    return 0;

}
