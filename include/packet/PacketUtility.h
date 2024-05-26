//
// Created by fogoz on 26/05/2024.
//

#ifndef NETWORKPACKET_PACKETUTILITY_H
#define NETWORKPACKET_PACKETUTILITY_H

#include <vector>
#include <string>
#include <set>
#include "BasePacket.h"

namespace packet_utility{

    typedef uint16_t array_size_type;
    typedef uint16_t string_size_type;

    static packet_size_type copyArrayOfType(const std::vector<std::string>&, packet_raw_type);

    static packet_size_type getArrayOfType(std::vector<std::string>&, packet_raw_type);

    template<typename T>
    static packet_size_type copyArrayOfType(const std::vector<T>&, packet_raw_type);

    template<typename T>
    static packet_size_type getArrayOfType(std::vector<T>&, packet_raw_type);

    template<typename T>
    static packet_size_type copySetOfType(const std::set<T>&, packet_raw_type);

    template<typename T>
    static packet_size_type getSetOfType(std::set<T>&, packet_raw_type);

    template<typename T>
    static packet_size_type copyType(const T&, packet_raw_type);

    template<typename T>
    static packet_size_type getType(T&, packet_raw_type);

    static packet_size_type copyType(const std::string&, packet_raw_type);

    static packet_size_type getType(std::string&, packet_raw_type);



    static packet_size_type copyType(const std::vector<std::string>&, packet_raw_type);

    static packet_size_type getType(std::vector<std::string>&, packet_raw_type);

    template<typename T>
    static packet_size_type copyType(const std::vector<T>&, packet_raw_type);

    template<typename T>
    static packet_size_type getType(std::vector<T>&, packet_raw_type);

    template<typename T>
    static packet_size_type copyType(const std::set<T>&, packet_raw_type);

    template<typename T>
    static packet_size_type getType(std::set<T>&, packet_raw_type);


}


#endif //NETWORKPACKET_PACKETUTILITY_H
