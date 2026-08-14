#include <iostream>
#include <string>
#include <cassert>

class IlariaVector
{
    int num = 0;
    int* data = nullptr;

public:
    void addElement(int value)
    {
        int* box = new int[num + 1];
        for (int i = 0; i < num; i++)
        {
            box[i] = data[i];
        }
        box[num] = value;
        delete[] data;
        data = box;
        num++;
    }

    int getElement(int position)
    {
        assert(position < num); // This is an INVARIANT
        return data[position];
    }

    int size() {
        return num;
    }

    void remove(int position)
    {
        int boxIndex = 0;
        int* box = new int[num - 1];

        for (int i = 0; i < num; i++)
        {
            if (i == position)
            {
                continue;
            }
            box[boxIndex] = data[i];
            boxIndex++;
        }

        delete[] data;
        data = box;
        num -= 1;
    }

    void replace(int position, int newValue)
    {
        assert(position < num);
        data[position] = newValue;
    }


    int& operator[] (int index) {

        assert(index < num);
        return data[index];
    }
};

int main()
{
    IlariaVector v;
    v.addElement(10);
    v.addElement(15);
    std::cout << "Print number at index 1\n";
    std::cout << v.getElement(1) << std::endl;
    std::cout << "Remove element at index 0 and print current number at index 0 \n";
    v.remove(0);
    std::cout << v.getElement(0) << std::endl;
    std::cout << "Print current size of v \n";
    std::cout << v.size() << std::endl; 
    std::cout << "Replace element at index 0 and print new element at index 0 \n";
    v.replace(0, 42);
    std::cout << v.getElement(0) << std::endl;
    std::cout << "Replace element at index 0 by overloading [] and print result \n";
    v[0] = 55;
    std::cout << v[0] << std::endl;

