/* Elijah Chan 11/2/2026
Stores three different child classes of media in a vector and allows the user to interact with it through add, search, and delete..
*/

#include<iostream>
#include<vector>
#include<cstring>
#include"media.h"
#include"videogame.h"
#include"music.h"
#include"movie.h"
using namespace std;

//Adds a videogame, music, or movie to the media vector.
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

//Searchs through the media vector for matching titles and returns a vector of matching int indices. 
vector<int> Search(vector<Media*> medv, char* title) {
  vector<int> matched;
 
  for (int i = 0; i < medv.size(); i ++) {
    if(!strcmp(medv[i]->getTitle(), title)) {
      matched.push_back(i);
    }
  }
  return matched;
}

//Same as above but overloaded for year instead of title.
vector<int> Search(vector<Media*> medv, int year) {
  vector<int> matched;
 
  for (int i = 0; i < medv.size(); i++) {
    if(medv[i]->getYear() == year) {
      matched.push_back(i);
    }
  }
  
 return matched;
}

//Iterates through the vector of matched ints and runs the media's print function.
void Print(vector<Media*> medv, vector<int> matched) {
  for(int i : matched) {
    medv[i]->Print();
  }
}

//Deletes each of the indices from the search function in the media vector.
void Del(vector<Media*> &medv, vector<int> matched) {
  char del;
  int count = 0;
  for(int i: matched) {
    cout << "Would you like to delete: " << endl;
    medv[i]->Print();
    cout << "(y/n): ";
    cin >> del;
    cin.ignore();
    if(del == 'y') {
      delete medv[i - count];
      medv[i - count] = nullptr;
      medv.erase(medv.begin() + (i - count));
      count++;
    }
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

  //Running loop.
  while(running) {
    cout << "Enter an input (add, search, delete, quit): ";
    cin.getline(cmd, 7);
    
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
    else if(!strcmp(cmd, "quit")) {
      running = false;
    }
    else {
      cout << "Invalid input" << endl;
      cin.ignore();
    }
  }
}
