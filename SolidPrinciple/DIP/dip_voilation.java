// Here, the NotificationService directly depends on the concrete implementations of EmailService and SMSService. 
// This violates DIP because if we want to add a new notification type (e.g., Push Notifications), the NotificationService class would need to change.
// Low-level modules (Concrete implementations)
class EmailService {
    public void sendEmail(String message) {
        System.out.println("Sending email: " + message);
    }
}

class SMSService {
    public void sendSMS(String message) {
        System.out.println("Sending SMS: " + message);
    }
}

// High-level module (Depends directly on low-level modules)
class NotificationService {
    private EmailService emailService;
    private SMSService smsService;

    public NotificationService() {
        this.emailService = new EmailService(); // Concrete dependency
        this.smsService = new SMSService();     // Concrete dependency
    }

    public void sendNotification(String message, String channel) {
        if (channel.equals("email")) {
            emailService.sendEmail(message);
        } else if (channel.equals("sms")) {
            smsService.sendSMS(message);
        }
    }
}

// Client code
public class Main {
    public static void main(String[] args) {
        NotificationService notificationService = new NotificationService();
        notificationService.sendNotification("Hello World!", "email");
        notificationService.sendNotification("Hello World!", "sms");
    }
}


//Problems:
//Tight coupling: NotificationService is tightly coupled with EmailService and SMSService. If you want to add a new notification type, you have to modify the //NotificationService class.
// No abstraction: The high-level class depends on the concrete implementations, rather than abstractions.
