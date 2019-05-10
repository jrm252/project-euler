package main

import "fmt"

func main() {
	fmt.Printf("Project Euler\n")
	problem1()
	problem2()
	problem3()
}

func problem3() {
	//What is the largest prime factor of the number 600851475143 ?
	sum := 0
	fmt.Printf("Problem 2: %1d \n", sum)
}

func problem2() {
	sum := 0
	fib1 := 1
	fib2 := 2
	fibNext := -1
	for {
		if fib2%2 == 0 {
			sum += fib2
		}

		fibNext = fib1 + fib2
		if fibNext > 4000000 {
			break
		}
		fib1 = fib2
		fib2 = fibNext
	}

	fmt.Printf("Problem 2: %1d \n", sum)
}

func problem1() {
	var sum int = 0

	for i := 0; i < 1000; i++ {
		if i%3 == 0 || i%5 == 0 {
			sum += i
		}
	}

	fmt.Printf("Problem 1: %1d \n", sum)
}
