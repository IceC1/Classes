#ifndef MEDIA
#define MEDIA
#include<iostream>

using namespace std;

class Media {
public:
  Media(char* t, int yr);
  
  virtual char* getTitle()const;
  virtual int getYear()const;
protected:
  char* title;
  int year;
};

#endif
