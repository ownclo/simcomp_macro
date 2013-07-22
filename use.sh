#!/bin/bash

set -e

INFILE="fixture/sample_infile.asm"
OUTFILE="fixture/sample_outfile.asm"

./bin/macro $INFILE $OUTFILE
cat $OUTFILE
