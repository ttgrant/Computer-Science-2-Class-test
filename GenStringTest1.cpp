#include <iostream>
#include <iomanip>
#include "GenString1.h"

using namespace std;



// Driver function to test Class String member functions    
int main( void )
{
  // Variable declarations/initializations
  const int SIZE = 5;
  int i = 0;
  int index = 0;
  
  // *** Test the default constructor, setString() and getString()
  // Specify an array of strings with the default constructor
  GenString string_array[SIZE]; 
  GenString gen;
  char array[] = "joe smith";
  //Test parameterized array
  GenString string_array1[SIZE] = {GenString(array), GenString(array),GenString(array)};
  GenString string_array2[] = {GenString(array), GenString(), GenString(array), GenString(array)};
  
  GenString gen_string_extra(array);
  const char *string3 = gen_string_extra.getString1();
  //string3[0] = 'J';

    
  /**********************************************************************************/
  /*****Additional Tests showing use of Pointers************************************/
  //Allocate space to hold the pointer
  GenString *gen_string_ptr;
  
  
  //Set gen_string_ptr to 3rd element (element of 2) of the array
  gen_string_ptr = &string_array2[2];
  cout << (*gen_string_ptr).getString() << endl;
  cout << gen_string_ptr->getString() << endl;
  cout << gen_string_ptr[0].getString() << endl;
  cout << gen_string_ptr[1].getString() << endl;
  cout << (gen_string_ptr + 1)->getString() << endl;
 
  
  //Allocate gen_string_ptr to a single pointer (use parametrized constructor
  gen_string_ptr = new GenString;  
  delete gen_string_ptr;

  gen_string_ptr = new GenString();
  delete gen_string_ptr;
  char array2[] = "  The   brown   fox ran     quickly     ";
  gen_string_ptr = new GenString(array2);
  
  //Cleanup the memory (destructor called automatically)
  delete gen_string_ptr;
      
  return 0;
}