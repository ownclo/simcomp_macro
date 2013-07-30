#!/bin/bash

set -e

CMD_NAME=./bin/macro

IN_PATTERN=_in.asm
OUT_PATTERN=_out.asm
EXP_PATTERN=_expect.asm
INFILES=fixture/*$IN_PATTERN

# $1 -- infile
# $2 -- outfile
# $3 -- expected_outfile
integration_test () {
    $CMD_NAME $1 $2
    diff $2 $3
}

count=0
for infile in $INFILES; do
    template=${infile%$IN_PATTERN}
    outfile=$template$OUT_PATTERN
    expected=$template$EXP_PATTERN

    integration_test $infile $outfile $expected
    echo -n "."
    count=$((count+1))
done

echo
echo "SUCCESSFULLY PASSED" $count "TESTS"
