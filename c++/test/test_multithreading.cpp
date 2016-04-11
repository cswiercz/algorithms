#include <chrono>
#include <cstddef>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

static std::mutex barrier;

template <class T>
std::vector<T> bounds(T parts, T mem)
{
  std::vector<T>bnd;
  int delta = mem / parts;
  int reminder = mem % parts;
  int N1 = 0, N2 = 0;
  bnd.push_back(N1);
  for (size_t i = 0; i < parts; ++i) {
    N2 = N1 + delta;
    if (i == parts - 1)
      N2 += reminder;
    bnd.push_back(N2);
    N1 = N2;
  }
  return bnd;
}

template <class T>
void dot_product(const std::vector<T>& v1, const std::vector<T>& v2, T& result,
                 size_t left, size_t right)
{
  T partial_sum(0);
  for(size_t i=left; i<right; ++i)
    partial_sum += v1[i] * v2[i];

  std::lock_guard<std::mutex> block(barrier);
  result += partial_sum;
}

int main(int argc, char** argv)
{
  size_t num_elements = 100000;
  size_t num_threads = 4;
  int result = 0;
  std::vector<std::thread> threads;

  std::vector<int> v1(num_elements, 1);
  std::vector<int> v2(num_elements, 2);

  // split num_elements into num_threads parts
  auto limits = bounds(num_threads, num_elements);

  // launch threads
  for(size_t i=0; i<num_threads; ++i)
    {
      threads.push_back(std::thread(
        dot_product<int>,
        std::ref(v1),
        std::ref(v2),
        std::ref(result),
        limits[i],
        limits[i+1]));
    }

  // join
  for (auto& t : threads)
    t.join();

  std::cout << result << std::endl;
  return 0;
}

// void func(size_t tid)
// {
//   std::this_thread::sleep_for(std::chrono::seconds(1));
//   std::cout << tid;
// }

// int main(int argc, char** argv)
// {
//   // set number of threads from command line (default: 2)
//   size_t num_threads(2);
//   if (argc > 1)
//     num_threads = atoi(argv[1]);

//   // launch a group of threads by emplacing them in the thread vector
//   std::vector<std::thread> threads;
//   for (size_t i=0; i < num_threads; ++i)
//     threads.emplace_back(std::thread(func,i));

//   // join threads with the main thread
//   for (auto& t : threads)
//     t.join();

//   return 0;
// }
