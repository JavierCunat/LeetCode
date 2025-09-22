class Bank {

private:
    int accountNum = 0;
    vector<long long> balances;

public:
    Bank(vector<long long>& balance) {
        accountNum = balance.size();
        balances = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1 > accountNum || account2 > accountNum) return false;

        if(balances[account1-1] < money) return false;
        balances[account1-1] -= money;
        balances[account2-1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(account > accountNum) return false;
        balances[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account > accountNum) return false;
        if(balances[account-1] < money) return false;
        balances[account-1] -= money;
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