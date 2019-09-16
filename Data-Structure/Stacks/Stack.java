package prub;

/**
 *
 * @author hardel
 */
public class Stack {
    private int tope = -1;
    private final int[] vec;

    public Stack(int max) {
        vec = new int[max];
    }
    
    public boolean isFull() {
        return tope == vec.length - 1;
    }
    
    public boolean isEmpty() {
        return tope == -1;
    }
    
    public void push(int element) {
        if(!isFull()) {
            vec[++tope] = element;
        } else{
            System.err.println("Stack OVERFLOW!!! xD");
        }
    }
    
    public int pop() {
        int topElement;
        
        if(!isEmpty()) {
            topElement = vec[tope--];
        } else{
            System.err.println("Can't pop on an empty stack, please enter data to the stack first");
            topElement = -1;
        }
        
        return topElement;
    }
    
    public void printStack() {
        if(!isEmpty()) {
            for(int i: vec) {
                System.out.println("Dato de la pila:" + i);
            }
        } else{
            System.err.println("Can't print an empty stack, please enter data to the stack first");
        }
    }
}
