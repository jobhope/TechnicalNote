#include<iostream>
#include<memory>

// Implementor
class Drawing
{
public:
    virtual void drawLine(int x, int y) = 0;
    virtual void fill() = 0;
};

// ConcreteImplementor
class RectDrawing : public Drawing
{
    void drawLine(int x, int y)
    {
        std::cout << "Rect Draw line from " << x << " to " << y << std::endl;
    }

    void fill()
    {
        std::cout << "Rect fill" << std::endl;
    }
};

// ConcreteImplementor
class CircleDrawing : public Drawing
{
    void drawLine(int x, int y)
    {
        std::cout << "Circle Draw line from " << x << " to " << y << std::endl;
    }

    void fill()
    {
        std::cout << "Circle fill" << std::endl;
    }
};

// Abstraction
class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() = default;
    Shape(Drawing* drawing)
    {
        this->drawing = drawing;
    }
    void drawLine(int x, int y)
    {
        drawing->drawLine(x, y);
    }
    void fill()
    {
        drawing->fill();
    }
private:
    Drawing* drawing;
};

// RefindAbstraction
class Rectangle : public Shape
{
public:
    Rectangle(Drawing* drawing) : Shape(drawing) { }

    void draw()
    {
        std::cout << "Rect draw extend" << std::endl;
    }
};

// RefindAbstraction
class Circle : public Shape
{
public:
    Circle(Drawing* drawing) : Shape(drawing) { }

    void draw()
    {
        std::cout << "Circle draw extend" << std::endl;
    }
};

int main()
{
    auto rectangle = std::unique_ptr<Shape>(new Rectangle(new RectDrawing));
    auto circle = std::unique_ptr<Shape>(new Circle(new CircleDrawing));

    rectangle->drawLine(1, 2);
    rectangle->fill();
    rectangle->draw();

    std::cout << std::endl << std::endl;
    circle->drawLine(3, 4);
    circle->fill();
    circle->draw();
    return 0;
}