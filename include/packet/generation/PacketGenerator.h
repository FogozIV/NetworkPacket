//
// Created by fogoz on 26/05/2024.
//

#ifndef NETWORKPACKET_PACKETGENERATOR_H
#define NETWORKPACKET_PACKETGENERATOR_H

#define PACKET(name, clientbound, ...) PACKET_CLIENTBOUND_##clientbound(name, clientbound, __VA_ARGS__)
//We generate the ClientBoundPacketEnum
#include "GeneratedEnumClientBound.h"
//We generate the ServerBoundPacketEnum
#include "GeneratedEnumServerBound.h"
//We generate the packets
#include "GeneratedPacketClass.h"

#undef PACKET

#endif //NETWORKPACKET_PACKETGENERATOR_H
