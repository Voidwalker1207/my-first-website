FROM ubuntu:24.04 AS build

RUN apt-get update && apt-get install -y\
   g++ cmake make git libasio-dev\
&& rm -rf/var/lib/apt/lists/*

WORKDIR /app
COPY CMakeLists.txt main.cpp./

RUN cmake-S.-B build-DCMAKE_BUILD_TYPE=Release\
   && cmake--build build-j2

   FROM ubuntu:24.04

   COPY--from=build/app/build/cpp_web_app/usr/local/bin/
   cpp_web_app
   ENV PORT=8080
   EXPOSE 8080
   
   CMD ["/usr/local/bin/cpp_web_app"]
   
