/*
  myShoeString.hpp

  header file for my string class
*/
#ifndef MYSHOESTRING_HPP_INCLUDED
#define MYSHOESTRING_HPP_INCLUDED

#include <cstring>
#include <iosfwd>
#include <string>
#include <iostream>
#include <cassert>

struct myShoeString
{
  // Defines the npos value. Use for methods.
  static constexpr std::size_t npos = -1;
  char *myString;
  int laceLength;

  // Constructors
  myShoeString();
  myShoeString(const char* NikeStr);
  myShoeString(const myShoeString& Shoe);
  myShoeString(const char* Shoe, const int& num);

  // Destructor
  ~myShoeString();

  // Function Declarations
  bool empty() const;
  char* data();
  myShoeString substr(const int&, const int&) const;
  int find(const char&) const;

  // Operator Overloaded Declarations
  myShoeString operator=(const myShoeString&);
  char operator=(char&) const;
  char& operator[](const int&) const;
  bool operator==(const char*) const;
  bool operator==(const myShoeString&) const;
  bool operator!=(const myShoeString&) const;
  bool operator!=(const char*) const;
  bool operator<(const myShoeString&) const;
  bool operator<(const char*) const;
  bool operator>(const myShoeString&) const;
  bool operator>(const char*) const;
  bool operator<=(const myShoeString&) const;
  bool operator>=(const myShoeString&) const;
  myShoeString operator+(const myShoeString&) const;
  void operator+=(const myShoeString&);
};

#endif // MYSHOESTRING_HPP_INCLUDED
