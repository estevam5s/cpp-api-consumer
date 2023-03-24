#pragma once
#include <string>

struct APIResponse {
    long status_code;
    std::string body;
};

class APIConsumer {
public:
    APIResponse get(const std::string& url);
};
