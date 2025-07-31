Common Strategies:
Lock ordering (most practical)
Always acquire locks in a fixed global order.

Example: if both threads need mutex1 and mutex2, always lock mutex1 
before mutex2.

Try-lock with timeout
Use std::try_lock or timed mutexes.
If you can’t acquire all locks, release what you hold and retry.
Prevents indefinite waiting.
  
Deadlock detection
Monitor resource wait graphs, detect cycles, 
and abort/restart one of the threads.

Often used in databases.

Reduce resource locking
Use finer-grained locks or lock-free data structures
(std::atomic, lock-free queues).
Reduces the chance of cycles forming.
