#ifndef TOWN_H
#define TOWN_H

using namespace std;

const int TOWN_MAX_SIZE = 25;
 

class Town{
  private:
  char m_grid[TOWN_MAX_SIZE][TOWN_MAX_SIZE];  
  int m_size;
  
  void clear();
  void build();  

  public:
  Town(const int size = TOWN_MAX_SIZE);

  friend ostream & operator<<(ostream &outs,const Town &a);
  int getSize() const{return m_size;}
  void s(char a)
};

#endif
