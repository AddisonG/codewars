#!/bin/bash +x

read -p "Please enter the name/url of the Kata: " input

# Attempt to get interpret user input as a URL
websiteName=$(curl -skm 15 "$input" | grep -oP '<meta content="\K[^"]*(?=" property="og:title" />)')

if [[ "$websiteName" ]]; then
	input="$websiteName"
fi

name=$(echo "${input,,}" | xargs | sed -r "s/[^a-z0-9]+/-/g")

if [[ ! "$name" || "$name" == "http-www-*" ]]; then
	echo "Bad input"
	exit 1
fi

read -p "Please enter language used for '$name': " ext
case $ext in
	py*)
		ext=(py python)
		;;
	c++|cpp)
		ext=(cpp cpp)
		;;
	c|go|java)
		ext=($ext $ext)
		;;
	*)
		echo "Invalid / new language"
		exit 2
		;;
esac
cd ${ext[1]}

# Make directories
mkdir -p "$name"

cd "$name"
if [[ -f "$name.$ext" ]]; then
	mkdir -p backup
	mv --backup=numbered "$name.$ext" "backup/$name.$ext"
fi

vim "$name.$ext"

echo "<html><head><meta http-equiv=\"refresh\" content=\"0; url=https://www.codewars.com/kata/$name/${ext[1]}\" /></head></html>" > "link.html"
