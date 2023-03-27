#include <stdio.h>

#include <windows.h>
#pragma comment(lib, "ws2_32.lib")

SOCKADDR_IN cAddr = { 0 };
int len = sizeof cAddr;
SOCKET clientSocket[1024];
int count = 0;


void tongxin(int idx){
	char buff[1024];
	int r;
	while (1){
		r = recv(clientSocket[idx], buff, 1023, NULL);
		if (r > 0){
			buff[r] = 0;
			printf("%d:%s\n", idx, buff);
			//�㲥����
			for (int i = 0; i < count; i++){
				send(clientSocket[i], buff, strlen(buff), NULL);
			}
		}
	}
}

int main(){
	//1 ����Э��汾
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2,2), &wsaData);
	if (LOBYTE(wsaData.wVersion) != 2 ||
		HIBYTE(wsaData.wVersion) != 2){
		printf("����Э��汾ʧ��!\n");
		return -1;
	}
	printf("����Э��ɹ�!\n");
	//2 ����socket
	SOCKET serverSocket =  socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (SOCKET_ERROR == serverSocket){
		printf("����socketʧ��!\n");
		WSACleanup();
		return -2;
	}
	printf("����socket�ɹ�!\n");

	//3 ����Э���ַ��
	SOCKADDR_IN addr = { 0 };
	addr.sin_family = AF_INET;//Э��汾
	addr.sin_addr.S_un.S_addr = inet_addr("192.168.0.100");//���Լ���ip
	addr.sin_port = htons(10086);//0 - 65535     10000����
	//os�ں� ����������  ��ռ�õ�һЩ�˿�   80  23  

	//4 ��
	int r = bind(serverSocket, (sockaddr*)&addr, sizeof addr);
	if (-1 == r){
		printf("bindʧ��!\n");
		closesocket(serverSocket);
		WSACleanup();
		return -2;
	}
	printf("bind�ɹ�!\n");

	//5 ����
	r = listen(serverSocket, 10);
	if (-1 == r){
		printf("listenʧ��!\n");
		closesocket(serverSocket);
		WSACleanup();
		return -2;
	}
	printf("listen�ɹ�!\n");


	//6 �ȴ��ͻ�������    ����    β������
	//�ͻ���Э���ַ��
	while (1){
		clientSocket[count] = accept(serverSocket, (sockaddr*)&cAddr, &len);
		if (SOCKET_ERROR == clientSocket[count]){
			printf("������崻���!\n");
			//8 �ر�socket
			closesocket(serverSocket);
			//9 ���Э����Ϣ
			WSACleanup();
			return -2;
		}
		printf("�пͻ������ӵ��������ˣ�%s!\n", inet_ntoa(cAddr.sin_addr));
		
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)tongxin,
			(char*)count, NULL, NULL);
		
		count++;
	}
	return 0;
}