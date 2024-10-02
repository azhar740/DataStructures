// In this example, the Notification class directly depends on the EmailService.
// Low-level module
class EmailService {
    public void sendEmail(String message) {
        System.out.println("Sending email: " + message);
    }
}

// High-level module
class Notification {
    private EmailService emailService;

    public Notification() {
        this.emailService = new EmailService(); // Direct dependency
    }

    public void send(String message) {
        emailService.sendEmail(message);
    }
}

// Usage
public class Main {
    public static void main(String[] args) {
        Notification notification = new Notification();
        notification.send("Hello via Email!");
    }
}
