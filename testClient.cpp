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
# include <libsocket/inetserverstream.hpp>
# include <libsocket/exception.hpp>

# include <libsocket/select.hpp>
# include <libsocket/socket.hpp>

# include <unistd.h>
# include <stdlib.h>

using std::string;
using namespace std;
using libsocket::inet_stream;
/*
 * This program connects to host:port (usually localhost),
 * closes the socket, reopens it with the same parameters
 * (to show what you may do with sockets... ;), receives
 * a message from the server and sends a message back.
 */

int main(int argc, char* argv[])
{
    using std::string;

    using libsocket::inet_stream;

    string host = "localhost";
    if(argc < 2) {
    	cout << "Usage ./TCPClientTest <port>" << endl;
    	return 0;
    }
    cout << argv[1] << endl;
    string port = argv[1];
    string answer;

    answer.resize(2000);
    std::cout << answer << std::endl;
	libsocket::inet_stream sock(host,port,LIBSOCKET_BOTH);
	for (;;) {
		string tst_str;
		std::getline(std::cin, tst_str);
		sock << tst_str;
	    answer.resize(2000);
	    std::cout << answer << std::endl;
	}

    return 0;
}



