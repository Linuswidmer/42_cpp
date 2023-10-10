#include "Serialize.hpp"

// a uint_ptr is guaranteed to be large enough to hold a pointer of any type

int main(void)
{
    Data data;

    data.breakfast = "none";
    data.lunch = "sdhfskfhsf";
    data.dinner = "ksdhfsfdshgjsdg";

    std::cout << "Pointer before (de)serialization: " << &data << std::endl;
    uintptr_t   uint_ptr = Serialize::serialize(&data);
    Data        *data_ptr = Serialize::deserialize(uint_ptr);

    std::cout << "Pointer after (de)serialization:  " << data_ptr << std::endl;
    std::cout   << data_ptr->breakfast << std::endl
                << data_ptr->lunch << std::endl
                << data_ptr->dinner << std::endl;
}