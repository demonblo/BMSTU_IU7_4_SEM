#ifndef UNTITLED72_ERRORS_H
#define UNTITLED72_ERRORS_H

#include <exception>
#include <string>

class setExpt : public std::exception
{
public:
    explicit setExpt(
            const std::string& filename,
            const std::string& classname,
            const int line,
            const std::string& time,
            const std::string& info)
    {
        msg = "In " + filename +
              "\nat line " + std::to_string(line) +
              "\nin class " + classname +
              "\nraised an exception: " + info +
              "\nat " + time;
    }
    [[nodiscard]] const char* what() const noexcept override {
        return msg.c_str();
    }

private:
    std::string msg;
};

class memError : public setExpt
{
public:
    memError(
            const std::string& filename,
            const std::string& classname,
            const int line,
            const std::string& time,
            const std::string& info = "Memory allocation error"
    ) : setExpt(filename, classname, line, time, info) {}
};

class rangeError : public setExpt
{
public:
    rangeError(
            const std::string& filename,
            const std::string& classname,
            const int line,
            const std::string& time,
            const std::string& info = "Specified value violates structure properties"
    ) : setExpt(filename, classname, line, time, info) {}
};

class nullPtrError : public setExpt
{
public:
    nullPtrError(
            const std::string& filename,
            const std::string& classname,
            const int line,
            const std::string& time,
            const std::string& info = "Attempt to work or dereference NULL pointer"
    ) : setExpt(filename, classname, line, time, info) {}
};
#endif //UNTITLED72_ERRORS_H
