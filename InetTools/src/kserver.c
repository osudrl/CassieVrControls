#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>

void error(char *msg)
{
	fprintf(stderr, "%s: %s\n",msg,strerror(errno));
	exit(1);
}

int open_listener_socket()
{
	int s = socket(PF_INET, SOCK_STREAM, 0);
	if (s == -1)
	{
		error("Can't open socket");
	}
	return s;
}

void bind_to_port(int socket, int port)
{
	struct sockaddr_in name;
	name.sin_family = PF_INET;
	name.sin_port = (in_port_t)htons(port);
	name.sin_addr.s_addr = htonl(INADDR_ANY);
	int reuse = 1;
	if(setsockopt(socket,SOL_SOCKET,SO_REUSEADDR,(char *)&reuse,sizeof(int)) == -1)
	{
		error("Can't set the reuse option of the socket.");
	}
	int c = bind (socket,(struct sockaddr *) &name, sizeof(name));
	if(c == -1)
		error("Can't bind to socket");
}

int say(int socket, char* s)
{
	int result = send(socket,s,strlen(s),0);
	if(result== -1)
		fprintf(stderr, "%s: %s\n", "Error talking to the client", strerror(errno));
	return result;
}

int read_in(int socket, char* buf, int len)
{
	char *s = buf;
	int slen = len;
	int c = recv(socket,s,slen,0);
	while((c>0) && (s[c-1] != '\n'))
	{
		s += c; slen -= c;
		c = recv(socket,s,slen,0);
	}
	if(c<0)
		return c;
	else if(c==0)
		buf[0] = '\0';
	else
		s[c-1]='\0';
	return len-slen;
}

int listener_d;

void handle_shutdown(int sig)
{
	if(listener_d)
		close(listener_d);

	fprintf(stderr, "Bye!\n");
	exit(0);
}

int main(int argc, char *argv[])
{

	//if (catch_signal(SIGINT, handle_shutdown) == -1)
	//	error("Can’t set the interrupt handler");

	listener_d = open_listener_socket();

	bind_to_port(listener_d, 30000);


	if (listen(listener_d, 10) == -1)
		error("Can’t listen");

	struct sockaddr_storage client_addr;

	unsigned int address_size = sizeof(client_addr);

	puts("Waiting for connection");

	char buf[255];


	while (1) 
	{
		int connect_d = accept(listener_d, (struct sockaddr *)&client_addr, &address_size);
		if (connect_d == -1)
			error("Can’t open secondary socket");

		if (say(connect_d, "Internet Knock-Knock Protocol Server\r\nVersion 1.0\r\nKnock! Knock!\r\n> ") != -1) 
		{
			read_in(connect_d, buf, sizeof(buf));
			//buf = "wt";
			say (connect_d, buf);
			if (strncasecmp("wt", buf, 12))
			{
				say(connect_d, "You should say ‘Who’s there?’");
				
			}	
			else 
			{
				if (say(connect_d, "Oscar\r\n> ") != -1) 
				{
					read_in(connect_d, buf, sizeof(buf));

					if (strncasecmp("Oscar who?", buf, 10))
						say(connect_d, "You should say ‘Oscar who?’!\r\n");
					else
						say(connect_d, "Oscar silly question, you get a silly answer\r\n");
				}
			}
		}
		close(connect_d);
	}
	return 0;
}
