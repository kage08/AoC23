package main

// Import standard packages
import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func check(input string) int {
	parts := strings.Split(input, ":")
	// gameNum, _ := strconv.Atoi(strings.TrimSpace(parts[0][5:]))
	teams := strings.Split(parts[1], ";")

	maxRed, maxGreen, maxBlue := 0, 0, 0
	for _, team := range teams {
		red, green, blue := 0, 0, 0
		cubes := strings.Split(team, ",")
		for _, cube := range cubes {
			parts := strings.Fields(cube)
			num, _ := strconv.Atoi(parts[0])
			color := parts[1]
			switch color {
			case "red":
				red += num
			case "green":
				green += num
			case "blue":
				blue += num
			}
		}
		if red > maxRed {
			maxRed = red
		}
		if green > maxGreen {
			maxGreen = green
		}
		if blue > maxBlue {
			maxBlue = blue
		}
	}

	//if maxRed <= 12 && maxGreen <= 13 && maxBlue <= 14 {
	return maxBlue * maxGreen * maxRed
	//}
	//return 0
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	total := 0
	for scanner.Scan() {
		line := scanner.Text()
		total += check(line)
	}
	if err := scanner.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "reading standard input:", err)
	}
	fmt.Println(total)
}
