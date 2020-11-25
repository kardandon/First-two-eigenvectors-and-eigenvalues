template <class T>

// Column Class Decleration
class  Column
{
public:

    // Constructers for Column Class
    Column();
    Column(unsigned int size);
    Column(unsigned int size, const T & initial);
    Column(const Column<T> & v);      
    // Destructor for Column Class
    ~Column();
    // Basic methods for Column Class
    unsigned int capacity() const;
    unsigned int size() const;
    bool empty() const;
    T & front();
    T & back();
    // Increasing size and adding value to back of that array
    void push_back(const T & value); 

    // Memory Allocation Methods for Column Class
    void reserve(unsigned int capacity);   
    void resize(unsigned int size);   
    void resize(unsigned int size, T val);   

    // Operator Overload for Column Class
    T & operator[](unsigned int index);  
    Column<T> & operator=(const Column<T> &);

    // Clearing Column
    void clear();
private:
    // Private variables of Column Class
    unsigned int my_size;
    unsigned int my_capacity;
    T * array;
};