#include<iostream>
#include"media.h"

using namespace std;

// Child class of Media that stores publisher, artist, and duration.
class Music : public Media {
 public:
  Music(char* title, int year, char* publisher, char* artist, int duration); // Constructor
  void Print()const; //Prints the stored information.
  char* getPublisher()const; //Returns the publisher.
  char* getArtist()const; // Returns the artist.
  ~Music(); //Destructor, deletes the new char* publisher and artist.
  int getDuration()const; // Returns the duration.
 protected:
   char* publisher;
   char* artist;
   int duration;
};
