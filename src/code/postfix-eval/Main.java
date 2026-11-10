// Evaluate a postfix expression using a stack
// Example: 5 2 3 * +  ->  5 + (2*3) = 11
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        String expression = "5 2 3 * +";   // numbers and operators separated by spaces
        Stack<Integer> stack = new Stack<>();

        for (String token : expression.split(" ")) {
            if (Character.isDigit(token.charAt(0))) {
                stack.push(Integer.parseInt(token));   // push the number
            } else {
                int right = stack.pop();               // pop right operand first
                int left = stack.pop();                // then left operand
                int result = 0;

                if (token.equals("+")) result = left + right;
                if (token.equals("-")) result = left - right;
                if (token.equals("*")) result = left * right;
                if (token.equals("/")) result = left / right;

                stack.push(result);                    // push the answer back
            }
        }
        System.out.println("Result: " + stack.peek());
    }
}
