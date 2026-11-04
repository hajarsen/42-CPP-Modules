#include "Serializer.hpp"

#include <iostream>

int main()
{
    Data data;
    data.id = 42;
    data.name = "serialized data";

    Data* original = &data;
    uintptr_t raw = Serializer::serialize(original);
    Data* restored = Serializer::deserialize(raw);

    std::cout << "Original pointer: " << original << std::endl;
    std::cout << "raw : " << raw << std::endl;
    std::cout << "Deserialized pointer: " << restored << std::endl;
    std::cout << "Pointers match: " << (original == restored ? "true" : "false") << std::endl;
    std::cout << "Data: " << restored->id << ", " << restored->name << std::endl;
    return original == restored ? 0 : 1;
}
