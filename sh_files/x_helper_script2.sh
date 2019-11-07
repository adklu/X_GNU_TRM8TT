#!/bin/sh
# path to edit... (username... path to release build...)
echo x_helper_script Test from 2
#ps -ef | grep GNU_TRM8TT | grep -v grep | awk '{print $2}' | xargs kill
#kill -9 $(ps -ef | grep "GNU_TRM8TT" | grep -v grep | awk '{print $2}')
if pgrep GNU_TRM8TT; then pkill GNU_TRM8TT; fi
sleep 1s
if pgrep ecasound; then pkill ecasound; fi
sleep 1s
if pgrep GNU_TRM8TT; then pkill GNU_TRM8TT; fi
sleep 1s
#ps -ef | grep ecasound | grep -v grep | awk '{print $2}' | xargs kill
#kill -9 $(ps -ef | grep "ecasound" | grep -v grep | awk '{print $2}')
if pgrep ecasound; then pkill ecasound; fi
sleep 1s
/home/username/build-GNU_TRM8TT-Debian9-Release/GNU_TRM8TT
