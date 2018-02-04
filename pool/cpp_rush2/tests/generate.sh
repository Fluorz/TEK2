if [ ! -z $1 ]
then
	make re
	./units
	gcov $1.gcno
	lcov --directory . -c -o rapport.info
	genhtml -o ../rapport -t "Test unitaires réalisé" rapport.info
	mv ../rapport .
	clean
	rm *.gcov *.gcda *.gcno *.info
	firefox rapport/index.html
else
	echo "generate [nom du fichier de test. Exemple si le fichier est test.c alors mettre test]"
fi
