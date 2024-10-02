// "No client should be forced to depend on methods it does not use."

// Shape interface forces implementation of both area() and volume()
interface Shape {
    double area();
    double volume(); // This is not applicable to 2D shapes like Rectangle
}

// Rectangle class is forced to implement the irrelevant volume() method
class Rectangle implements Shape {
    private double length;
    private double width;

    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    @Override
    public double area() {
        return length * width;
    }

    @Override
    public double volume() {
        // Rectangle does not have a volume, but is forced to implement this method
        throw new UnsupportedOperationException("Rectangle does not have a volume!");
    }
}

// Cube class correctly implements both area() and volume()
class Cube implements Shape {
    private double side;

    public Cube(double side) {
        this.side = side;
    }

    @Override
    public double area() {
        return 6 * side * side; // Surface area of a cube
    }

    @Override
    public double volume() {
        return side * side * side; // Volume of a cube
    }
}

// Client code
public class Main {
    public static void main(String[] args) {
        Shape rectangle = new Rectangle(5, 10);
        System.out.println("Area of rectangle: " + rectangle.area());
        // rectangle.volume(); // This would throw an exception

        Shape cube = new Cube(3);
        System.out.println("Area of cube: " + cube.area());
        System.out.println("Volume of cube: " + cube.volume());
    }
}
