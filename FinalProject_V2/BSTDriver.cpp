/*Driver program demonstrating creating a tree, adding, finding and deleting nodes
Dr. Augustine 10/30/2017
Status: works with completed and correct BSTree.cpp
*/

/*Template Directions: #include "BSTREEInt.hpp"
but do NOT compile it (or add it to the project)*/
#include <iostream>
#include "functions.hpp"
#include "BSTree.hpp"



using namespace std;

int main()
{
    char menu;
    string ActorFile = "actor-actress.csv";
 
	cout << "Adding Nodes...\n";
    BSTree<GeneralData, string>* ActorTree = new BSTree<GeneralData, string>;
   
    ActorTree -> ReadCSVFile(ActorFile);
//    ActorTree -> deleteNode("Richard Barthelmess");
    
    //test of finding node based on string value.
    Node<GeneralData, string> fNode = *ActorTree -> findNode("Gloria Swanson");
   
    
    ActorTree -> print(cout, ActorTree -> Root() -> Right()-> Data());
//    ActorTree ->printInorder();
    
    
    
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
                //TODO Add a record to Actor-Actress Database
            {

            
              break;
            }

            case 'b':
            case 'B':
                //TODO Add a record to movie database

                break;

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
                //TODO Sort the Actor-Actress database by any field

                break;

            case 'k':
            case 'K':
                //TODO Sort the movie database by any field

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

                return 0;
                break;

            default:
                cout << "Please select valid input" << endl;

                break;
        }
    }
    return 0;

}
