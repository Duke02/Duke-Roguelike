#include <iostream>

#include "Duke/FileLogger.h"
#include "Duke/TimeKeeper.h"

namespace Duke {
    
    FileLogger::FileLogger() {
        
    }

    FileLogger::FileLogger(const std::string& filename, const LogLevel& logLevel) {
        this->outputFile.open(filename);
        this->level = logLevel;
    }
    
    LogError FileLogger::writeToFile(std::string& message, const LogLevel& logLevel) {
        if(!properWritePriviledges(logLevel)) {
                return LogError::FILE_LOW_LEVEL;
        }
        if(!this->outputFile.good()) {
            return LogError::WRITE_ERROR;
        }
        
        this->outputFile << TimeKeeper.currTime() << " " <<
                            FileLogger::logLevelToStr(logLevel) << ": " << message << std::endl;
        return LogError::OKAY;
    }
    
    bool FileLogger::properWritePriviledges(const LogLevel& logLevel) {
        return logLevel >= this->level;
    }
    
    
};
