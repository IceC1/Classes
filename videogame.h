#include<iostream>
#include"media.h"

using namespace std;

class Videogame : public Media {
 public:
  Videogame(char* title, int year, char* publisher, int rating);
  void Print()const;
  char* getPublisher()const;
  int getRating()const;
 protected:
  char* publisher;
  int rating;
};
