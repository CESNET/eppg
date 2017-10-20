/* Automatically generated by p4c-fpp from p4-16/parser.p4 on Fri Oct 20 12:04:55 2017
 */
#include "parser.h"
#include <stdint.h>
#include <stdlib.h>
#include <arpa/inet.h>

int fpp_parse_packet(const uint8_t *packet, uint32_t packet_len, packet_hdr_t **out){
    packet_hdr_t *last_hdr = NULL;
    packet_hdr_t *hdr = NULL;
    const uint8_t *fpp_packetStart = packet;
    const uint8_t *fpp_packetEnd = packet + packet_len;
    uint64_t fpp_packetOffsetInBits = 0;
    enum fpp_errorCodes fpp_errorCode = ParserDefaultReject;

    struct ieee802_1q_h vlan_q;
    struct mpls_h mpls;
    struct eompls_h eompls;
    struct gre_h gre;
    struct gre_sre_h gre_sre;
    struct l2tp_h l2tp;
    struct teredo_auth_h teredo_auth;
    struct teredo_origin_h teredo_origin;
    struct pptp_uncomp_proto_h pptp_uncomp_proto;
    struct pptp_comp_proto_h pptp_comp_proto;
    uint16_t udp_src_port;
    uint8_t tmp_13;
    uint16_t tmp_14;
    uint8_t tmp_15;
    uint8_t tmp_16;
    uint8_t tmp_17;
    uint8_t tmp_18;
    uint32_t tmp_19;
    uint32_t tmp_20;
    uint32_t tmp_21;
    uint32_t tmp_22;
    uint8_t tmp_23;
    uint16_t tmp_24;
    uint8_t tmp_25;
    uint8_t tmp_26;

    (void) vlan_q;
    (void) mpls;
    (void) eompls;
    (void) gre;
    (void) gre_sre;
    (void) l2tp;
    (void) teredo_auth;
    (void) teredo_origin;
    (void) pptp_uncomp_proto;
    (void) pptp_comp_proto;
    (void) udp_src_port;
    (void) tmp_13;
    (void) tmp_14;
    (void) tmp_15;
    (void) tmp_16;
    (void) tmp_17;
    (void) tmp_18;
    (void) tmp_19;
    (void) tmp_20;
    (void) tmp_21;
    (void) tmp_22;
    (void) tmp_23;
    (void) tmp_24;
    (void) tmp_25;
    (void) tmp_26;

    *out = NULL;

    goto start;
    start: {
        goto parse_ethernet;
    }
    parse_ethernet: {
/* extract(headers[0])*/
        if (fpp_packetEnd < fpp_packetStart + BYTES(fpp_packetOffsetInBits + 112)) {
            fpp_errorCode = PacketTooShort;
            goto reject;
        }
        struct ethernet_h *headers = (struct ethernet_h *) malloc(sizeof(struct ethernet_h));
        if (headers == NULL) { fpp_errorCode = OutOfMemory; goto fpp_end; }
        hdr = (packet_hdr_t *) malloc(sizeof(packet_hdr_t));
        if (hdr == NULL) { free(headers); fpp_errorCode = OutOfMemory; goto fpp_end; }
        
        hdr->type = fpp_ethernet_h;
        hdr->hdr = headers;
        hdr->next = NULL;

        if (*out == NULL) {
                *out = hdr;
                last_hdr = hdr;
        } else {
                last_hdr->next = hdr;
                last_hdr = hdr;
        }

        headers->header_offset = fpp_packetOffsetInBits / 8;

        headers[0].dst_addr[0] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 0) >> 0));
        headers[0].dst_addr[1] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 1) >> 0));
        headers[0].dst_addr[2] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 2) >> 0));
        headers[0].dst_addr[3] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 3) >> 0));
        headers[0].dst_addr[4] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 4) >> 0));
        headers[0].dst_addr[5] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 5) >> 0));
        fpp_packetOffsetInBits += 48;

        headers[0].src_addr[0] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 0) >> 0));
        headers[0].src_addr[1] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 1) >> 0));
        headers[0].src_addr[2] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 2) >> 0));
        headers[0].src_addr[3] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 3) >> 0));
        headers[0].src_addr[4] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 4) >> 0));
        headers[0].src_addr[5] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 5) >> 0));
        fpp_packetOffsetInBits += 48;

        headers[0].ethertype = ntohs((uint16_t)((load_half(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 16;

        headers[0].header_valid = 1;
        switch (headers[0].ethertype) {
            case 2048: goto parse_ipv4;
            case 34525: goto parse_ipv6;
            case 34887: goto parse_mpls;
            case 34888: goto parse_mpls;
            case 33024: goto parse_vlan_q;
            default: goto reject;
        }
    }
    parse_vlan_q: {
/* extract(vlan_q)*/
        if (fpp_packetEnd < fpp_packetStart + BYTES(fpp_packetOffsetInBits + 32)) {
            fpp_errorCode = PacketTooShort;
            goto reject;
        }
        vlan_q.pcp = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)) >> 5) & FPP_MASK(uint8_t, 3)));
        fpp_packetOffsetInBits += 3;

        vlan_q.cfi = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)) >> 4) & FPP_MASK(uint8_t, 1)));
        fpp_packetOffsetInBits += 1;

        vlan_q.vid = ntohs((uint16_t)((load_half(fpp_packetStart, BYTES(fpp_packetOffsetInBits))) & FPP_MASK(uint16_t, 12)));
        fpp_packetOffsetInBits += 12;

        vlan_q.ethertype = ntohs((uint16_t)((load_half(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 16;

        vlan_q.header_valid = 1;
        switch (vlan_q.ethertype) {
            case 2048: goto parse_ipv4;
            case 34525: goto parse_ipv6;
            case 34887: goto parse_mpls;
            case 34888: goto parse_mpls;
            case 33024: goto parse_vlan_q;
            default: goto reject;
        }
    }
    parse_mpls: {
/* extract(mpls)*/
        if (fpp_packetEnd < fpp_packetStart + BYTES(fpp_packetOffsetInBits + 32)) {
            fpp_errorCode = PacketTooShort;
            goto reject;
        }
        mpls.label = ntohl((uint32_t)((load_word(fpp_packetStart, BYTES(fpp_packetOffsetInBits)) >> 12) & FPP_MASK(uint32_t, 20)));
        fpp_packetOffsetInBits += 20;

        mpls.tc = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)) >> 1) & FPP_MASK(uint8_t, 3)));
        fpp_packetOffsetInBits += 3;

        mpls.bos = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits))) & FPP_MASK(uint8_t, 1)));
        fpp_packetOffsetInBits += 1;

        mpls.ttl = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 8;

        mpls.header_valid = 1;
        switch (mpls.bos) {
            case 0: goto parse_mpls;
            case 1: goto parse_mpls_end;
            default: goto reject;
        }
    }
    parse_mpls_end: {
tmp_13 = /* lookahead()*/
        ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)) >> 4) & FPP_MASK(uint8_t, 4)));
