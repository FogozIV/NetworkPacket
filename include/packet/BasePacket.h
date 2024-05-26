//
// Created by fogoz on 26/05/2024.
//

#ifndef NETWORKPACKET_BASEPACKET_H
#define NETWORKPACKET_BASEPACKET_H

#include <cstdint>
#include <memory>

typedef uint16_t packet_size_type;
typedef uint8_t *packet_raw_type;
typedef uint16_t packet_id_type;

class BasePacket {
public:
    virtual const packet_id_type getPacketID() const = 0;

    bool isClientBound() const;

    bool isServerBound() const;

    virtual packet_size_type getPacket(packet_raw_type packet) const;

    virtual packet_size_type getFullPacket(packet_raw_type packet) const;

    virtual packet_size_type getFullPacket(char *packet) const;

    virtual std::shared_ptr<BasePacket> parsePacket(packet_raw_type data, packet_size_type size) = 0;
};

#endif //NETWORKPACKET_BASEPACKET_H
