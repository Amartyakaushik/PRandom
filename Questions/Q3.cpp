#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <map>
#include <utility>
using namespace std;

vector<int> processTransactionSequence(vector<int> accountCredits, const vector<string>& transactionLog) {
    // Mapping for delayed cashback events
    map<long long, vector<pair<int, int>>> pendingCashbackSchedule;
    
    for (int transactionIndex = 0; transactionIndex < transactionLog.size(); transactionIndex++) {
        // Analyze each transaction request
        istringstream transactionDetails(transactionLog[transactionIndex]);
        string transactionType;
        long long transactionTimestamp;
        int accountHolder, transactionAmount;
        
        if (!(transactionDetails >> transactionType >> transactionTimestamp >> accountHolder >> transactionAmount)) {
            // Invalid transaction format
            return vector<int>{-(transactionIndex + 1)};
        }
        
        // Process any pending cashback events before current transaction
        while (!pendingCashbackSchedule.empty() && pendingCashbackSchedule.begin()->first <= transactionTimestamp) {
            auto scheduledEvent = pendingCashbackSchedule.begin();
            for (auto& cashbackEntry : scheduledEvent->second) {
                int accountIndex = cashbackEntry.first;
                int cashbackValue = cashbackEntry.second;
                if (accountIndex >= 0 && accountIndex < accountCredits.size()) {
                    accountCredits[accountIndex] += cashbackValue;
                }
            }
            pendingCashbackSchedule.erase(scheduledEvent);
        }
        
        // Validate account index
        int accountIndex = accountHolder - 1;
        if (accountIndex < 0 || accountIndex >= accountCredits.size()) {
            return vector<int>{-(transactionIndex + 1)};
        }
        
        if (transactionType == "deposit") {
            accountCredits[accountIndex] += transactionAmount;
        } else if (transactionType == "withdraw") {
            if (accountCredits[accountIndex] < transactionAmount) {
                return vector<int>{-(transactionIndex + 1)};
            }
            accountCredits[accountIndex] -= transactionAmount;
            
            // Calculate and schedule cashback
            int cashbackAmount = (transactionAmount * 2) / 100;
            long long cashbackDueTime = transactionTimestamp + 24LL * 3600;
            pendingCashbackSchedule[cashbackDueTime].push_back({accountIndex, cashbackAmount});
        } else {
            return vector<int>{-(transactionIndex + 1)};
        }
    }
    return accountCredits;
}

// Optional: Example main function to demonstrate usage
int main() {
    vector<int> initialBalances = {100, 200, 300};
    vector<string> transactions = {
        "deposit 1000 1 50",
        "withdraw 1001 2 30"
    };
    
    vector<int> finalBalances = processTransactionSequence(initialBalances, transactions);
    
    for (int balance : finalBalances) {
        cout << balance << " ";
    }
    cout << endl;
    
    return 0;
}