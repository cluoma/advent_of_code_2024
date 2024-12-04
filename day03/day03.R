data <- readLines("input.txt") %>%
  paste0(collapse = "")

instr <- str_extract_all(data, "(mul\\([0-9]{1,3},[0-9]{0,3}\\))", simplify = TRUE)

total <- 0
for (x in instr) {
  print(x)
  t <- str_extract_all(x, "[0-9]{0,3}", simplify = TRUE) %>%
    as.integer() %>%
    prod(na.rm=TRUE)
  total <- total + t
}

# Part 2
instr <- str_extract_all(data, "(mul\\([0-9]{1,3},[0-9]{0,3}\\))|(do\\(\\))|(don't\\(\\))", simplify = TRUE)

total <- 0
on <- TRUE
for (x in instr) {
  if (x == "do()") {
    on <- TRUE
    next
  }
  else if (x == "don't()") {
    on <- FALSE
    next
  }

  if (on == TRUE) {
    print(x)
    t <- str_extract_all(x, "[0-9]{0,3}", simplify = TRUE) %>%
      as.integer() %>%
      prod(na.rm=TRUE)
    total <- total + t
  }
}
total