#include "packet.h"


#include <openssl/rsa.h>
#include <openssl/rand.h>



void proc_0xFE(share* shared, craftIk_epoll* clnt_epoll, int clnt_num){
	char message[]={0xff,0x00,0x23,0x00,0x41,0x00,0x20,0x00,0x4d,0x00,0x69,0x00,0x6e,0x00,0x65,0x00,0x63,0x00,0x72,0x00,0x61,0x00,0x66,0x00,0x74,0x00,0x20,0x00,0x53,0x00,0x65,0x00,0x72,0x00,0x76,0x00,0x65,0x00,0x72,0x00,0x20,0x00,0x66,0x00,0x6f,0x00,0x72,0x00,0x20,0x00,0x63,0x00,0x72,0x00,0x61,0x00,0x66,0x00,0x74,0x00,0x49,0x00,0x6b,0x00,0xa7,0x00,0x30,0x00,0xa7,0x00,0x32,0x00,0x30};//이부분 더미임 설정파일에서 읽어와야됨.
	send(clnt_epoll->events[clnt_num].data.fd, message, sizeof(message), 0);

}

void proc_0x0A(share* shared, craftIk_epoll* clnt_epoll, int clnt_num){
	char message[1];
	recv(clnt_epoll->events[clnt_num].data.fd, message, (size_t)sizeof(message), 0);
	players* thisPlayer= getThisPlayer();
	memcpy(&(thisPlayer->on_ground), message, sizeof(thisPlayer->on_ground));
	if(alive_tick_cool()== true){//TODO: alive_tick_cool
		proc_0x00(shared, clnt_epoll, clnt_num);
	}
}

void proc_0x0B(share* shared, craftIk_epoll* clnt_epoll, int clnt_num){

	char message[33];
	recv(clnt_epoll->events[clnt_num].data.fd, message, (size_t)sizeof(message), 0);
	players* thisPlayer= getThisPlayer();//TODO: make get this player
	memcpy(&(thisPlayer->abs_x_pos), message, sizeof(thisPlayer->abs_x_pos));
	memcpy(&(thisPlayer->abs_y_pos), message+ 8, sizeof(thisPlayer->abs_y_pos));
	memcpy(&(thisPlayer->stance), message+ 16, sizeof(thisPlayer->stance));
	memcpy(&(thisPlayer->abs_z_pos), message+ 24, sizeof(thisPlayer->abs_z_pos));
	memcpy(&(thisPlayer->on_ground), message+ 32, sizeof(thisPlayer->on_ground));

}

void proc_0x00(share* shared, craftIk_epoll* clnt_epoll, int clnt_num){//TODO
}
