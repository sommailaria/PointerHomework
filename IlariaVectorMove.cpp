#include <iostream>
#include <string>
#include <cassert>

template <typename T>
class IlariaVector
{
    int num = 0;
    T* data = nullptr;
    int capacity = 0;

public:

    // Default Constructor  

    IlariaVector()
    {
        capacity = 1;
        data = new T[capacity];

    }

    // Copy Constructor 

    IlariaVector(const IlariaVector& other) {
        T* box = new T[other.capacity];
        for (int i = 0; i < other.num; i++)
        {
            box[i] = other.data[i];
        }
        data = box;
        num = other.num;
        capacity = other.capacity;
    }

    // Move Constructor 

    IlariaVector(IlariaVector&& other) {
        data = other.data;
        num = other.num;
        capacity = other.capacity;
        other.capacity = 1;
        other.data = new T[other.capacity];
        other.num = 0;
    }

    // Move Operator 

    IlariaVector& operator=(IlariaVector&& other) {

        if (this == &other) {

            return *this;
        }
        delete[] data;
        data = other.data;
        num = other.num;
        capacity = other.capacity;
        other.capacity = 1;
        other.data = new T[other.capacity];
        other.num = 0;
        return *this;

    }

    // Destructor 

    ~IlariaVector()
    {
        delete[] data;
    }

    // = operator

    IlariaVector& operator=(const IlariaVector& other)
    {
        T* box = new T[other.capacity];
        for (int i = 0; i < other.num; i++)
        {
            box[i] = other.data[i];
        }
        delete[] data;
        data = box;
        num = other.num;
        capacity = other.capacity;
        return *this;
    }


    // Member functions 

    void addElement(const T& value)
    {
        if (capacity == num)
        {
            T* box = new T[capacity * 2];
            for (int i = 0; i < num; i++)
            {
                box[i] = data[i];
            }

            delete[] data;
            data = box;
            capacity = capacity * 2;
        }
        data[num] = value;
        num++;
    }

    const T& getElement(int position) const
    {
        assert(position < num); // This is an INVARIANT
        return data[position];
    }

    int size() {
        return num;
    }

    void remove(int position)
    {
        int writeToData = 0;
        for (int i = 0; i < num; i++)
        {
            if (i == position)
            {
                continue;
            }

            data[writeToData] = data[i];
            writeToData++;
        }
        num = num - 1;
    }

    void replace(int position, T newValue)
    {
        assert(position < num);
        data[position] = newValue;
    }


    T& operator[] (int index) {

        assert(index < num);
        return data[index];
    }


};

int main()
{
    std::cout << "\n--- Testing move assignment ---\n";

    IlariaVector<std::string> source;
    source.addElement("one");
    source.addElement("two");
    source.addElement("three");

    IlariaVector<std::string> destination;
    destination.addElement("old");
    destination.addElement("data");

    destination = std::move(source);

    std::cout << "destination[0]: " << destination[0] << '\n';
    std::cout << "destination[1]: " << destination[1] << '\n';
    std::cout << "destination[2]: " << destination[2] << '\n';

    std::cout << "source size: " << source.size() << '\n';
    std::cout << "destination size: " << destination.size() << '\n';

    std::cout << "\n--- Testing source after move assignment ---\n";

    IlariaVector<int> a;
    a.addElement(1);
    a.addElement(2);

    IlariaVector<int> b;
    b.addElement(100);

    b = std::move(a);

    a.addElement(50);

    std::cout << "a size: " << a.size() << '\n';
    std::cout << "a[0]: " << a[0] << '\n';

    std::cout << "b size: " << b.size() << '\n';
    std::cout << "b[0]: " << b[0] << '\n';
    std::cout << "b[1]: " << b[1] << '\n';


    return 0;

}
