#ifndef DUKE_APP_H
#define DUKE_APP_H

#include "Duke/ExitCode.h"
#include "Duke/FileLogger.h"

namespace Duke {

    class App {
        public:
            App();
            
            ErrorCode run();
            void addLogFile(const FileLogger& logFile);
    };

};

#endif
