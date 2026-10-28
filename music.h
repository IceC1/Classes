#include<iostream>
#include"media.h"

using namespace std;

class Music : public Media {
 public:
  Music(char* title, int year, char* publisher, char* artist, int duration);
  void Print()const;
  char* getPublisher()const;
  char* getArtist()const;
  void del();
  int getDuration()const;
 protected:
   char* publisher;
   char* artist;
   int duration;
};
