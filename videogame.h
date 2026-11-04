#include<iostream>
#include"media.h"

using namespace std;

//Child class of media.
class Videogame : public Media {
 public:
  Videogame(char* title, int year, char* publisher, int rating); //Constructor
  void Print()const; //Outputs the stored information.
  char* getPublisher()const; //Returns the publisher.
  ~Videogame(); //Destructor
  int getRating()const; //Returns the rating.
 protected:
  char* publisher;
  int rating;
};
