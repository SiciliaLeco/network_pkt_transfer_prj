#include "transport.h"
#include "network.h"
#include "mac.h"
#include <stdio.h>
#include <string.h>

void receive_udp(uchar *datagram, uint len)
{
	uchar *data;
	data = datagram;
	printf("-----infomation received from ip layer-----\n");
	// for(int i =0; i < len -4; i++)
	// 	printf("%c", data[i]);
	FILE *ipfile = fopen(netfile, "r");
	fread(data, sizeof(char), len, ipfile);
	for (int i = 0; i < len - 4; i++)
		printf("%c", data[i]);
}
void send_udp(uint src_port, uint dst_port, uchar *payload, int len)
{
	printf("-----udp transport-----\n");
	thdr header; // udp协议头部信息定义
	char buf[len + 8];
	uchar hdr[4];
	hdr[0] = header.src_port = src_port;
	printf("src port:%d\n", hdr[0]);
	hdr[1] = header.dest_port = dst_port;
	printf("dst port:%d\n", hdr[1]);
	hdr[2] = header.checksum = 0;
	printf("udp checksum:%d\n", hdr[2]);
	hdr[3] = header.len = len + 8;
	printf("udp length:%d\n", hdr[3]);
	// checksum(uchar* buffer, uint size)
	memcpy(buf, hdr, 4);
	memcpy(buf + 4, payload, len);
	udp_send_to_ip(buf, len + 4);
	//// 和ip层连接起来
}

void udp_send_to_ip(char *packet, int len)
{
	/*
		packet: 应用层得到的数据信息，传给传输层
		len: 包的大小（字节长度）
	*/
	printf("------udp info send to ip layer-----\n");
	struct ipaddr src, dst; // 设定ip地址，这里调用了ip层的结构体
	src.seg1 = 192;
	src.seg2 = 168;
	src.seg3 = 0;
	src.seg4 = 1;
	dst.seg1 = 192;
	dst.seg2 = 168;
	dst.seg3 = 0;
	dst.seg4 = 2;
	uchar buf[2000];
	send_ip(&buf[0], src, dst, 17, packet, len); // 17 ~ udp
}
