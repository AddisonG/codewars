package kata

func SumMultiples(number, multiple int) int {
  if (number <= 0) {
    return 0
  }
  count := float64(number / multiple)
  return int(count * (count + 1.0) * float64(multiple) / 2.0)
}

func Multiple3And5(number int) int {
  number--
  return SumMultiples(number, 3) + SumMultiples(number, 5) - SumMultiples(number, 15)
}
