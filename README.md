## Send a c struct over TCP/IP network

This smal project is just a bullshit example about sending C structures over network.

This way is suitable for writing structures on all file descriptors like sockets, pipes, and etc.

## Build

```
mkdir build

cd build

cmake ..

cmake --build .

./server & ./client

```