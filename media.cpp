#include<iostream>
#include"media.h"

using namespace std;

Media::Media(char* t, int yr) {
  title = t;
  year = yr;
}

char* Media::getTitle() {
  return title;
}

int Media::getYear() {
  return year;
}
