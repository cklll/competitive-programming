// https://leetcode.com/problems/candy/?envType=study-plan-v2&envId=top-interview-150

package main

import (
	"fmt"
)

func candy(ratings []int) int {
	// strategy: 2 passes.
	// 1st pass: ensure right higher than left
	// 2nd pass: ensure left higher than right
	candies := make([]int, len(ratings))

	for i, rating := range ratings {
		if i == 0 {
			candies[0] = 1
			continue
		}

		if rating > ratings[i-1] {
			candies[i] = candies[i-1] + 1
		} else {
			candies[i] = 1
		}
	}

	for i := len(ratings) - 2; i >= 0; i-- {
		if ratings[i] > ratings[i+1] {
			candies[i] = max(candies[i], candies[i+1]+1)
		}
	}

	result := 0

	for _, candy := range candies {
		result += candy
	}
	return result
}

func main() {
	ratings1 := []int{1, 0, 2}
	ratings2 := []int{1, 2, 2}
	fmt.Println(candy(ratings1))
	fmt.Println(candy(ratings2))
}
