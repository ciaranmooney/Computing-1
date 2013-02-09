/*
*  simpleServer.c
*  1917 lab 5
*
*  Created by Richard Buckland on 28/01/11.
*  Copyright 2011 Licensed under Creative Commons SA-BY-NC 3.0.
*
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#ifdef _WIN32
	#include <winsock2.h>
	#include <ws2tcpip.h>
	#define close closesocket
#else
	#include <netinet/in.h>
	#include <unistd.h>
#endif

int waitForConnection (int serverSocket);
int makeServerSocket (int portno);
void serveHTML (int socket);

#define SIMPLE_SERVER_VERSION 1.0
#define REQUEST_BUFFER_SIZE 1000
#define DEFAULT_PORT 7191
#define NUMBER_OF_PAGES_TO_SERVE 10
// after serving this many pages the server will halt

int main (int argc, char* argv[]) {

#ifdef _WIN32
WSADATA wsaData;
WSAStartup((2 << 8) + 2, &wsaData);
#endif

puts("************************************");
printf("Starting simple server %f\n", SIMPLE_SERVER_VERSION);
puts("Serving poetry since 2011");

int serverSocket = makeServerSocket(DEFAULT_PORT);
printf("Access this server at http://localhost:%d/\n", DEFAULT_PORT);
puts("************************************");

char request[REQUEST_BUFFER_SIZE];
int numberServed = 0;
while ( numberServed < NUMBER_OF_PAGES_TO_SERVE) {
	printf("*** So far served %d pages ***\n", numberServed);

	int connectionSocket = waitForConnection(serverSocket);
	// wait for a request to be sent from a web browser, open a new
	// connection for this conversation

	// read the first line of the request sent by the browser
	int bytesRead = recv (connectionSocket, request, sizeof(request) - 1, 0);
	assert (bytesRead >= 0);
	// were we able to read any data from the connection?

	// print entire request to the console
	printf (" *** Received http request ***\n %s\n", request);

	//send the browser a simple html page using http
	puts (" *** Sending http response ***");
	serveHTML (connectionSocket);

	// close the connection after sending the page- keep aust beautiful
	close (connectionSocket);
	++numberServed;
}

// close the server connection after we are done- keep aust beautiful
puts("** shutting down the server **");
close (serverSocket);

#ifdef _WIN32
WSACleanup();
#endif

return EXIT_SUCCESS;
}

void serveHTML(int socket) {

const char* message =
	"HTTP/1.1 200 OK\r\n"
	"Content-Type: application/xhtml+xml\r\n"
	"\r\n"
	"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
	"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 2.0//EN\" \"http://www.w3.org/MarkUp/DTD/xhtml2.dtd\">"
	"<html xmlns=\"http://www.w3.org/1999/xhtml\">"
	"<head><title>I wandered lonely as a cloud</title></head>"
	"<body>"
	"Oh, how do you do young Willie McBride?<br />"
	"Do you mind if I sit here down by your graveside?<br />"
	"And rest for awhile neath the warm summer sun<br />"
	"I've been walking all day, and I'm nearly done<br />"
	"<br />"
	"And I see by your gravestone, you were only nineteen<br />"
	"When you joined the great fallen in nineteen sixteen<br />"
	"Well I hope you died quick and I hope you died clean<br />"
	"Or Willy Mcbride, was it slow and obscene?<br />"
	"<br />"
	"Did they beat the drums slowly?<br />"
	"Did they play the pipes lowly?<br />"
	"Did they sound the death march as they lowered you down?<br />"
	"And did the band play 'The Last Post' in chorus?<br />"
	"Did the pipes play 'The Flowers Of The Forest'?<br />"
	"<br />"
	"And did you leave a wife or a sweetheart behind?<br />"
	"In some loyal heart is your memory enshrined?<br />"
	"And though you died back in nineteen-sixteen<br />"
	"To that loyal heart are you always nineteen?<br />"
	"<br />"
	"Or are you a stranger without a name?<br />"
	"Forever enshrined behind some glass pane<br />"
	"In an old photograph, torn and tattered, and stained.<br />"
	"And faded to yellow in a brown leather frame.<br />"
	"<br />"
	"Did they beat the drums slowly?<br />"
	"Did they play the pipes lowly?<br />"
	"Did they bugles carry you over as they lowered you down?<br />"
	"And did the band play 'The Last Post' in chorus?<br />"
	"Did the pipes play 'The Flowers Of The Forest'?<br />"
	"<br />"
	"Well the sun's shining down on these green fields of France<br />"
	"The warm wind blows gently, and the red poppies dance<br />"
	"The trenches have vanished long under the plow<br />"
	"There's no gas, no barb wire, there's no guns firing now<br />"
	"<br />"
	"But here in this graveyard that's still no-man's land<br />"
	"The countless white crosses stand mute in the sand<br />"
	"To man's blind indifference to his fellow man<br />"
	"The whole generation was butchered and damned<br />"
	"<br />"
	"Did they beat the drums slowly?<br />"
	"Did they play the pipes lowly?<br />"
	"Did they bugles carry you over as they lowered you down?<br />"
	"And did the band play 'The Last Post' in chorus?<br />"
	"Did the pipes play 'The Flowers Of The Forest'?<br />"
	"<br />"
	"And I can't help but wonder young Willy McBride<br />"
	"Do those that lie here know why that they died?<br />"
	"And did they really believe you when you told them the cause<br />"
	"Did they really believe that this war would end wars?<br />"
	"<br />"
	"Well the suffering, and the sorrow, the glory of pain<br />"
	"The killing and dying they were all done in vain<br />"
	"For young Willy McBride it's all happened again,<br />"
	"And again, and again, and again, and again...<br />"
	"<br />"
	"Did they beat the drums slowly?<br />"
	"Did they play the pipes lowly?<br />"
	"Did they bugles carry you over as they lowered you down?<br />"
	"And did the band play 'The Last Post' in chorus?<br />"
	"Did the pipes play 'The Flowers Of The Forest'?<br />"
	"</body></html>";
printf ("about to send=> %s\n", message);
send (socket, message, strlen(message), 0);
}


// start the server listening on the specified port number
int makeServerSocket(int portNumber) {

// create socket
int serverSocket = socket (AF_INET, SOCK_STREAM, 0);
assert (serverSocket >= 0);
// error opening socket

// bind socket to listening port
struct sockaddr_in serverAddress;
serverAddress.sin_family      = AF_INET;
serverAddress.sin_addr.s_addr = INADDR_ANY;
serverAddress.sin_port        = htons (portNumber);

// let the server start immediately after a previous shutdown
int optionValue = 1;
setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &optionValue, sizeof(int));

int bindSuccess = bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

assert (bindSuccess >= 0);
// if this assert fails wait a short while to let the operating
// system clear the port before trying again

return serverSocket;
}

// wait for a browser to request a connection,
// returns the socket on which the conversation will take place
int waitForConnection(int serverSocket) {

// listen for a connection
const int serverMaxBacklog = 10;
listen(serverSocket, serverMaxBacklog);

// accept the connection
struct sockaddr_in clientAddress;
socklen_t clientLen = sizeof(clientAddress);
int connectionSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientLen);
assert(connectionSocket >= 0);
// error on accept

return connectionSocket;
}
