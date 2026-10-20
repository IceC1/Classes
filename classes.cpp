#include<iostream>
#include<vector>
#include<cstring>
#include"media.h"
#include"videogame.h"
using namespace std;

void Add(vector<Media*> &medv) {
  char input[9];
  cout << "What type of media would you like to create? (videogame, music, movie): ";
    cin.getline(input, 10);
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
    
    Videogame* game = new Videogame(title, year, publisher, rating);

    medv.push_back(game);

    }
    else if(!strcmp(input, "music")) {
      
    }
    else if(!strcmp(input, "movie")) {
      
    }
    else {
      cout << "Invalid input" << endl;
    }
    
}

void Search(vector<Media*> medv, char* title, int year) {
  for (vector<Media*>::iterator it = medv.begin(); it != medv.end(); it++) {

  }
}

void Del(vector<Media*> &medv) {

}


int main() {
  Media* list[2];
  vector<Media*> medv;
  char cmd[6];
  char ty;
  char title[30];
  int year;
  bool running = true;
  while(running) {
    cout << "Enter an input (ADD, SEARCH, DELETE): ";
    cin.getline(cmd, 6);
    if(!strcmp(cmd, "ADD")) {
      Add(medv);
      cin.ignore();
    }
    else if(!strcmp(cmd, "SEARCH")) {
      cout << "Would you like to search by title or year? (t/y): ";
      cin >> ty;
      if(ty = 't') {
	cout << "What title would you like to find?: ";
	cin.getline(title, 30);
	Search(medv, title, 0);
      }
      if(ty = 'y') {
	cout << "What year would you like to find?: ";
	cin >> year;
	Search(medv, NULL, year);
      }
      cin.ignore();
    }
    else if(!strcmp(cmd, "DELETE")) {
      Del(medv);
    }
    else {
      cout << "Invalid input" << endl;
    }
  }
}
