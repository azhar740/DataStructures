interface Shape {
    void display();
}

interface TwoDimensionalShape extends Shape {
    double area();
}

interface ThreeDimensionalShape extends Shape {
    double volume();
}

class Square implements TwoDimensionalShape {
    double side;

    public Square(double side) {
        this.side = side;
    }

    @Override
    public void display() {
        System.out.println("Square");
    }

    @Override
    public double area() {
        return side * side;
    }
}

class Rectangle implements TwoDimensionalShape {
    double length;
    double width;

    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    @Override
    public void display() {
        System.out.println("Rectangle");
    }

    @Override
    public double area() {
        return length * width;
    }
}

class Cube implements ThreeDimensionalShape {
    double side;

    public Cube(double side) {
        this.side = side;
    }

    @Override
    public void display() {
        System.out.println("Cube");
    }

    @Override
    public double volume() {
        return side * side * side;
    }
}

public class Main {
    public static void main(String[] args) {
        Square square = new Square(5);
        Rectangle rectangle = new Rectangle(4, 6);
        Cube cube = new Cube(3);

        square.display();
        System.out.println("Area: " + square.area());

        rectangle.display();
        System.out.println("Area: " + rectangle.area());

        cube.display();
        System.out.println("Volume: " + cube.volume());
    }
}