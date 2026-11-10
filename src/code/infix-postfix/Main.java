// Infix to Postfix using a stack
// Example: A+B*C  ->  ABC*+
import java.util.Stack;

public class Main {
    static int precedence(char op) {          // higher number = done first
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return 0;
    }

    public static void main(String[] args) {
        String infix = "A+B*C";
        String postfix = "";
        Stack<Character> stack = new Stack<>();

        for (char c : infix.toCharArray()) {
            if (Character.isLetterOrDigit(c)) {         // operand: send to output
                postfix += c;
            } else if (c == '(') {
                stack.push(c);
            } else if (c == ')') {                      // pop until '('
                while (!stack.isEmpty() && stack.peek() != '(') postfix += stack.pop();
                stack.pop();                            // throw away '('
            } else {                                    // operator
                while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(c))
                    postfix += stack.pop();
                stack.push(c);
            }
        }
        while (!stack.isEmpty()) postfix += stack.pop();   // empty the stack

        System.out.println("Infix:   " + infix);
        System.out.println("Postfix: " + postfix);
    }
}
