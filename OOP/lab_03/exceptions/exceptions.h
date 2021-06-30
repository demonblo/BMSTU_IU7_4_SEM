#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>
using namespace std;

class ExceptionApps : public std::exception
{
public:
    explicit ExceptionApps(
                           const string& filename,
                           const string& classname,
                           const int line,
                           const char *time,
                           const string& info)
    {
        m_msg = "In: "          + filename             +
                "\ninside: "    + classname            +
                "\nat line: "   + to_string(line)      +
                "\nat: "        + time                 +
                "\noccured: "   + info;
    }

    const char *what() const noexcept override {
        return m_msg.c_str();
    }
private:
    string m_msg;
};

class ErrorRange : public ExceptionApps
{
 public:
    ErrorRange(
            const string& filename,
            const string& classname,
            const int line,
            const char *time,
            const string& info = "Error range"
            ): ExceptionApps(filename, classname, line, time, info){}
};

class ErrorModelBuild : public ExceptionApps
{
 public:
    ErrorModelBuild(
            const string& filename,
            const string& classname,
            const int line,
            const char *time,
            const string& info = "Model build error"
            ): ExceptionApps(filename, classname, line, time, info){}
};

class ErrorCameraLack : public ExceptionApps
{
 public:
    ErrorCameraLack(
            const string& filename,
            const string& classname,
            const int line,
            const char *time,
            const string& info = "Camera lack"
            ): ExceptionApps(filename, classname, line, time, info){}
};

class ErrorObjectLack : public ExceptionApps
{
 public:
    ErrorObjectLack(
            const string& filename,
            const string& classname,
            const int line,
            const char *time,
            const string& info = "Object lack"
            ): ExceptionApps(filename, classname, line, time, info){}
};

class ErrorDrawerLack : public ExceptionApps
{
 public:
    ErrorDrawerLack(
            const string& filename,
            const string& classname,
            const int line,
            const char *time,
            const string& info = "Drawer lack"
            ): ExceptionApps(filename, classname, line, time, info){}
};

class ErrorFileOpen : public ExceptionApps
{
 public:
    ErrorFileOpen(
            const string& filename,
            const string& classname,
            const int line,
            const char *time,
            const string& info = "Error file open"
            ): ExceptionApps(filename, classname, line, time, info){}
};

class ErrorAllocMemmory : public ExceptionApps
{
 public:
    ErrorAllocMemmory(
            const string& filename,
            const string& classname,
            const int line,
            const char *time,
            const string& info = "Error alloc memory"
            ): ExceptionApps(filename, classname, line, time, info){}
};

class ErrorEmpty : public ExceptionApps
{
 public:
    ErrorEmpty(
            const string& filename,
            const string& classname,
            const int line,
            const char *time,
            const string& info = "Error alloc memory"
            ): ExceptionApps(filename, classname, line, time, info){}
};

class ErrorConfigFile : public ExceptionApps
{
 public:
    ErrorConfigFile(
            const string& filename,
            const string& classname,
            const int line,
            const char *time,
            const string& info = "Error config file"
            ): ExceptionApps(filename, classname, line, time, info){}
};


#endif // EXCEPTIONS_H
