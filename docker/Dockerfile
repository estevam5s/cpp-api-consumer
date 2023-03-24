# Imagem base
FROM ubuntu:20.04

# Atualiza e instala os pacotes necessários
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    curl \
    libcurl4-openssl-dev \
    git

# Copia o projeto para o container
WORKDIR /app
COPY . .

# Compila o projeto
RUN mkdir build && cd build && cmake .. && make

# Executa o programa
CMD ["./build/api_consumer"]
