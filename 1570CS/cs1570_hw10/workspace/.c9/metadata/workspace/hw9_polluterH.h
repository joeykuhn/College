{"filter":false,"title":"hw9_polluterH.h","tooltip":"/hw9_polluterH.h","undoManager":{"mark":0,"position":0,"stack":[[{"start":{"row":0,"column":0},"end":{"row":97,"column":0},"action":"insert","lines":["/*","Programmers: Kevin Schoonover","Teacher: Dr. Leopold","Section: 1D","Date: 11/18/2016","Description: This function creates a town of Size defined by user, places both","              an activist and Polluter within the town and moves them four","              times exclusively of one another, printing the state of the town","              each time.","*/","#ifndef HEADER_POL","#define HEADER_POL","","#include \"hw9_townH.h\"","","using namespace std;","","//////////","// Defaults for the classes' member variables","//////////","const char DEFAULT_IDENTIFIER_POL = 'P';","const int START_ROW_POL = -1;","const int START_COLUMN_POL = -1;","","class Polluter","{","  private:","    //////////","    // Initilzation of the private class variables","    //////////","    string m_name;","    int m_row;","    int m_column;","    char m_id;","","  public:","","    //////////","    // Parameterized constructor for the Polluter class which changes the","    // Polluters name.","    //////////","    Polluter(string name)","    {","      m_name = name;","      m_row = START_ROW_POL;","      m_column = START_COLUMN_POL;","      m_id = DEFAULT_IDENTIFIER_POL;","    }","","    //////////","    // Pre: town must be defined and there must be one space wthin the grid","    //      which has EMPTY_IDENTIFIER as its identifier","    // Post: the Polluter instance's identifier will be placed randomly within","    //       the confines of the walls of the grid on a valid location(location","    //       wihch has an EMPTY_IDENTIFIER)","    // Desc: This function randomly places the Polluter instance's identifier","    //       within the confines of the grid on its own tile.","    //////////","    void placeMe(Town &town);","    //////////","    // Pre: town must be defined and the Polluter must have a valid move in","    //      one of the cardinal directions (i.e a adjactent tile must have","    //      empty identifier)","    // Post: The function randomily decides a cardinal direcion to move the","    //       Polluter and move the character identifier to that location on","    //       the grid.","    // Description: This function randomly moves the Polluter in one of the","    //              four cardinal directions if atleast one movement is valid.","    //////////","    void randMove(Town & town);","","    //////////","    // Pre: townMust be defined and newRow and newColumn must be within the","    //      grid size of town.","    // Post: The function sets the identifier in the current Polluter position","    //       to EMPTY_IDENTIFIER and places the instance identiier dY rows","    //       and dX columns away. Also, sets the current position of the","    //       Polluter instance to the new position(i.e. changing m_row and","    //       m_column to accomdiate)","    // Description: The function moves the Polluter instance dY rows and dX","    //              columns away and sets the Polluter instance's position","    //              to the new position","    //////////","    void move_to(Town &town, const int dY, const int dX);","","    //////////","    // Pre: ostream must be open and every member variable within pol must","    //      be defined.","    // Post: The function outputs and formats all of the Polluter's member","    //       variables to the ostream o and returns the ostream for chaining.","    // Description: This function takes the information within pol's member","    //              variables and outputs them to the ostream.","    //////////","    friend ostream& operator <<(ostream& o, const Polluter& pol);","};","","#endif",""],"id":1}]]},"ace":{"folds":[],"scrolltop":658.5,"scrollleft":0,"selection":{"start":{"row":97,"column":0},"end":{"row":97,"column":0},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":0},"timestamp":1479519347074,"hash":"8adbcffe5312461036e3c4a160025d33f559fbf9"}