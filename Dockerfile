FROM debian:buster
LABEL maintainer="user"

RUN apt-get update && apt-get -y install \
       sudo systemd systemd-sysv \
       build-essential wget libffi-dev libssl-dev \
       mc git cmake \
       autoconf \
       automake \
       libtool \
       gawk \
       parted \
       udev \
       python \
       qemu-system-arm \
       curl wget git nano \
       vim cmake-curses-gui gdebi-core \
       dosfstools doxygen flex libclang1-6.0 libfl-dev libfl2 libllvm6.0 libncurses5 libpython2.7 \ 
       libsdl2-2.0-0 libsndio7.0 libtinfo5 libxapian30 libxss1 socat \
       && apt-get autoremove --yes && apt-get clean --yes

COPY ./KasperskyOS-Community-Edition_1.1.1.13_en.deb  /tmp/KasperskyOS-Community-Edition_1.1.1.13_en.deb 
RUN gdebi -n /tmp/KasperskyOS-Community-Edition_1.1.1.13_en.deb

# add user 'docker'
RUN useradd -r -u 1000 -U -m docker-KOS

# prepare working directory
RUN mkdir /workspace && chown -R docker-KOS /workspace
WORKDIR /workspace

ENV LC_ALL C.UTF-8
ENV LANG C.UTF-8
ENV LANGUAGE C.UTF-8

RUN apt-get update && apt-get -y install \
       device-tree-compiler\
       && apt-get autoremove --yes && apt-get clean --yes

#USER docker  
ENTRYPOINT [ "/bin/bash", "-l", "-c" ]
