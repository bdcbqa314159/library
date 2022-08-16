#include <cppTutorial1>
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <cmath>
#include <iomanip>
#include <future>
#include <exception>
#include <condition_variable>
#include <queue>

using namespace std;

void work()
{
      for (int i = 0; i < 10; i++)
      {
            this_thread::sleep_for(chrono::milliseconds(500));
            cout << "Loop " << i << endl;
      }
}

void basics()
{
      thread t1(work);
      thread t2(work);
      t1.join();
      t2.join();
}

void shared_data()
{
      // One solution.
      // int count = 0;
      atomic count = 0;
      const int ITERATIONS = 1000;

      thread t1([&count]()
                {
                      for (int i = 0; i < ITERATIONS; i++)
                      {
                            ++count;
                      } });

      thread t2([&count]()
                {
                      for (int i = 0; i < ITERATIONS; i++)
                      {
                            ++count;
                      } });
      t1.join();
      t2.join();

      cout << count << endl;
      // We don't have always 2*ITERATIONS here.
      // One thread copies the value and the other thread the same.
      // They increment them within the copies.
      // The shared_data brings problems.
      // Atomic could solve this issue in this case NOT in GENERAL => mutexes.
}

void mutexes()
{
      int count = 0;

      const int ITERATIONS = 1000000;

      mutex mtx;

      auto f = [&]()
      {
                      for (int i = 0; i < ITERATIONS; i++)
                      { 
                        mtx.lock();
                        ++count;
                        mtx.unlock();
                        // With this the sharing data behaves as expected. Only one thread can lock the variable.
                        // Without unlock we will head to a inifinite loop.
                        // The threads don't interfere with each others.

                      } };

      thread t1(f);

      thread t2(f);
      t1.join();
      t2.join();

      cout << count << endl;
}

void work2(int &count, mutex &mtx)
{
      for (int i = 0; i < 1E6; i++)
      {
            mtx.lock();
            ++count;
            mtx.unlock();
      }
}

void functionArguments()
{
      int count = 0;

      const int ITERATIONS = 1000000;

      mutex mtx;

      // ref if we want to pass them by ref within threads
      thread t1(work2, ref(count), ref(mtx));

      thread t2(work2, ref(count), ref(mtx));
      t1.join();
      t2.join();

      cout << count << endl;
}

void work3(int &count, mutex &mtx)
{
      for (int i = 0; i < 1E6; i++)
      {
            // unique_lock<mutex> guard(mtx) gives same result but it has more methods. To keep it simple we  use lock_guard.
            lock_guard<mutex> guard(mtx);
            ++count;
      }
}

void locking()
{
      int count = 0;

      const int ITERATIONS = 1000000;

      mutex mtx;

      // ref if we want to pass them by ref within threads
      thread t1(work3, ref(count), ref(mtx));

      thread t2(work3, ref(count), ref(mtx));
      t1.join();
      t2.join();

      cout << count << endl;
}

class App
{
public:
      int count = 0;
      mutex mtx;

public:
      void operator()()
      {
            for (int i = 0; i < 1E6; i++)
            {
                  lock_guard<mutex> guard(mtx);
                  ++count;
            }
      }
      int getCount()
      {
            return count;
      }
};

void threadsCallable()
{
      App app;

      const int ITERATIONS = 1000000;

      thread t1(ref(app));

      thread t2(ref(app));
      t1.join();
      t2.join();

      cout << app.getCount() << endl;
}

double calculate_pi(int terms)
{
      double answer = 0.;
      if (terms < 1)
      {
            throw runtime_error("Terms cannot be less than 1");
      }

      for (int i = 0; i < terms; i++)
      {
            int sign = i % 2 == 0 ? 1 : -1;
            double term = 1. / (2 * i + 1);
            answer += sign * term;
      }

      return 4. * answer;
}

