#include "functions.hpp"
//
//
////int menu(){
////    char menu;
//    string ActorFile = "actor-actress.csv";
////
////    //Build actor/Actress binary tree from CSV file
////    BSTree<Node, string> ActorTree = ReadCSVFile(ActorFile);
////
////    //showing actor tree
////    ActorTree;
////
//////    ActorTree.removeNode("Janet Gaynor");          //TODO... currently at leftchild == null, loops with new left child, not old...
//////    ActorTree.printInOrder();
////
////    ActorTree;
////    //Build pictures binary tree
////
////
////    //Build nominations tree
////
//
//
////    while (menu != 'x' || menu != 'X'){
//        cout << "Binary Search tree for Film Database" << endl;
//        cout << "A: Add a record to Actor-Actress Database" << endl;
//        cout << "B: Add a record to movie database" << endl;
//        cout << "C: Add a record to nominations Database --extra credit--" << endl;
//        cout << "D: Search for a record in Actor-Actress Database and MODIFY field" << endl;
//        cout << "E: Search for a record in movie database and MODIFY field." << endl;
//        cout << "F: Search for a record in Nominations Database and MODIFY field. --extra credit--" << endl;
//        cout << "G: Search for record in Actor Actress Database and DELETE the field" << endl;
//        cout << "H: Search for a record in movie database and DELETE field" << endl;
//        cout << "I: Search for a record in the Nominations Database and DELETE field --extra credit--" << endl;
//        cout << "J: Sort the Actor-Actress database by any field" << endl;
//        cout << "K: Sort the movie database by any field" << endl;
//        cout << "L: Sort the Nominations databse by any field --extra credit--" << endl;
//        cout << "M: Complete search the Actor-Actress database" << endl;
//        cout << "N: Complete search the movie database" << endl;
//        cout << "O: Complete search the Nominations database --extra credit--" << endl;
//        cout << "P: Partial search the Actor-Actress database" << endl;
//        cout << "Q: Partial search the Movie database" << endl;
//        cout << "R: Partial search the nomiations Database --Extra credit--" << endl;
//        cout << "X: Exit" << endl;
//
//        cout << "Please enter your selection: ";
//        cin >> menu;
//        cout << endl;
//
//        switch (menu) {
//            case 'a':
//            case 'A':
//                //TODO Add a record to Actor-Actress Database
//            {
//
//              break;
//            }
//
//            case 'b':
//            case 'B':
//                //TODO Add a record to movie database
//
//                break;
//
//            case 'c':
//            case 'C':
//                //TODO add a record to nominations Database --extra credit--
//
//                break;
//
//            case 'd':
//            case 'D':
//                //TODO search for a record in Actor-Actress Database and MODIFY field
//
//                break;
//
//            case 'e':
//            case 'E':
//                //TODO search for a record in movie database and MODIFY field.
//
//                break;
//
//            case 'f':
//            case 'F':
//                //TODO search for a record in Nominations Database and MODIFY field. --extra credit--
//                break;
//
//            case 'g':
//            case 'G':
//                //TODO search for record in Actor Actress Database and DELETE the field
//
//                break;
//
//            case 'h':
//            case 'H':
//                //TODO search for a record in movie database and DELETE field
//
//                break;
//
//            case 'i':
//            case 'I':
//                //TODO search for a record in the Nominations Database and DELETE field --extra credit--
//
//                break;
//
//            case 'j':
//            case 'J':
//                //TODO Sort the Actor-Actress database by any field
//
//                break;
//
//            case 'k':
//            case 'K':
//                //TODO Sort the movie database by any field
//
//                break;
//
//            case 'l':
//            case 'L':
//                //TODO Sort the Nominations databse by any field --extra credit--
//
//                break;
//
//            case 'm':
//            case 'M':
//                //TODO complete search the Actor-Actress database
//
//                break;
//
//            case 'n':
//            case 'N':
//                //TODO complete search the movie database
//
//                break;
//
//            case 'o':
//            case 'O':
//                //TODO complete search the Nominations database --extra credit--
//
//                break;
//
//            case 'p':
//            case 'P':
//                //TODO Partial search the Actor-Actress database
//
//                break;
//
//            case 'q':
//            case 'Q':
//                //TODO partial search the Movie database
//
//                break;
//
//            case 'r':
//            case 'R':
//                //TODO Partial search the nomiations Database --Extra credit--
//
//                break;
//
//            case 'x':
//            case 'X':
//
//                return 0;
//                break;
//
//            default:
//                cout << "Please select valid input" << endl;
//
//                break;
//        }
////    }
//
////
////    return 0;
////}
//
//




//using member function.. this was used as template.

//template <typename DATATYPE, typename KEYTYPE>
//BSTree<DATATYPE,KEYTYPE> ReadCSVFile(string filename){
//
//    std::ifstream infile;
//    int _Year = 0;
//    bool _Winner = 0;
//    string _Award,_Name, _Film;
//    BSTree<DATATYPE,KEYTYPE> B;
//
//    infile.open(filename);
//
//    if(!infile.is_open()){cout << "Error" << endl;}
//
//    //this gets the first line of the csv file and "trashes" it
//    getline(infile, _Award,'\n');
//    while (!infile.eof()) {
//        //Year,Award,Winner,Name,Film
//        infile >> _Year;
//        infile.ignore();
//        getline(infile,_Award,',');
//        infile >> _Winner;
//        infile.ignore();
//        getline(infile,_Name,',');
//        getline(infile,_Film,'\n');
//        GeneralData* newEntry = new GeneralData(_Year, _Award, _Winner, _Name, _Film);
//
//
//
//        B.addNode(_Name, *newEntry);
//    }
//
//    infile.close();
//
//    return B;
//}
