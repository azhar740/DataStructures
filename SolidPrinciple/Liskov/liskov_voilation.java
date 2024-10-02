// Let’s say we have a Bird superclass and a Penguin subclass. All birds can fly, but penguins cannot. If we try to substitute a Penguin object where a Bird is expected, it could lead to unexpected behavior or runtime errors.


// Problems:
// The Penguin class violates LSP because substituting a Penguin for a Bird causes an exception when calling the fly() method.
// The subclass (Penguin) does not behave in the same way as the superclass (Bird), leading to unexpected behavior.

// Superclass Bird
class Bird {
    public void fly() {
        System.out.println("Bird is flying");
    }
}

// Subclass Penguin that violates LSP
class Penguin extends Bird {
    @Override
    public void fly() {
        // Penguins can't fly, so we override the method to prevent flying
        throw new UnsupportedOperationException("Penguins can't fly!");
    }
}

// Client code
public class Main {
    public static void main(String[] args) {
        Bird sparrow = new Bird();
        Bird penguin = new Penguin(); // Substituting Penguin where Bird is expected
        
        sparrow.fly(); // Works fine
        penguin.fly(); // Throws an exception at runtime, violating LSP
    }
}
