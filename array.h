#include <iostream>
#include <unordered_map>

template<class T>
class Array {
private:
    std::unordered_map<int, T> elements;
    int size;

public:
    Array() {
        std::cout << "Creating array." << std::endl;
        this->size = 0;
    }

    void append(const T& element) {
        this->elements.insert({this->size++, element}); 
    }

    const T& operator[](int index) const {
        if (this->size > index)
            return this->elements.at(index);

        throw "No such element.";
    }

    int getSize() const {
       return this->size;
    }

    template<class X>
    Array<X> map(X(*func)(const T&)) {
        Array<X> newArray;
        for (int i = 0; i < this->size; i++) {
           auto x = func(elements[i]);
           newArray.append(x);
        }
        return newArray;
    }

    Array<T> filter(bool(*func)(const T&)) {
       Array<T> ret;
       for (int i = 0; i < this->size; i++) {
          if (func(elements[i]))
             ret.append(elements[i]);
       }
       return ret;
    }

    void print() const {
       std::cout << "[";
       for(int i = 0; i < this->size; i++) {
          std::cout << this->elements.at(i) << ",";
       }
       std::cout << "]" << std::endl;
    }

    Array<T> operator+(const Array<T>& other) const {
       Array<T> ret;
       for (int i = 0; i < this->size; i++) {
          ret.append(elements.at(i));
       }

       for (int i = 0; i < other.getSize(); i++) {
          ret.append(other[i]);
       }

       return ret;
    }
};

class Dummy {
private:
    static int count;
    int id;

public:
    Dummy() {
        this->id = Dummy::count++;
        std::cout << "Created dummy " << this->id << std::endl;
    }

    Dummy(int id) {
        this->id = id;
        std::cout << "Created dummy " << this->id << std::endl;
    }

    std::string getName() const {
        return std::string("Dummy ") + std::to_string(this->id);
    }

    int getId() const {
       return this->id;
    }
};

int Dummy::count = 0;

std::ostream& operator<<(const Dummy& dummy, std::ostream& os) {
    os << dummy.getName();
    return os;
}

std::ostream& operator<<(std::ostream& os, const Dummy& dummy) {
    os << dummy.getName();
    return os;
}
/*
int main(int argc, const char **argv) {
    Array<Dummy> array;
    {
        Dummy dummy1;
        Dummy dummy2;
        Dummy dummy3;
        array.append(dummy1);
        array.append(dummy2);
        array.append(dummy3);
    }

    std::cout << array[0] << std::endl;
    std::cout << array[1] << std::endl;

    try {
        std::cout << array[2] << std::endl;
    } catch (const char *e) {
        std::cout << e << std::endl;
        // return 1;
    }

    std::cout << "-------------" << std::endl;
    auto f = [](Dummy& el){return el;};
    Dummy(*ff)(const Dummy&) = [](const Dummy& el){return Dummy(el.getId() * 100);};

    Array<Dummy> newArray = array.map<Dummy>(ff);

    std::cout << "-------------" << std::endl;

    bool (*fff)(const Dummy&) = [](const Dummy& el){return el.getId() < 200;};
    Array<Dummy> filteredArray = newArray.filter(fff);

    array.print();
    newArray.print();
    filteredArray.print();

    std::cout << "-------------" << std::endl;

    Array<Dummy> sum = array + newArray + filteredArray;
    sum.print();

    return 0;
}*/
