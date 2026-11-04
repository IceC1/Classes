#include<iostream>
#include"music.h"

using namespace std;

//Constructor
Music::Music(char*t, int yr, char*pub, char*art, int dur): Media(t, yr) {
  publisher = pub;
  artist = art;
  duration = dur;
}

//Outputs the information.
void Music::Print()const{
  cout << "Music: ";
  Media::Print();
  cout << "-publisher: " << publisher << endl << "-artist: " << artist << endl << "-duration: " << duration << endl;
}

//Returns the publisher.
char* Music::getPublisher()const{
  return publisher;
}

//Returns the artist.
char* Music::getArtist()const{
  return artist;
}

//Destructor
Music::~Music() {
  delete[] publisher;
  delete[] artist;
}

//Returns the duration.
int Music::getDuration()const{
  return duration;
}
