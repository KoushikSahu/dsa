package main

type OrangeType int

const (
	Empty OrangeType = iota
	Fresh
	Rotten
)

func hasAdjacentRotten(i int, j int, grid [][]int) bool {
	n := len(grid)
	m := len(grid[0])
	return ((i > 0 && grid[i-1][j] == int(Rotten)) ||
		(i < n - 1 && grid[i+1][j] == int(Rotten)) ||
		(j > 0 && grid[i][j-1] == int(Rotten)) ||
		(j < m - 1 && grid[i][j+1] == int(Rotten)))
}

type Coordinates struct {
    X int
    Y int
}

func orangesRotting(grid [][]int) int {
	n := len(grid)
	m := len(grid[0])
	ans := 0
	shouldTerminate := false
	for ans < 100 {
		if !shouldTerminate {
			madeChange := false
            toUpdate := []Coordinates{}
			for i := 0; i < n; i++ {
				for j := 0; j < m; j++ {
					if grid[i][j] == int(Fresh) && hasAdjacentRotten(i, j, grid) {
                        toUpdate = append(toUpdate, Coordinates{i, j})
						madeChange = true
					}
				}
			}
            for _, c := range toUpdate {
                grid[c.X][c.Y] = int(Rotten)
            }
			if !madeChange {
				shouldTerminate = true
			}
		} else {
			break
		}
        ans += 1
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if grid[i][j] == int(Fresh) {
                return -1
			}
		}
	}
	return ans - 1
}
