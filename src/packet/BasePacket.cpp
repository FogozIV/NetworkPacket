//
// Created by fogoz on 26/05/2024.
//

#include "../../include/packet/BasePacket.h"

bool BasePacket::isClientBound() const {
    return (getPacketID() & 0x8000) != 0;
}

bool BasePacket::isServerBound() const {
    return !isClientBound();
}

packet_size_type BasePacket::getFullPacket(packet_raw_type packet) const {
    packet_size_type size = getPacket(packet + sizeof(packet_size_type));
    size += sizeof(packet_size_type);
    *((uint16_t*)packet) = size;
    return size;
}

packet_size_type BasePacket::getPacket(packet_raw_type packet) const {
    *((packet_id_type*)packet) = getPacketID();
    return sizeof(packet_id_type);
}

packet_size_type BasePacket::getFullPacket(char *packet) const {
    return this->getFullPacket(reinterpret_cast<packet_raw_type>(packet));
}
