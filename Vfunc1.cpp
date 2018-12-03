#include <iostream>

using namespace std;

class Base
{
  public:
    void vfunc() { cout << "This is Base's vfunc()" << endl; };
};

class Derived1 : public Base
{
  public:
    void vfunc() { cout << "This is Derived1's vfunc()\n"; };
    void vfunc1() { cout << "vfunc1() is invoked\n"; };
    void vfunc2() { cout << "vfunc2() is invoked\n"; };
};

class Derived2 : public Base
{
  public:
    void vfunc() { cout << "This is Derived2's vfunc()" << endl; };
}; 

void foo(Base& base);

int main()
{
  Base		base;
  Base		*base_ptr;
  Derived1 	derived1;
  Derived2  derived2;
  //1. Assign sub class to base class
  base = derived1;
  
  //2. What is displayed here?
  base.vfunc();
  
  //3. Assign sub class to base class ptrs here
  base_ptr = &derived1;
  
  //4. What is displayed here
  base_ptr->vfunc();
  
  foo(derived1);
  foo(derived2);
  foo(base);
  
  //5. Is this possible?
  //derived2 = base;

  //6. Is this possible?
  //base_ptr->vfunc2();
 
  return 0;
}

void foo(Base& base)
{
  base.vfunc();
}
