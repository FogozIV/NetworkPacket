//
// Created by fogoz on 26/05/2024.
//

#ifndef NETWORKPACKET_GENERATEDENUMCLIENTBOUND_H
#define NETWORKPACKET_GENERATEDENUMCLIENTBOUND_H

#define PACKET_CLIENTBOUND_true(name, ...) \
    ClientBound##name,

#define PACKET_CLIENTBOUND_false(name, ...)

enum ClientBoundPacket{
    PACKET_LIST
};

#undef PACKET_CLIENTBOUND_false
#undef PACKET_CLIENTBOUND_true


#endif //NETWORKPACKET_GENERATEDENUMCLIENTBOUND_H
