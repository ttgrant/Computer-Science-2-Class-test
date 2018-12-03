#include <iostream>
#include "graph1.h"
#include "Color.h"

Color::Color()
{
	r = 0;
	g = 0;
	b = 0;
}
Color::Color(int r, int g, int b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}
void Color::setColor(int r, int g, int b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}
int Color::getRed()
{
	return(r);
}
int Color::getGreen()
{
	return(g);
}
int Color::getBlue()
{
	return(b);
}
Color Color::operator+(Color right)
{
	int r, g, b;
	Color holder;
	r = this->r + right.getRed();
	if (r > 255)
		r = 255;
	g = this->g + right.getGreen();
	if (g > 255)
		g = 255;
	b = this->b + right.getBlue();
	if (b > 255)
		b = 255;
	holder.setColor(r, g, b);
	return(holder);
}
Color Color::operator-(Color right)
{
	int r, g, b;
	Color holder;
	r = this->r - right.getRed();
	if (r < 0)
		r = 0;
	g = this->g - right.getGreen();
	if (g < 0)
		g = 0;
	b = this->b - right.getBlue();
	if (b < 0)
		b = 0;
	holder.setColor(r, g, b);
	return(holder);
}
Color Color::operator/(int right)
{
	int r, g, b;
	Color holder;
	r = this->r/right;
	
	g = this->g/right;
	
	b = this->b/right;
	
	holder.setColor(r, g, b);
	return(holder);


}
Color Color::operator*(int right)
{
	int r, g, b;
	Color holder;
	r = this->r * right;

	g = this->g * right;

	b = this->b * right;
	holder.setColor(r, g, b);
	return(holder);
}
bool Color::operator==(Color right)
{
	
	bool tester = true;
	if (this->r != right.getRed())
		tester = false;
	if (this->g != right.getGreen())	
		tester = false;
	if (this->b != right.getBlue())
		tester = false;
	return(tester);


}
bool Color::operator!=(Color right)
{
	bool tester = false;
	if (this->r != right.getRed())
		tester = true;
	if (this->g != right.getGreen())
		tester = true;
	if (this->b != right.getBlue())
		tester = true;
	return(tester);
}
void Color::operator=(Color right)
{
	this->r = right.getRed();
	this->g = right.getGreen();
	this->b = right.getBlue();
}
Color Color::operator!()
{
	Color holder;
	int r, g, b;
	r = 255 - this->r;
	g = 255 - this->g;
	b = 255 - this->b;
	holder.setColor(r, g, b);
	return(holder);


}

void Color::draw(int x, int y, int w, int h)
{
	int obj;
	obj = drawRect(x, y, w, h);
	::setColor(obj, r, g, b);

}