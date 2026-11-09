/*
  track.cpp
  Student ID: M00837954
  Created: 26/02/2023
  Updated: /2022
*/

#include "track.h"
#include <string>
#include <iostream>


Track::Track( std::string title,
	      std::string artist,
	      int duration)
{
  this->title = title;
  this->artist = artist;
  this->duration = duration
}


Track::~Track(){
}


std::string getTitle(){
  return title;
}


std::string getArtist(){
  return artist;
}


int getDuration(){
  return duration;
}
