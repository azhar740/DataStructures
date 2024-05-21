//### Example:
//Let's create an example of a customer service system.
//#### Handler (SupportHandler):

abstract class SupportHandler {
    protected SupportHandler nextHandler;

    public void setNextHandler(SupportHandler nextHandler) {
        this.nextHandler = nextHandler;
    }

    public void handleRequest(String request) {
        if (nextHandler != null) {
            nextHandler.handleRequest(request);
        }
    }
}


//#### ConcreteHandlers (FrontLineSupport, TechnicalSupport, ManagerSupport):
class FrontLineSupport extends SupportHandler {
    public void handleRequest(String request) {
        if (request.equals("basic issue")) {
            System.out.println("FrontLineSupport: Handling basic issue.");
        } else {
            System.out.println("FrontLineSupport: Passing to next handler.");
            super.handleRequest(request);
        }
    }
}

class TechnicalSupport extends SupportHandler {
    public void handleRequest(String request) {
        if (request.equals("technical issue")) {
            System.out.println("TechnicalSupport: Handling technical issue.");
        } else {
            System.out.println("TechnicalSupport: Passing to next handler.");
            super.handleRequest(request);
        }
    }
}

class ManagerSupport extends SupportHandler {
    public void handleRequest(String request) {
        if (request.equals("complex issue")) {
            System.out.println("ManagerSupport: Handling complex issue.");
        } else {
            System.out.println("ManagerSupport: Unable to handle the request.");
        }
    }
}


//#### Client:

public class ChainOfResponsibilityExample {
    public static void main(String[] args) {
        SupportHandler frontLine = new FrontLineSupport();
        SupportHandler technical = new TechnicalSupport();
        SupportHandler manager = new ManagerSupport();

        frontLine.setNextHandler(technical);
        technical.setNextHandler(manager);

        System.out.println("Sending basic issue:");
        frontLine.handleRequest("basic issue");

        System.out.println("\nSending technical issue:");
        frontLine.handleRequest("technical issue");

        System.out.println("\nSending complex issue:");
        frontLine.handleRequest("complex issue");

        System.out.println("\nSending unknown issue:");
        frontLine.handleRequest("unknown issue");
    }
}


//### Summary:
//
//    - *Handler* (SupportHandler): Defines an interface for handling requests and sets the next handler in the chain.
//    - *ConcreteHandlers* (FrontLineSupport, TechnicalSupport, ManagerSupport): Implement the Handler interface, handle specific types of requests, and pass the request along the chain if they can't handle it.
//    - *Client*: Sends the request to the first handler in the chain.
//
//    The Chain of Responsibility pattern allows you to send requests through a chain of handlers, decoupling the sender from the receiver and providing a flexible way to handle various types of requests.