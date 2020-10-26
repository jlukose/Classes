#ifndef movie_h
#define movie_h

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Movie : public Media{
 public:
  Movie();
  virtual int getType();
  char* getDirector();
  int* getDuration();
  float* getRating();
 private:
  char director[20];
  int duration;
  float rating;
};

#endif
