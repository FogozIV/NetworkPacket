//
// Created by fogoz on 27/05/2024.
//

#ifndef NETWORKPACKET_PACKETPARSER_H
#define NETWORKPACKET_PACKETPARSER_H

#include <functional>
#include "PacketUtility.h"

#ifndef PACKET_LIST
#define PACKET_LIST
#endif


#define PACKET(name, clientbound, ...) PACKET_CLIENTBOUND_##clientbound(name, clientbound, __VA_ARGS__)

#define PACKET_CLIENTBOUND_true(name, bound, ...) \
    clientBoundPacket.push_back(ClientBound##name##Packet::parsePacket);


#define PACKET_CLIENTBOUND_false(name, bound, ...) \
    serverBoundPacket.push_back(ServerBound##name##Packet::parsePacket);

class PacketParser{
    std::vector<std::function<std::shared_ptr<BasePacket>(packet_raw_type)>> clientBoundPacket;
    std::vector<std::function<std::shared_ptr<BasePacket>(packet_raw_type)>> serverBoundPacket;
public:
    PacketParser();

    packet_size_type getPacketLength(packet_raw_type buffer);

    packet_size_type getPacketLength(char* buffer);

    packet_id_type getPacketID(packet_raw_type buffer);

    packet_id_type getPacketID(char* buffer);

    bool isClientBound(packet_raw_type buffer);

    std::shared_ptr<BasePacket> parsePacket(packet_raw_type buffer, bool clientBound);
};



#endif //NETWORKPACKET_PACKETPARSER_H
