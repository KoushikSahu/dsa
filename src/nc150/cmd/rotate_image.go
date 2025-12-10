package main

func rotate(matrix [][]int) [][]int {
	n := len(matrix)
	m := len(matrix[0])
	for i := range n {
		for j := range m {
			if i < j {
				matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
			}
		}
		l, h := 0, m - 1
		for l < h {
			matrix[i][l], matrix[i][h] = matrix[i][h], matrix[i][l]
			l += 1
			h -= 1
		}
	}
	return matrix
}
