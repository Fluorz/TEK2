## Installation and Download of docker
sudo apt-get update

sudo apt-get install \
    apt-transport-https \
    ca-certificates \
    curl \
    software-properties-common

curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -


sudo add-apt-repository \
       "deb [arch=amd64] https://download.docker.com/linux/ubuntu \
       $(lsb_release -cs) \
       stable"

sudo apt-get update
sudo apt-get install docker-ce

sudo docker run hello-world


#Docker epitech image download
sudo docker pull epitechcontent/epitest-docker

var=$?
if [ $var != 0 ]
then
	echo "problem with epitech docker image"
fi

#container_id create

id=$(sudo docker container list -a | tail -2 | head -c 12)
cp content/compile.sh content/tmp_compile.sh
echo "container_id=$id" > content/compile.sh
cat content/tmp_compile.sh >> content/compile.#!/bin/sh

#Mise dans le bin
mv content/compile.sh ~/bin/
var=$?
if [ $var != 0 ]
then
	mkdir ~/bin/
	mv content/compile.sh ~/bin/
fi

#Création Alias
echo "alias compile='~/bin/compile.sh'" >> ~/.zshrc
echo "alias compile='~/bin/compile.sh'" >> ~/.bashrc
sudo apt-get update
source ~.zshrc ~.bashrc

echo "ENJOY !"

#test
compile -help
