package kata

func Solution(str string) []string {
  if (len(str) % 2 == 1) {
    str = str + "_"
  }
  ret := make([]string, len(str) / 2)
  for i, c := range str {
    ret[i / 2] = ret[i / 2] + string(c)
  }
  return ret
}
