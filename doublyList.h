// Doubly Linked List
#ifndef _DOUBLY_H_
#define _DOUBLY_H_

/*
  car.h
  Student ID: M00837954
  Created: 12/03/2023
  Updated: 20/04/2023
*/

#include <string>
#include <iostream>
#include "Track.h"

class Node{
 private:
  Track track;
  Node *prev;
  Node *next;

 public:
  // constructor
  Node(Node* head, Track track){
    this->value = track;
    this->next = NULL;
    this->prev = head.next;
  }

  // destructor
  ~Node() {
    Node *head = this;
    while (head != NULL){
      node *
    }
  }
}

#endif

