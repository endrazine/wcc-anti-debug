FROM ubuntu:24.04

RUN apt update && apt upgrade -y

WORKDIR /root/

COPY ./testcases/ .

RUN apt-get install -y clang libbfd-dev uthash-dev libelf-dev libcapstone-dev  libreadline-dev libiberty-dev libgsl-dev build-essential git debootstrap file cargo openssh-server apache2 nginx gcc upx

RUN apt-get install -y libbpf1 libtirpc-dev

# Build wcc & install it
RUN git clone https://github.com/endrazine/wcc.git && cd wcc && git checkout && git submodule init && git submodule update && make && make install

RUN apt install -y libpcre2-dev libaprutil1-dev libapr1-dev libexpat1-dev uuid-dev

RUN make

