#include <stdio.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>


#include <platform/platform.h>
#include <kos_net.h>


int main() {
  int sock, listener;
  struct sockaddr_in addr;
  char buf[1024];
  int bytes_read;

   printf("Start KOS server\n");
   perror(DEFAULT_INTERFACE "app point 0 \n");


#if PLATFORM_OS(KOS)
#define server_addr "10.0.2.2"
    /* Add network interface. */
    if (!configure_net_iface(DEFAULT_INTERFACE, "10.0.2.10", DEFAULT_MASK, DEFAULT_GATEWAY, DEFAULT_MTU)) {

        perror(DEFAULT_INTERFACE ": network iface configuration failed\n");
        return EXIT_FAILURE;
    }

    if (!list_network_ifaces()) {
        perror("listing of host network interfaces failes\n");
        return EXIT_FAILURE;
    }

#else
#define server_addr "localhost"
#endif

  listener = socket(AF_INET, SOCK_STREAM, 0);

  if(listener < 0) { perror("socket"); return 1;}
    addr.sin_family = AF_INET;
    addr.sin_port = htons(3425);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
      perror("bind"); return 1;
    }
    listen(listener, 1);
    while(1) {
      sock = accept(listener, NULL, NULL);
      if(sock < 0) {
        perror("accept"); return 1;
      }
      while(1) {
        bytes_read = recv(sock, buf, 1024, 0);
        if(bytes_read <= 0)
          break;
        printf("Receive message: %s\n", buf);
      }
      close(sock);
   }
   close(listener);
}

