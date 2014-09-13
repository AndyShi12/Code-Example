#!/bin/bash

cd "$(cd "$(dirname "$0")" ; pwd)/.."

EXEC="$1"
INF="$2"
OUTF="$3"
EXPECTEDF="$4"
VALGF="$5"

TMPF=$(mktemp /tmp/$USER.$EXEC.XXXXX)
trap cleanup EXIT
cleanup()
{
    rm -f $TMPF
}

echo
echo "./$EXEC $INF > $OUTF"
./$EXEC $INF > $OUTF
PASS=$?
echo "cat $OUTF"
echo
cat $OUTF | sed 's/^/   /'
echo

# -- Check program output -- #
echo -n "Checking expected output: $EXPECTEDF - "
OUT_OKAY=0
diff -w $OUTF $EXPECTEDF > $TMPF && OUT_OKAY=1 

(( $OUT_OKAY == 1 )) && echo "okay"
(( $OUT_OKAY != 1 )) \
    && echo "FAIL. Expected: " \
    && echo \
    && cat $EXPECTEDF | sed 's/^/   /' 


# -- Check valgrind output -- #
VALG_OKAY=0
if (( $OUT_OKAY == 1 )) ; then
    echo -n "Performing memory-check with valgrind: - "

    valgrind --tool=memcheck --leak-check=full --verbose \
	--log-file=$VALGF ./$EXEC $INF > $OUTF

    cat "$VALGF" | grep -q "ERROR SUMMARY: 0 errors from 0 contexts" && VALG_OKAY=1

    (( $VALG_OKAY == 1 )) && echo "okay"
    (( $VALG_OKAY != 1 )) \
	&& echo "FAIL!" \
	&& echo "Examine the file '$VALGF' to diagnose the problem."
fi

echo

(( $OUT_OKAY == 1 )) && (( $VALG_OKAY == 1 )) && exit 0
exit 1

