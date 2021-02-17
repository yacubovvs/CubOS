

/*
#ifdef _WIN32
  // See http://stackoverflow.com/questions/12765743/getaddrinfo-on-win32 
  #ifndef _WIN32_WINNT
    #define _WIN32_WINNT 0x0501
  #endif
  #include <winsock2.h>
  #include <Ws2tcpip.h>
#else
  #include <sys/socket.h>
  #include <arpa/inet.h>
  #include <netdb.h>
  #include <unistd.h>
#endif
*/

#include <iostream>

#if defined(_WIN32) || defined(_WIN64)
    //#pragma comment(lib, "ws2_32")//включаем библиотеку для сокетов
    //#include <winsock2.h>
    #include <sys/types.h>
#include <winsock2.h>
#include <memory.h>
#include <conio.h>
    //#include <Ws2tcpip.h>
#else
    #include <sys/socket.h>
    #include <arpa/inet.h>
#endif

#define MSG_SIZE 1024
#define REPLY_SIZE 65536

bool driver_display_needToUpdateScreen = false;

void driver_display_loop(){
  if(driver_display_needToUpdateScreen){
    printf("U\n");
    driver_display_needToUpdateScreen = false;
  }
}

uint16_t get_uint16Color(byte red, byte green, byte blue){
  return ( (red*31/255) <<11)|( (green*31/255) <<6)|( (blue*31/255) <<0);
}

void setup_displayDriver(){

  WSADATA wData;
	struct sockaddr_in addr,serv_addr;
	SOCKET sock;
	if(WSAStartup(MAKEWORD(1,1),&wData)!=0)
	{
		std::cout<<"socket not initialized\n";
	}
	std::cout<<"socket initialized\n";

	sock=socket(AF_INET,SOCK_STREAM,0);
	if(sock==-1)
	{
		std::cout<<"socket not created\n";
	}
	
	addr.sin_family=AF_INET;
	addr.sin_port=htons(9100);
	addr.sin_addr.s_addr=htonl(INADDR_LOOPBACK);
	bind(sock,(struct sockaddr *)&addr,sizeof(addr));

	char HostName[1024];
	DWORD HostIP = 0;
	LPHOSTENT lphost;	
	gethostname(HostName, 1024);
	lphost=gethostbyname(HostName);
	serv_addr.sin_family=AF_INET;
	memcpy((char*)&serv_addr.sin_addr,lphost->h_addr,lphost->h_length);
	serv_addr.sin_port=htons(9100);

	int error;
	if(connect(sock,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
	{
		std::cout<<"connect error\n";
		error=WSAGetLastError();
		std::cout<<error<<"\n";
		//_getch();
		return;
	}
	std::cout<<"connect success\n";


  char message1[10];
  char message2[10];
  char message3[10];

  char buff[15];

  std::cout<<"insert value\n";
  std::cin>>message1;
  std::cin>>message2;
  std::cin>>message3;

	send(sock,message1,sizeof(message1),0);
	send(sock,message2,sizeof(message2),0);
	send(sock,message3,sizeof(message3),0);

	recv(sock,buff,sizeof(buff),0);	//3 param -sizeof accepted data
	std::cout<<"answer "<<buff<<"\n";
	recv(sock,buff,sizeof(buff),0);
	std::cout<<"answer "<<buff<<"\n";
	//getch();

	shutdown(sock,2);
	closesocket(sock);
	WSACleanup();
	return;
}
 


void sleep_displayDriver(){
  //debug("Display sleep");
}

void wakeup_displayDriver(){
  //debug("Display wakeup");
}

void powerOff_displayDriver(){
  //debug("Display poweroff");
}

void powerOn_displayDriver(){
  //debug("Display poweron");
}


void fillScreen(byte red, byte green, byte blue){
  //debug("Fill screen");
  printf("F\n");
  driver_display_needToUpdateScreen = true;
}

void setPixel(int x, int y){
  delay(5);
  printf("P %d %d\n", x, y);
  driver_display_needToUpdateScreen = true;
  #if defined(SCREEN_ROTATION_90)
    
  #elif defined(SCREEN_ROTATION_180)
    
  #elif defined(SCREEN_ROTATION_270)
    
  #else
    
  #endif
}

void setDrawColor(byte red_new, byte green_new, byte blue_new){
  printf("C %d %d %d\n", red_new, green_new, blue_new);
}

#ifdef USE_PRIMITIVE_HARDWARE_DRAW_ACCELERATION
  void driver_display_drawFastVLine(int16_t x, int16_t y, int16_t w){
    printf("LV %d %d %d\n", x, y, w);
    driver_display_needToUpdateScreen = true;
    #if defined(SCREEN_ROTATION_90)
      
    #elif defined(SCREEN_ROTATION_180)
      
    #elif defined(SCREEN_ROTATION_270)
      
    #else
      
    #endif
    
  }

  void driver_display_drawFastHLine(int16_t x, int16_t y, int16_t h){
    printf("LH %d %d %d\n", x, y, h);
    driver_display_needToUpdateScreen = true;
    #if defined(SCREEN_ROTATION_90)
      
    #elif defined(SCREEN_ROTATION_180)
      
    #elif defined(SCREEN_ROTATION_270)
      
    #else
      
    #endif
  }

  void driver_display_fillRect(int16_t x, int16_t y, int16_t w, int16_t h){
    printf("R %d %d %d %d\n", x, y, w, h);
    driver_display_needToUpdateScreen = true;
    #if defined(SCREEN_ROTATION_90)
      
    #elif defined(SCREEN_ROTATION_180)
      
    #elif defined(SCREEN_ROTATION_270)
      
    #else
      
    #endif
  }
#endif