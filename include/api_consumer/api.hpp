#pragma once

#include <string>
#include <curl/curl.h>
#include "utils.hpp"

class APIConsumer {
public:
    APIConsumer();
    ~APIConsumer();
    Response get(const std::string& url);

private:
    CURL* curl;
    static size_t write_callback(void* contents, size_t size, size_t nmemb, void* userp);
};
