#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>
int main() {
    Data data;
    data.integer = 42;
    data.str = "Hello Serializer";
    data.value = 3.14f;

    std::cout << "Original Data address: " << &data << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized (as integer): " << raw << std::endl;

    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer: " << ptr << std::endl;

    if (ptr == &data)
        std::cout << " Same address! Serialization works.\n";
    else
        std::cout << "Something went wrong.\n";

    // Access data through ptr
    std::cout << "ptr->integer = " << ptr->integer << std::endl;
    std::cout << "ptr->str = " << ptr->str << std::endl;
    std::cout << "ptr->value = " << ptr->value << std::endl;

    return 0;
}