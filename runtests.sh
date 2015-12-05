
#!/usr/bin/env bash

cd bin/tests

echo ""

FILES=`find -type f -executable -exec sh -c "file -i '{}' | grep -q 'x-executable; charset=binary'" \; -print`
for f in $FILES
do
	echo "=========================="
	printf "TESTING ${f:2} ......\n"

	printf "Testcases\t"
	$f
	if [[ $? -eq 0 ]]; then
		printf "\e[32msuccess\e[0m!"
	else
		printf "\e[31mfailed\e[0m!"
	fi
	printf "\n"

	valgrind --leak-check=full -q $f
	printf "Valgrind\t"
	if [[ $? -eq 0 ]]; then
		printf "\e[32msuccess\e[0m!"
	else
		printf "\e[31mfailed\e[0m!"
	fi

	printf "\n"
	printf "\n"
done

