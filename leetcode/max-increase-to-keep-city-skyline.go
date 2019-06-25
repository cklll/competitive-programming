// https://leetcode.com/problems/max-increase-to-keep-city-skyline/submissions/

func maxIncreaseKeepingSkyline(grid [][]int) int {
	numOfRow := len(grid)
	numOfCol := len(grid[0])

	tallestOfEachRow := make([]int, numOfRow)
	tallestOfEachCol := make([]int, numOfCol)

	for i := 0; i < numOfRow; i++ {
			tallestOfEachRow[i] = 0
	}
	for i := 0; i < numOfCol; i++ {
			tallestOfEachCol[i] = 0
	}

	for i := 0; i < numOfRow; i++ {
			for j := 0; j < numOfRow; j++ {
					if tallestOfEachRow[i] < grid[i][j] {
							tallestOfEachRow[i] = grid[i][j]
					}
					if tallestOfEachCol[j] < grid[i][j] {
							tallestOfEachCol[j] = grid[i][j]
					}
			}
	}

	result := 0
	for i := 0; i < numOfRow; i++ {
			for j := 0; j < numOfRow; j++ {
					max1 := tallestOfEachRow[i]
					max2 := tallestOfEachCol[j]

					if max1 < max2 {
							result += max1 - grid[i][j]
					} else {
							result += max2 - grid[i][j]
					}
			}
	}

	return result
}
