#include<iostream>
#include"videogame.h"

using namespace std;

Videogame::Videogame(char* t, int yr, char* pub, int rat): Media(t, yr) {
  publisher = pub;
  rating = rat;
    }

void Videogame::Print()const{
  cout << "Videogame: " << title << ", published: " << year << ", by " << publisher << ", rated: " << rating << endl;
}

char* Videogame::getPublisher()const{
  return publisher;
}
int Videogame::getRating()const{
  return rating;
}
