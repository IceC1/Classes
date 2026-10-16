#include<iostream>
#include<vector>
#include<cstring>
#include"media.h"
#include"videogame.h"
using namespace std;

void Add(vector<Media*> &medv) {
  char input[9];
  cout << "What type of media would you like to create? (videogame, music, movie): ";
    cin.getline(input, 9);
    char* title = new char[30];
    char t[30];
    int year = 0;
    
  if(!strcmp(input, "videogame")) {
    char* publisher = new char[30];
    char p[30];
    int rating = 0;

    cout << "What is the videogames title?: ";
    cin.getline(t, 30);
    strcpy(title, t);
    cout << "What is the videogames publisher?: ";
    cin.getline(p, 30);
    strcpy(publisher, p);
    cout << "What year was the videogame made?: ";
    cin >> year;
    cout << "What is this videogames rating?: ";
    cin >> rating;
    
    Videogame game = new Videogame(title, year, publisher, rating);

    cout << game.getTitle() << endl;
    cout << game.getYear() << endl;
    cout << game.getPublisher() << endl;
    cout << game.getRating() << endl;
    }
    else if(!strcmp(input, "music")) {
      
    }
    else if(!strcmp(input, "movie")) {
      
    }
    else {
      cout << "Invalid input" << endl;
    }
    
}

void Search(vector<Media*> medv) {

}

void Del(vector<Media*> &medv) {

}


int main() {
  Media* list[2];
  vector<Media*> medv;
  char input[6];

  cout << "Enter an input (ADD, SEARCH, DELETE): ";
  cin.getline(input, 6);
  if(!strcmp(input, "ADD")) {
      Add(medv);
    }
    else if(!strcmp(input, "SEARCH")) {
      Search(medv);
    }
    else if(!strcmp(input, "DELETE")) {
      Del(medv);
    }
    else {
      cout << "Invalid input" << endl;
    }
      
}
