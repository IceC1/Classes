#include<iostream>
#include"music.h"

using namespace std;

Music::Music(char*t, int yr, char*pub, char*art, int dur): Media(t, yr) {
  publisher = pub;
  artist = art;
  duration = dur;
}

void Music::Print()const{
  cout << "Music: ";
  Media::Print();
  cout << "-publisher: " << publisher << endl << "-artist: " << artist << endl << "-duration: " << duration << endl;
}

char* Music::getPublisher()const{
  return publisher;
}

char* Music::getArtist()const{
  return artist;
}

void Music::del() {
  delete[] publisher;
  delete[] artist;
  publisher = nullptr;
  artist = nullptr;
  Media::del();
}

int Music::getDuration()const{
  return duration;
}
