# API Consumer Project
====================

This project demonstrates a simple API consumer using C++ and the libcurl library to perform HTTP requests. The project is containerized with Docker for easy setup and execution.


## Project Structure
-----------------

```css
.
├── build/
├── docker/
│   └── Dockerfile
├── src/
│   ├── api_consumer/
│   │   ├── api.cpp
│   │   ├── api.hpp
│   │   ├── utils.cpp
│   │   └── utils.hpp
│   └── main.cpp
├── .dockerignore
├── .gitignore
├── CMakeLists.txt
├── README.md
└── package.json
```

## Technologies and Languages
--------------------------

*   C++: Main programming language used for the project
*   libcurl: C library for performing HTTP requests
*   CMake: Build system for managing the compilation process
*   Docker: Containerization platform for easy setup and execution
*   Node.js: Used for creating a script to execute the compiled C++ program


## Requirements
----------

* C++11 compatible C++ compiler
* CMake (version 3.10 or higher)
* libcurl4-openssl-dev


## Installation of dependencies
---------------------------

On Ubuntu, install the dependencies using the command:

```bash
sudo apt-get install g++ cmake libcurl4-openssl-dev
```


## compilation
----------

To compile the project, follow these steps:

1. Create a directory for the compilation:

```bash
mkdir build cd build
```

2. Generate the build files with CMake:

```bash
cmake ..
```

3. Compile the project using Make:

```bash
make
```


### Execution
--------

After successful compilation, run the `api_consumer` program in the `build` directory:

```bash
./api_consumer
```

The program will make a GET request to the URL `https://jsonplaceholder.typicode.com/posts` and display the result in the console.


## Setup and Execution
-------------------

### Building and running the project

1.  Install Docker on your machine, if you haven't already.
2.  Open a terminal, navigate to the root folder of the project, and run the following command to build the Docker image:

```bash
docker build -t api_consumer -f docker/Dockerfile .
```

3.  After the image is built, run the following command to start a container with the created image:

```bash
docker run --rm api_consumer
```

The container will start, and the compiled program will run inside it. When the program finishes executing, the container will be removed automatically.


### Running the API

The API used in this project is a public API from [JSONPlaceholder](https://jsonplaceholder.typicode.com/). The API provides sample data for testing and prototyping.

The project performs a GET request to the following endpoint:

```arduino
https://jsonplaceholder.typicode.com/posts
```

This endpoint returns a list of posts as JSON data. The response is printed on the console when running the containerized program.


### Contribution
------------

Feel free to contribute to this project, providing suggestions for improvements, bug fixes or implementing new features.


## License
-------

This project is licensed under the MIT License.