//
// Created by fogoz on 26/05/2024.
//

#include "../../include/packet/BasePacket.h"

bool NetworkPacket::BasePacket::isClientBound() const {
    return (getPacketID() & 0x8000) == 0;
}

bool NetworkPacket::BasePacket::isServerBound() const {
    return !isClientBound();
}

NetworkPacket::packet_size_type NetworkPacket::BasePacket::getFullPacket(NetworkPacket::packet_raw_type packet) const {
    packet_size_type size = getPacket(packet + sizeof(packet_size_type));
    size += sizeof(packet_size_type);
    *((uint16_t*)packet) = size;
    return size;
}

NetworkPacket::packet_size_type NetworkPacket::BasePacket::getPacket(NetworkPacket::packet_raw_type packet) const {
    *((packet_id_type*)packet) = getPacketID();
    return sizeof(packet_id_type);
}

NetworkPacket::packet_size_type NetworkPacket::BasePacket::getFullPacket(char *packet) const {
    return getFullPacket(reinterpret_cast<packet_raw_type>(packet));
}
