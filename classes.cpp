//Classes by Joshua Lukose October 2020
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include "media.h"
#include "game.h"
#include "music.h"
#include "movie.h"

using namespace std;
//initialization and function prototypes
void mediaadd(vector<Media*>* media, int type);
void mediasearch(vector<Media*>* media);
void mediadelete(vector<Media*>* media);
char input[20];

int main(){
  vector<Media*> mediaV;
  while(true){
    cout << "Commands: ADD, SEARCH, DELETE, QUIT" << endl;
    cin.get(input, 20);
    cin.clear();
    cin.ignore(256, '\n');
    if (strcmp(input, "ADD") == 0){//add function
      while(true){
	cout << "'GAME', 'MUSIC', or 'MOVIE'?" << endl;
	cin.get(input, 20);
	cin.clear();
	cin.ignore(256, '\n');
	if (strcmp(input, "GAME") == 0){
	  mediaadd(&mediaV, 0);
	  break;
	}
	if (strcmp(input, "MUSIC") == 0){
	  mediaadd(&mediaV, 1);
	  break;
	}
	if (strcmp(input, "MOVIE") == 0){
	  mediaadd(&mediaV, 2);
	  break;
	}
      }
    }
    if (strcmp(input, "SEARCH") == 0){//search function
      mediasearch(&mediaV);
    }
    if (strcmp(input, "DELETE") == 0){//delete function
      mediadelete(&mediaV);
    }
    if (strcmp(input, "QUIT") == 0){//quit
      return 0;
    }
  }
}

void mediaadd(vector<Media*>* media, int type){//add method
  if (type == 0){//add game
    Game* ngame = new Game();
    cout << "Enter title" << endl;
    cin.get(ngame -> getTitle(), 20);
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Enter year" << endl;
    cin >> *ngame -> getYear();
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Enter publisher" << endl;
    cin.get(ngame -> getPublisher(), 20);
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Enter rating" << endl;
    cin >> *ngame -> getRating();
    cin.clear();
    cin.ignore(256, '\n');
    media->push_back(ngame);
  }
  if (type == 1){//add music
    Music* nmusic = new Music();
    cout << "Enter title" << endl;
    cin.get(nmusic -> getTitle(), 20);
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Enter year" << endl;
    cin >> *nmusic -> getYear();
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Enter artist" << endl;
    cin.get(nmusic -> getArtist(), 20);
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Enter duration" << endl;
    cin >> *nmusic -> getDuration();
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Enter publisher" << endl;
    cin >> *nmusic -> getPublisher();
    cin.clear();
    cin.ignore(256, '\n');
    media->push_back(nmusic);
  }
  if (type == 2){//add movie
    Movie* nmovie = new Movie();
    cout << "Enter title" << endl;
    cin.get(nmovie -> getTitle(), 20);
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Enter year" << endl;
    cin >> *nmovie -> getYear();
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Enter director" << endl;
    cin.get(nmovie -> getDirector(), 20);
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Enter duration" << endl;
    cin >> *nmovie -> getDuration();
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Enter rating" << endl;
    cin >> *nmovie -> getRating();
    cin.clear();
    cin.ignore(256, '\n');
    media->push_back(nmovie);
  }
}

