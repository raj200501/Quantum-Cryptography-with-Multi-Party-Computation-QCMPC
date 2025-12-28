#!/bin/bash

# Deploy the Docker containers

if [ -f docker-compose.yml ]; then
docker-compose up --build
else
    if [ -f deployment/docker-compose.yml ]; then
        docker-compose -f deployment/docker-compose.yml up --build
    else
        echo "No docker-compose.yml found in repository root or deployment/." >&2
        exit 1
    fi
fi
