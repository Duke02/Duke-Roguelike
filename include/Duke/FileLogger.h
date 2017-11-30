#include <fstream>
#include <string>

namespace Duke {

    enum class LogLevel {
        ALL, DEBUG, ERROR, NONE
    };

    enum class LogError {
        OKAY, // Everything was ok.
        FILE_LOW_LEVEL, // File Logger object had too low of a level for given write command.
                        // You asked it to write a DEBUG log but the object only takes ERROR.
        WRITE_ERROR, // Any kind of write error (can't find file, etc.)
        UNKNOWN // Don't know what it might be.
    };

    class FileLogger {
    private:
        std::ofstream outputFile;
        LogLevel level;

    public:
        FileLogger(const std::string& filename, const LogLevel& logLevel);
        FileLogger();
        
        static std::string logLevelToStr(const LogLevel& logLevel);
        
        LogError writeToFile(std::string& message, const LogLevel& logLevel);
        bool properWritePriviledges(const LogLevel& logLevel);
        
    };


};
