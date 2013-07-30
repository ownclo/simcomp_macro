#!/bin/bash

set -e

INFILE="fixture/simple_in.asm"
OUTFILE="fixture/simple_out.asm"

./bin/macro $INFILE $OUTFILE
cat $OUTFILE