void promisesFutures()
{
      // Without multi threading it is long...
      // cout << setprecision(15);
      // cout << calculate_pi(1E7) << endl;

      promise<double> promise;
      auto do_calculation = [&](int terms)
      {
            auto result = calculate_pi(terms);
            promise.set_value(result);
      };

      thread t1(do_calculation, 1E9);
      future<double> future = promise.get_future();
      cout << setprecision(15);
      cout << future.get() << endl;

      t1.join();
}

void exceptions()
{
      promise<double> promise;
      auto do_calculation = [&](int terms)
      {
            try
            {
                  auto result = calculate_pi(terms);
                  promise.set_value(result);
            }
            catch (...)
            {
                  promise.set_exception(current_exception());
            }
      };

      thread t1(do_calculation, 1E6);
      future<double> future = promise.get_future();

      try
      {
            cout << setprecision(15);
            cout << future.get() << endl;
      }
      catch (const exception &e)
      {
            cout << e.what() << endl;
      }

      t1.join();
}

void packagingTasks()
{

      packaged_task<double(int)> task1(calculate_pi);
      future<double> future1 = task1.get_future();
      thread t1(move(task1), 1E6);

      try
      {
            double result = future1.get();
            cout << setprecision(15) << result << endl;
      }
      catch (exception &e)
      {
            cout << "ERROR: " << e.what() << endl;
      }

      t1.join();
}

void waitingForThreads()
{
      atomic<bool> ready = false;

      thread t1([&]()
                { 
                  this_thread::sleep_for(chrono::milliseconds(2000));
                  ready = true; });

      t1.join();

      while (!ready)
      {
            this_thread::sleep_for(chrono::milliseconds(100));
      }

      cout << "ready " << ready << endl;
}

void conditions()
{
      condition_variable condition;
      mutex mtx;

      bool ready = false;

      thread t1([&]()
                { 
                  this_thread::sleep_for(chrono::milliseconds(2000));
                  unique_lock<mutex> lock(mtx);
                  ready = true;
                  lock.unlock();
                  condition.notify_one(); });

      unique_lock<mutex> lock(mtx);
      while (!ready)
      {
            condition.wait(lock);
      }

      cout << "ready " << ready << endl;

      t1.join();
}

void checkingConditionSharedRessources()
{
      condition_variable condition;
      mutex mtx;

      bool ready = false;

      thread t1([&]()
                { 
                  this_thread::sleep_for(chrono::milliseconds(2000));
                  cout<<"t1 acquiring lock"<<endl;
                  unique_lock<mutex> lock(mtx);
                  cout<<"t1 acquired lock"<<endl;
                  ready = true;
                  lock.unlock();
                  cout<<"t1 released lock, notifying"<<endl;
                  condition.notify_one(); });

      cout << "main thread acquiring lock" << endl;
      unique_lock<mutex> lock(mtx);

      cout << "main thread acquired lock, waiting" << endl;
      condition.wait(lock, [&]()
                     { return ready; });

      cout << "main thread finished waiting" << endl;
      cout << "ready " << ready << endl;

      t1.join();
}

template <class E>
class blocking_queue
{
      int max_size;
      queue<E> mq;
      mutex mtx;
      condition_variable cond;

public:
      blocking_queue(int max_size) : max_size(max_size)
      {
      }
      void push(E e)
      {
            unique_lock<mutex> lock(mtx);
            cond.wait(lock, [this]()
                      { return mq.size() < max_size; });
            mq.push(e);
            lock.unlock();
            cond.notify_one();
            cout << "push" << endl;
            return;
      }

      E front()
      {
            unique_lock<mutex> lock(mtx);
            cond.wait(lock, [this]()
                      { return !mq.empty(); });
            E item = mq.front();

            return item;
      }

      void pop()
      {
            unique_lock<mutex> lock(mtx);
            cond.wait(lock, [this]()
                      { return !mq.empty(); });
            mq.pop();

            lock.unlock();
            cond.notify_one();

            cout << "pop" << endl;
      }

