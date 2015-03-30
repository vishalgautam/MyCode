#include<stdio.h>
#include<stdlib>
#include<unistd>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
int main(){
	fd_set master_fd;
	fd_set read_Fd;
	int maxfd,listener,newfd;
	struct addrinfo *cl,*sr; 
	struct sockaddr_in servr,clientadd;
	char remoteip[INET6_ADDRSTRLEN];
	socklen_t addrlen;
	FD_ZERO(&master);
	FD_ZERO(read);
	if((listener==socket(PF_INET,SOCK_STREAM,0))==-1){
		perror("socket");
		exit(1);
	}
	if(setsockopt(listener,SOL_SOCKET,\
	   SO_REUSEADDR,&yes,sizeof (int))==-1){
		perror("socketopt");
		exit(1);
	}
	servr.sin_family=AF_INET;
	servr.sin_addr.s_addr=INAADR_ANY;
	servr.sin_port=htons(port);
	memset(servr.sin_zero,'\0',sizeof(servr.sin_zero));
	if(bind(listener,(struct sockaddr*)&sevr,sizeof(servr))==-1){
		perror("bind");
		exit(1);
	}
	if(listen(listener,10)==-1){
		perror("listener");
		exit(1);
	}
	FD_SET(listener,master_fd);
	maxfd=listener;
	while(1){
		read_fd=master_fd;
		if(select(max+1,read_fd,NULL,NULL,NULL)==-1){
			perror("select");
			exit(1);
		}
		for(int i=0;i<maxfd+1;i++){
			if(IS_SET(i,&read_fd)){
				if(i==listener){
					addrlen=sizeof(clientadd);
					if(newfd=accept(listener,(struct sockaddr*)&clientadd,&addlen)==-1){
						perro("accept");
					}
					else {
						FD_SET(newfd,master);
						if(newfd>maxfd) 
						maxfd=newfd;
					}
				}
				else {
					if(numbytes=recv(i,buff,max-1)<0){
						if(numbytes==0){
							printf("connection closed by %d",i);
							else perror("recv");
						}
						close(i);
						FD_CLR(i,&master_fd);
					}
					else{
						printf("client[%d]:%s\n ",i,buff);
					}
				}
			}
		}
	}
}
