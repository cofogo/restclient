all:
	g++ src/main.cpp -o restcli -std=c++14 -lrestclient-cpp -lcurl
