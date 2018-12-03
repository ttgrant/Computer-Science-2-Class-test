#include "Array.h"

//Constructor
Array::Array(int sz)
{
  //Allocate pointer
  p = new int[sz];
  
  //Set size
  size = sz;
}


//Destructor
Array::~Array()
{
  //Cleanup memory
  delete[] p;
}

//Copy Constructor
Array::Array(const Array &a)
{
  //Variable Declaration/Initialization
  int i = 0;
  
  //Make an exact copy of a!
  p = new int[a.size];
  size = a.size;
  
  //copy elements one at a time
  for (i = 0; i < a.size; i++)
    p[i] = a.p[i];
}
  
//put method
void Array::put(int i, int j)
{
  if ((i >= 0) && (i < size))
    p[i] = j;
}

//get method
int Array::get(int i)
{
  return(p[i]);
}