import java.util.List;

class Cone {
    private double radius;
    private double height;

    public Cone(double radius, double height) {
        this.radius = radius;
        this.height = height;
    }

    @Override
    double volume() {
        return (1.0 / 3) * Math.PI * Math.pow(radius, 2) * height;
    }
}

// Class Cuboid extends Shape
class Cuboid {
    private double length;
    private double width;
    private double height;

    public Cuboid(double length, double width, double height) {
        this.length = length;
        this.width = width;
        this.height = height;
    }

    @Override
    double volume() {
        return length * width * height;
    }
}

// Class Cylinder extends Shape
class Cylinder {
    private double radius;
    private double height;

    public Cylinder(double radius, double height) {
        this.radius = radius;
        this.height = height;
    }

    @Override
    double volume() {
        return Math.PI * Math.pow(radius, 2) * height;
    }
}
// VolumeCalculator class
public class VolumeCalculator {

    // Method to calculate the sum of volumes of a list of Shape objects
    public double sumVolumeCalculator(List<Shape> shapes) {
        double totalVolume = 0;
        for (Shape shape : shapes) {
            totalVolume += shape.volume();
        }
        return totalVolume;
    }

    // Violation: Modified method to include new shape types
    public double sumVolumeCalculatorWithSpecificShapes(List<Object> shapes) {
        double totalVolume = 0;
        for (Object shape : shapes) {
            if (shape instanceof Cone) {
                totalVolume += ((Cone) shape).volume();
            } else if (shape instanceof Cuboid) {
                totalVolume += ((Cuboid) shape).volume();
            } else if (shape instanceof Cylinder) {
                totalVolume += ((Cylinder) shape).volume();
            }
            // Violation: Need to modify this method when adding a new shape
            else if (shape instanceof Sphere) {
                totalVolume += ((Sphere) shape).volume();
            }
        }
        return totalVolume;
    }

    public static void main(String[] args) {
        Shape cone = new Cone(5, 10);
        Shape cuboid = new Cuboid(4, 5, 6);
        Shape cylinder = new Cylinder(3, 7);

        VolumeCalculator calculator = new VolumeCalculator();
        List<Object> shapes = List.of(cone, cuboid, cylinder);

        System.out.println("Volume of Cone: " + cone.volume());
        System.out.println("Volume of Cuboid: " + cuboid.volume());
        System.out.println("Volume of Cylinder: " + cylinder.volume());
        System.out.println("Total Volume: " + calculator.sumVolumeCalculator(shapes));
    }
}