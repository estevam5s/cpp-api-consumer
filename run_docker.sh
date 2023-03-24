#!/bin/bash

echo "Building Docker image..."
docker build -t api-consumer-image .

echo "Running Docker container..."
docker run --rm -it -p 8080:8080 --name api-consumer-container api-consumer-image
