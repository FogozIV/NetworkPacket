//
// Created by fogoz on 26/05/2024.
//

#include "../../include/packet/PacketUtility.h"

packet_size_type packet_utility::copyArrayOfType(const std::vector<std::string> &array, packet_raw_type buffer) {
    *((array_size_type *) buffer) = (array_size_type) array.size();
    packet_size_type size = sizeof(array_size_type);
    for (const auto &i: array) {
        *((string_size_type *) (buffer + size)) = i.size();
        size += sizeof(string_size_type);
        memcpy((void *) (buffer + size), (void *) i.data(), i.size());
        size += i.size();
    }
    return size;
}

packet_size_type packet_utility::getArrayOfType(std::vector<std::string> &array, packet_raw_type buffer) {
    array_size_type array_size = *((array_size_type *) buffer);
    packet_size_type size = sizeof(array_size_type);
    for (int i = 0; i < array_size; i++) {
        string_size_type stringSize = *((string_size_type *) (buffer + size));
        size += sizeof(stringSize);
        std::string str((char*)(buffer + size), stringSize);
        size += stringSize;
        array.push_back(str);
    }
    return size;
}
