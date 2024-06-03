FROM gcc:latest as build

WORKDIR /gtest_build

RUN apt-get update && \
    apt-get install -y \
      libgtest-dev \
      cmake \
      build-essential

RUN cmake -DCMAKE_BUILD_TYPE=Release /usr/src/gtest && \
    cmake --build .

ADD ./src /app/src

WORKDIR /app/build

# Testing and build
RUN cmake ../src && \
    cmake --build . && \
    ctest --output-on-failure

FROM ubuntu:latest

WORKDIR /app

COPY --from=build /app/build/frequency_dictionary_app .
COPY --from=build /app/build/frequency_dictionary_test .

ENTRYPOINT ["./frequency_dictionary_app"]
