#include<iostream>
#include"movie.h"

using namespace std;

Movie::Movie(char* t, int yr, char* dir, int dur, int rat): Media(t, yr) {
  director = dir;
  duration = dur;
  rating = rat;
}

void Movie::Print()const{
  cout << "Movie: ";
  Media::Print();
  cout << "-director: " << director << endl << "-duration: " << duration << endl << "-rating: " << rating << endl;
}


char* Movie::getDirector()const{
  return director;
}

void Movie::del() {
  delete[] director;
  director = nullptr;
  Media::del();
}

int Movie::getDuration()const{
  return duration;
}

int Movie::getRating()const{
  return rating;
}
