#include "../src/api_consumer/api.hpp"
#include <iostream>
#include <cassert>

void teste_get() {
    APIConsumer api;

    std::string url = "https://jsonplaceholder.typicode.com/posts";
    auto response = api.get(url);

    assert(response.status_code == 200);

    std::cout << "Teste GET bem-sucedido!" << std::endl;
}

int main() {
    teste_get();
    std::cout << "Todos os testes foram concluídos com sucesso!" << std::endl;
    return 0;
}
