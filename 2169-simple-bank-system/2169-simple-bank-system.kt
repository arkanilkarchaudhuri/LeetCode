class Bank(
    balance: LongArray
) {
    private val accounts = Array<Account>(balance.size + 1) {
        if (it == 0) Account(0L)
        else Account(balance[it - 1])
    }

    fun transfer(a: Int, b: Int, money: Long): Boolean {
        return if (a < accounts.size && b < accounts.size) accounts[a].transfer(accounts[b], money) else false
    }

    fun deposit(a: Int, money: Long): Boolean {
        return if (a < accounts.size) accounts[a].deposit(money) else false
    }

    fun withdraw(a: Int, money: Long): Boolean {
        return if (a < accounts.size) accounts[a].withdraw(money) else false
    }
}

private class Account(var balance: Long) {
    fun transfer(other: Account, money: Long): Boolean {
        if (balance >= money) {
            balance -= money
            other.balance += money
            return true
        }
        return false
    }

    fun deposit(money: Long): Boolean {
        balance += money
        return true
    }

    fun withdraw(money: Long): Boolean {
        if (balance >= money) {
            balance -= money
            return true
        }
        return false
    }
}