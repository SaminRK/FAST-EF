FROM ubuntu:bionic

# Updating the packages
RUN apt-get update
# Installing the freeDiameter dependencies
RUN apt-get -y install mercurial cmake make gcc g++ bison flex libsctp-dev libgnutls28-dev libgcrypt-dev libidn11-dev ssl-cert debhelper fakeroot libpq-dev libmysqlclient-dev libxml2-dev swig python-dev

# Downloading the code
RUN hg clone http://www.freediameter.net/hg/freeDiameter src
WORKDIR /src
RUN hg checkout 1.2.1


# Making the freeDiameter code
WORKDIR /build
RUN cmake ../src -DCMAKE_BUILD_TYPE=Debug -DALL_EXTENSIONS=ON -DCMAKE_INSTALL_PREFIX='/usr/local' \
&& make \
&& make install

COPY script.sh /build/
RUN chmod +x /build/script.sh
ENTRYPOINT /build/script.sh

EXPOSE 3868 3869 5658
