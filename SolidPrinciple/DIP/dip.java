// Now, let's apply the Dependency Inversion Principle. The high-level NotificationService should depend on an abstraction (NotificationSender interface), and the // low-level modules (EmailService and SMSService) should also implement that abstraction.

// Abstraction (Interface)
interface NotificationSender {
    void send(String message);
}

// Low-level modules (Implementing the abstraction)
class EmailService implements NotificationSender {
    @Override
    public void send(String message) {
        System.out.println("Sending email: " + message);
    }
}

class SMSService implements NotificationSender {
    @Override
    public void send(String message) {
        System.out.println("Sending SMS: " + message);
    }
}

// High-level module (Depends on abstraction, not on concrete implementations)
class NotificationService {
    private NotificationSender notificationSender;

    // Dependency is injected through constructor
    public NotificationService(NotificationSender notificationSender) {
        this.notificationSender = notificationSender;
    }

    public void sendNotification(String message) {
        notificationSender.send(message);
    }
}

// Client code
public class Main {
    public static void main(String[] args) {
        NotificationSender emailSender = new EmailService();
        NotificationService emailNotificationService = new NotificationService(emailSender);
        emailNotificationService.sendNotification("Hello via Email!");

        NotificationSender smsSender = new SMSService();
        NotificationService smsNotificationService = new NotificationService(smsSender);
        smsNotificationService.sendNotification("Hello via SMS!");
    }
}


// Improvements:
// Loose coupling: The NotificationService depends on the NotificationSender interface rather than concrete classes. New types of notifications (e.g., Push Notifications) can be added without modifying NotificationService.
// Easier to extend: You can easily add more notification channels by implementing the NotificationSender interface.
// Dependency Injection: Dependencies are injected via constructor, promoting flexibility and testability
