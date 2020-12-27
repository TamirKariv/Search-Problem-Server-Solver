#include <iostream>
#include "MatrixSearchable.h"
#include "DFS.h"
#include "BestFirstSearch.h"
#include "BFS.h"
#include "AStar.h"
#include "MyTestClientHandler.h"
#include "Server.h"
#include <vector>
#include <string>
#include "MySerialServer.h"

using namespace std;

int main(int argc, char **argv) {
    //set up the server
    server_side::Server *server = new MySerialServer();
    int port = stoi(argv[1]);
    //set the client handler
    MyTestClientHandler *ch = new MyTestClientHandler(port);
    //open up the server
    server->open(port, ch);
    //get inputs from textiles
    vector<string> inputStream;
    vector<string> outputStream;
    inputStream.push_back("Graphs/Graph1.txt");
    inputStream.push_back("Graphs/Graph2.txt");
    inputStream.push_back("Graphs/Graph3.txt");
    inputStream.push_back("Graphs/Graph4.txt");
    inputStream.push_back("Graphs/Graph5.txt");
    inputStream.push_back("Graphs/Graph6.txt");
    inputStream.push_back("Graphs/Graph7.txt");
    inputStream.push_back("Graphs/Graph8.txt");
    inputStream.push_back("Graphs/Graph9.txt");
    inputStream.push_back("Graphs/Graph10.txt");
    //get outputs location
    for (int i = 0; i <10 ; ++i) {
        outputStream.push_back("solution.txt");
    }
    //connect to the server and handle the clients via the client handler.
    ch->HandleClient(inputStream, outputStream);
}