//
// Created by fogoz on 26/05/2024.
//

#ifndef NETWORKPACKET_GENERATEDPACKETCLASS_H
#define NETWORKPACKET_GENERATEDPACKETCLASS_H
#include "../PacketUtility.h"

#ifndef PACKET_LIST
#define PACKET_LIST
#endif

#define PACKET_CLIENTBOUND_false(name, bound, ...) \
    X_PACKET(name, ServerBound, bound, __VA_ARGS__)

#define PACKET_CLIENTBOUND_true(name, bound, ...) \
    X_PACKET(name, ClientBound, bound, __VA_ARGS__)

#define EXTRACT(...) __VA_ARGS__

#define DONT_EXTRACT(...)

#define PARAMETERS(count, ...) \
    PARAMS_INIT_##count(__VA_ARGS__)


#define PARAMS_INIT_0(...) \
    , DONT_EXTRACT , (), , , ,

#define PARAMS_INIT_1(type, name) \
    type name;, EXTRACT, (type name), this->name = name;, type get##name() const{return this->name;}, size += packet_utility::copyType(name, buffer+size);, size+= packet_utility::getType(packet->name, buffer+size);

#define PARAMS_1(params_definition, constructor_extractor, params_constructor, params_constructor_content, params_getter, params_to_buffer, params_from_buffer, type, name) \
    params_definition type name;, EXTRACT, (EXTRACT params_constructor, type name), params_constructor_content this->name = name;, params_getter type get##name() const{return this->name;}, params_to_buffer, size += packet_utility::copyType(name, buffer+size);, size+= packet_utility::getType(packet->name, buffer+size);

#define PARAMS_INIT_2(type, name, ...) \
    PARAMS_1(params_definition type name;, EXTRACT, (EXTRACT params_constructor, type name), params_constructor_content this->name = name;, params_getter type get##name() const{return this->name;}, params_to_buffer, size += packet_utility::copyType(name, buffer+size);, size+= packet_utility::getType(packet->name, buffer+size);, __VA_ARGS__)

#define PARAMS_2(params_definition, constructor_extractor, params_constructor, params_constructor_content, params_getter, params_to_buffer, params_from_buffer, type, name, ...) \
    PARAMS_1(params_definition type name;, EXTRACT, (EXTRACT params_constructor, type name), params_constructor_content this->name = name;, params_getter type get##name() const{return this->name;}, params_to_buffer, size += packet_utility::copyType(name, buffer+size);, size+= packet_utility::getType(packet->name, buffer+size);, __VA_ARGS__)
#define PARAMS_INIT_3(type, name, ...) \
    PARAMS_2(params_definition type name;, EXTRACT, (EXTRACT params_constructor, type name), params_constructor_content this->name = name;, params_getter type get##name() const{return this->name;}, params_to_buffer, size += packet_utility::copyType(name, buffer+size);, size+= packet_utility::getType(packet->name, buffer+size);, __VA_ARGS__)


#define X_PACKET(name, BoundName, clientbound, params_definition, constructor_extractor, params_constructor, params_constructor_content, params_getter, params_to_buffer, params_from_buffer) \
class BoundName##name##Packet : public BasePacket{                                                                          \
    params_definition                                                                                                       \
    public:                                                                                                                 \
        const packet_id_type getPacketID() const override{                                                                  \
            return BoundName##name + (clientbound ? 0x8000 : 0);                                                            \
        }                                                                                                                   \
        constructor_extractor(BoundName##name##Packet() = default;)                                                         \
        BoundName##name##Packet(EXTRACT params_constructor) {                                                               \
                params_constructor_content                                                                                  \
        }                                                                                                                   \
        params_getter                                                                                                       \
        packet_size_type getPacket(packet_raw_type buffer) const override {                                                 \
            packet_size_type size = 0;                                                                                      \
            params_to_buffer                                                                                                \
            return size;                                                                                                    \
        }                                                                                                                   \
        static std::shared_ptr<BoundName##name##Packet> parsePacket(packet_raw_type buffer){                                \
            packet_size_type size = 0;                                                                                      \
            std::shared_ptr<BoundName##name##Packet> packet(new BoundName##name##Packet());                                 \
            params_from_buffer                                                                                              \
            return packet;                                                                                                  \
        }                                                                                                                   \
};

PACKET_LIST

#undef PARAMS_1
#undef PARAMS_2
#undef PARAMS_INIT_0
#undef PARAMS_INIT_1
#undef PARAMS_INIT_2
#undef PARAMS_INIT_3

#undef PARAMETERS

#undef PACKET_CLIENTBOUND_false
#undef PACKET_CLIENTBOUND_true




#endif //NETWORKPACKET_GENERATEDPACKETCLASS_H
