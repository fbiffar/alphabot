#!/usr/bin/env bash
# default values
node='main'
path='node.ept'
prompt="Specify node with 's', path of the heptagon file with 'p' "
prompt+="display -p node.ept\n"
while getopts 's:p:h' flag
do
    case "${flag}" in
        s) node=${OPTARG} ;;
        p) path=${OPTARG} ;;
        h) printf "$prompt" ; exit 0 ;;
    esac
done

cd "heptagon/"
(simulate.sh -s $node -p $path -k 1) 
filename="${path##*/}";
filename="${filename%.*}"
filename="${filename,}"
if [[ -z "${filename}" ]]
then echo "Please enter a valid filepath!"; exit 0;
fi

cd ".."

dest_src=$pwd."/supervisor"
src=$pwd."/heptagon/"$filename"_c"
cp "$src/"$filename"_types.c" "$dest_src/"$filename"_types.c"
cp "$src/"$filename"_types.h" "$dest_src/"$filename"_types.h"
cp "$src/"$filename".c" "$dest_src/"$filename".c"
cp "$src/"$filename".h" "$dest_src/"$filename".h"
sed --in-place '/pervasives.h/d' "$dest_src/"$filename"_types.h"