//
// Created by fogoz on 27/05/2024.
//
#include "packet/PacketParser.h"

PacketParser::PacketParser() {
    PACKET_LIST
}

packet_size_type PacketParser::getPacketLength(packet_raw_type buffer) {
    return *((packet_size_type*)buffer);
}

packet_size_type PacketParser::getPacketLength(char *buffer) {
    return getPacketLength((packet_raw_type)buffer);
}

packet_id_type PacketParser::getPacketID(packet_raw_type buffer) {
    return *((packet_id_type*)(buffer + sizeof(packet_size_type)));
}

bool PacketParser::isClientBound(packet_raw_type buffer) {
    return (getPacketID(buffer) & 0x8000) != 0;
}

packet_id_type PacketParser::getPacketID(char *buffer) {
    return getPacketID((packet_raw_type)buffer);
}

std::shared_ptr<BasePacket> PacketParser::parsePacket(packet_raw_type buffer, bool clientBound) {
    auto array = clientBound ? clientBoundPacket : serverBoundPacket;
    if(isClientBound(buffer) != clientBound){
        return nullptr;
    }
    packet_size_type length = getPacketLength(buffer);
    packet_id_type  id = getPacketID(buffer) & 0x7FFF;
    if(array.size() < id){
        return nullptr;
    }
    return array[id](buffer);
}

