#ifndef ARP_H
#define ARP_H

/* ARP protocol opcodes. */
#define ARPOP_REQUEST   1               /* ARP request.  */
#define ARPOP_REPLY     2               /* ARP reply.  */
#define ARPOP_RREQUEST  3               /* RARP request.  */
#define ARPOP_RREPLY    4               /* RARP reply.  */
#define ARPOP_InREQUEST 8               /* InARP request.  */
#define ARPOP_InREPLY   9               /* InARP reply.  */
#define ARPOP_NAK       10              /* (ATM)ARP NAK.  */



typedef struct arphdr
{
    unsigned short arp_hrd;    /* format of hardware address */
    unsigned short arp_pro;    /* format of protocol address */
    unsigned char arp_hln;    /* length of hardware address */
    unsigned char arp_pln;    /* length of protocol address */
    unsigned short arp_op;     /* ARP/RARP operation */

    unsigned char arp_sha[6];    /* sender hardware address */
    unsigned int arp_spa;    /* sender protocol address */
    unsigned char arp_tha[6];    /* target hardware address */
    unsigned int arp_tpa;    /* target protocol address */
};

struct arp
{
    struct ethhdr eth_hdr;
    struct arphdr arp_hdr;
};
#endif

