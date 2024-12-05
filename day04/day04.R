data <- readLines("input.txt") %>%
  str_split("", simplify = TRUE)

XMAS <- c("X", "M", "A", "S")
dir <- list(
  c( 1,  1),
  c( 1, -1),
  c(-1,  1),
  c(-1, -1),
  c( 0,  1),
  c( 0, -1),
  c( 1,  0),
  c(-1,  0)
)
xmas_checker <- function(dir, x, y, current_letter, dimx, dimy) {
  if (data[y, x] == "S" && current_letter == 4)
    return(TRUE)

  if (data[y, x] == XMAS[current_letter]) {
    x <- x + dir[1]
    y <- y + dir[2]

    if (x > dimx || y > dimy || x < 1 || y < 1)
      return(FALSE)
    else
      return(xmas_checker(dir, x, y, current_letter + 1, dimx, dimy))
  } else {
    return(FALSE)
  }
}

xmas_count <- 0
for (x in 1:ncol(data)) {
  for (y in 1:nrow(data)) {
    for (d in dir) {
      if (data[y, x] == XMAS[1] & xmas_checker(d, x, y, 1, ncol(data), nrow(data))) {
        xmas_count <- xmas_count + 1
      }
    }
  }
}

# Part 2
xmas_checker2 <- function(x, y, dimx, dimy) {
  if (x >= dimx || y >= dimy || x <= 1 || y <= 1) {
    return(FALSE)
  }

  check1 <- FALSE
  check2 <- FALSE
  if ( (data[y+1, x+1] == "S" && data[y-1, x-1] == "M") ||
       (data[y+1, x+1] == "M" && data[y-1, x-1] == "S") ) {
    check1 <- TRUE
  }
  if ( (data[y+1, x-1] == "S" && data[y-1, x+1] == "M") ||
       (data[y+1, x-1] == "M" && data[y-1, x+1] == "S") ) {
    check2 <- TRUE
  }
  if (check1 && check2)
    return(TRUE)
  else
    return(FALSE)
}

xmas_count2 <- 0
for (x in 1:ncol(data)) {
  for (y in 1:nrow(data)) {
    if (data[y, x] == "A" & xmas_checker2(x, y, ncol(data), nrow(data))) {
      xmas_count2 <- xmas_count2 + 1
    }
  }
}