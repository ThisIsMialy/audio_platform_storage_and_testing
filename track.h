#ifndef _TRACK_H_
#define _TRACK_H_


/*
  track.h
  Student ID: M00837954
  Created: 26/02/2023
  Updated: /2022
*/

#include <string>

class Track
{
 private:
  std::string title;
  std::string artist;
  int duration;

 public:
  Track* (std::string title, std::string artist, int duration);

  virtual ~Track();

  std::string getTitle();
  std::string getArtist();
  int getDuration();

  
};



#endif
