/*
	shapes.h
*/

#ifndef SHAPES_H_
#define SHAPES_H_

#include<iostream>
#include<fstream>
#include<cmath>
#include<string>

using namespace std;

enum class Shapes{Triangle,Rectangle,Circle};	


void containerCircleWriteFile(int radius,ofstream &inputStream);
void containerRectangleWriteFile(int wContainer,int hContainer,ofstream &inputStream);
void containerTriangleWriteFile(int length,ofstream &inputStream);


void containerRectangleInsideCircle(int wContainer,int hContainer,int radius,ofstream &inputStream);
void containerRectangleInsideTriangle(double wContainer,double hContainer,double length,ofstream &inputStream);
void containerRectangleInsideRectangle(int wContainer,int hContainer,int wSmall,int hSmall,ofstream &inputStream);

void containerTriangleInsideTriangle(double length,double smallLength,ofstream &inputStream);
void containerTriangleInsideCircle(double length,int sradius,ofstream &inputStream);
void containerTriangleInsideRectangle(double length,double wSmall, double hSmall,ofstream &inputStream);

void containerCircleInsideCircle(double radius,double sradius,ofstream &inputStream);
void containerCircleInsideRectangle(double radius,double wSmall, double hSmall,ofstream &inputStream);
void containerCircleInsideTriangle(double 	radius,double length,ofstream &inputStream);
int circle_equation(double x,double y,double radius);

#endif
