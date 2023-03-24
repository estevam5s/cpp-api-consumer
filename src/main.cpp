#include <iostream>
#include "api_consumer/api.hpp"
#include "api_consumer/utils.hpp"

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

    // Usar a função utilitária example_function
    std::string input = "Teste de função utilitária.";
    std::cout << "Função utilitária: " << utils::example_function(input) << std::endl;

    return 0;
}
