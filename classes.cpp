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

    cout << game->getTitle();
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

vector<int> Search(vector<Media*> medv, char* title) {
  vector<int> matched;
 
  for (vector<Media*>::iterator it = medv.begin(); it != medv.end(); it ++) {
      if(!strcmp(m->getTitle(), title)) {
      matched.push_back(m);
    }
  }
  return matched;
}

vector<int> Search(vector<Media*> medv, int year) {
  vector<int> matched;
  
  for (Media* m: medv) {
    if(m->getYear() == year) {
      matched.push_back(m);
    }
  }
  return matched;
}

void Print(vector<Media*> medv) {
  for(Media* m : matched) {
    m->Print();
  }
}

void Del(vector<Media*> &medv) {
  for(Media* m: matched) {
    m->del();
    delete m;
  }
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
	cout << "What title would you like to search with?: ";
	cin.getline(title, 30);       
	matched = Search(medv, title);
	Print(matched);
      }
      else if(ty == 'y') {
	cout << "What year would you like to search with?: ";
	cin >> year;
	cin.ignore();
	matched = Search(medv, year);
	Print(matched);
      }
    }
    else if(!strcmp(cmd, "DELETE")) {
      cout << "Would you like to delete by title or year? (t/y): ";
      cin >> ty;
      cin.ignore();
      if(ty == 't') {
	cout << "What title would you like to delete?: ";
	cin.getline(title, 30);       
	matched = Search(medv, title);
	Del(matched);
      }
      else if(ty == 'y') {
	cout << "What year would you like to delete?: ";
	cin >> year;
	cin.ignore();
	matched = Search(medv, year);
	Del(matched);
      }
    }
    else {
      cout << "Invalid input" << endl;
      cin.clear();
    }
  }
}
