# SQL

## ACID

- Atomicity: it can manage a set of operations as a single "unit", so either everything succeeds or everything is aborted and comes back to the previous state
for example - bank transactions, if one account transfers x dollars to another account, either the transaction works as a whole or nothing gets transferred,
this way it protects both accounts as if one account has a debit and the other does not get a credit, it screws up the transaction

- Consistency: basically, things are only saved if they respect all kinds of requirements defined by the database administrator

- Isolation: you can have 10 people working on the same database simultaneously and the resulting state is exactly the one you expect if those 10 people worked on the database one by one

- Durability.Things are actually saved in a non-volatile memory (so not just in RAM).
