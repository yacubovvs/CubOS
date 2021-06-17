

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

uint16_t current_drawColor;
unsigned char driver_display_screenBrightness = 0;

uint16_t getDrawColor(){
  return current_drawColor;
}

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

#ifdef TOUCH_SCREEN_ENABLE
  bool TOUCH_SCREEN_isTouching = false;
  int TOUCH_SCREEN_X = 0;
  int TOUCH_SCREEN_Y = 0;

  bool getTOUCH_SCREEN_isTouching(){
    return TOUCH_SCREEN_isTouching;
  }

  int getTOUCH_SCREEN_X(){
    return TOUCH_SCREEN_X;
  }

  int getTOUCH_SCREEN_Y(){
    return TOUCH_SCREEN_Y;
  }
#endif

bool driver_display_needToUpdateScreen = false;

#if defined(_WIN32) || defined(_WIN64) 
#else
  typedef int SOCKET;
#endif

SOCKET sock;

void sendMessageToDisplay(String message){
  const int str_len = message.length() + 1; 
  char char_array[str_len];
  message.toCharArray(char_array, str_len);
  send(sock,char_array,sizeof(char_array),0);
}

void driver_display_setup(){


  #if defined(_WIN32) || defined(_WIN64)
    WSADATA wData;
  #endif
  
	struct sockaddr_in addr,serv_addr;
	#if defined(_WIN32) || defined(_WIN64) 
    if(WSAStartup(MAKEWORD(1,1),&wData)!=0)
    {
      std::cout<<"socket not initialized\n";
    }
  #else
    int sockfd = 0, n = 0;
    char recvBuff[1024];
    memset(recvBuff, '0',sizeof(recvBuff));
  #endif
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

	
  
  #if defined(_WIN32) || defined(_WIN64)
  char HostName[1024];
    DWORD HostIP = 0;
    LPHOSTENT lphost;	  
    gethostname(HostName, 1024);
	  lphost=gethostbyname(HostName);
    serv_addr.sin_family=AF_INET;
	  memcpy((char*)&serv_addr.sin_addr,lphost->h_addr,lphost->h_length);
    serv_addr.sin_port=htons(9100);
  #else
    memset(&serv_addr, '0', sizeof(serv_addr));
    
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(9100);

    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0){
        printf("\n inet_pton error occured\n");
    }

/*
    if( connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
       printf("\n Error : Connect Failed \n");
    }*/

  #endif	

	int error;
	//if(connect(sock,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
  if(connect(sock,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
	{
		std::cout<<"connect error\n";
    #if defined(_WIN32) || defined(_WIN64) 
      error=WSAGetLastError();
      std::cout<<error<<"\n";
    #endif
		//_getch();
	}else{
    std::cout<<"connect success\n";
  }
	
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

void driver_display_setDrawColor(uint16_t color){
  current_drawColor = color;

  unsigned char r = (color & 0xF800) >> 11; //  5bit
  unsigned char g = (color & 0x07E0) >> 5;  //  6bit
  unsigned char b = color & 0x001F;         //  5bit

  r = (r * 255) / 31;
  g = (g * 255) / 63;
  b = (b * 255) / 31;
  sendMessageToDisplay("C " + String(r) + " " + String(g) + " " + String(b) + "\n");
}

void driver_display_setDrawColor(unsigned char red_new, unsigned char green_new, unsigned char blue_new){
  current_drawColor = get_uint16Color(red_new, green_new, blue_new);
  sendMessageToDisplay("C " + String(red_new) + " " + String(green_new) + " " + String(blue_new) + "\n");
}

void driver_display_loop(){
  if(driver_display_needToUpdateScreen){
    sendMessageToDisplay("U\n");
    driver_display_needToUpdateScreen = false;
  }
}

void display_driver_setPixel(int x, int y){
  sendMessageToDisplay("P " + String(x) + " " + String(y) + "\n");
  driver_display_needToUpdateScreen = true;
  #if defined(SCREEN_ROTATION_90)
    
  #elif defined(SCREEN_ROTATION_180)
    
  #elif defined(SCREEN_ROTATION_270)
    
  #else
    
  #endif
}

void display_driver_setPixel(int x, int y, uint16_t newColor){
  driver_display_setDrawColor(newColor);
  display_driver_setPixel(x, y);
}

void deriver_displayfillScreen(unsigned char red, unsigned char green, unsigned char blue){
  //debug("Fill screen");
  setDrawColor(red, green, blue);
  sendMessageToDisplay("F\n");
  driver_display_needToUpdateScreen = true;
}

bool button[] = {false, false, false, false};
bool digRead(unsigned char b){
  return button[b];
}

#ifdef TOUCH_SCREEN_ENABLE

  void driver_display_updateTouchScreen(){
    char buff[15];  
    sendMessageToDisplay("T\n");
    recv(sock,buff,sizeof(buff),0);

    TOUCH_SCREEN_isTouching = (buff[0]=='1');

    //char x[1];
    //char y[1];

    std::string x = "     ";
    std::string y = "     ";
    
    x[0] = buff[1];
    x[1] = buff[2];
    x[2] = buff[3];
    x[3] = buff[4];
    x[4] = buff[5];

    y[0] = buff[6];
    y[1] = buff[7];
    y[2] = buff[8];
    y[3] = buff[9];
    y[4] = buff[10];

    TOUCH_SCREEN_X = stoi(x);
    TOUCH_SCREEN_Y = stoi(y);
  }
#endif

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

void driver_display_setBrightness(unsigned char brightness){
  // brightness: 0..100%
  brightness =  (unsigned char)((int)brightness*255/100);
  //M5.Lcd.setBrightness(brightness);
}