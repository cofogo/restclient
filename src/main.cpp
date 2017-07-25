#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;

//3rd party libs
#include "restclient-cpp/restclient.h"

void print_resp(RestClient::Response& _r);

int main()
{
    RestClient::Response r;

    //get
    cout << "\n\n";
    cout << "\t\t*** sending get request ***\n";
    r = RestClient::get("https://httpbin.org/get");

    print_resp(r);

    string data_str = "";
    while(data_str != "quit" && data_str != "q") {
        cout << "\ntype in a string you want to send to the service\n";
        cout << "or type in 'q' to quit\n>";

        char data_cstr[512];
        cin.getline(data_cstr, sizeof(data_cstr));
        data_str = data_cstr;

        if(data_str == "q") {break;}

        //set
        cout << "\n\n";
        cout << "\t\t*** sending data to /put ***\n";
        r = RestClient::put("https://httpbin.org/put", "text/plain", data_str);

        print_resp(r);
    }
    
    cout << "application will now exit.\nHave a good day!\n";

    return 0;
}

void print_resp(RestClient::Response& _r)
{
    cout << "\n*\n*** response code ***\n*\n";
    cout << _r.code << endl;
    cout << "************************\n";
    cout << "*** response headers ***\n";
    cout << "************************\n";
    for(const auto &pair : _r.headers) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << "*********************\n";
    cout << "*** response body ***\n";
    cout << "*********************\n";
    cout << _r.body << endl;
    cout << "***********************\n";
    cout << "*** end of response ***\n";
    cout << "***********************\n";
}
