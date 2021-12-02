/*
    myShorString.cpp

    decleration file for my string class
*/
#include "myShoeString.hpp"

// Default Constructor
// Precondition: Receives Nothing
// Postcondition: Dynamically allocates c-string, with size 1, and sets only value to null terminator
//                Also sets length of string class to -1 for easy identification of empty string
myShoeString::myShoeString()
{
   myString = new char[1];
   myString[0] = '\0';
   laceLength = -1;
}

// Overloaded Constructor
// Precondition: Receives a string literal
// Postcondition: Updates c-string to value provided, and updates the length
myShoeString::myShoeString(const char* NikeStr)
{
   if (NikeStr == ""){
       laceLength = -1;
       myString = new char[1];
       myString[0] = '\0';
   }
   else{
   laceLength = strlen(NikeStr);
   myString = new char[laceLength + 1];
   strcpy(myString, NikeStr);
   myString[laceLength + 1] = '\0';
   }
}

// Copy Constructor
// Precondition: Receives myShoeString object, read only
// Postcondition: Updates called object to value passed in from other object
myShoeString::myShoeString(const myShoeString& Shoe)
{
    laceLength = Shoe.laceLength;
    myString = new char[laceLength+1];
    strcpy(myString, Shoe.myString);
}

// Overloaded Constructor
// Precondition: Receives string literal, and a length to copy
// Postcondition: Updates object starting at string literal, with length of int passed
myShoeString::myShoeString(const char* Shoe, const int& num)
{
    laceLength = num + 1;
    myString = new char[laceLength];
        for (int x = 0; x < num; ++x)
        {
            myString[x] = Shoe[x];
        }
     myString[laceLength + 1] = '\0';
}

// Destructor
// Deletes Dynamically Allocated C-string pointer
myShoeString::~myShoeString()
{
    delete []myString;
}

// Precondition: Passed nothing
// Postcondition: Returns boolean value based on if the object is empty(true) or not(false)
bool myShoeString::empty() const
{
    if (laceLength == -1 || myString[0] == '\0'){
        return true;
    }
    else return false;
}

// Precondition: Receives nothing
// Postcondition: Returns pointer to the c-string of the object
char* myShoeString::data()
{
    char* returnShoe;
    returnShoe = myString;
    return returnShoe;
}

// Precondition: Receives int value of index
// Postcondition: Returns c-string address index provided, as long as index is valid
char& myShoeString::operator[](const int& index) const
{
    // If index is less than zero, invalid, return first position
    if (index < 0)
    {
        std::cout << "Error, index provided invalid. Defaulting to first space." << std::endl;
        return myString[0];
    }
    else if (index > laceLength)   // if index is greater than max, return first position
    {
        std::cout << "Error, index larger than max size. Defaulting to first space." << std::endl;
        return myString[0];
    }
    return myString[index];
}

// Precondition: Receives read only character
// Postcondition: Returns index of where that character is, or npos(-1) if not found
int myShoeString::find(const char& S) const
{
    // search until null terminator, if passed value found return that index
    for (int x = 0; myString[x] != '\0'; ++x)
    {
        if (myString[x] == S)
        {
            return x;
        }
    }
    return npos;
}

// Precondition: Receives read only int index, and read only int length
// Postcondition: Returns myShoeString object with string starting at passed index, with length of passed length
myShoeString myShoeString::substr(const int& index, const int& length) const
{
    const char* S = &myString[index];
    myShoeString R(S, length);
    return R;
}

// Precondition: Receives read only string object
// Postcondition: Return dynamically allocated c-string pointer that contains c-string of passed object
myShoeString myShoeString::operator=(const myShoeString& S)
{
    // If address is the same, than self assignment attempted
    if (this == &S){
        std::cout << "Self Assignment Avoided" << std::endl;
        return S;
    }
    else{      // otherwise create new string and copy contents over and return
       laceLength = S.laceLength;
       delete []myString;
       myString = new char[laceLength];
       strcpy(myString, S.myString);
       return myString;
     }
}

