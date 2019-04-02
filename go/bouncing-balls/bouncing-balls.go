package kata

func BouncingBall(height, bounce, window float64) int {
  if (height <= 0 || window >= height || bounce <= 0 || bounce >= 1) {
    return -1
  }
  return 2 + BouncingBall(height * bounce, bounce, window)
}
