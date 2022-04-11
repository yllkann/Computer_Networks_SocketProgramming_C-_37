#include <iostream>
#include <WS2tcpip.h>
#include <string>
#include<stdlib.h>
#include<string.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

void main()
{

    string ipAddress = "127.0.0.1";            //Ip Address of the Server
    int port = 8080;                        //Listening port # on the server

    /*
    Steps for the client Server to Work:
    * Step 1: Intiliaze WinSock
    * Step 2: Create Socket
    * Step 3: Fill in a hint Structure
    * Step 4: Connect to server
    * Step 5: Do-While loop to send and receive the data
    * Step 6: Gracefully close down Everything
    */

    //Step 1: Initliaze the WinSock
    WSADATA data;
    WORD ver = MAKEWORD(2, 2);
    int WSResult = WSAStartup(ver, &data);
    if (WSResult != 0)
    {
        cerr << "can't start winsock, ERR #" << WSResult << endl;
        return;
    }

    //Step 2: Create Socket
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET)
    {
        cerr << "Can't create Socket, Err # " << WSAGetLastError << endl;
        WSACleanup();
        return;
    }

