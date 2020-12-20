#include <stdio.h>
#include <string.h>
#define uchar unsigned char
void test(uchar *frame){
	uchar t[2];
	for(int i =0; i < 2; i++)
		t[i] = 4+i;
	memcpy(&frame[0], t, 2);
	int m = t[0];
	printf("%d\n", m);
}

void test2(uchar *frame) {
	uchar hdr[10];
	memcpy(&hdr[0], frame, 10);
	for(int i=0;i<10;i++)
		printf("%c\n", hdr[i]);
}
void test3(uchar *frame, uchar *payload) {
	for(int i = 0; i < 2; i++){
		payload[i] = frame[i];
	}
}
int main(){
	// uchar buf[2000];
	uchar buf[] = {65,66,67,68,69,70,71,72,73,74};
	// test(&buf[0]);
	// printf("%d %d", buf[0], buf[1]);
	// test2(buf);
	uchar *pay;
	test3(buf, &pay[0]);
	printf("%d %d", pay[0], pay[1]);
}