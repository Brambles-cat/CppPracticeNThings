template <typename T>

class Node {
    T value;

    public:
    Node<T> *next = nullptr;

    Node<T>(T data) {
        value = data;
    }

    T& getValue() {
        return value;
    }
    
};