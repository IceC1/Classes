#ifndef MEDIA
#define MEDIA
#include<iostream>

using namespace std;

//Parent class of each media type that stores title and year.
class Media {
public:
  Media(char* t, int yr);
  virtual void Print()const; //Prints the media's title and year.
  virtual char* getTitle()const; //Returns a char* of the media"s title
  ~Media(); //Handles the memory deletion of the char* title on the heap.
  virtual int getYear()const; //Returns an int of the media's year
protected:
  char* title;
  int year;
};

#endif
