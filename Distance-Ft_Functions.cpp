// Distance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Distance.h"

using namespace std;

Distance::Distance() : feet(0), inches(0.0) {
}

Distance::Distance(unsigned ft, double in) {

	this->feet = ft;
	this->inches = in;
	init();
}
Distance::Distance(double in) {
	//int ft;
	//feet = ft;
	this->feet = 0;
	this->inches = in;
	init();
}
unsigned Distance::getFeet() const {
	return this->feet;
}
double Distance::getInches() const {
	return this->inches;
}
double Distance::distanceInInches() const {
	double totalIn = 0.0;
	totalIn = (static_cast<double>(this->feet) * 12.0) + (this->inches * 1.0);

	return totalIn;
}
double Distance::distanceInFeet() const {
	double totalFt = 0.0;
	totalFt = (this->inches / 12.0) + (this->feet);

	return totalFt;
}
double Distance::distanceInMeters() const {
	double meters = 0.0;
	meters = ((static_cast<double>(this->feet) * 12.0) + (this->inches) * 1.0) * 0.0254;

	return meters;
}
Distance Distance::operator+(const Distance& rhs) const {

	double equals = distanceInInches() + rhs.distanceInInches();
	Distance thing(equals);
	return thing;
}
Distance Distance::operator-(const Distance& rhs) const {
	double equals = distanceInInches() - rhs.distanceInInches();
	Distance thing(equals);
	return thing;
}
ostream& operator<<(ostream& out, const Distance& rhs) {
	out << rhs.getFeet() << "\' " << rhs.getInches() << "\"";
	return out;
}
void Distance::init() {
	if (inches < 0) {
		this->inches *= -1;
	}
	if (feet < 0) {
		this->feet *= -1;
	}
	while (inches > 12) {
		this->inches -= 12;
		this->feet += 1;
	}

}