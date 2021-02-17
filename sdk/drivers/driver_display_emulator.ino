

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

uint16_t get_uint16Color(byte red, byte green, byte blue){
  return ( (red*31/255) <<11)|( (green*31/255) <<6)|( (blue*31/255) <<0);
}

SOCKET sock;

void sendMessageToDisplay(String message){
  const int str_len = message.length() + 1; 
  char char_array[str_len];
  message.toCharArray(char_array, str_len);
  send(sock,char_array,sizeof(char_array),0);
}

void setup_displayDriver(){

  WSADATA wData;
	struct sockaddr_in addr,serv_addr;
	
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
	}
	std::cout<<"connect success\n";


  char message1[10];
  char message2[10];
  char message3[10];

  char buff[15];
  

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

void driver_display_loop(){
  if(driver_display_needToUpdateScreen){
    sendMessageToDisplay("U\n");
    driver_display_needToUpdateScreen = false;
  }
}

void setPixel(int x, int y){
  sendMessageToDisplay("P " + String(x) + " " + String(y) + "\n");
  driver_display_needToUpdateScreen = true;
  #if defined(SCREEN_ROTATION_90)
    
  #elif defined(SCREEN_ROTATION_180)
    
  #elif defined(SCREEN_ROTATION_270)
    
  #else
    
  #endif
}

void setDrawColor(byte red_new, byte green_new, byte blue_new){
  sendMessageToDisplay("C " + String(red_new) + " " + String(green_new) + " " + String(blue_new) + "\n");
}

void fillScreen(byte red, byte green, byte blue){
  //debug("Fill screen");
  setDrawColor(red, green, blue);
  sendMessageToDisplay("F\n");
  driver_display_needToUpdateScreen = true;
}

bool button[] = {false, false, false, false};
bool digRead(unsigned char b){
  return button[b];
}

void driver_display_updateControls(){
  char buff[15];
  sendMessageToDisplay("K\n");
	recv(sock,buff,sizeof(buff),0);
  //printf(buff);

  button[0] = (buff[0]=='1');
  button[1] = (buff[1]=='1');
  button[2] = (buff[2]=='1');
  button[3] = (buff[3]=='1');
  /*
  printf("%d-", (int)(buff[0]=='1'));
  printf("%d-", (int)(buff[1]=='1'));
  printf("%d-", (int)(buff[2]=='1'));
  printf("%d\n", (int)(buff[3]=='1'));
  */

}


#ifdef USE_PRIMITIVE_HARDWARE_DRAW_ACCELERATION
  void driver_display_drawFastVLine(int16_t x, int16_t y, int16_t w){
    sendMessageToDisplay("LV " + String(x) + " " + String(y) + " " + String(w) + "\n");
    driver_display_needToUpdateScreen = true;
    #if defined(SCREEN_ROTATION_90)
      
    #elif defined(SCREEN_ROTATION_180)
      
    #elif defined(SCREEN_ROTATION_270)
      
    #else
      
    #endif
    
  }

  void driver_display_drawFastHLine(int16_t x, int16_t y, int16_t h){
    sendMessageToDisplay("LH " + String(x) + " " + String(y) + " " + String(h) + "\n");
    driver_display_needToUpdateScreen = true;
    #if defined(SCREEN_ROTATION_90)
      
    #elif defined(SCREEN_ROTATION_180)
      
    #elif defined(SCREEN_ROTATION_270)
      
    #else
      
    #endif
  }

  void driver_display_fillRect(int16_t x, int16_t y, int16_t w, int16_t h){
    sendMessageToDisplay("R " + String(x) + " " + String(y) + " " + String(w) + " " + String(h) + "\n");
    driver_display_needToUpdateScreen = true;
    #if defined(SCREEN_ROTATION_90)
      
    #elif defined(SCREEN_ROTATION_180)
      
    #elif defined(SCREEN_ROTATION_270)
      
    #else
      
    #endif
  }
#endif