// Precondition: Receives string literal
// Postcondition: Returns true if objects string and passed string are equal, false otherwise
bool myShoeString::operator==(const char* S) const
{
    if (strcmp(myString, S) == 0){
        return true;
    }
    else return false;
}

// Precondition: Receives read only myShoeString object
// Postcondition: Returns true if object string and passed object string are equal, false otherwise
bool myShoeString::operator==(const myShoeString& S) const
{
    if (strcmp(myString, S.myString) == 0){
        return true;
    }
    else return true;
}

// Precondition: Receives read only myShoeString object
// Postcondition: Returns true if object string and passed object string are NOT equal, false otherwise
bool myShoeString::operator!=(const myShoeString& S) const
{
    if (strcmp(myString, S.myString) == 1){
        return true;
    }
    else return true;
}

// Precondition: Receives string literal
// Postcondition: Returns true if object string and passed object string are NOT equal, false otherwise
bool myShoeString::operator!=(const char* S) const
{
    if (strcmp(myString, S) == 1){
        return false;
    }
    else return true;
}

// Precondition: Receives read only myShoeString object
// Postcondition: Returns true if object is lexicographically less than passed object, false otherwise
bool myShoeString::operator<(const myShoeString& Right) const
{
    if (strcmp(myString, Right.myString) < 0){
        return true;
    }
    else return false;
}


// Precondition: Receives string literal
// Postcondition: Returns true if object is lexicographically less than passed string literal, false otherwise
bool myShoeString::operator<(const char* S) const
{
    if (strcmp(myString, S) < 0){
        return true;
    }
    else return false;
}

// Precondition: Receives read only myShoeString object
// Postcondition: Returns true if object is lexicographically greater than passed object, false otherwise
bool myShoeString::operator>(const myShoeString& Right) const
{
     if (strcmp(myString, Right.myString) > 0){
        return true;
    }
    else return false;
}

// Precondition: Receives string literal
// Postcondition: Returns true if object is lexicographically greater than passed object, false otherwise
bool myShoeString::operator>(const char* S) const
{
    if (strcmp(myString, S) > 0){
        return true;
    }
    else return false;
}

// Precondition: Receives read only myShoeString object
// Postcondition: Returns true if object is lexicographically less than or equal to passed object, false otherwise
bool myShoeString::operator<=(const myShoeString& Right) const
{
    if (strcmp(myString, Right.myString) < 0 || strcmp(myString, Right.myString) == 0){
        return true;
    }
    else return false;
}

// Precondition: Receives read only myShoeString object
// Postcondition: Returns true if object is lexicographically greater than or equal to passed object, false otherwise
bool myShoeString::operator>=(const myShoeString& Right) const
{
    if (strcmp(myString, Right.myString) > 0 || strcmp(myString, Right.myString) == 0){
        return true;
    }
    else return false;
}

// Precondition: Receives read only myShoeString object
// Postcondition: Returns myShoeString object with string value equal to current object string and passed object string
myShoeString myShoeString::operator+(const myShoeString& Right) const
{
    myShoeString NEW;
    int newLaceLength = laceLength + Right.laceLength + 1;
    NEW.myString = new char[newLaceLength];
        // Copy string from current object over
        for (int x = 0; x < laceLength; ++x)
        {
            NEW.myString[x] = myString[x];
        }
        // Then copy string from passed object over, i used to copy from object, y used to start at correct spot of new string
        int i = 0;
        for (int y = laceLength; y < newLaceLength; ++y)
        {
            NEW.myString[y] = Right.myString[i];
            ++i;
        }
        NEW.laceLength = newLaceLength;
        NEW.myString[newLaceLength] = '\0';
        return NEW;
}

// Precondition: Receives read only myShoeString object
// Postcondition: Updates(adds) current object with passed objects string value
void myShoeString::operator+=(const myShoeString& Right)
{
    int newLaceLength = Right.laceLength + laceLength;
        int i = 0;
        for (int x = laceLength; x < newLaceLength; ++x)
        {
            myString[x] = myString[i];
            ++i;
        }
        laceLength = newLaceLength;
        myString[laceLength] = '\0';
}
