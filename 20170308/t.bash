#!/bin/sh
if [ "$TERM" = "linux" ]; then
  /bin/echo -e "
  \e]P0292929
  \e]P1cf6a4c
  \e]P219cb00
  \e]P3fad07a
  \e]P48197bf
  \e]P58787af
  \e]P6668799
  \e]P7888888
  \e]P8525252
  \e]P9ff9d80
  \e]PA23fd00
  \e]PBffefbf
  \e]PCaccaff
  \e]PDc4c4ff
  \e]PE80bfaf
  \e]PFe8e8d3
  "
  # get rid of artifacts
  clear
fi
