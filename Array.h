#ifndef ARRAY_H
#define ARRAY_H

class Array
{
  private:
   int *p;
   int size;
   
  public:
    Array() { size = 10; p = new int[size];} //Default Constructor
    Array(int sz); //Constructor
    ~Array();	   //Destructor
    Array(const Array &a); //Copy Constructor
    void put(int i, int j); //Like our setElement
    int get(int i); //Like out getElement
   
};

#endif
    