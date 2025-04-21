
/*1. Code-Level Optimizations
✅ Avoid Unnecessary Copies
Use references or move semantics where appropriate.*/
void process(const string& s); // good: no copy
void process(string s);        // bad: copy

/*2.Use std::move() for large objects when transferring ownership: 
*/
string s = "big data";
vector<string> v;
v.push_back(move(s));

// 3. Prefer Pre-Allocation
// Avoid dynamic memory resizing in loops.
vector<int> v;
v.reserve(10000); // avoid reallocating while pushing

// 4. Use Appropriate Data Structures
// Choose wisely:
// unordered_map over map if you don’t need ordering.
// vector over list if you need fast indexing.
// array if size is fixed and known at compile time.

2. Compiler-Level Optimization
// 1. Use optimization flags when building:
These O2,O3,Ofast flags control the level of optimization the compiler applies during the build process. 
Here's what each of them does in GCC/g++:
Flag	  Optimization Level	             Safe	     Fast   	May Break Standards
-O0	    No optimization (default)	       ✅	       🚫	         ❌
-O1	    Basic optimization	             ✅	       ✅	         ❌
-O2	    Balanced, safe optimizations	   ✅	       ✅✅	     ❌
-O3	    Aggressive optimizations	       ✅	       ✅✅✅	   ❌
-Ofast	Max speed (may ignore rules)	   🚫	       🔥🔥🔥	   ✅✅✅ (but risky)

g++ -O2 main.cpp -o app       # good balance
g++ -O3 main.cpp -o app       # aggressive (faster, but bigger)
g++ -Ofast main.cpp -o app    # very aggressive (may break strict standards)

// 2. Multithreading for Performance
// Use multiple threads or cores to do work in parallel:
// std::thread or std::async for concurrency.
// Use thread pools for high-frequency task execution.
// Lock only what's necessary, avoid over-locking.

mutex m;
void safeWork() {
    lock_guard<mutex> lock(mutex1);
    // Critical section
}

// 3.Algorithm and Complexity
// This matters more than anything. Example:
// Inefficient
for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        sum += a[i] * b[j];

// Optimized with better math or caching
// Use STL algorithms — they’re highly optimized:
sort(v.begin(), v.end());  // Fast & optimized

// Quick Win Checklist
// Technique	Benefit
// emplace_back() over push_back()	 - Avoids temp object
// reserve() for containers	         -Reduces reallocations
// Inline small functions	           -Removes call overhead
// Reduce virtual calls	             -Avoid vtables where possible
// Use constexpr where possible	     -Compile-time computation

  
