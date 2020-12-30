#ifndef NETWORK_H_
#define NETWORK_H_
#define uchar unsigned char
#define uint unsigned int
#define mtu 1500
#define netfile "test00.txt"
#define netfragfile "testn00.txt"

typedef struct ipaddr
{ // ip 地址
	uchar seg1;
	uchar seg2;
	uchar seg3;
	uchar seg4;
} ipaddr;

typedef struct iphdr
{
	uchar version;
	uchar ihl;
	uchar tos; // type of service
	uchar tot_len;
	uchar id;
	uchar frag_offset;
	uchar ttl;
	uchar protocol;
	uchar checksum;
	struct ipaddr saddr;
	struct ipaddr daddr;
	uchar more_frag;
} iphdr;

void send_mac(int len, char *buf);
// void send_transport_udp(uchar *payload, int len);

void send_ip(uchar *buf, ipaddr srcip, ipaddr dstip, uchar prtcl, uchar *payload, int len);
void receive_ip(uchar *packet, uint len); //unpack
int checksum();
int verify_ip_checksum();
int verify_ip_addr(ipaddr srcip);
void send_transport_udp(uchar *payload, int len);
#endif