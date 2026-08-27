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
    IlariaVector<int> v;
   
    v.addElement(10);
    v.addElement(15);
    std::cout << "Print number at index 1\n";
    std::cout << v.getElement(1) << std::endl;
    std::cout << "Remove element at index 0 and print current number at index 0 \n";
    v.remove(0);
    std::cout << v.getElement(0) << std::endl;
    std::cout << "Print current size of v \n";
    std::cout << v.size() << std::endl;
    std::cout << "Set element at index 0 and print new element at index 0 \n";
    v.replace(0, 42);
    std::cout << v.getElement(0) << std::endl;
    std::cout << "Set element at index 0 by overloading [] and print result \n";
    v[0] = 55;
    std::cout << v[0] << std::endl;

    IlariaVector<std::string> words;
    std::cout << "Testing vector class with strings \n"; 
    words.addElement("blue");
    words.addElement("red");
    words.addElement("white");
    std::cout << "Print element at index 1 \n"; 
    std::cout << words.getElement(1) << std::endl;
    std::cout << "Remove element at index 0 and print current number at index 0 \n";
    words.remove(0);
    std::cout << words.getElement(0) << std::endl;
    std::cout << "Printing size of words: " << words.size() << std::endl;
    std::cout << "Replace white with black" << std::endl;
    words.replace(1, "black");
    std::cout << "Check that black is now at index 1 in words: " << words.getElement(1) << std::endl;
    std::cout << "Read and replace a value with []: \n";
    words[0] = "green";
    std::cout << words[0] << std::endl;    
    IlariaVector<std::string> colors = words;
    colors[0] = "violet";
    std::cout << "words[0] is " << words[0] << "and colors[0] is " << colors[0] << std::endl;
    // Testing = operator
    IlariaVector<std::string> strings;
    strings = words;
    std::cout << "strings[0]:" << strings[0] << "words[0]: " << words[0] << std::endl;
 
    return 0;

}
