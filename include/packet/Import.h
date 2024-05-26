//
// Created by fogoz on 26/05/2024.
//

#ifndef NETWORKPACKET_IMPORT_H
#define NETWORKPACKET_IMPORT_H
#define PACKET_LIST \
    PACKET(Ping, true, PARAMETERS(0))                        \
    PACKET(Pong, true, PARAMETERS(0))                        \
    PACKET(Ping, false, PARAMETERS(0))                       \
    PACKET(Pong, false, PARAMETERS(0))


#include "generation/PacketGenerator.h"


#endif //NETWORKPACKET_IMPORT_H
