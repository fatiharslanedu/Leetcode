#!/bin/bash
# @Author: Fatih Arslan
# Script executable with 4th command in the script. After that script can be started "./161003_uyg1A.sh"
# chmod +x 161003_uyg1A.sh
while true
do
echo -e "\nPress any key to continue after the situations."
read -n 1 -srp ""
echo -e ">> 2.0: The script executable and add the comment section top of the script.\n"
read -n 1 -srp ""
echo  -e ">> 2.1: Creating a directory (tempFiles)...\n"
read -n 1 -srp "" ;mkdir -p tempFiles
echo -e ">> 2.2: Listing all content with subdirectories including sizes and other details.\n"
read -n 1 -srp "" ;ls -1Rrs 
echo -e "\n>> 2.3: Moving source code (.cpp and .sh extensions) to tempFiles folder\n"
read -n 1 -srp "" ;cp *.cpp *.sh tempFiles/ ;ls -qR
echo -e "\n>> 2.4: Removing non-folder files in the working directory.\n"
read -n 1 -srp "" ;rm *.cpp *.sh *.txt *.out ;ls -qR
echo -e "\n>> 2.5: Copying all files in the tempFiles folder into working directory.\n"
read -n 1 -srp "" ;cd tempFiles/ ;cp *.cpp *.sh .. ;cd .. ;ls -qR
echo -e "\n>> 2.6: Removing tempFiles folder with content.\n"
read -n 1 -srp "" ;rm -r tempFiles/ ;ls -qR
echo -e "\n>> 2.7: Building c++ code.\n"
read -n 1 -srp "" ;g++ 161003_uyg1A.cpp -o executableOutput.out
echo -e "\n>> 2.8.0: Example run via console.\n"
./executableOutput.out

for i in 1 2 3
do
	echo -e "\nEnter a number: "
	g++ 161003_uyg1A.cpp -o executableOutput.out
	./executableOutput.out >> 161003_uyg1A.txt	
	echo -e ">>2.8.$i: Executing the c++ code, codeoutput to outputTxt.txt file. And then the character count is..."
	wc -wc 161003_uyg1A.txt
	echo -e "----"
done
echo -e "\n>> 2.9: Reading output txt file on terminal\n"
cat 161003_uyg1A.txt
chmod +x 161003_uyg1A.sh
echo -e "\nThank you for using this script.\n"
done



