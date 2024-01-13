# Docker name
# charlesdias/cpp_project_demo
#
# docker build
# docker build --no-cache --build-arg "host_uid=$(id -u)" --build-arg "host_gid=$(id -g)" -t charlesdias/cpp_project_demo:<version> -t charlesdias/cpp_project_demo:latest .
#
# docker push
# docker push charlesdias/cpp_project_demo --all-tags

# docker build --no-cache --build-arg "host_uid=$(id -u)" --build-arg "host_gid=$(id -g)" -t charlesdias/cpp_project_demo:1.0 -t charlesdias/cpp_project_demo:latest .

FROM ubuntu:22.04

LABEL maintainer="Charles Dias <charlesdias@tecnofuturo.com.br>"

ENV TZ=America/Fortaleza
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

# Download Linux support tools
RUN apt-get update && apt-get clean && apt-get install -y \
    build-essential git wget python3 python3-pip tree vim curl zip unzip tar \
    doxygen graphviz gcovr lcov ccache flawfinder cppcheck valgrind \
    pkg-config llvm clang-tidy clang-format \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# Install Lizard
RUN pip3 install lizard

# Install CMake-format
RUN pip3 install cmake-format

# Get and install the CMake
ENV version=3.28.1

RUN wget https://github.com/Kitware/CMake/releases/download/v$version/cmake-$version-Linux-x86_64.sh \
      -q -O /tmp/cmake-install.sh \
      && chmod u+x /tmp/cmake-install.sh \
      && mkdir /usr/bin/cmake \
      && /tmp/cmake-install.sh --skip-license --prefix=/usr/bin/cmake \
      && rm /tmp/cmake-install.sh

# Set up the CMake path
ENV PATH="/usr/bin/cmake/bin:${PATH}"

# In Ubuntu, /bin/sh is a link to /bin/dash. The dash shell does not support
# the source command. Replace dash with bash
RUN rm /bin/sh && ln -s bash /bin/sh

# Set environment variables, which are used later in the Dockerfile.
ENV USER_NAME embedded
ENV PROJECT embedded

ARG host_uid=1001
ARG host_gid=1001
RUN groupadd -g $host_gid $USER_NAME && \
    useradd -g $host_gid -m -s /bin/bash -u $host_uid $USER_NAME

USER $USER_NAME

# RUN mkdir ${HOME}/oe-core && cd ${HOME}/oe-core

WORKDIR /home/$USER_NAME/project
