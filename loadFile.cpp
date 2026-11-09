/*
  loadFile.cpp
  Student ID: M00837954
  Created: 26/02/2023
  Updated: /2023
*/

#include <iostream>
#include <fstream>
#include <cstring>


/*
  check if file exists
  @param filename
  @return bool
 */
inline bool file_exists (const std::string& filename){
  std::ifstream f(filename.c_str());
  return f.good();
};


/*splits string into multiple substrings where there is a delimiter
 @param line of string to be split
 @return void */


/*TODO: change delimiter to tab*/
void stringSplit(const std::string& line){
  std::string str;
  str = line;
  std::string delimiter = "\t";
  std::vector<std::string> vect;

  size_t position = 0;
  std::string token;
  while ((position = str.find(delimiter)) != std::string::npos){
    token = str.substr(0, position);
    vect.push_back(token);
    str.erase(0, position + delimiter.length());
  }
  vect.push_back(str);
  
  turnIntoClass(vect); /*Change to turn into track objs*/
};




