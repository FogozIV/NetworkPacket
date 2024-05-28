//
// Created by fogoz on 26/05/2024.
//

#include "../../include/packet/PacketUtility.h"

static packet_size_type packet_utility::copyArrayOfType(const std::vector<std::string> &array, packet_raw_type buffer) {
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

static packet_size_type packet_utility::getArrayOfType(std::vector<std::string> &array, packet_raw_type buffer) {
    array_size_type array_size = *((array_size_type *) buffer);
    packet_size_type size = sizeof(array_size_type);
    for (int i = 0; i < array_size; i++) {
        string_size_type stringSize = *((string_size_type *) (buffer + size));
        size += sizeof(stringSize);
        std::string str((char *) (buffer + size), stringSize);
        size += stringSize;
        array.push_back(str);
    }
    return size;
}

template<typename T>
static packet_size_type packet_utility::copyArrayOfType(const std::vector<T> &array, packet_raw_type buffer) {
    *((array_size_type *) buffer) = (array_size_type) array.size();
    packet_size_type size = sizeof(array_size_type);
    memcpy((void *) (buffer + size), (void *) array.data(), array.size() * sizeof(T));
    return size + array.size() * sizeof(T);
}

template<typename T>
static packet_size_type packet_utility::getArrayOfType(std::vector<T> &array, packet_raw_type buffer) {
    array_size_type arraySize = *((array_size_type *) buffer);
    packet_size_type size = sizeof(array_size_type);
    T *otherPacket = (T *) (buffer + size);
    std::copy(&otherPacket[0], &otherPacket[arraySize], std::back_inserter(array));
    size += arraySize * sizeof(T);
    return size;
}

template<typename T>
static packet_size_type packet_utility::copySetOfType(const std::set<T> &array, packet_raw_type buffer) {
    *((array_size_type *) buffer) = array.size();
    packet_size_type size = sizeof(array_size_type);
    std::copy(array.begin(), array.end(), (T *) (buffer + size));
    return size + sizeof(T) * array.size();
}
template<typename T>
static packet_size_type packet_utility::getSetOfType(std::set<T>& array, packet_raw_type buffer){
    array_size_type arraySize = *((array_size_type*)buffer);
    packet_size_type size = sizeof (array_size_type);
    T* otherPacket = (T*)(buffer+size);
    std::copy(&otherPacket, &otherPacket[arraySize], std::back_inserter(array));
    return size + arraySize * sizeof(T);
}

template<typename T>
static packet_size_type packet_utility::copyType(const T& data , packet_raw_type buffer){
    *((T*) buffer) = data;
    return sizeof (T);
}

template<typename T>
static packet_size_type packet_utility::getType(T& data, packet_raw_type buffer){
    data = *((T*)buffer);
    return sizeof(T);
}

static packet_size_type packet_utility::copyType(const std::string& str, packet_raw_type buffer){
    *((string_size_type*)buffer) = str.size();
    packet_size_type size = sizeof(string_size_type);
    memcpy((void*)(buffer+size), (void*)str.data(), str.size());
    return size + str.size();
}

static packet_size_type packet_utility::getType(std::string& str, packet_raw_type buffer){
    string_size_type stringSize = *((string_size_type*) buffer);
    packet_size_type size = sizeof(string_size_type);
    str = std::string ((char*)(buffer+size), stringSize);
    return size + stringSize;
}


static packet_size_type packet_utility::copyType(const std::vector<std::string>& array, packet_raw_type buffer){
    return copyArrayOfType(array, buffer);
}

static packet_size_type packet_utility::getType(std::vector<std::string>& array, packet_raw_type buffer){
    return getArrayOfType(array, buffer);
}

template<typename T>
static packet_size_type packet_utility::copyType(const std::vector<T>& array, packet_raw_type buffer){
    return copyArrayOfType(array, buffer);
}

template<typename T>
static packet_size_type packet_utility::getType(std::vector<T>& array, packet_raw_type buffer){
    return getArrayOfType(array, buffer);
}

template<typename T>
static packet_size_type packet_utility::copyType(const std::set<T>& array, packet_raw_type buffer){
    return copySetOfType(array, buffer);
}

template<typename T>
static packet_size_type packet_utility::getType(std::set<T>& array, packet_raw_type buffer){
    return getSetOfType(array, buffer);
}
