class IlariaVector
{
    int num = 0;
    int* data = nullptr;
    int capacity = 0;

public:
    
    // Default Constructor  

    IlariaVector()
    {
        capacity = 1;
        data = new int[capacity];

    }

    // Copy Constructor 

    IlariaVector(const IlariaVector& other) {
        int* box = new int[other.capacity];
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
        int* box = new int[other.capacity];
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

    void addElement(int value)
    {
        if (capacity == num)
        {
            int* box = new int[capacity * 2];
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
