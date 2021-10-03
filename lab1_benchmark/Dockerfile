FROM ubuntu:20.04
RUN apt-get update
RUN apt-get install -y git
RUN apt-get install -y build-essential

COPY lab1_benchmark.cpp .

RUN gcc -o lab1_benchmark  lab1_benchmark.cpp -lstdc++

ENTRYPOINT lab1_benchmark
