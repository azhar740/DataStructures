abstract class Shape {
    public abstract double volume();
}

class Cuboid extends Shape {
    private double length;
    private double width;
    private double height;

    public Cuboid(double length, double width, double height) {
        this.length = length;
        this.width = width;
        this.height = height;
    }

    @Override
    public double volume() {
        return length * width * height;
    }
}

class Cylinder extends Shape {
    private double radius;
    private double height;

    public Cylinder(double radius, double height) {
        this.radius = radius;
        this.height = height;
    }

    @Override
    public double volume() {
        return Math.PI * radius * radius * height;
    }
}

class Cone extends Shape {
    private double radius;
    private double height;

    public Cone(double radius, double height) {
        this.radius = radius;
        this.height = height;
    }

    @Override
    public double volume() {
        return (Math.PI * radius * radius * height) / 3;
    }
}

class VolumeCalculator {
    public double sumVolume(Shape[] shapes) {
        double totalVolume = 0;
        for (Shape shape : shapes) {
            totalVolume += shape.volume();
        }
        return totalVolume;
    }
}

public class Main {
    public static void main(String[] args) {
        Cuboid cuboid = new Cuboid(5, 3, 2);
        Cylinder cylinder = new Cylinder(2, 4);
        Cone cone = new Cone(3, 6);

        Shape[] shapes = {cuboid, cylinder, cone};

        VolumeCalculator calculator = new VolumeCalculator();
        double totalVolume = calculator.sumVolume(shapes);

        System.out.println("Total volume: " + totalVolume);
    }
}
