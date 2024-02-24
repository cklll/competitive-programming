// https://leetcode.com/problems/text-justification/submissions/?envType=study-plan-v2&envId=top-interview-150

package main

import (
	"fmt"
	"strings"
)

func padLine(words *[]string, wordsLength int, finalWidth int) string {
	spacesToAdd := finalWidth - wordsLength

	if len(*words) == 1 {
		return (*words)[0] + strings.Repeat(" ", spacesToAdd)
	}

	quotient := spacesToAdd / (len(*words) - 1)
	remainder := spacesToAdd % (len(*words) - 1)

	result := ""

	for idx, word := range *words {
		result += word

		if idx != (len(*words) - 1) {
			result += strings.Repeat(" ", quotient)

			if idx < remainder {
				result += " "
			}
		}
	}
	return result
}

func padLastLine(words *[]string, finalWidth int) string {
	currentWidth := 0
	result := ""
	for idx, word := range *words {
		result += word
		currentWidth += len(word)

		if idx != len(*words) - 1 {
			result += " "
			currentWidth += 1
		}
	}

	result += strings.Repeat(" ", finalWidth - currentWidth)

	return result
}

func fullJustify(words []string, maxWidth int) []string {
	result := []string{}
	currentLength := 0
	currentWords := []string{}

	for _, word := range words {
		if currentLength + len(word) + len(currentWords) - 1 >= maxWidth {
			result = append(result, padLine(&currentWords, currentLength, maxWidth))

			currentLength = 0
			currentWords = []string{}
		}
		currentWords = append(currentWords, word)
		currentLength += len(word)
	}

	result = append(result, padLastLine(&currentWords, maxWidth))

	return result
}

func printResult(words []string) {
	for _, word := range words {
		fmt.Println(word)
		// fmt.Println(len(word))
	}
}

func main() {
	words := []string{
		"This", "is", "an", "example", "of", "text", "justification.",
	}

	printResult(fullJustify(words, 16))

	words = []string{
		"What","must","be","acknowledgment","shall","be",
	}
	printResult(fullJustify(words, 16))

	words = []string{
		"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do",
	}
	printResult(fullJustify(words, 20))
}
