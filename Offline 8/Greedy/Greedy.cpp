#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<string>
#include<sstream>
#include<cstring>
using namespace std;

template<typename T>
class LineParser
{
public:
    string str;
    char delim;
    vector<T> output;

public:
    LineParser()
    {
        // pass
    }

    LineParser(string line, char delimeter)
    {
        str = line;
        delim = delimeter;
    }

    vector<T> parseLineToInteger()
    {
        stringstream ss(str);
        string token;
        int num;

        while(getline(ss, token, delim))
        {
            num = stoi(token);
            output.push_back(num);
        }
        return output;
    }

};


/// function to find minimum cost of buying all plants
int findMinCost(int N, int K, vector<int> priceList)
{
    int cost = 0;
    // sorting prices in descending order as price increment factor increase in
    // each iteration, then if we choose the larger price later, cost will
    // increase significantly, large price will dominate the total cost
    // so wee need to take the larger prices earlier in greedy manner
    sort(priceList.begin(), priceList.end(), [=](int x, int y){return x>y;});

    for(int index=0; index<K; index++)
    {
        int i = index; // starting index of each friend no
        // friend 0 starts at 0, friend 1 starts at 1 and so on..
        // and wait for their cycle again depending on K

        int j = 0; // price increment factor, for each friend it is 0 in the beginning
        while(i<N) // while each friend finishes himself traversing the whole sorted priceList
        {
            cost = cost + (j + 1)*priceList[i];
            j++; // j = 0,1,2...
            i=i+K;  // for example. if friend count K=3, then friend 0 will access i = 0,3,6 index prices
            // and friend 1 will access i = 1,4,7 index prices
        }
    }

    return cost;
}

/// utility functions
/// isValid method to validate and limit input to numeric value only
bool isValid(string str)
{
    for(int i=0; i<str.length(); i++)
    {
        if( !( (str[i] >= 48 && str[i] <= 57) || str[i] == 32 ) )
           return false;
    }
    return true;
}

/// main function
int main()
{
    while(true)
    {
        cout<<"# Enter Input. Enter Q to Quit."<<endl;

        // N = number of plants
        // K = number of friends
        int N,K;
        string input;

        // parsing line 1
        fflush(stdin);
        getline(cin, input);

        // exit condition
        if(input == "Q" || input == "q")
        {
            cout<<"Program Terminated"<<endl;
            exit(0);
        }

        // validating input for only numeric value
        if(!isValid(input))
        {
            cout<<"Invalid Input. Try Again."<<endl;
            continue;
        }


        LineParser<int> inputParser(input,' '); // parsing input line on space delimiter
        auto nums = inputParser.parseLineToInteger(); // vector of integer input

        // validating user input
        if(nums.size() == 2)
        {
            N = nums[0];
            K = nums[1];
        }
        else
        {
            cout<<"Invalid Input. Try Again."<<endl;
            continue;
        }

        // parsing line 2
        fflush(stdin);
        getline(cin, input);

        // validating input for only numeric value
        if(!isValid(input))
        {
            cout<<"Invalid Input. Try Again."<<endl;
            continue;
        }

        LineParser<int> priceParser(input,' '); // parsing input line on space delimiter
        auto priceList = priceParser.parseLineToInteger(); // vector of integer input

        // validating user input
        if(isValid(input) && priceList.size() == N)
        {
            int cost = findMinCost(N, K, priceList);
            cout<<"# Output: "<<endl;
            cout<<cost<<endl;
        }
        else
        {
            cout<<"Invalid Input. Try Again."<<endl;
            continue;
        }

        cout<<endl;
    }

    return 0;
}

