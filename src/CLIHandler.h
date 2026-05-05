cpp
#ifndef CLIHANDLER_H
#define CLIHANDLER_H

#include <boost/asio.hpp>
#include <Eigen/Dense>
#include <string>
#include <vector>

struct CLIOptions {
    std::string inputFilePath;
    std::string outputFilePath;
    bool verbose;
    bool help;
    int numThreads;
};

void parseCommandLine(int argc, char* argv[]);

#endif // CLIHANDLER_H