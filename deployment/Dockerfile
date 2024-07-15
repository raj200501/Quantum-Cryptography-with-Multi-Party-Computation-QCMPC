FROM gcc:latest

WORKDIR /app

COPY quantum_cryptography /app/quantum_cryptography
COPY smpc /app/smpc
COPY config /app/config

RUN apt-get update && apt-get install -y cmake

RUN cd /app/quantum_cryptography && cmake . && make
RUN cd /app/smpc && cmake . && make

CMD ["./main"]