;        switch (tmp_13) {
            case 4: goto parse_ipv4;
            case 6: goto parse_ipv6;
            case 0: goto parse_eompls;
            default: goto reject;
        }
    }
    parse_eompls: {
/* extract(eompls)*/
        if (fpp_packetEnd < fpp_packetStart + BYTES(fpp_packetOffsetInBits + 32)) {
            fpp_errorCode = PacketTooShort;
            goto reject;
        }
        eompls.zero = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)) >> 4) & FPP_MASK(uint8_t, 4)));
        fpp_packetOffsetInBits += 4;

        eompls.res = ntohs((uint16_t)((load_half(fpp_packetStart, BYTES(fpp_packetOffsetInBits))) & FPP_MASK(uint16_t, 12)));
        fpp_packetOffsetInBits += 12;

        eompls.seq_num = ntohs((uint16_t)((load_half(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 16;

        eompls.header_valid = 1;
        goto parse_ethernet;
    }
    parse_pptp: {
tmp_14 = /* lookahead()*/
        ntohs((uint16_t)((load_half(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
;        switch (tmp_14) {
            case 65283: goto parse_pptp_uncomp_addr_cntrl;
            default: goto parse_pptp_comp_addr_cntrl;
        }
    }
    parse_pptp_uncomp_addr_cntrl: {
/* advance(16)*/
        fpp_packetOffsetInBits += 16;
tmp_15 = /* lookahead()*/
        ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
;tmp_16 = (tmp_15 & 1);        switch (tmp_16) {
            case 0: goto parse_pptp_uncomp_proto;
            case 1: goto parse_pptp_comp_proto;
            default: goto reject;
        }
    }
    parse_pptp_comp_addr_cntrl: {
tmp_17 = /* lookahead()*/
        ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
;tmp_18 = (tmp_17 & 1);        switch (tmp_18) {
            case 0: goto parse_pptp_uncomp_proto;
            case 1: goto parse_pptp_comp_proto;
            default: goto reject;
        }
    }
    parse_pptp_uncomp_proto: {
/* extract(pptp_uncomp_proto)*/
        if (fpp_packetEnd < fpp_packetStart + BYTES(fpp_packetOffsetInBits + 16)) {
            fpp_errorCode = PacketTooShort;
            goto reject;
        }
        pptp_uncomp_proto.proto = ntohs((uint16_t)((load_half(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 16;

        pptp_uncomp_proto.header_valid = 1;
        switch (pptp_uncomp_proto.proto) {
            case 33: goto parse_ipv4;
            case 87: goto parse_ipv6;
            case 253: goto accept;
            case 49185: goto accept;
            default: goto reject;
        }
    }
    parse_pptp_comp_proto: {
/* extract(pptp_comp_proto)*/
        if (fpp_packetEnd < fpp_packetStart + BYTES(fpp_packetOffsetInBits + 8)) {
            fpp_errorCode = PacketTooShort;
            goto reject;
        }
        pptp_comp_proto.proto = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 8;

        pptp_comp_proto.header_valid = 1;
        switch (((uint16_t)pptp_comp_proto.proto)) {
            case 33: goto parse_ipv4;
            case 87: goto parse_ipv6;
            case 253: goto accept;
            case 49185: goto accept;
            default: goto reject;
        }
    }
    parse_ipv4: {
/* extract(headers[0])*/
        if (fpp_packetEnd < fpp_packetStart + BYTES(fpp_packetOffsetInBits + 160)) {
            fpp_errorCode = PacketTooShort;
            goto reject;
        }
        struct ipv4_h *headers = (struct ipv4_h *) malloc(sizeof(struct ipv4_h));
        if (headers == NULL) { fpp_errorCode = OutOfMemory; goto fpp_end; }
        hdr = (packet_hdr_t *) malloc(sizeof(packet_hdr_t));
        if (hdr == NULL) { free(headers); fpp_errorCode = OutOfMemory; goto fpp_end; }
        
        hdr->type = fpp_ipv4_h;
        hdr->hdr = headers;
        hdr->next = NULL;

        if (*out == NULL) {
                *out = hdr;
                last_hdr = hdr;
        } else {
                last_hdr->next = hdr;
                last_hdr = hdr;
        }

        headers->header_offset = fpp_packetOffsetInBits / 8;

        headers[0].version = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)) >> 4) & FPP_MASK(uint8_t, 4)));
        fpp_packetOffsetInBits += 4;

        headers[0].ihl = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits))) & FPP_MASK(uint8_t, 4)));
        fpp_packetOffsetInBits += 4;

        headers[0].diffserv = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 8;

        headers[0].total_len = ntohs((uint16_t)((load_half(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 16;

        headers[0].identification = ntohs((uint16_t)((load_half(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 16;

        headers[0].flags = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)) >> 5) & FPP_MASK(uint8_t, 3)));
        fpp_packetOffsetInBits += 3;

        headers[0].frag_offset = ntohs((uint16_t)((load_half(fpp_packetStart, BYTES(fpp_packetOffsetInBits))) & FPP_MASK(uint16_t, 13)));
        fpp_packetOffsetInBits += 13;

        headers[0].ttl = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 8;

        headers[0].protocol = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 8;

        headers[0].hdr_checksum = ntohs((uint16_t)((load_half(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 16;

        headers[0].src_addr = ntohl((uint32_t)((load_word(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 32;

        headers[0].dst_addr = ntohl((uint32_t)((load_word(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 32;

        headers[0].header_valid = 1;
/* advance(((uint32_t)((((int32_t)((uint32_t)headers[0].ihl)) + -5) << 5)))*/
        fpp_packetOffsetInBits += ((uint32_t)((((int32_t)((uint32_t)headers[0].ihl)) + -5) << 5));
        switch (headers[0].protocol) {
            case 6: goto parse_tcp;
            case 17: goto parse_udp;
            case 1: goto accept;
            case 47: goto parse_gre;
            case 4: goto parse_ipv4;
            case 41: goto parse_ipv6;
            default: goto reject;
        }
    }
    parse_ipv6: {
/* extract(headers[0])*/
        if (fpp_packetEnd < fpp_packetStart + BYTES(fpp_packetOffsetInBits + 320)) {
            fpp_errorCode = PacketTooShort;
            goto reject;
        }
        struct ipv6_h *headers = (struct ipv6_h *) malloc(sizeof(struct ipv6_h));
        if (headers == NULL) { fpp_errorCode = OutOfMemory; goto fpp_end; }
        hdr = (packet_hdr_t *) malloc(sizeof(packet_hdr_t));
        if (hdr == NULL) { free(headers); fpp_errorCode = OutOfMemory; goto fpp_end; }
        
        hdr->type = fpp_ipv6_h;
        hdr->hdr = headers;
        hdr->next = NULL;

        if (*out == NULL) {
                *out = hdr;
                last_hdr = hdr;
        } else {
                last_hdr->next = hdr;
                last_hdr = hdr;
        }

        headers->header_offset = fpp_packetOffsetInBits / 8;

        headers[0].version = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)) >> 4) & FPP_MASK(uint8_t, 4)));
        fpp_packetOffsetInBits += 4;

        headers[0].traffic_class = ntohs((uint8_t)((load_half(fpp_packetStart, BYTES(fpp_packetOffsetInBits)) >> 4) & FPP_MASK(uint8_t, 8)));
        fpp_packetOffsetInBits += 8;

        headers[0].flow_label = ntohl((uint32_t)((load_word(fpp_packetStart, BYTES(fpp_packetOffsetInBits)) >> 8) & FPP_MASK(uint32_t, 20)));
        fpp_packetOffsetInBits += 20;

        headers[0].payload_len = ntohs((uint16_t)((load_half(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 16;

        headers[0].next_hdr = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 8;

        headers[0].hop_limit = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 8;

        headers[0].src_addr[0] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 0) >> 0));
        headers[0].src_addr[1] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 1) >> 0));
        headers[0].src_addr[2] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 2) >> 0));
        headers[0].src_addr[3] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 3) >> 0));
        headers[0].src_addr[4] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 4) >> 0));
        headers[0].src_addr[5] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 5) >> 0));
        headers[0].src_addr[6] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 6) >> 0));
        headers[0].src_addr[7] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 7) >> 0));
        headers[0].src_addr[8] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 8) >> 0));
        headers[0].src_addr[9] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 9) >> 0));
        headers[0].src_addr[10] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 10) >> 0));
        headers[0].src_addr[11] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 11) >> 0));
        headers[0].src_addr[12] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 12) >> 0));
        headers[0].src_addr[13] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 13) >> 0));
        headers[0].src_addr[14] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 14) >> 0));
        headers[0].src_addr[15] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 15) >> 0));
        fpp_packetOffsetInBits += 128;

        headers[0].dst_addr[0] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 0) >> 0));
        headers[0].dst_addr[1] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 1) >> 0));
        headers[0].dst_addr[2] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 2) >> 0));
        headers[0].dst_addr[3] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 3) >> 0));
        headers[0].dst_addr[4] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 4) >> 0));
        headers[0].dst_addr[5] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 5) >> 0));
        headers[0].dst_addr[6] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 6) >> 0));
        headers[0].dst_addr[7] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 7) >> 0));
        headers[0].dst_addr[8] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 8) >> 0));
        headers[0].dst_addr[9] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 9) >> 0));
        headers[0].dst_addr[10] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 10) >> 0));
        headers[0].dst_addr[11] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 11) >> 0));
        headers[0].dst_addr[12] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 12) >> 0));
        headers[0].dst_addr[13] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 13) >> 0));
        headers[0].dst_addr[14] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 14) >> 0));
        headers[0].dst_addr[15] = (uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits) + 15) >> 0));
        fpp_packetOffsetInBits += 128;

        headers[0].header_valid = 1;
        switch (headers[0].next_hdr) {
            case 6: goto parse_tcp;
            case 17: goto parse_udp;
            case 58: goto accept;
            case 47: goto parse_gre;
            case 4: goto parse_ipv4;
            case 41: goto parse_ipv6;
            default: goto reject;
        }
    }
    parse_gre: {
/* extract(gre)*/
        if (fpp_packetEnd < fpp_packetStart + BYTES(fpp_packetOffsetInBits + 32)) {
            fpp_errorCode = PacketTooShort;
            goto reject;
        }
        gre.C = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)) >> 7) & FPP_MASK(uint8_t, 1)));
        fpp_packetOffsetInBits += 1;

        gre.R = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)) >> 6) & FPP_MASK(uint8_t, 1)));
        fpp_packetOffsetInBits += 1;

        gre.K = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)) >> 5) & FPP_MASK(uint8_t, 1)));
        fpp_packetOffsetInBits += 1;

        gre.S = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)) >> 4) & FPP_MASK(uint8_t, 1)));
        fpp_packetOffsetInBits += 1;

        gre.s = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)) >> 3) & FPP_MASK(uint8_t, 1)));
        fpp_packetOffsetInBits += 1;

        gre.recur = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits))) & FPP_MASK(uint8_t, 3)));
        fpp_packetOffsetInBits += 3;

        gre.A = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)) >> 7) & FPP_MASK(uint8_t, 1)));
        fpp_packetOffsetInBits += 1;

        gre.flags = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)) >> 3) & FPP_MASK(uint8_t, 4)));
        fpp_packetOffsetInBits += 4;

        gre.ver = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits))) & FPP_MASK(uint8_t, 3)));
        fpp_packetOffsetInBits += 3;

        gre.proto = ntohs((uint16_t)((load_half(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 16;

        gre.header_valid = 1;
        switch (gre.ver) {
            case 0: goto parse_gre_v0;
            case 1: goto parse_gre_v1;
            default: goto reject;
        }
    }
    parse_gre_v0: {
/* advance(((((uint32_t)gre.C) | ((uint32_t)gre.R)) << 5))*/
        fpp_packetOffsetInBits += ((((uint32_t)gre.C) | ((uint32_t)gre.R)) << 5);
/* advance((((uint32_t)gre.K) << 5))*/
        fpp_packetOffsetInBits += (((uint32_t)gre.K) << 5);
/* advance((((uint32_t)gre.S) << 5))*/
        fpp_packetOffsetInBits += (((uint32_t)gre.S) << 5);
        switch (gre.R) {
            case 1: goto parse_gre_sre;
            case 0: goto parse_gre_v0_fin;
            default: goto reject;
        }
    }
    parse_gre_v0_fin: {
        switch (gre.proto) {
            case 2048: goto parse_ipv4;
            case 34525: goto parse_ipv6;
            case 34827: goto parse_pptp;
            case 25944: goto parse_ethernet;
            case 34887: goto parse_mpls;
            case 34888: goto parse_mpls;
            default: goto reject;
        }
    }
    parse_gre_v1: {
/* advance(32)*/
        fpp_packetOffsetInBits += 32;
/* advance((((uint32_t)gre.S) << 5))*/
        fpp_packetOffsetInBits += (((uint32_t)gre.S) << 5);
/* advance((((uint32_t)gre.A) << 5))*/
        fpp_packetOffsetInBits += (((uint32_t)gre.A) << 5);
        switch (gre.proto) {
            case 2048: goto parse_ipv4;
            case 34525: goto parse_ipv6;
            case 34827: goto parse_pptp;
            case 25944: goto parse_ethernet;
            case 34887: goto parse_mpls;
            case 34888: goto parse_mpls;
            default: goto reject;
        }
    }
    parse_gre_sre: {
/* extract(gre_sre)*/
        if (fpp_packetEnd < fpp_packetStart + BYTES(fpp_packetOffsetInBits + 32)) {
            fpp_errorCode = PacketTooShort;
            goto reject;
        }
        gre_sre.addr_family = ntohs((uint16_t)((load_half(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 16;

        gre_sre.offset = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 8;

        gre_sre.length = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 8;

        gre_sre.header_valid = 1;
/* advance(((uint32_t)gre_sre.length))*/
        fpp_packetOffsetInBits += ((uint32_t)gre_sre.length);
        switch (gre_sre.length) {
            case 0: goto parse_gre_v0_fin;
            default: goto parse_gre_sre;
        }
    }
    parse_l2tp: {
/* extract(l2tp)*/
        if (fpp_packetEnd < fpp_packetStart + BYTES(fpp_packetOffsetInBits + 16)) {
            fpp_errorCode = PacketTooShort;
            goto reject;
        }
        l2tp.type = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)) >> 7) & FPP_MASK(uint8_t, 1)));
        fpp_packetOffsetInBits += 1;

        l2tp.length = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)) >> 6) & FPP_MASK(uint8_t, 1)));
        fpp_packetOffsetInBits += 1;

        l2tp.res1 = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)) >> 4) & FPP_MASK(uint8_t, 2)));
        fpp_packetOffsetInBits += 2;

        l2tp.seq = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)) >> 3) & FPP_MASK(uint8_t, 1)));
        fpp_packetOffsetInBits += 1;

        l2tp.res2 = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)) >> 2) & FPP_MASK(uint8_t, 1)));
        fpp_packetOffsetInBits += 1;

        l2tp.offset = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)) >> 1) & FPP_MASK(uint8_t, 1)));
        fpp_packetOffsetInBits += 1;

        l2tp.priority = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits))) & FPP_MASK(uint8_t, 1)));
        fpp_packetOffsetInBits += 1;

        l2tp.res3 = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)) >> 4) & FPP_MASK(uint8_t, 4)));
        fpp_packetOffsetInBits += 4;

        l2tp.version = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits))) & FPP_MASK(uint8_t, 4)));
        fpp_packetOffsetInBits += 4;

        l2tp.header_valid = 1;
        switch (l2tp.version) {
            case 2: goto parse_l2tp_v2;
            default: goto reject;
        }
    }
    parse_l2tp_v2: {
/* advance((((uint32_t)l2tp.length) << 4))*/
        fpp_packetOffsetInBits += (((uint32_t)l2tp.length) << 4);
/* advance(32)*/
        fpp_packetOffsetInBits += 32;
/* advance((((uint32_t)l2tp.seq) << 5))*/
        fpp_packetOffsetInBits += (((uint32_t)l2tp.seq) << 5);
tmp_19 = /* lookahead()*/
        ntohl((uint32_t)((load_word(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
;tmp_20 = (((uint32_t)l2tp.offset) * tmp_19);tmp_21 = (tmp_20 << 3);tmp_22 = tmp_21;/* advance(tmp_22)*/
        fpp_packetOffsetInBits += tmp_22;
/* advance((((uint32_t)l2tp.offset) << 4))*/
        fpp_packetOffsetInBits += (((uint32_t)l2tp.offset) << 4);
        switch (l2tp.type) {
            case 0: goto parse_pptp;
            default: goto reject;
        }
    }
    parse_teredo: {
tmp_23 = /* lookahead()*/
        ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)) >> 4) & FPP_MASK(uint8_t, 4)));
