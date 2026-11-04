#include<iostream>
#include"movie.h"

using namespace std;

// Constructor
Movie::Movie(char* t, int yr, char* dir, int dur, int rat): Media(t, yr) {
  director = dir;
  duration = dur;
  rating = rat;
}

// Prints out each variable stored. 
void Movie::Print()const{
  cout << "Movie: ";
  Media::Print();
  cout << "-director: " << director << endl << "-duration: " << duration << endl << "-rating: " << rating << endl;
}

// Returns the director of the movie.
char* Movie::getDirector()const{
  return director;
}

// Destructor
Movie::~Movie() {
  delete[] director;
}

// Returns the duration of the movie.
int Movie::getDuration()const{
  return duration;
}

// Returns the rating of the movie.
int Movie::getRating()const{
  return rating;
}
