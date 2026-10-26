#include<iostream>
#include"videogame.h"

using namespace std;

Videogame::Videogame(char* t, int yr, char* pub, int rat): Media(t, yr) {
  publisher = pub;
  rating = rat;
    }

void Videogame::Print()const{
  cout << "Videogame: " << title << endl << ", by " << publisher << endl << ", published: " << year << endl << ", rated: " << rating << endl;
}

char* Videogame::getPublisher()const{
  return publisher;
}

void Videogame::del() {
  delete[] publisher;
  publisher = nullptr;
  Media::del();
}

int Videogame::getRating()const{
  return rating;
}
