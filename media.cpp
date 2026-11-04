#include<iostream>
#include"media.h"

using namespace std;

Media::Media(char* t, int yr) {
  title = t;
  year = yr;
}

//Outputs the stored title and year. 
void Media::Print()const{
  cout << title << endl << "-year: " << year << endl;  
}

//Returns the title of the media.
char* Media::getTitle()const{
  return title;
}

//Deletes the title
Media::~Media() {
  delete[] title;
}

int Media::getYear()const{
  return year;
}
