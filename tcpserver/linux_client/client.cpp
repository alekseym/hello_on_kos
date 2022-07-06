#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include<arpa/inet.h>	//inet_addr

int main() {
  char message[] = "Hello World!\n";
  char buf[sizeof(message)];
  int sock;
  struct sockaddr_in addr;
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if(sock < 0) {
    perror("socket"); return 1;
  }
  addr.sin_family = AF_INET;
  addr.sin_port = htons(3425);;//(10022);//htons(3425);
//  addr.sin_addr.s_addr = inet_addr("192.168.1.10");  //htonl(INADDR_LOOPBACK);

  addr.sin_addr.s_addr = inet_addr("10.0.2.10");  //htonl(INADDR_LOOPBACK);

  if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("connect"); return 1;
  }
  printf ("Hello\n");

  send(sock, message, sizeof(message), 0);
  close(sock);
  return 0;
}
