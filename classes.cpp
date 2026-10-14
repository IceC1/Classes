#include<iostream>
#include<cstring>
#include "media.h"

using namespace std;

Add(vector<*Media> &medv) {
  char type[9];
  cout << "What type of media would you like to create? (videogame, music, movie): "
    cin.getline(input, 9);
  
  if(!strcmp(input, "videogame") {
      
    }
    else if(!strcmp(input, "music")) {
      
    }
    else if(!strcmp(input, "movie")) {
      
    }
    else {
      cout << "Invalid input" << endl;
    }
    
}

Search(vector<*Media> medv) {

}

Delete(vector<*Media> &medv) {

}


int main() {
  vector<*Media> medv;
  char input[6];

  cout << "Enter an input (ADD, SEARCH, DELETE): ";
  cin.getline(input, 6);
  if(!strcmp(input, "ADD") {
      Add(medv);
    }
    else if(!strcmp(input, "SEARCH")) {
      Search(medv);
    }
    else if(!strcmp(input, "DELETE")) {
      Delete(medv);
    }
    else {
      cout << "Invalid input" << endl;
    }
      
}
