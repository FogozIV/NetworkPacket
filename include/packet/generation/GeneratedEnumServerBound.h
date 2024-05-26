//
// Created by fogoz on 26/05/2024.
//

#ifndef NETWORKPACKET_GENERATEDENUMSERVERBOUND_H
#define NETWORKPACKET_GENERATEDENUMSERVERBOUND_H

#define PACKET_CLIENTBOUND_true(name, ...)

#define PACKET_CLIENTBOUND_false(name, ...) \
    ServerBound##name,

enum ServerBoundPacket{
    PACKET_LIST
};


#undef PACKET_CLIENTBOUND_false
#undef PACKET_CLIENTBOUND_true

#endif //NETWORKPACKET_GENERATEDENUMSERVERBOUND_H