void mediasearch(vector<Media*>* media){//search method
  char title[20];
  int year;
  cout << "Search by 'TITLE' or by 'YEAR'?" << endl;
  cin.get(input, 20);
  cin.clear();
  cin.ignore(256, '\n');
  if (strcmp(input, "TITLE") == 0){//search by title
    cout << "Enter title" << endl;
    cin.get(title, 20);
    cin.clear();
    cin.ignore(256, '\n');
  }
  if (strcmp(input, "YEAR") == 0){//search by year
    cout << "Enter year" << endl;
    cin >> year;
    cin.clear();
    cin.ignore(256, '\n');
  }
  vector<Media*>::iterator i;
  for (i = media -> begin(); i != media -> end(); i++){//uses iterator to go through all movies
    if (strcmp((*i) -> getTitle(), title) == 0 || *(*i) -> getYear() == year){//check title or year
      if((*i) -> getType() == 0){//game
	cout << "Type: Game" << endl;
	cout << "Title: " << (*i) -> getTitle() << endl;
	cout << "Year: " << *(*i) -> getYear() << endl;
	cout << "Publisher: " << dynamic_cast<Game*>(*i) -> getPublisher() << endl;
	cout << "Rating: " << *dynamic_cast<Game*>(*i) -> getRating() << endl << endl;
      }
      if((*i) -> getType() == 1){//music
	cout << "Type: Music" << endl;
	cout << "Title: " << (*i) -> getTitle() << endl;
	cout << "Year: " << *(*i) -> getYear() << endl;
	cout << "Artist: " << dynamic_cast<Music*>(*i) -> getArtist() << endl;
	cout << "Duration: " << *dynamic_cast<Music*>(*i) -> getDuration() << endl;
	cout << "Publisher: " << dynamic_cast<Music*>(*i) -> getPublisher() << endl << endl;
      }
      if((*i) -> getType() == 2){//movie	
	cout << "Type: Movie" << endl;
	cout << "Title: " << (*i) -> getTitle() << endl;
	cout << "Year: " << *(*i) -> getYear() << endl;
	cout << "Director: " << dynamic_cast<Movie*>(*i) -> getDirector() << endl;
	cout << "Duration: " << *dynamic_cast<Movie*>(*i) -> getDuration() << endl;
	cout << "Rating: " << *dynamic_cast<Movie*>(*i) -> getRating() << endl << endl;
      }
    }
  }
}

void mediadelete(vector <Media*>* media){//delete method
  char title[20];
  int year;
  char answer;
  cout << "Search by 'TITLE' or by 'YEAR'?" << endl;
  cin.get(input, 20);
  cin.clear();
  cin.ignore(256, '\n');
  if (strcmp(input, "TITLE") == 0){//search by title
    cout << "Enter title" << endl;
    cin.get(title, 20);
    cin.clear();
    cin.ignore(256, '\n');
  }
  if (strcmp(input, "YEAR") == 0){//search by year
    cout << "Enter year" << endl;
    cin >> year;
    cin.clear();
    cin.ignore(256, '\n');
  }
  vector<Media*>::iterator i;
  for (i = media -> begin(); i != media -> end(); i++){//uses iterator to go through all media
    if (strcmp((*i) -> getTitle(), title) == 0 || *(*i) -> getYear() == year){//check title or year
      if((*i) -> getType() == 0){//game
	cout << endl << "Type: Game" << endl;
	cout << "Title: " << (*i) -> getTitle() << endl;
	cout << "Year: " << *(*i) -> getYear() << endl;
	cout << "Publisher: " << dynamic_cast<Game*>(*i) -> getPublisher() << endl;
	cout << "Rating: " << *dynamic_cast<Game*>(*i) -> getRating() << endl << endl;
      }
      if((*i) -> getType() == 1){//music
	cout << endl << "Type: Music" << endl;
	cout << "Title: " << (*i) -> getTitle() << endl;
	cout << "Year: " << *(*i) -> getYear() << endl;
	cout << "Artist: " << dynamic_cast<Music*>(*i) -> getArtist() << endl;
	cout << "Duration: " << *dynamic_cast<Music*>(*i) -> getDuration() << endl;
	cout << "Publisher: " << dynamic_cast<Music*>(*i) -> getPublisher() << endl << endl;
      }
      if((*i) -> getType() == 2){//movie	
	cout << endl << "Type: Movie" << endl;
	cout << "Title: " << (*i) -> getTitle() << endl;
	cout << "Year: " << *(*i) -> getYear() << endl;
	cout << "Director: " << dynamic_cast<Movie*>(*i) -> getDirector() << endl;
	cout << "Duration: " << *dynamic_cast<Movie*>(*i) -> getDuration() << endl;
	cout << "Rating: " << *dynamic_cast<Movie*>(*i) -> getRating() << endl << endl;
      }
      cout << "Are you sure you want to delete this? (y/n)" << endl;//confirms delete
      cin >> answer;
      cin.clear();
      cin.ignore(256, '\n');
      if (answer == 'y'){//deletes the media
	delete *i;
	i = media -> erase(i);
	i--;
      }
    }
  }
}
