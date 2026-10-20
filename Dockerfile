FROM ubuntu:24.04 AS build

RUN apt-get update && apt-get install -y\
  g++ cmake make git libasio-dev\
  && rm-rf /var/lib/apt/lists/*

  WORKDIR /app

COPY CMakeLists.txt main.cpp./

 RUN cmake -S . -B build -DCMAKE_BUILD_TYPE=Release\
    && cmake--build build-j2

FROM ubuntu:latest

# Copy the binary from the build stage into the final image
COPY --from=build /app/build/cpp_web_app /usr/local/bin/cpp_web_app

EXPOSE 10000

CMD ["/usr/local/bin/cpp_web_app"]


   
