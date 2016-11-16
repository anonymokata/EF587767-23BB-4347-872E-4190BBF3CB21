FROM ubuntu:14.04
MAINTAINER tchupp

# Install Basic Packages
RUN apt-get update -y
RUN apt-get upgrade -y

RUN apt-get install -y build-essential
RUN apt-get install -y pkg-config
RUN apt-get install -y check

RUN apt-get update -y
RUN apt-get install -y valgrind

# Make dev-home
RUN mkdir /home/dev
WORKDIR /home/dev

CMD ["make", "mem_test"]