/*
Profit Development

Tyler Durden is a salesperson and is assigned a task to travel to sell soaps. He must travel to different countries with S states each. His manager has also provided him with an integer array A, of length N. Array 'A' represents a rating list which shows the past sales in a certain state. Below are a few rules for him to follow to increase the efficiency of his travel :-

• Tyler should begin his travel from the state which has the lowest rating.

• When he starts his travel in a country, he should visit all the states in that country before going to a different country.

Your task is to help Tyler plan his travel route and return an integer value representing the country and the rating of the state Tyler will be travelling to in month M based on the rating list.

Note:

The rating list contains data for all the states together, so the first S ratings are for country 1, the next S ratings are for country 2 and so on.

• The month count starts from 1 and if two or more countries have the same lowest rating then choose the country whose state has the second lowest rating.

Input Specification

input1: An integer value N representing the length of the rating list
input2: An integer value S, representing the number of states in a country.

input3: An integer value M, representing the month number.

input4: An integer array A, representing the rating list.

Output Specification

Output1: Return the country Tyler will be travelling to in month M based on the rating list.

Output2: Return the state Tyler will be travelling to in month M based on the rating list.

Example 1:

input1 : 6

input2 : 3

input3: 6

input4: (2,1,9,3,1,4)

Output1 : 2

Output2 : 4
Explanation:

There are 6 states where Tyler needs to travel, and each country has 3 states. Based on the rating list, the route of his travel will be:


• Country 1 -> Country 2 (Since the lowest rating is same in both the countries, we look at the second lowest rating and thus, Tyler will start his travel with Country 1)


• Country 1: State with rating 1-> State with rating 2 -> State with rating 9

• Country 2: State with rating 1-> State with rating 3 -> State with rating 4

Using this route, Tyler will be in Country 2 and State with rating 4 during the 6th month. Therefore, 2 and 4 will be returned as output1 and output2, respectively.

Example 2:

input1 : 12

input2:3

input3:7

input4: (4,5,7,9,3,2,5,1,3,2,4,1)

Output1:2

Output2:2

Explanation:

There are 12 states which Tyler needs to travel to, and each country has 3 states. Based on the rating list, the route of his travel will be:..

Country 4-> Country 3-> Country 2-> Country 1 (Since the lowest rating is same in Country 4 and Country 3, we look at the second lowest rating and thus, Tyler will stat his travel with Country 4)

• Country 4: State with rating 1-> State with rating 2-> State with rating 4

• Country 3: State with rating 1-> State with rating 3-> State with rating 5

• Country 2: State with rating 2-> State with rating 3-> State with rating 9

Country 1: State with rating 4-> State with rating 5-> State with rating 7

Using this route, Tyler will be in Country 2 and State with rating 2 during the 7th month. Therefore, 2 and 2 will be returned as output1 and output2, respectively.

*/
#include<stdio.h>
#include<string.h>
#include <vector>
#include <algorithm>
#include <utility>
#include<bits/stdc++.h>
using namespace std;
struct Result {
    int output1;
    int output2;
};

// S -> no of states , M - month , A - array of rating list 
Result profitDevelopment(int N, int S, int M, int A[]){  // N -> total number of states representing it's rating 
    int nOfCountries = N / S;   
    vector<vector<int>>countries(nOfCountries);  // total nOfCountries countries with each S no of states.
    for(int i = 0; i < nOfCountries; i++){
        countries[i].resize(S);  // assigning each country with equal(S) no of states;
        for(int j = 0; j < S; j++){
            countries[i][j] = A[i * S + j];
        }
    } 
    
    for(auto& country : countries){
        sort(country.begin(), country.end());  // sorting each country's state according to their rating
    }

    sort(countries.begin(), countries.end()); // sorting countries vector starting with country with least_rating

    vector<pair<int, int>> travelRoute;
    for(int i = 0; i < nOfCountries; i++){
        for(int j = 0; j < S; j++){
            travelRoute.push_back({i+1, countries[i][j]});
        }
    }

    int country = travelRoute[M-1].first;
    int state = travelRoute[M-1].second;
    Result res;
    res.output1 = country;
    res.output2 = state;
    return res;
}

int main() {
    int N, S, M;
    cout<<"Enter length rating list: ";
    cin>>N;
    cout<<"Enter no of avg. month: ";
    cin>>S;
    cout<<"Enter the month: ";
    cin>>M;
    cout<<"Enter the ratings for the list: ";
    int A[N];
    for(int i = 0; i < N; i++){
        cin>>A[i];
    }

    Result res = profitDevelopment(N, S, M, A);
    cout<<"Country no: "<< res.output1<<endl;
    cout<<"State no: "<<res.output2<<endl;


    // Example 1
    // int N1 = 6;
    // int S1 = 3;
    // int M1 = 6;
    // int A1[] = {2, 1, 9, 3, 1, 4};

    // Result result1 = profitDevelopment(N1, S1, M1, A1);
    // cout << "Output1: " << result1.output1 << endl;
    // cout << "Output2: " << result1.output2 << endl;

    // Example 2
    // int N2 = 12;
    // int S2 = 3;
    // int M2 = 7;
    // int A2[] = {4, 5, 7, 9, 3, 2, 5, 1, 3, 2, 4, 1};

    // Result result2 = profitDevelopment(N2, S2, M2, A2);
    // cout << "Output1: " << result2.output1 << endl;
    // cout << "Output2: " << result2.output2 << endl;

    return 0;
}