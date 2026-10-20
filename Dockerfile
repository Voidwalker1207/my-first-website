FROM ubuntu:24.04 AS build

RUN apt-get update && apt-get install -y\
  g++ cmake make git libasio-dev\
  && rm-rf /var/lib/apt/lists/*

  WORKDIR/app

COPY CMkeLists.txt main.cpp./

 RUN cmake-S.-B build-DCMAKE-BUILD-TYPE=Release\
    && cmake--build build-j2

FROM ubuntu:8080

EXPOSE 8080

CMD["/usr/local/bin/cpp_web_app"]


   
