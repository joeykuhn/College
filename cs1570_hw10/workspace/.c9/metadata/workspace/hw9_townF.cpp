{"filter":false,"title":"hw9_townF.cpp","tooltip":"/hw9_townF.cpp","undoManager":{"mark":0,"position":0,"stack":[[{"start":{"row":0,"column":0},"end":{"row":79,"column":0},"action":"insert","lines":["/*","Programmers: Kevin Schoonover","Teacher: Dr. Leopold","Section: 1D","Date: 11/18/2016","Description: This function creates a town of Size defined by user, places both","              an activist and Polluter within the town and moves them four","              times exclusively of one another, printing the state of the town","              each time.","*/","","#include \"hw9_townH.h\"","","Town::Town(const int grid)","{","  if(grid <= MAX && grid <= MAX)","  {","    m_townSize_r = grid;","    m_townSize_c = grid;","    clear();","    build(grid, grid);","  }","  else","  {","    cout << \"[Error] Initializing town class with variable > MAX, please \"","         << \"try again.\" << endl;","  }","}","","void Town::clear()","{","  for(int i = 0; i < MAX; i++)","  {","    for(int j = 0; j < MAX; j++)","    {","      m_townSpace[i][j] = EMPTY_IDENTIFIER;","    }","  }","","  return;","}","","void Town::build(const int rows, const int columns)","{","  for(int i = 0; i < rows; i++)","  {","    for(int j = 0; j < columns; j++)","    {","      if(i == 0 || j == 0 || i == (rows - 1) || j == (columns - 1))","      {","        if(i == (rows - 1)/2 || j == (columns - 1)/2)","        {","          m_townSpace[i][j] = EXIT_IDENTIFIER;","        }","        else","        {","          m_townSpace[i][j] = WALL_IDENTIFIER;","        }","      }","    }","  }","","  return;","}","","ostream& operator <<(ostream &out, const Town& town)","{","  for(int i = 0; i < town.m_townSize_r; i++)","  {","    for(int j = 0; j < town.m_townSize_c; j++)","    {","      cout << town.m_townSpace[i][j];","    }","","    cout << endl;","  }","","  return(out);","}",""],"id":1}]]},"ace":{"folds":[],"scrolltop":0,"scrollleft":0,"selection":{"start":{"row":79,"column":0},"end":{"row":79,"column":0},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":{"row":60,"state":"start","mode":"ace/mode/c_cpp"}},"timestamp":1479519360555,"hash":"d5ebfba4ee22693a8350c95141552be489609c36"}