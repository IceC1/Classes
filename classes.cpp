#include<iostream>
#include<vector>
#include<cstring>
#include"media.h"
#include"videogame.h"
#include"music.h"
#include"movie.h"
using namespace std;

void Add(vector<Media*> &medv) {
  char input[9];
  cout << "What type of media would you like to create? (videogame, music, movie): ";
  cin.getline(input, 10);
  char* title = new char[30];
  int year = 0;
    
  if(!strcmp(input, "videogame")) {
    char* publisher = new char[30];
    int rating = 0;

    cout << "What is the videogame's title?: ";
    cin.getline(title, 30);
    cout << "What is the videogame's publisher?: ";
    cin.getline(publisher, 30);
    cout << "What year was the videogame made?: ";
    cin >> year;
    cout << "What is this videogame's rating?: ";
    cin >> rating;
    
    Videogame* game = new Videogame(title, year, publisher, rating);

    medv.push_back(game);

  }
  else if(!strcmp(input, "music")) {
    char* publisher = new char[30];
    char* artist = new char[30];
    int duration = 0;

    cout << "What is the music's title?: ";
    cin.getline(title, 30);
    cout << "What is the music's publisher?: ";
    cin.getline(publisher, 30);
    cout << "Who is this music's artist?: ";
    cin.getline(artist, 30);
    cout << "What year was the music made?: ";
    cin >> year;
    cout << "What is this music's duration(mins)?: ";
    cin >> duration;
    
    Music* music = new Music(title, year, publisher, artist, duration);

    medv.push_back(music);
  }
  else if(!strcmp(input, "movie")) {
    char* director = new char[30];
    int duration = 0;
    int rating = 0;
    
    cout << "What is this movie's title?: ";
    cin.getline(title, 30);
    cout << "What is this movie's publisher?: ";
    cin.getline(director, 30);
    cout << "What year was this movie made?: ";
    cin >> year;
    cout << "What is this movie's duration(mins)?: ";
    cin >> duration;
    cout << "What is this movie's rating?: ";
    cin >> rating;
    
    Movie* movie = new Movie(title, year, director, duration, rating);

    medv.push_back(movie);
  }
  else {
    cout << "Invalid input" << endl;
  }
    
}

vector<int> Search(vector<Media*> medv, char* title) {
  vector<int> matched;
 
  for (int i = 0; i < medv.size(); i ++) {
    if(!strcmp(medv[i]->getTitle(), title)) {
      matched.push_back(i);
    }
  }
  return matched;
}

vector<int> Search(vector<Media*> medv, int year) {
  vector<int> matched;
 
  for (int i = 0; i < medv.size(); i++) {
    if(medv[i]->getYear() == year) {
      matched.push_back(i);
    }
  }
  
 return matched;
}

void Print(vector<Media*> medv, vector<int> matched) {
  for(int i : matched) {
    medv[i]->Print();
  }
}

void Del(vector<Media*> &medv, vector<int> matched) {
  for(int i: matched) {
    medv[i]->del();
    delete medv[i];
    medv[i] = nullptr;
    medv.erase(medv.begin() + i);
  }
}


int main() {
  Media* list[2];
  vector<Media*> medv;
  vector<int> matched;
  char cmd[7];
  char ty;
  char title[30];
  int year;
  bool running = true;
  while(running) {
    
    cout << "Enter an input (add, search, delete): ";
    cin.getline(cmd, 7);
    cout << "cmd: " << cmd << endl;
    if(!strcmp(cmd, "add")) {
      Add(medv);
      cin.ignore();
    }
    else if(!strcmp(cmd, "search")) {
      cout << "Would you like to search by title or year? (t/y): ";
      cin >> ty;
      cin.ignore();
      if(ty == 't') {
	cout << "What title would you like to search with?: ";
	cin.getline(title, 30);       
	matched = Search(medv, title);
	Print(medv, matched);
      }
      else if(ty == 'y') {
	cout << "What year would you like to search with?: ";
	cin >> year;
	cin.ignore();
	matched = Search(medv, year);
	Print(medv, matched);
      }
    }
    else if(!strcmp(cmd, "delete")) {
      cout << "Would you like to delete by title or year? (t/y): ";
      cin >> ty;
      cin.ignore();
      if(ty == 't') {
	cout << "What title would you like to delete?: ";
	cin.getline(title, 30);       
	matched = Search(medv, title);
	Del(medv, matched);
      }
      else if(ty == 'y') {
	cout << "What year would you like to delete?: ";
	cin >> year;
	cin.ignore();
	matched = Search(medv, year);
	Del(medv, matched);
      }
    }
    else {
      cout << "Invalid input" << endl;
      cin.clear();
    }
  }
}
