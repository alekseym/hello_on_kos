### Hello Example
There are some examples for students to simplify LAB tasks for KOS CE development class. They are based on original examples from KOS CE SDK.

### Prerequisites
Before you begin, ensure that you have met the following requirements:
- You have installed the latest version of [KasperskyOS Community Edition](https://os.kaspersky.com/development/download/)
- You have Debian GNU/Linux "Buster" 10.7


### How to use docker enviroment to run examples

### Get source:

cd ~
https://github.com/alekseym/hello_on_kos.git
cd hello_on_kos

### Compile docker image
docker build -t getting-started .


### Setup development enviroment:

docker run -it -v ~/hello_on_kos/hello_with_args:/workspace --device /dev/net/tun:/dev/net/tun --privileged --rm getting-started bash

### Compile and run in Docker: 
cd ./hello_with_args
./cross-build.sh



