#include <iostream>
#include <time.h>
void stack_dynamic_array();
void static_array();
void explicit_heap_dynamic_array();

const int ITERATIONS = 100000;
const int ARRAY_SIZE = 10000;

// const int start, stop;
int main() {
    clock_t startTime = clock();
    //stack
    // record start time
  for(int i = 0; i < ITERATIONS; i++)
    stack_dynamic_array();
  //stop timer
    clock_t stopTime = clock();
    // ms
    clock_t stack_in_ms = stopTime - startTime;
    // s
    double stack_in_s = (double)(stack_in_ms / CLOCKS_PER_SEC);
  // print time
	std::cout << "The time required by stack: " << stack_in_s << "s and " << stack_in_ms << "ms" << "\n";
    
    
    
    //array
    // unsigned int startTime, stopTime;
    startTime = clock();
  //time for stack static_array
  for(int i = 0; i < ITERATIONS; i++)
    static_array();
  //stop timer
  stopTime = clock();
    clock_t array_in_ms = stopTime - startTime;
    double array_in_s = (double)(array_in_ms / CLOCKS_PER_SEC);
  // print time
	std::cout << "The time required by static_array: " << array_in_s << "s and " << array_in_ms << "ms" << "\n";




    //heap
  //time for stack explicit_heap_dynamic_array
  startTime = clock();
  for(int i = 0; i < ITERATIONS; i++)
    explicit_heap_dynamic_array();
  //stop timer
  stopTime = clock();
  clock_t heap_in_ms = stopTime - startTime;
  double heap_in_s = (double)(heap_in_ms / CLOCKS_PER_SEC);
  // print time
  	std::cout << "The time required by heap: " << heap_in_s << "s and " << heap_in_ms << "ms" << "\n";

}

// stack
void stack_dynamic_array(){
  int stack_dynamic_array[ARRAY_SIZE];

}

// array
void static_array(){
  static int static_array[ARRAY_SIZE];

}

// heap
void explicit_heap_dynamic_array(){
  int *explicit_heap_dynamic_array = new int[ARRAY_SIZE];
}