@echo off

REM Navegue até a pasta build
cd build

REM Execute o CMake para gerar os arquivos de compilação
cmake ..

REM Compile o projeto
make

REM Execute o programa compilado
api_consumer.exe

REM Volte para a pasta raiz do projeto
cd ..
