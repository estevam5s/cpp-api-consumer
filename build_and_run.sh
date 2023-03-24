#!/bin/bash

# Navegue até a pasta build
cd build

# Execute o CMake para gerar os arquivos de compilação
cmake ..

# Compile o projeto
make

# Execute o programa compilado
./api_consumer

# Volte para a pasta raiz do projeto
cd ..