      int size()
      {
            lock_guard<mutex> lock(mtx);
            return mq.size();
      }
};

void queues()
{
      blocking_queue<int> q(5);

      // This does not work with consistency

      thread t1([&]()
                {
            for (int i = 0; i<10; i++){
                  cout<<"pushing "<<i<<endl;
                  cout<<"queue size: "<<q.size()<<endl;
                  q.push(i);
            } });

      thread t2([&]()
                {
            for (int i = 0; i<10; i++){
                  auto item = q.front();
                  q.pop();
                  cout<<"consumed "<<i<<endl;
            } });

      t1.join();
      t2.join();
}

void anotherWork()
{
      for (int i = 0; i < 5; i++)
      {
            cout << "running..." << endl;
            this_thread::sleep_for(chrono::microseconds(1000));
      }
}

int anotherWork1(int id)
{
      for (int i = 0; i < 5; i++)
      {
            cout << "running..." << endl;
            this_thread::sleep_for(chrono::microseconds(1000));
      }
      return id * 7;
}

void asyncTest()
{
      future<void> f1 = async(launch::async, anotherWork);
      future<void> f2 = async(launch::async, anotherWork);
      f1.get();
      f2.get();

      future<int> f3 = async(launch::async, anotherWork1, 0);
      future<int> f4 = async(launch::async, anotherWork1, 1);

      f3.get();
      f4.get();
}

mutex g_mtx;

int task1(int id)
{
      unique_lock<mutex> lock(g_mtx);
      cout << "Starting " << id << endl;
      lock.unlock();
      this_thread::sleep_for(chrono::seconds(3));

      return id;
}

int task2(int id)
{
      unique_lock<mutex> lock(g_mtx);
      cout << "Starting " << id << endl;
      lock.unlock();
      int seconds = (int)(5. * rand()) / RAND_MAX + 3;
      this_thread::sleep_for(chrono::seconds(seconds));

      return id;
}

void lotsOfThreads()
{
      cout << "Cores for threading: " << endl;
      cout << thread::hardware_concurrency() << endl;

      vector<shared_future<int>> futures;

      for (int i = 0; i < thread::hardware_concurrency(); i++)
      {
            shared_future<int> f = async(launch::async, task1, i);
            futures.push_back(f);
      }

      for (auto f : futures)
      {
            cout << "Returned: " << f.get() << endl;
      }
}

void threadPool()
{
      blocking_queue<shared_future<int>> futures(2);

      thread t1([&]()
                { for (int i = 0; i < 20; i++)
                        {
                              shared_future<int> f = async(launch::async, task2, i);
                              futures.push(f);
      } });

      for (int i = 0; i < 20; i++)
      {
            shared_future<int> f = futures.front();
            int value = f.get();
            futures.pop();
            cout << "Returned" << value << endl;
      }
      t1.join();
}

double calculate_pi1(int terms, int start, int skip)
{
      double answer = 0.;
      if (terms < 1)
      {
            throw runtime_error("Terms cannot be less than 1");
      }

      for (int i = start; i < terms; i += skip)
      {
            int sign = i % 2 == 0 ? 1 : -1;
            double term = 1. / (2 * i + 1);
            answer += sign * term;
      }

      return 4. * answer;
}

int main()
{

      vector<shared_future<double>> futures;
      const int CONCURRENCY = thread::hardware_concurrency();

      auto start = chrono::steady_clock::now();

      for (int i = 0; i < CONCURRENCY; i++)
      {
            shared_future<double> f = async(launch::async, calculate_pi1, 1E7, i, CONCURRENCY);
            futures.push_back(f);
      }

      double sum = 0.;
      for (auto f : futures)
      {
            sum += f.get();
      }

      auto end = chrono::steady_clock::now();

      cout << setprecision(15) << endl;
      cout << "PI: " << M_PI << endl;
      cout << "Calculated PI: " << sum << endl;
      auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
      cout << "Computation done in " << duration << " ms" << endl;

      return 0;
}