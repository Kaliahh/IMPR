#!/bin/bash
ping -c 3 www.google.com #> /dev/null 2>/dev/null
if [ $? != 0 ]
then
    echo "Your site seems to be down"
fi
