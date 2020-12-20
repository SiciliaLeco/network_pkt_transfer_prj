#ifndef MAC_H_
#define MAC_H_
#include <stdio.h>
#include <string.h>
#define uchar unsigned char
#define uint unsigned int 
#define ifile "input1220.txt" // 宏定义输出帧的文件夹

uint crc32_table[256];
void make_crc32_table();
uint crc32(uchar *string, uint size);
uint assemble(uchar *frame, uchar *payload, int paylen);
void send(FILE *sendfile, uchar *frame, uint len);
int checkCRC(uchar *crcGet, uchar *crcCal);
int disassemble(FILE *sendfile, uchar *frame, uchar *paylaod);
void receive();
void process_and_send_frame(int len, uchar *buf);
#endif