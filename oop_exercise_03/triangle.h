#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"
#include "point.h"

class Triangle : public Figure {
public:
	Triangle();
	Triangle(std::istream& in);
	double area() const override;
	Point center() const override;
	std::ostream& print(std::ostream& out) const override;
private:
	Point A;
	Point B;
	Point C;
};
#endif
