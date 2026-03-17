import java.util.LinkedList;
import java.util.EmptyStackException;

public class CustomStack<T> {

    private LinkedList<T> list;

    public CustomStack() {
        this.list = new LinkedList<>();
    }

    public void push(T value) {
        list.addFirst(value);
    }

    public T pop() {
        if (isEmpty()) {
            throw new EmptyStackException();
        }
        return list.removeFirst();
    }

    public int size() {
        return list.size();
    }

    public T peek() {
        if (isEmpty()) {
            throw new EmptyStackException();
        }
        return list.getFirst();
    }

    public boolean isEmpty() {
        return list.isEmpty();
    }

    @Override
    public String toString() {
        return "Zawartość stosu (od szczytu): " + list.toString();
    }
}