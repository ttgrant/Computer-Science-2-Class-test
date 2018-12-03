#include <iostream>
#include <cstring>
#include <cstdlib>
#include "GenString1.h"

using namespace std;


//-----------------------------------------------------------------------
// Default Constructor: Initializes string to null (0) 
//
GenString::GenString()
{
  string = NULL;
}


                    
//-----------------------------------------------------------------------
// Constructor: Calls setString( ) 
//
GenString::GenString( char *string_value)   
{
  string = NULL;                   // Initialize string before calling setString()
  setString( string_value);
}
//-----------------------------------------------------------------------
// Copy Constructor 
//
GenString::GenString( const GenString &string_value)  
{
  string = 0;                  // Initialize string before calling setString()
  setString( string_value.string);
}
//-----------------------------------------------------------------------
// Destructor: frees new memory
//
GenString::~GenString()                    
{
  delete[] string;
}
//-----------------------------------------------------------------------
// Sets the string to string_value 
//
void GenString::setString(char *string_value) 
{
  // Check for Previous Allocation and deallocate if necessary
  
    delete [] string;
  
  
    
  // Allocate string
  string = new char[strlen(string_value) + 1];	// enough space for '\0'
 
  // Copy string, including null
  strcpy_s( string, strlen(string) +1, string_value);
}
//-----------------------------------------------------------------------
// Returns the string
//
char* GenString::getString()          
{
  
  // Alternative to constant: Return a copy of the string 
 int str_length = strlen(string);
  
  // Allocate copy
  char *copy = new char[str_length + 1];	// enough space for '\0'
  
  // Copy string, including null
  strcpy_s(copy, str_length + 1,string);
  
  return copy; 
  
}
//-----------------------------------------------------------------------
// Returns true if string equals another_string
//
bool GenString::isEqual( GenString another_string)  
{
  if (strcmp(string,another_string.getString()) == 0)
    return(true);
  else
    return(false);

  
}
//-----------------------------------------------------------------------
// Converts string to lowercase
//
void GenString::toLower()                     
{
  for (int index = 0; index < (int)strlen(string); index++)
  {
    string[index] = tolower(string[index]);
  }
}
//-----------------------------------------------------------------------
// Converts string to uppercase 
//
void GenString::toUpper()                     		
{
  for (int index = 0; index < (int)strlen(string); index++)
  {
    string[index] = toupper(string[index]);
  }
}
//-----------------------------------------------------------------------
// Returns a character of the string at the specified index.
//    If the index is < 0 or >= length, prints an error message
//
char GenString::getChar( int index)            
{
  if (index < 0 || index >= (int)strlen(string))
  {
    cout << "\n\nERROR: Index is out-of-bounds.\n\n";
    return ('\0');
  }
  
  return string[index]; 
}


const char* GenString::getString1() 
{
  return (string);
}

void GenString::change() const
{
 //string = new char[10];
  

}

//-----------------------------------------------------------------------
// Returns the character at the specified index.
//    If the index is < 0 or > length, prints an error message 
//    (referenced object[] is an l-value)
//
char& GenString::operator[](int index)
{
  // Check range
  if (index < 0 || index > (int)strlen(string))
  {
    cout << "\n\nERROR: Index is out-of_bounds.\n";
    exit(1);
  }
  
  return string[(int)index];
}

//-----------------------------------------------------------------------
// Returns the character at the specified index.
//    If the index is < 0 or > length, prints an error message 
//    (referenced object[] is an l-value)
//
/*const char& GenString::operator[](int index) const
{
  // Check range
  if (index < 0 || index > strlen(string))
  {
    cout << "\n\nERROR: Index is out-of_bounds.\n";
    exit(1);
  }
  
  return string[index];
}*/
//-----------------------------------------------------------------------

