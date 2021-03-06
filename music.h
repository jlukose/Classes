#ifndef music_h
#define music_h

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Music : public Media{
 public:
  Music();
  virtual int getType();
  char* getArtist();
  int* getDuration();
  char* getPublisher();
 private:
  char artist[20];
  int duration;
  char publisher[20];
};

#endif
