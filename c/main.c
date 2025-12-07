#include <stdio.h>
#include <WinSock2.h>
//#pragma comment(lib,"ws2_32.lib")

int main()
{


	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	
	SOCKET client_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == client_socket)
	{
		printf("create socket failed\n");
		return -1;
	}
	
	struct sockaddr_in target;
	target.sin_family = AF_INET;
	target.sin_port = htons(6355);
	target.sin_addr.s_addr = inet_addr("192.168.88.87");

	if (-1 == connect(client_socket, (struct sockaddr*)&target, sizeof(target)))
	{
		printf("connect server failed\n");
		closesocket(client_socket);
		return -1;
	}

	while (1)
	{
		char sbuffer[1024] = { 0 };
		printf("please input your message:");
		scanf("%s", sbuffer);
		send(client_socket, sbuffer, strlen(sbuffer), 0);

		char rbuffer[1024] = { 0 };
		int ret = recv(client_socket, rbuffer, 1024, 0);
		if (ret <= 0)
		{
			break;
		}
		printf("%s\n", rbuffer);
	} 

	closesocket(client_socket);


	return 0;

}