;        switch (tmp_23) {
            case 6: goto parse_ipv6;
            case 0: goto parse_teredo_hdr;
            default: goto reject;
        }
    }
    parse_teredo_hdr: {
tmp_24 = /* lookahead()*/
        ntohs((uint16_t)((load_half(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
;        switch (tmp_24) {
            case 1: goto parse_teredo_auth_hdr;
            case 0: goto parse_teredo_origin_hdr;
            default: goto reject;
        }
    }
    parse_teredo_auth_hdr: {
/* extract(teredo_auth)*/
        if (fpp_packetEnd < fpp_packetStart + BYTES(fpp_packetOffsetInBits + 32)) {
            fpp_errorCode = PacketTooShort;
            goto reject;
        }
        teredo_auth.zero = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 8;

        teredo_auth.type = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 8;

        teredo_auth.id_len = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 8;

        teredo_auth.auth_len = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 8;

        teredo_auth.header_valid = 1;
/* advance((((((uint32_t)teredo_auth.id_len) << 3) + (((uint32_t)teredo_auth.auth_len) << 3)) + 72))*/
        fpp_packetOffsetInBits += (((((uint32_t)teredo_auth.id_len) << 3) + (((uint32_t)teredo_auth.auth_len) << 3)) + 72);
tmp_25 = /* lookahead()*/
        ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)) >> 4) & FPP_MASK(uint8_t, 4)));
