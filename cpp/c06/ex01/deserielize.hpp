#ifndef DESERIELIZE_HPP
#define DESERIELIZE_HPP
#include "data.hpp"

uintptr_t	serialize(Data* ptr);
Data   		*deserialize(uintptr_t raw);


#endif