#ifndef POLLUTER_H
#define POLLUTER_H

class POLLUTER
{
  private:
    string m_name;
    char m_x;
    char m_y;
    char m_representation;

  public:
    Polluter(string name, char representation = 'P')
    {
      m_name = name;
      m_representation = representation;
      m_x = -1;
      m_y = -1;
    }

    void placeMe();
}

#endif
