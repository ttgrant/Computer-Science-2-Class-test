#include <iostream>
#include <cstring>

using namespace std;

class Quadrilateral
{
  protected:
    char *name;
    
  public:
    virtual double getArea() = 0;
    virtual void print() { cout << "Im Quadrilateral" << endl;}
    double getPerimeter() { cout << "In perimeter" << endl; return (4,0);}
    void setName(char *name)
    {
      this->name = new char[strlen(name) + 1];
      strcpy(this->name,name);
    }
    Quadrilateral()
    {
      name = NULL;
    }

    virtual ~Quadrilateral()
    {
      delete[] name;
    }
};

class Rectangle : public Quadrilateral
{
  protected:
     char *rectangle_info;
  public:
    Rectangle::Rectangle();
    virtual double getArea();
    virtual void print() 
    {Quadrilateral::print(); 
     cout << "In Rectangle" << endl;}
    double getCentroid() {return(3);}
    virtual ~Rectangle()
    {
      delete[] rectangle_info;
    }
};

Rectangle::Rectangle()
{
  rectangle_info = new char[strlen("Im a Rectangle") + 1];
  strcpy(rectangle_info,"Im a Rectangle");
}

double Rectangle::getArea()
{
  cout << "Inside of Rectangle getArea()" << endl;
  return(4.0);
}

class Square : public Rectangle
{
  private:
    char* square_info;
  public:
    Square::Square();
    double getArea();
    void print() { Quadrilateral::print(); cout << "In Square" << endl;}
    double getColorforSquare() { 
       return 0;}

    ~Square()
    {
      delete[] square_info;
    }
};

Square::Square()
{
  square_info = new char[strlen("Im a Square") + 1];
  strcpy(square_info,"Im a Square");
}

double Square::getArea()
{
  cout << "In squares getArea() " << endl;
  return(3.0);
}

class Trapezoid : public Quadrilateral
{
  public:
    double getArea() { cout << "In Trapezoid getArea() " << endl; return(2.0);}
    void print() {cout << "In Trapezoid" << endl;}
};
    
int main(void)
{
  Quadrilateral *quad;
  //Quadirlateral quad1;  //Q1 what happens here
  Rectangle rect;
  Rectangle *rect_ptr;
  Square *sq_ptr;
  Square square;
  Trapezoid trap;
  
  //Set the names
  square.setName("Square");
  rect.setName("Rectangle");
  trap.setName("Trapezoid");
  
  //Q2 What's displayed by this sequence
  quad = &trap;
  cout << quad->getArea() << endl;
  quad->print();
  
  //Q3 Can I do this (Also shares pointers because I did not overload =)
  rect = square;
  
  //Q4 - What is displayed here?
  cout << rect.getArea() << endl;
  rect.print();
  
  //Q5 - Will this work better?
  rect_ptr = &square;
  rect_ptr->getArea();
  rect_ptr->print();
  
  //Q6 Will this work (Cannot convert rectangle to square!)
  //sq_ptr = &rect;

  Rectangle rect_a;
  
  //Q7 I can type cast instead!
  sq_ptr = (Square *)&rect_a;
  
  //Q8 What is displayed here?
  sq_ptr->getArea();
  sq_ptr->print();
  
  //Q9 What happens here?
  cout << sq_ptr->getColorforSquare() << endl;

  Rectangle *rect1;
  Square square1;

  rect1 = &square1;

  rect1->getArea();
  rect1->print();
  //rect1->getColorforSquare(); What happens here

  //convert back to a Square
  Square *sq2 = (Square *)rect1;
  sq2->getArea();
  sq2->print();
  sq2->getColorforSquare();

  //Work with pointers
  Quadrilateral* quad1 = new Square;
  quad1->setName("Square");
  delete quad1;

  Rectangle* rect_ptr1 = new Square;
  rect_ptr1->setName("Square");
  delete rect_ptr1;
  
  
  
  
  return 0;
}
  
  