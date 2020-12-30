#ifndef TRANSPORT_H_
#define TRANSPORT_H_
#define uchar unsigned char
#define uint unsigned int

typedef struct thdr
{ // transport layer header
	uchar src_port;
	uchar dest_port;
	uchar checksum;
	uchar len;
} thdr;

void receive_udp(uchar *datagram, uint len);

void send_udp(uint src_port, uint dst_port, uchar *payload, int len);
void udp_send_to_ip(char *packet, int len);
#endif