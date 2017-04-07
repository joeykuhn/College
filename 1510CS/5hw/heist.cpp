#include <iostream>

bool solve(char x, char y, char **maze);

int main()
{
  char **maze, bendr, bendcol;
  int cs, rs = 1;

  for (int m = 0; ; m++)
  {
    std::cin >> rs >> cs;
    if (rs == 0 && cs == 0)
      break;
    std::cout << "Map : "<< m << std::endl;
    std::cin.ignore();

    maze = new char *[rs];
    for (int i = 0; i < rs; i++)
    {
      maze[i] = new char[cs];
    }

    char dummy;
    for (int i = 0; i < rs; i++)
    {
      for (int j = 0; j < cs; j++)
      {
        std::cin.get(maze[i][j]);
        if (maze[i][j] == 'B')
        {
          bendr = i;
          bendcol = j;
        }
      }
      std::cin.get(dummy);
    }

    solve(bendcol, bendr, maze);

    for(int k=0; k < rs; k++)
  {
    for(int j=0; j < cs; j++)
    {
      std::cout << maze[k][j];
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  for(int k=0; k < rs; k++)
  {
    delete [] maze[k];
  }
  delete [] maze;

  }

  return 0;
}

bool solve(char x, char y, char **maze)
{
  int tx, ty = 0;
  for (int i = 0;i < 4 ; i++)
  {
    switch(i)
    {
      case 0:
          tx = x;
          ty = y+1;
          break;
      case 1:
          tx = x;
          ty = y-1;
          break;
      case 2:
         tx = x+1;
         ty = y;
         break;
      case 3:
         tx = x-1;
         ty = y;
         break;
    }
    if (maze[ty][tx] == ' ' || maze[ty][tx] == 'E')
    {
      if (maze[ty][tx] == 'E')
        return true;
      else
      {
        (maze[ty][tx] == 'B')? true : maze[ty][tx] ='.';
        bool solved = solve(tx,ty, maze);
        if (solved)
          return true;
        else
          (maze[ty][tx] == 'B')? true : maze[ty][tx] =' ';
      }
    }
  }
  return false;

}
