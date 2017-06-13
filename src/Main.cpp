/**
 * @mainpage
 * @file Main.cpp
 * @brief Start point
 * @author LionZXY
 *
 * Start point Recast server. Initializing @see Server and @see MainThread.
 * Init config class @see Config.
 **/
#include <sqlite/src/sqlite3.h>
#include "Server.h"

/**
 * @brief Main method :)
 **/
int main() {
    Server server;
    sqlite3 *sq;
    server.initServer();
    server.mainLoop();
    return EXIT_SUCCESS;
}