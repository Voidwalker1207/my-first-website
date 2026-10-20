FROM ubuntu:24.04 AS build

RUN apt-get update && apt-get install -y \
    g++ cmake make git libasio-dev ca-certificates \
    && rm -rf /var/lib/apt/lists/*

  WORKDIR /app

COPY . .
#Clone Crow locally to avoid any CMake network or archive errors
RUN git clone --depth 1 --branch v1.2.1 https://github.com/CrowCpp/Crow.git vendor/crow
 RUN rm -rf build && cmake -S . -B build -DCMAKE_BUILD_TYPE=Release && cmake --build build -j2

FROM ubuntu:latest

COPY --from=build /app/build/cpp_web_app /usr/local/bin/cpp_web_app

EXPOSE 10000

CMD ["/usr/local/bin/cpp_web_app"]


   
