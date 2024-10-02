// Superclass Bird
abstract class Bird {
    public abstract void makeSound();
}

// Subclass of Bird that can fly
class FlyingBird extends Bird {
    public void fly() {
        System.out.println("Flying bird is flying");
    }

    @Override
    public void makeSound() {
        System.out.println("Flying bird is making sound");
    }
}

// Subclass of Bird that cannot fly
class Penguin extends Bird {
    @Override
    public void makeSound() {
        System.out.println("Penguin is making sound");
    }

    // No fly() method, as penguins don't fly
}

// Client code
public class Main {
    public static void main(String[] args) {
        Bird sparrow = new FlyingBird();
        Bird penguin = new Penguin(); // Substituting Penguin where Bird is expected

        sparrow.makeSound();
        ((FlyingBird) sparrow).fly(); // Sparrow can fly

        penguin.makeSound();
        // No need to call fly() for penguin, as penguin doesn't have that behavior
    }
}