;        switch (tmp_25) {
            case 6: goto parse_ipv6;
            case 0: goto parse_teredo_hdr;
            default: goto reject;
        }
    }
    parse_teredo_origin_hdr: {
/* extract(teredo_origin)*/
        if (fpp_packetEnd < fpp_packetStart + BYTES(fpp_packetOffsetInBits + 64)) {
            fpp_errorCode = PacketTooShort;
            goto reject;
        }
        teredo_origin.zero = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 8;

        teredo_origin.type = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 8;

        teredo_origin.port = ntohs((uint16_t)((load_half(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 16;

        teredo_origin.ip = ntohl((uint32_t)((load_word(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 32;

        teredo_origin.header_valid = 1;
tmp_26 = /* lookahead()*/
        ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)) >> 4) & FPP_MASK(uint8_t, 4)));
;        switch (tmp_26) {
            case 6: goto parse_ipv6;
            case 0: goto parse_teredo_hdr;
            default: goto reject;
        }
    }
    parse_tcp: {
/* extract(headers[0])*/
        if (fpp_packetEnd < fpp_packetStart + BYTES(fpp_packetOffsetInBits + 160)) {
            fpp_errorCode = PacketTooShort;
            goto reject;
        }
        struct tcp_h *headers = (struct tcp_h *) malloc(sizeof(struct tcp_h));
        if (headers == NULL) { fpp_errorCode = OutOfMemory; goto fpp_end; }
        hdr = (packet_hdr_t *) malloc(sizeof(packet_hdr_t));
        if (hdr == NULL) { free(headers); fpp_errorCode = OutOfMemory; goto fpp_end; }
        
        hdr->type = fpp_tcp_h;
        hdr->hdr = headers;
        hdr->next = NULL;

        if (*out == NULL) {
                *out = hdr;
                last_hdr = hdr;
        } else {
                last_hdr->next = hdr;
                last_hdr = hdr;
        }

        headers->header_offset = fpp_packetOffsetInBits / 8;

        headers[0].src_port = ntohs((uint16_t)((load_half(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 16;

        headers[0].dst_port = ntohs((uint16_t)((load_half(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 16;

        headers[0].seq_num = ntohl((uint32_t)((load_word(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 32;

        headers[0].ack_num = ntohl((uint32_t)((load_word(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 32;

        headers[0].data_offset = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)) >> 4) & FPP_MASK(uint8_t, 4)));
        fpp_packetOffsetInBits += 4;

        headers[0].res = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits))) & FPP_MASK(uint8_t, 4)));
        fpp_packetOffsetInBits += 4;

        headers[0].flags = ((uint8_t)((load_byte(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 8;

        headers[0].window = ntohs((uint16_t)((load_half(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 16;

        headers[0].checksum = ntohs((uint16_t)((load_half(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 16;

        headers[0].urgent_ptr = ntohs((uint16_t)((load_half(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 16;

        headers[0].header_valid = 1;
/* advance(((uint32_t)((((int32_t)((uint32_t)headers[0].data_offset)) + -5) << 5)))*/
        fpp_packetOffsetInBits += ((uint32_t)((((int32_t)((uint32_t)headers[0].data_offset)) + -5) << 5));
        goto parse_payload;
    }
    parse_udp: {
/* extract(headers[0])*/
        if (fpp_packetEnd < fpp_packetStart + BYTES(fpp_packetOffsetInBits + 64)) {
            fpp_errorCode = PacketTooShort;
            goto reject;
        }
        struct udp_h *headers = (struct udp_h *) malloc(sizeof(struct udp_h));
        if (headers == NULL) { fpp_errorCode = OutOfMemory; goto fpp_end; }
        hdr = (packet_hdr_t *) malloc(sizeof(packet_hdr_t));
        if (hdr == NULL) { free(headers); fpp_errorCode = OutOfMemory; goto fpp_end; }
        
        hdr->type = fpp_udp_h;
        hdr->hdr = headers;
        hdr->next = NULL;

        if (*out == NULL) {
                *out = hdr;
                last_hdr = hdr;
        } else {
                last_hdr->next = hdr;
                last_hdr = hdr;
        }

        headers->header_offset = fpp_packetOffsetInBits / 8;

        headers[0].src_port = ntohs((uint16_t)((load_half(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 16;

        headers[0].dst_port = ntohs((uint16_t)((load_half(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 16;

        headers[0].len = ntohs((uint16_t)((load_half(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 16;

        headers[0].checksum = ntohs((uint16_t)((load_half(fpp_packetStart, BYTES(fpp_packetOffsetInBits)))));
        fpp_packetOffsetInBits += 16;

        headers[0].header_valid = 1;
udp_src_port = headers[0].src_port;        switch (headers[0].dst_port) {
            case 1701: goto parse_l2tp;
            case 3544: goto parse_teredo;
            default: goto parse_udp_2;
        }
    }
    parse_udp_2: {
        switch (udp_src_port) {
            case 1701: goto parse_l2tp;
            case 3544: goto parse_teredo;
            default: goto parse_payload;
        }
    }
    parse_payload: {
/* extract(headers[0])*/
        if (fpp_packetEnd < fpp_packetStart + BYTES(fpp_packetOffsetInBits + 0)) {
            fpp_errorCode = PacketTooShort;
            goto reject;
        }
        struct payload_h *headers = (struct payload_h *) malloc(sizeof(struct payload_h));
        if (headers == NULL) { fpp_errorCode = OutOfMemory; goto fpp_end; }
        hdr = (packet_hdr_t *) malloc(sizeof(packet_hdr_t));
        if (hdr == NULL) { free(headers); fpp_errorCode = OutOfMemory; goto fpp_end; }
        
        hdr->type = fpp_payload_h;
        hdr->hdr = headers;
        hdr->next = NULL;

        if (*out == NULL) {
                *out = hdr;
                last_hdr = hdr;
        } else {
                last_hdr->next = hdr;
                last_hdr = hdr;
        }

        headers->header_offset = fpp_packetOffsetInBits / 8;

        headers[0].header_valid = 1;
        goto accept;
    }

    reject: { return fpp_errorCode; }

    accept:
    {
        return NoError;
    }
    fpp_end:
    return fpp_errorCode
;
}