#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

void error(const char *msg)
{
	perror(msg);
	exit(0);
}

int main(int argc, char *argv[])
{
    
    int server_port, socket_fd, n;
    struct hostent *server_host;
    struct sockaddr_in server_address;
    char buff[333];

    /* Get server hostname port */
    if (argc < 3) 
    {
        printf(stderr "user %s hostname port", argv[0]);
        exit(0);
        
    }

    /* Get server port from command line arguments or stdin. */
    server_port = atoi(argv[2]);
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0)
    error("socket failed");
    
    /* Get server host from server name. */
    server_host = gethostbyname(argv[1]);
    if (server_host == NULL)
    {
        printf(stderr, "Error, no host");
        exit(0);
    }

    /* Initialise IPv4 server address with server host. */
    bzero((char *) &server_address, sizeof (server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *)server_host->h_addr,
          (char *) &server_address.sin_addr.s_addr,
          server_host->h_length); 
          
    server_address.sin_port = htons(server_port);

    /* Connect to socket with server address. */
    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof server_address)<0) 
		perror("connect error");
		printf("Client: ");
        while(1);
	{

    bzero(buff,333);
        fgets(buff,333,stdin);
        n = write(socket_fd,buff,strlen(buff));
        if (n < 0) 
             error("socket write error");
        bzero(buff,333);
        n = read(socket_fd,buff,333);
        if (n < 0) 
             error("socket read error");
        printf("Server : %s\n",buff);
        int i = strncmp("Assalammualaikum..." , buff , 3);
        if(i == 0)
               break;
	}
    
    close(socket_fd);
    return 0;
}
