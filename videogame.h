#include<iostream>
#include"media.h"

using namespace std;

class Videogame : public Media {
 public:
  Videogame(char* publisher, int rating);
  char* getPublisher()const;
  int getYear()const;
 protected:
  char* publisher;
  int rating;
};
