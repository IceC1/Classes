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

vector<Media*> Search(vector<Media*> medv, char* title) {
  vector<Media*> matched;

  // Brady told me this.
  for (Media* m: medv) {
    if(m->getTitle() == title) {
      matched.push_back(m);
    }
  }
  return matched;
}

vector<Media*> Search(vector<Media*> medv, int year) {
  vector<Media*> matched;
  
  for (Media* m: medv) {
    if(m->getYear() == year) {
      matched.push_back(m);
    }
  }

  return matched;
}

void Print(vector<Media*> matched) {
  for(Media* m : matched) {
    m->Print();
  }
}

void Del(vector<Media*> &medv) {

}


int main() {
  Media* list[2];
  vector<Media*> medv;
  vector<Media*> matched;
  char cmd[7];
  char ty;
  char title[30];
  int year;
  bool running = true;
  while(running) {
    
    cout << "Enter an input (ADD, SEARCH, DELETE): ";
    cin.getline(cmd, 7);
    cout << "cmd: " << cmd << endl;
    if(!strcmp(cmd, "ADD")) {
      Add(medv);
      cin.ignore();
    }
    else if(!strcmp(cmd, "SEARCH")) {
      cout << "Would you like to search by title or year? (t/y): ";
      cin >> ty;
      cin.ignore();
      if(ty == 't') {
	cout << "What title would you like to find?: ";
	cin.getline(title, 30);
	matched = Search(medv, title);
	Print(matched);
      }
      if(ty == 'y') {
	cout << "What year would you like to find?: ";
	cin >> year;
	cin.ignore();
	matched = Search(medv, year);
	Print(matched);
      }
      cin.ignore();
    }
    else if(!strcmp(cmd, "DELETE")) {
      Del(medv);
    }
    else {
      cout << "Invalid input" << endl;
      cin.clear();
    }
  }
}
