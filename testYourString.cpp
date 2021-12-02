/*
   testYourString.cpp

   This file calls and tests my string class constructors, overloaded operators, etc.

   asserts() are used to guarantee functionality 
*/

#include "myShoeString.hpp"

// Output
std::ostream& operator<<(std::ostream&, myShoeString const&);

// Encapsulate all of the String tests.
struct Test_string
{
  void default_ctor()
  {
    // Check the default contructor.
    myShoeString s;
    assert(s.empty());
  }

  void string_ctor()
  {
    char const* str = "hello";
    myShoeString s = str;
    assert(s.data() != str);
    assert(strcmp(s.data(), str) == 0);
  }


  void copy_ctor()
  {
    myShoeString s1 = "hello";
    myShoeString s2 = s1;
    assert(strcmp(s1.data(), s2.data()) == 0);
  }

  void copy_assign()
  {
    myShoeString s1 = "hello";
    myShoeString s2;
    s2 = s1;
    assert(strcmp(s1.data(), s2.data()) == 0);
  }

  void string_assign()
  {
    myShoeString s;
    s = "hello";
    assert(!strcmp(s.data(), "hello"));
  }

  void self_assign()
  {
    myShoeString s1 = "hello";
    s1 = s1;
  }

  void empty()
  {
    myShoeString const s1;
    assert(s1.empty());
    myShoeString const s2 = "";
    assert(s2.empty());
  }

  void access()
  {
    myShoeString s1 = "hello";
    s1[0] = 'a';
    assert(s1[0] == 'a');

    myShoeString const s2 = "test";
    assert(s2[0] == 't');

    assert(s1[-1]);
    assert(s2[-1]);
  }

  void find()
  {
    myShoeString const s1 = "abcdef";
    assert(s1.find('c') == 2);
    assert(s1.find('z') == s1.npos);
  }

  void substr()
  {
    myShoeString const s1 = "abcdef";
    myShoeString s2 = s1.substr(0, 3);
    myShoeString s3 = s1.substr(3, 3);
    assert (s2 == "abc");
    assert (s3 == "def");
  }

  void equality()
  {
    myShoeString const s1 = "hello";
    myShoeString const s2 = "goodbye";
    assert(s1 == s1);
    assert(s1 != s2);
  }

  void ordering()
  {
    myShoeString s1 = "abc";
    myShoeString s2 = "def";
    assert(s1 < s2);
    assert(s2 > s1);
    assert(s1 <= s1);
    assert(s1 >= s1);
  }

  void concatenation()
  {
    myShoeString s1 = "abc";
    myShoeString s2 = "def";
    myShoeString s3 = s1 + s2;
    myShoeString s4 = "abcdef";
    assert(s3 == s4);
  }

  void self_concatenation()
  {
    myShoeString s1 = "abc";
    s1 += s1;
    myShoeString s2 = "abcabc";
    assert(s1 == s2);
  }

  // The assert test runner for this test class.
  void run()
  {
    default_ctor();
    string_ctor();
    copy_ctor();
    copy_assign();
    string_assign();
    self_assign();
    empty();
    access();
    find();
    substr();
    equality();
    ordering();
    concatenation();
    self_concatenation();
  }
};

int main()
{
  Test_string test;
  test.run();
  std::cout << "\nTest run passed! All asserts passed.\n\n";
  return 0;
}
