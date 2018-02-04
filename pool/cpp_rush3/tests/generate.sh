make re
./units
lcov --directory ../ -c -o rapport.info
#lcov --remove '/usr/include/*' '/usr/lib/*' -c -o rapport.info
lcov --remove rapport.info '/usr/include/*' '/usr/lib/*' '/usr/local/*' 'tests/*' -o rapport_filtered.info
genhtml -o ./rapport -t "Coverage" rapport_filtered.info
clean
make fclean
rm -f *.info
cd ../ ; find . -name "*.gcno" -type f -delete ; cd -
cd ../ ; find . -name "*.gcda" -type f -delete ; cd -
google-chrome rapport/index.html
