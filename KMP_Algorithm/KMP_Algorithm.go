package algorithmStudy

func KmpSearch(str string, target string) (bool, int) {
	if len(target) > len(str) {
		return false, 0
	}

	pi := newPi(target)

	iter := 0
	for iter <= len(str)-len(target) {

		for str[iter] != target[0] && iter <= len(str)-len(target) {
			iter++
		}

		matchCount := 1
		for matchCount < len(target) {
			if target[matchCount] != str[iter+matchCount] {
				break
			}
			matchCount++
		}
		if matchCount == len(target) {
			return true, iter
		}

		iter += matchCount - pi[matchCount]
	}

	return false, 0
}

func newPi(target string) []int {
	targLen := len(target)
	pi := make([]int, targLen+1)
	pi[0] = 0
	pi[1] = 0

	makePi := func(str string) int {
		strLen := len(str)
		count := 1

		for count <= strLen/2 {
			if str[:count] != str[strLen-count:] {
				break
			}
			count++
		}

		return count - 1
	}

	for i := 2; i <= targLen; i++ {
		pi[i] = makePi(target[:i])
	}

	return pi
}
