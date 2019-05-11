#include <iostream>
#include <string>
#include <vector>

// Poliformizam radi samo na heapu!

// Zadatak:
// Napraviti interface Shape koji ima metode Area i Perimeter
// Napraviti klase Triangle, Circle, Square koji implementiraju Shape:
// Napraviti objekte svake podklase i ispisati Area i Perimeter!

// Zadatak:
// Proširiti funkcionalnost te prebaciti odgovornost za shapeove na korisnika
// Dati korisniku na unos koji shape želi i koliko ih želi napraviti
// Na kraju ispisati informacije o svim shapeovima koje je korisnik unio
class IShape
{
public:

	virtual double getArea() = 0;
	virtual double getPerimeter() = 0;
	virtual std::string getName() = 0;
};

class Triangle : public IShape
{
public:
	Triangle(double x, double y, double z)
	{
		a = x;
		b = y;
		c = z;
	}
	double a, b, c, area, perimeter;
	std::string name = "triangle";

	std::string getName()
	{
		return name;
	}
	double getArea()
	{
		double s = (a + b + c) / 2;
		area = sqrt((s - a)*(s - b)*(s - c));
		return area;
	}
	double getPerimeter()
	{
		perimeter = a + b + c;
		return perimeter;
	}
};

class Circle : public IShape
{
public:
	Circle(double rad)
	{
		r = rad;
	}
	double r, area, perimeter;
	std::string name = "circle";

	std::string getName()
	{
		return name;
	}
	double getArea()
	{
		area = r * r*_Pi;
		return area;
	}
	double getPerimeter()
	{
		perimeter = 2 * r*_Pi;
		return perimeter;
	}
private:
	float _Pi = 3.14;
};

class Square : public IShape
{
public:
	Square(double x)
	{
		a = x;
	}
	double a, area, perimeter;
	std::string name = "square";

	std::string getName()
	{
		return name;
	}
	double getArea()
	{
		area = a * a;
		return area;
	}
	double getPerimeter()
	{
		perimeter = 4 * a;
		return perimeter;
	}
};

void printShapeInfo(IShape* shape)
{
	std::cout << "Shape name: " << shape->getName() << std::endl;
	std::cout << shape->getName() << " perimeter is: " << shape->getPerimeter() << std::endl;
	std::cout << shape->getName() << " area is: " << shape->getArea() << std::endl;
	std::cout << "=======================================" << std::endl;
}

int main()
{
	Triangle* triangleShape = new Triangle(2, 2, 2);
	Square* squareShape = new Square(1);
	Circle* circleShape = new Circle(4);

	std::vector<IShape*> shapes;
	shapes.push_back(triangleShape);
	shapes.push_back(squareShape);
	shapes.push_back(circleShape);

	for (IShape* it : shapes)
	{
		printShapeInfo(it);
	}

	std::cin.get();
	delete triangleShape;
	delete squareShape;
	delete circleShape;
}