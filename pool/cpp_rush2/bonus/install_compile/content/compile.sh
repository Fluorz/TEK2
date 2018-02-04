#Made by Léo Lecherbonnier EPITECH promo 2021 leo.lecherbonnier@epitech.eu

#Your docker container id
container_id='bb55daebaa99'




#Fonctions and Printer
printHelp()
{
	echo "\033[1mcompile [FOLDER TO TEST] [ARGUMENTS] [OPTIONS]\033[0m"
	echo
	echo "\033[1mARGUMENTS : \033[0m"
	echo
	echo "		--help"
	echo "		--make		[Require a Makefile]"
	echo "		--gcc		[Require c files with main]"
	echo "		--gcc-main	[Require c files without main]"
	echo "		--g++		[Require c++ files]"
	echo
	echo "\033[1mOPTIONS: \033[0m"
	echo "		--exec		[binary name for make] + arguments"
	echo "		--valgrind	[binary name for make] + arguments"
}

printCompileTest()
{
	echo "\033[1m======== COMPILE TEST ========\033[0m"
	echo
}

printExecTest()
{
	echo
	echo "\033[1m======== EXECUTION TEST =======\033[0m"
	echo
}

printValgrindTest()
{
	echo
	echo "\033[1m======== VALGRIND EXECUTION TEST =======\033[0m"
	echo
}

printBadOptions()
{
	echo
	echo "\033[41mBAD OPTIONS : $3\033[0m"
	echo
	echo "		-exec		[binary name for make] + arguments"
	echo "		-valgrind	[binary name for make] + arguments"
}

deleteFiles()
{
	rm .container_restart
	sudo docker container exec -i $container_id bash -c "cd home/projet_compile_test/ ; rm -rf $1 ; rm -rf .mkdir_create"
	sudo docker container exec -i $container_id bash -c "rm -rf home/projet_compile_test"
}

checkCompile()
{
	var=$?
	if [ $var != 0 ]
	then
		echo "\033[41mCOMPILE FAIL\033[0m"
		deleteFiles
		exit 1
	else
		echo "\033[42mCOMPILE SUCCESS\033[0m"
	fi

}

startDockerContainer()
{
	#Docker container restart and create folder and cp folder to test
	sudo docker container restart $container_id 2> .container_restart 1> .container_restart

	#Verifiy docker container
	var=$?
	if [ $var != 0 ]
	then
		echo
		echo "\033[41mCONTAINER ID FAIL\033[0m"
		echo ""
		echo "Verifiy the container ID"
		exit 1
	fi
}

createWorkSpace()
{
	#create folder in the home
	sudo docker container exec -i $container_id bash -c "mkdir home/projet_compile_test/ > .mkdir_create"

	#copy folder
	sudo docker cp $1 $container_id:/home/projet_compile_test/
}

addMain()
{
	sudo docker container exec -i $container_id bash -c "cd home/projet_compile_test/$1/ ; echo 'int main(void) { return (0);}' > add_main.c"
	echo "main.c added for compile"
	echo
}

addMainc()
{
	sudo docker container exec -i $container_id bash -c "cd home/projet_compile_test/$1/ ; echo 'int main(void) { return (0);}' > add_main.cpp"
	echo "main.cpp added for compile"
	echo
}

checkFolderExist()
{
	if [ ! -d "$1" ]
	then
		echo "\033[41mFOLDER DOESN'T EXIST\033[0m";
		echo
		echo "\033[1mPlease enter the folder you wanna test\033[0m"
		echo
		printHelp
		exit 1
	fi
}

checkReturnExec()
{
	var=$?
	if [ $var != 0 ]
	then
		echo
		echo "Execution test finish with return code : \033[31m$var\033[0m"
	else
		echo
		echo "Execution test finish with return code : \033[32m$var\033[0m"
	fi
}

