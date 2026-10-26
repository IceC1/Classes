#include<iostream>
#include"media.h"

using namespace std;

Media::Media(char* t, int yr) {
  title = t;
  year = yr;
}

void Media::Print()const{
  cout << "hi";  
}

char* Media::getTitle()const{
  return title;
}

void Media::del() {
  delete[] title;
  title = nullptr;
}

int Media::getYear()const{
  return year;
}
