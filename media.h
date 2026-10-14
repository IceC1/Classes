#ifndef MEDIA
#define MEDIA
#include<iostream>

using namespace std;

class Media {
public:
  Media(char* t, int yr);
protected:
  virtual char* getTitle()const;
  virtual int getYear()const;
  char* title;
  int year;
};

#endif