findCompileType()
{
	if [ -z $2 ]
	then
		if [ -f "$1/Makefile" ]
		then
			type_compile='--make'
		else
			cd $1
			ls *.c 2> .tmp 1> .tmp
			var_c=$?
			ls *.cpp 2> .tmp 1> .tmp
			var_cpp=$?
			cd - > .tmp
			if [ $var_c != 0 ] && [ $var_cpp != 0 ]
			then
				echo "no extension (.c or .cpp) found for compile"
				exit 1
			elif [ $var_c = 0 ] && [ $var_cpp != 0 ]
			then
				type_compile="--gcc"
			elif [ $var_cpp = 0 ]
			then
				type_compile='--g++'
			else
				echo "extension problem to find the good compile. Please choose manually"
				exit 1
			fi
			rm $1/.tmp
		fi
	fi
}

#End of Fonctions




#HELP
if [ ! -z $1 ]
then
	#For help
	if [ $1 = "-help" ] || [ $1 = "--help" ]
	then
		printHelp
		exit 0
	fi
fi

#COMPILE SCRIPT
if [ ! -z $1 ] && [ ! -z $2 ]
then

	checkFolderExist $1
	startDockerContainer

	createWorkSpace $1

	#For GCC
	if [ $2 = "--gcc" ] || [ $2 = "--gcc-main" ] || [ $2 = "--g++" ] || [ $2 = "--g++-main" ]
	then

	printCompileTest

	#-gcc-main, add main.c
	if [ $2 = "--gcc-main" ]
	then
		addMain $1
	fi

	if [ $2 = "--g++-main" ]
	then
		addMainc $1
	fi
	#Different compile gcc or g++
	if [ $2 = "--gcc" ] || [ $2 = "--gcc-main" ]
	then
		sudo docker container exec -i $container_id bash -c "cd home/projet_compile_test/$1 ; gcc *.c -I./ -g3 -W -Wextra -Werror -Wall -std=gnu99"
	else
		sudo docker container exec -i $container_id bash -c "cd home/projet_compile_test/$1 ; g++ -W -Wall -Werror -Wextra -std=c++14 *.cpp"
	fi

	#Check if compile SUCCESS or Fail
	checkCompile

	#Exec and Valgrind part
	if [ ! -z $3 ]
	then
		if [ $3 = "--exec" ]
		then
			printExecTest
			sudo docker container exec -i $container_id bash -c "cd home/projet_compile_test/$1 ; ./a.out $4 $5 $6"
			checkReturnExec

		elif [ $3 = "--valgrind" ]
		then
			printValgrindTest
			sudo docker container exec -i $container_id bash -c "cd home/projet_compile_test/$1 ; valgrind ./a.out $4 $5"
			checkReturnExec
		else
			printBadOptions
			exit 1

		fi
	fi

	#For Make
	elif [ $2 = "--make" ]
	then
		printCompileTest
		#sudo docker container exec -i $container_id bash -c "cd home/projet_compile_test/$1 ; make re && echo -e '\033[42m\nCOMPILE SUCCESS\033[0m'  || echo -e '\033[41mCOMPILE FAIL\033[0m'"

		sudo docker container exec -i $container_id bash -c "cd home/projet_compile_test/$1 ; make re"

		#Check Compile if Fail or SUCCESS
		echo
		checkCompile

		if [ ! -z $3 ]
		then
			if [ -z $4 ]
			then
				echo
				echo "\033[1m======== PROBLEM DETECTED WITH EXECUTION TEST =======\033[0m"
				echo
				echo "\033[41m Don't forget the binary name to execute test\033[0m"
				exit 1
			fi
			if [ $3 = "--exec" ]
			then
				printExecTest
				sudo docker container exec -i $container_id bash -c "cd home/projet_compile_test/$1 ; './'$4 $5 $6 $7"
				checkReturnExec
			elif [ $3 = "--valgrind" ]
			then
				printValgrindTest
				sudo docker container exec -i $container_id bash -c "cd home/projet_compile_test/$1 ; valgrind './'$4 $5 $6 $7"
				checkReturnExec
			else
				printBadOptions
				exit 1
			fi
		fi
	else
		echo "\033[31mBAD ARGUMENTS\033[0m"
		echo
		echo "Usage of compile :"
		echo
		printHelp
	fi

	deleteFiles

#For bad input
else
	echo "\033[1mcompile :\033[0m \033[31;1mfatal error:\033[0m no input files or arguments"
	echo
	printHelp
fi
