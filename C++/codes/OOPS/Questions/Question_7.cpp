#include <iostream>
using namespace std;

class Shape {
   protected:
    float dimension;

   public:
    void getDimension() {
        cin >> dimension;
    }

    virtual float calculateArea() = 0;
    virtual float calculatePerimenter() = 0;
};

class Square : public Shape {
   public:
    float calculateArea() {
        return dimension * dimension;
    }
    float calculatePerimenter() {
        return dimension * 4;
    }
};

class Circle : public Shape {
   public:
    float calculateArea() {
        return 3.14 * dimension * dimension;
    }
    float calculatePerimenter() {
        return 3.14 * dimension * 2;
    }
};

class Rectangle : public Shape {
    int breadth;
   public:
    void getinfo(){
        cout<<"Length: ";
        Shape::getDimension();
        cout<<"Breadth: ";
        cin>>breadth;
    }
    float calculateArea() {
        return dimension * breadth;
    }
    float calculatePerimenter() {
        return (dimension + breadth) * 2;
    }
};

int main() {
    Square square;
    Circle circle;
    Rectangle rectangle;

    cout << "Enter the length of the square: ";
    square.getDimension();
    cout << "Area of square: " << square.calculateArea() << endl;
    cout << "Perimenter of square: " << square.calculatePerimenter() << endl;

    cout << "\nEnter radius of the circle: ";
    circle.getDimension();
    cout << "Area of circle: " << circle.calculateArea() << endl;
    cout << "Perimeter of circle: " << circle.calculatePerimenter() << endl;

    cout << "\nEnter length and breadth of the rectangle: \n";
    rectangle.getinfo();
    cout << "Area of rectangle: " << rectangle.calculateArea() << endl;
    cout << "Perimeter of rectangle: " << rectangle.calculatePerimenter() << endl;

    return 0;
}