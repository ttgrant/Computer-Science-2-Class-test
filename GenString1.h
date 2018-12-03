// Member functions defined in "String.cpp"
#ifndef GEN_STRING_H
#define GEN_STRING_H


class GenString
{
  private: 		
    char *string;             // pointer to null-terminated array of characters
   
  public:
    // ** Constructors and Destructors
    // Default Constructor: Initializes string to null (0)
    GenString();                    
    GenString( char *string_value);          // Constructor: Calls setString( ) 
    GenString(char* str, int id);
    GenString( const GenString &string_value);  // Copy Constructor!! 
    ~GenString();                            // Destructor: frees new memory
    // ** Set and Get Functions
    void setString(char *string_value);   // Sets the string to string_value 
    char* getString() ;        // Returns the string
    // ** Special Functions
    // Returns true if string equals another_string
    bool isEqual(GenString another_string);  
    void toLower();                       // Converts string to lowercase
    void toUpper();                       // Converts string to uppercase
    // Returns a character of the string at the specified index.
    //    If the index is < 0 or >= length, prints an error message
    char getChar( int index);            
    // Returns the length of string (excluding null)
    int getLength() { return strlen(string);}  
    const char* getString1();
    void change() const;  
    char& operator[](int a);
    
                	
};

#endif