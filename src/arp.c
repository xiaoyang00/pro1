#include "arp.h"

int arp_build_request(unsigned char *buf, int buf_len, unsigned int srcip, unsigned char *srcmac, unsigned int dstip, unsigned char *dstmac)
{
    struct arp *arpnode = buf;


    if( buf_len < sizeof(struct arp) )
        return -1;

    //build ethernet packet header
    memcpy(arpnode->eh_hdr.eh_dst, dstmac, 6);
    memcpy(arpnode->eh_hdr.eh_src, srcmac, 6);
    arpnode->ehhdr.eh_type = htons(EPT_ARP);

    //build arp packet header
    arpnode->arp_hdr.arp_hrd = 0x0001;
    arpnode->arp_hdr.arp_pro = 0x0001;
    arpnode->arp_hdr.arp_hln = 6;
    arpnode->arp_hdr.arp_pln = 4;
    memcpy(arpnode->arp_hdr.arp_sha, srcmac, 6);
    arpnode->arp_hdr.arp_spa = srcip;
    memcpy(arpnode->arp_hdr.arp_dha, dstmac, 6);
    arpnode->arp_hdr.arp_dpa = dstip;
	
}

int arp_build_request(unsigned char *buf, int buf_len, unsigned int srcip, unsigned char *srcmac, unsigned int dstip, unsigned char *dstmac)
{

    struct arp *arpnode = buf;


    if( buf_len < sizeof(struct arp) )
        return -1;

    //build ethernet packet header
    memcpy(arpnode->eh_hdr.eh_dst, dstmac, 6);
    memcpy(arpnode->eh_hdr.eh_src, srcmac, 6);
    arpnode->ehhdr.eh_type = htons(EPT_ARP);

    //build arp packet header
    arpnode->arp_hdr.arp_hrd = htons(0x0001);
    arpnode->arp_hdr.arp_pro = htons(0x0001);
    arpnode->arp_hdr.arp_hln = htons(6);
    arpnode->arp_hdr.arp_pln = htons(4);
    memcpy(arpnode->arp_hdr.arp_sha, srcmac, 6);
    arpnode->arp_hdr.arp_spa = htonl(srcip);
    memcpy(arpnode->arp_hdr.arp_dha, dstmac, 6);
    arpnode->arp_hdr.arp_dpa = htonl(dstip);
}
