FROM ubuntu:latest AS build

RUN apt-get update && apt-get install -y cmake \
                                         build-essential \ 
                                         git \
                                         librdkit-dev \
                                         libboost-all-dev \
                                         libeigen3-dev \ 
                                         python3-dev \ 
                                         python3-numpy
# install gRPC following gRPC docs
WORKDIR /deps
RUN git clone --recurse-submodules -b v1.71.0 --depth 1 --shallow-submodules https://github.com/grpc/grpc
RUN  mkdir -p /deps/grpc/cmake/build && \
                cd /deps/grpc/cmake/build && \
                cmake -DgRPC_INSTALL=ON \
                      -DgRPC_BUILD_TESTS=OFF \
                      -DCMAKE_POLICY_VERSION_MINIMUM=3.5 \
                      -DCMAKE_CXX_STANDARD=17 \
                      -DCMAKE_INSTALL_PREFIX=/deps \
                      ../.. && \
                make -j8 && make install

COPY . /cmpstd

RUN cd /cmpstd && cmake -DCMAKE_PREFIX_PATH=/deps \
                         -S /cmpstd -B /build && \
                         cmake --build /build --target install

EXPOSE 9999
CMD ["service"]
