package main

import (
	"flag"
	"fmt"
	"strings"
	"sync"
	"strconv"
)

func generatePermutations(numbers []int, resultChan chan<- []int, wg *sync.WaitGroup) {
	defer wg.Done()

	// Helper function to generate permutations recursively
	var permute func([]int, int)
	permute = func(arr []int, i int) {
		if i == len(arr) {
			// Send the current permutation to the channel
			resultChan <- append([]int(nil), arr...) // sending a copy of arr
			return
		}
		for j := i; j < len(arr); j++ {
			// Swap
			arr[i], arr[j] = arr[j], arr[i]
			permute(arr, i+1)
			// Swap back
			arr[i], arr[j] = arr[j], arr[i]
		}
	}

	// Generate permutations for the list of numbers
	permute(numbers, 0)
}

func main() {
	// Parse the command-line argument
	n := flag.Int("n", 0, "The number up to which permutations will be generated (1 to n).")
	flag.Parse()

	if *n <= 0 {
		fmt.Println("Please provide a valid positive integer for n.")
		return
	}

	// Create the list of numbers from 1 to n
	numbers := make([]int, *n)
	for i := 0; i < *n; i++ {
		numbers[i] = i + 1
	}

	// Channel to receive permutations and wait group for synchronization
	resultChan := make(chan []int)
	var wg sync.WaitGroup

	// Launch the permutation generator goroutine
	wg.Add(1)
	go generatePermutations(numbers, resultChan, &wg)

	// Wait for all goroutines to finish and print the results
	go func() {
		wg.Wait()
		close(resultChan) // Close the channel after all goroutines are done
	}()

	// Print the permutations as they come, space-separated without brackets
	for perm := range resultChan {
		// Convert each element to string and join them with space
		var strPerm []string
		for _, num := range perm {
			strPerm = append(strPerm, strconv.Itoa(num))
		}
		// Join the slice of strings with spaces
		fmt.Println(strings.Join(strPerm, " "))
	}
}
