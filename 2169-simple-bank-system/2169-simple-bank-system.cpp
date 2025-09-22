class Bank {

private:
    unordered_map<int, long long> accToMoney;
    int accountNum = 0;

public:
    Bank(vector<long long>& balance) {
        accountNum = balance.size();
        for(int i = 1; i <= accountNum; i++) {
            accToMoney[i] += balance[i-1];
        }
    }

    bool isValidAccount(int account) {
        if(account > accountNum || account < 1) return false;
        return true;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(!isValidAccount(account1)) return false;
        if(!isValidAccount(account2)) return false;

        if(accToMoney[account1] < money) return false;
        accToMoney[account1] -= money;
        accToMoney[account2] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(!isValidAccount(account)) return false;
        accToMoney[account] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!isValidAccount(account)) return false;
        if(accToMoney[account] < money) return false;
        accToMoney[account] -= money;
        return true;
    }


};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */