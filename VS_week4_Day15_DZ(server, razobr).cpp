﻿#include <iostream>
#include <exception>
#include <string>
using namespace std;

string AskTimeServer() {
    
}

class TimeServer {
public:
    string GetCurrentTime() {
        try
        {
            LastFetchedTime = AskTimeServer();
            return LastFetchedTime;
        }
        catch (const std::system_error&)
        {
            return LastFetchedTime;
        }
        catch (...) {
            throw;
        }
        
    }

private:
    string LastFetchedTime = "00:00:00";
};

int main() {
    
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    }
    catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}