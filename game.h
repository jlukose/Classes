#ifndef game_h
#define game_h
#include <iostream> 
#include <cstring>
#include "media.h" 

using namespace std; 

class Game : public Media{
 public:
  Game(); 
  virtual int getType();
  char* getPublisher();
  float* getRating();
 private:  
  char publisher[20];
  float rating;
};

#endif
