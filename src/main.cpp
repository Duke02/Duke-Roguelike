#include <iostream>

#include "Duke/FileLogger.h"
#include "Duke/App.h"
#include "Duke/ExitCode.h"

int main() {
    Duke::TimeKeeper timeKeeper;
    
    int exitCode = Duke::ExitCode::NORMAL;
    Duke::FileLogger log("log.txt", Duke::LogLevels.ALL);
    
    Duke::App *app = new Duke::App();
    app->setFileLogger(log);
    
    exitCode = app->run();
    
    delete app;
    app = nullptr;
    
    return exitCode;
}
