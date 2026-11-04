#include<iostream>
#include"videogame.h"

using namespace std;

//Constructor
Videogame::Videogame(char* t, int yr, char* pub, int rat): Media(t, yr) {
  publisher = pub;
  rating = rat;
    }

//Outputs the publisher and rating.
void Videogame::Print()const{
  cout << "Videogame: ";
  Media::Print();
  cout << "-publisher: " << publisher << endl << "-rating: " << rating << endl;
}

//Returns the publisher.
char* Videogame::getPublisher()const{
  return publisher;
}

//Destroys the new char* publisher.
Videogame::~Videogame() {
  delete[] publisher;
}

//Returns the rating.
int Videogame::getRating()const{
  return rating;
}
