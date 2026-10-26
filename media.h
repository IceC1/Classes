#ifndef MEDIA
#define MEDIA
#include<iostream>

using namespace std;

class Media {
public:
  Media(char* t, int yr);
  virtual void Print()const;
  virtual char* getTitle()const;
  virtual void del();
  virtual int getYear()const;
protected:
  char* title;
  int year;
};

#endif
