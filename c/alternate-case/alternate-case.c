char *alternateCase (char *string) {
  char *pointer = string;
  while (*pointer) {
    if (*pointer >= 'A' && *pointer <= 'Z') {
      *pointer += 'a' - 'A';
    } else if (*pointer >= 'a' && *pointer <= 'z') {
      *pointer += 'A' - 'a';
    }
    pointer++;
  }
  return string;
}
