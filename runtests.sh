
#!/usr/bin/env bash

cd bin/tests

echo ""

FILES=`find -type f -executable -exec sh -c "file -i '{}' | grep -q 'x-executable; charset=binary'" \; -print`
for f in $FILES
do
	echo "==================="
	printf "TESTING ${f:2} ......\n"
	$f
	if [[ $? -eq 0 ]]; then
		echo -e "Testcases \e[32msuccess\e[0m!"
	else
		echo -e "Testcases \e[31mfailed\e[0m!"
	fi

	valgrind --leak-check=full -q $f
	if [[ $? -eq 0 ]]; then
		echo -e "Valgrind \e[32msuccess\e[0m!"
	else
		echo -e "Valgrind \e[31mfailed\e[0m!"
	fi

	echo ""
done

