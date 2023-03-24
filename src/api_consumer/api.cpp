#include <iostream>
#include <string>
#include <curl/curl.h>
#include "api_consumer/api.hpp"


size_t APIConsumer::write_callback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

APIConsumer::APIConsumer() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
}

APIConsumer::~APIConsumer() {
    curl_global_cleanup();
}

APIResponse APIConsumer::get(const std::string& url) {
    CURL* curl;
    CURLcode res;
    APIResponse response;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response.body);

        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response.status_code);
        }

        curl_easy_cleanup(curl);
    }

    return response;
}

int main() {
    // Criar uma instância da classe APIConsumer
    APIConsumer api;

    // Realizar uma requisição GET para a URL desejada
    std::string url = "https://jsonplaceholder.typicode.com/posts";
    auto response = api.get(url);

    // Imprimir o resultado da requisição
    std::cout << "GET " << url << std::endl;
    std::cout << "Status Code: " << response.status_code << std::endl;
    std::cout << "Body: " << std::endl << response.body << std::endl;

    return 0;
}
