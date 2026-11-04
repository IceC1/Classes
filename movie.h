#include<iostream>
#include"media.h"

using namespace std;
//Child class of media that stores director, duration, and rating of a movie.
class Movie : public Media {
 public:
  Movie(char* title, int year, char* director, int duration, int rating);//Constructor
  void Print()const; // Prints the information stored in the class.
  char* getDirector()const; // Returns a char* of the director.
  ~Movie(); // Destructor
  int getDuration()const;// Returns an int of the duration.
  int getRating()const; // Returns an int of the rating.
 protected:
  char* director;
  int duration;
  int rating;
};
