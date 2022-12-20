package algorithmStudy

import (
	"fmt"
	"testing"
)

func TestKmpSearch(t *testing.T) {
	str := "takemyheartandpleasedontbreakit"
	target := "heart"
	b, index := KmpSearch(str, target)
	fmt.Println(b, index)
	if b != true || index != 6 {
		t.Errorf("TestKmpSearch failed.")
	}

}

func TestNewPi(t *testing.T) {
	str := "ABBA"
	pi := newPi(str)

	if pi[0] != 0 ||
		pi[1] != 0 ||
		pi[2] != 0 ||
		pi[3] != 0 ||
		pi[4] != 1 {
		t.Errorf("TestNewPi failed.")
	}
}
