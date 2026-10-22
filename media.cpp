#include<iostream>
#include"media.h"

using namespace std;

Media::Media(char* t, int yr) {
  title = t;
  year = yr;
}

void Media::Print()const {
  
}

char* Media::getTitle()const{
  return title;
}

int Media::getYear()const{
  return year;
}
