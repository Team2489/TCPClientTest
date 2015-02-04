/*
 * testClient.cpp

 *
 *  Created on: Jan 30, 2015
 *      Author: vigneshv
 */
# include <iostream>
# include <string>
# include <unistd.h>
# include <stdio.h>
# include <utility>
# include <unistd.h>
# include <stdlib.h>
# include "Client.h"

using std::string;
using namespace std;
/*
 * This program connects to host:port (usually localhost),
 * closes the socket, reopens it with the same parameters
 * (to show what you may do with sockets... ;), receives
 * a message from the server and sends a message back.
 */
TCPClient *client;
int main(int argc, char* argv[])
{
	client = new TCPClient("127.0.0.1");
    directions replyTemp;

	for (;;) {
		if (client->IsConnected()) {
			int ret = client->Send(TCPClient::PULL);
			std::cout << "Send returned " << ret <<std::endl;

			ret = client->Receive(&replyTemp);

			std::cout << "Receive returned " << ret <<std::endl;
			if(ret < 0) {
				std::cout << "Receive error " << ret <<std::endl;
			}

		} else {
			client->Connect();
			replyTemp.status = -1;
		}
		sleep(1);
	}

    return 0;
}



