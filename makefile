all:
	g++ src/main_test.cpp -o test_rest -std=c++14 -lrestclient-cpp -lcurl
