// Abstraction
interface NotificationService {
    void send(String message);
}

// Low-level module for Email
class EmailService implements NotificationService {
    public void send(String message) {
        System.out.println("Sending email: " + message);
    }
}

// Low-level module for SMS
class SMSService implements NotificationService {
    public void send(String message) {
        System.out.println("Sending SMS: " + message);
    }
}

// High-level module
class Notification {
    private NotificationService service;

    // Dependency injection via constructor
    public Notification(NotificationService service) {
        this.service = service; // Depends on abstraction
    }

    public void send(String message) {
        service.send(message);
    }
}

// Usage
public class Main {
    public static void main(String[] args) {
        NotificationService emailService = new EmailService();
        Notification emailNotification = new Notification(emailService);
        emailNotification.send("Hello via Email!");

        NotificationService smsService = new SMSService();
        Notification smsNotification = new Notification(smsService);
        smsNotification.send("Hello via SMS!");
    }
}
