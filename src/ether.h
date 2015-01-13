#ifndef ETHER_H
#define ETHER_H

#define EPT_IP   0x0800    /* type: IP */
#define EPT_ARP   0x0806    /* type: ARP */
#define EPT_RARP 0x8035    /* type: RARP */
#define ARP_HARDWARE 0x0001    /* Dummy type for 802.3 frames */
#define ARP_REQUEST 0x0001    /* ARP request */
#define ARP_REPLY 0x0002    /* ARP reply */

typedef struct ehhdr 
{
unsigned char eh_dst[6];   /* destination ethernet addrress */
unsigned char eh_src[6];   /* source ethernet addresss */
unsigned short eh_type;   /* ethernet pachet type */
}EHHDR, *PEHHDR;

#endif
